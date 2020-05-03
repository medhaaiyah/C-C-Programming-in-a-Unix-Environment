/*
 * Filename:             signalHandling.cc
 * Date:                 04/18/2020
 * Author:               Medha Aiyah
 * Email:                mva170001@utdallas.edu
 * Version:              1.0
 * Copyright:            2020, All Rights Reserved
 *
 * Description:
 *      This file responds to the SIGINT, SIGTERM, and SIGHUP Unix signal.
 *   
*/

#include "program5.h"
#include <signal.h>
#include <csignal>
#include <iostream>
#include <stdio.h>

using namespace std;

void signalHandling(int signum)
{
        //This is what will have for SIGINT and SIGTERM signals

	if(signum == SIGINT || signum == SIGTERM)
        {
       		writeToLog("Daemon interrupted. Shutting down.");
        	removePid();
        	closerFile();
        	exit(signum);
        }

	//This is what will happen for the SIGHUP signal

        else if (signum == SIGHUP)
        {
                writeToLog("re-reading configuration file.");
                parse_config_file();
                writeToLog("Configuration updated");
        }
}


void sigHand()
{
	//This calls the SIGINT function

        signal(SIGINT, signalHandling);
	sleep(1);
	
	//This calls the SIGTERM function	

        signal(SIGTERM, signalHandling);
        sleep(1);

	//This calls the SIGHUP function

	signal(SIGHUP, signalHandling);
	sleep(1);
}

