/*
 * Filename:             loggingFunctions.cc
 * Date:                 04/18/2020
 * Author:               Medha Aiyah
 * Email:                mva170001@utdallas.edu
 * Version:              1.0
 * Copyright:            2020, All Rights Reserved
 *
 * Description:
 *      This is used to create the logging file and will print when the daemon starts
 *      running.
*/

#include "program5.h"

ofstream log;

void createLog()
{
	//It will open the log file stored in the map

	log.open(myMap[LOGFILE].c_str());
	
	//This what will happen if the log file cannot open	

	if(!log.is_open())
	{
		cout << "LOG FILE COULD NOT BE OPENED/CREATED" << endl;
	}

	//This is what will happen if the log file can open

	else
	{

		//This is where the daemon is true		

		if(myMap[DAEMONMODE] == "true")
		{
			if(myMap[VERBOSE] == "true")
			{
				log << "Currently: Daemon started, log file created" << endl;
			}
		}
				
		//This is where the daemon is not running

		else
		{
			if(myMap[VERBOSE] == "true")
			{
				log << "Currently: Running without daemon, log file created" << endl;
			}
		}
	}

}

//This function where the string can write to the log file

void writeToLog(string message)
{
	log << message << endl;
}

//This function will close the log

void closerFile()
{
	log.close();
}
