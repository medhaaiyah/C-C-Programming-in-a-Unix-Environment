/*
 * Filename:             program5.cc
 * Date:                 04/18/2020
 * Author:               Medha Aiyah
 * Email:                mva170001@utdallas.edu
 * Version:              1.0
 * Copyright:            2020, All Rights Reserved
 *
 * Description:
 *      This program will call the processes that are required for the daemon to run and will
 *      remove the pid file once the daemon shuts down.
*/

#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <bits/stdc++.h>
#include <sys/types.h>
#include <linux/limits.h>
#include "program5.h"

using namespace std;

map<int,string> myMap;

int main(int argc,char **argv)
{
	int wd, fd;
	int pidId;
	
	//These are the functions that are called so that the D flag is the conf file is parsed 
	
	command_line(argc,argv);
	parse_config_file();
	
	//This will create the log	

	createLog();
	
	//These are the error statements I get

	if(fd<0)
	{
        	writeToLog("Error in initializing inotify");
	}
	if(wd<0)
	{
        	writeToLog("error with adding watch to directory");
	}
	else
	{
		//This is what will happen when verbose is true

        	if(myMap[VERBOSE] == "true")
           	{
			writeToLog("Watching directory");
		}
	}

	//This will check the verbose status
	
	if(myMap[VERBOSE] == "true")
	{
		writeToLog("Starting program in verbose mode.");
	}

	//This is what happens when a pid is created

    	if(FileExists("cs3377dirmond.pid"))
    	{
      		writeToLog("Daemon is already running");
      		exit(1);
    	}
	
	//This is where the daemon will run
	
	else
    	{
      		if(myMap[VERBOSE] == "true")
      		{
        		writeToLog("creating ./versions subfolder");
      		}
        	string subfolder = "mkdir -p " + myMap[WATCHDIR] + "/.versions";
        	system(subfolder.c_str());

      		//create pid file and handle fork()
     		
		if(myMap[DAEMONMODE]=="true")
     		{
        		pidId= processControl();
         		if(myMap[VERBOSE] == "true")
               		{
                    		writeToLog("Moving to process control (creating pid file and log file and etc).");
                	}
     		}
        	create_pid_file(pidId);
        	sigHand();

                //This is where a daemon will end                

     		if(myMap[DAEMONMODE] =="false")
     		{
        		writeToLog("Running without daemon");
        	}
     		while(1)
     		{
        		inotifyStart();
     		}
     		if(myMap[DAEMONMODE] == "false")
     		{
        		removePid();
        		closerFile();
     		}
   	}

	return 0;
}
