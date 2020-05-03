/*
 * Filename:             processControl.cc
 * Date:                 04/18/2020
 * Author:               Medha Aiyah
 * Email:                mva170001@utdallas.edu
 * Version:              1.0
 * Copyright:            2020, All Rights Reserved
 *
 * Description:
 *      This file will trigger the daemon to make the a time-stamp copy of a file.
 *
*/

#include "program5.h"

using namespace std;

//This functions will determine whether the file exists

bool FileExists(const std::string& name)
{
        struct stat buffer;
        return (stat(name.c_str(), &buffer) == 0);
}

//This will be calling the forking

int processControl()
{	
	writeToLog("In processControl()");
        writeToLog("Doing the fork process");
        pid_t pid = fork();
	
	//This is what will happen fork will fail	

        if (pid<0)
        {
                cout<<"Fork failed." <<endl;
                exit(1);
        }

	//This is what will happen when verbose is true	

	if(pid > 0)
	{
		if(myMap[VERBOSE] == "true")
		{
			writeToLog("Parent exited.");
		}
		exit(1);
	}
	
	//Calling the child fork
	
        if(pid == 0)
        {
                writeToLog("We are in the child fork portion.");
		return getpid();
        }
        return 0;
}

//This is focusing on the creation of the pid file

void create_pid_file(int pidIdNum)
{
        //This is what will happen when the pid file exists

	if(FileExists("cs3377dirmond.pid"))
        {
                writeToLog("Daemon is already running");
                exit(1);
        }

        else
        {
                ofstream pidFile("cs3377dirmond.pid");
                pidFile <<pidIdNum <<endl;
                pidFile.close();
        //      createLog();
                if(myMap[VERBOSE] == "true")
                {
                        writeToLog("pid file created and closed");
                }
        }
        return;
}

//This will remove the pid file

void removePid()
{
	if(myMap[VERBOSE] == "true")
        {
                writeToLog("Removing pid file");
        }
        remove("cs3377dirmond.pid");
        return;
}
