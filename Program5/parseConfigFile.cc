//Sanjeev wants me to edit this!!
/*
 * Filename:             parseConfigFile.cc
 * Date:                 04/18/2020
 * Author:               Medha Aiyah
 * Email:                mva170001@utdallas.edu
 * Version:              1.0
 * Copyright:            2020, All Rights Reserved
 *
 * Description:
 *      This file will use rude config to parse throught the conf file so that the
 *      daemon knows what to run.
 *
*/


#include "program5.h"
#include "src/config.h"
#include <iostream>
using namespace rude;

void parse_config_file()
{	
	//This is creating the input file variable

        const char *inputFile = myMap[CONFIGFILENAME].c_str();
        Config myconfig;
	
	//It is loading the inputFile

        if(myconfig.load(inputFile))
        {
		//This is what will happen if the section is not called parameters

                if(myconfig.setSection("Parameters",false))
                {
                if(myconfig.exists("Verbose"))
                {
                        myMap[VERBOSE] = myconfig.getStringValue("Verbose");
                }

		//This is what will happen there is a section for parameters		

                else
                {
                        cout << "Verbose definition missing." << endl;
                }
                if(myconfig.exists("LogFile"))
                {
                        myMap[LOGFILE] = myconfig.getStringValue("LogFile");
                }
                else
                {
                        cout << "LogFile definition missing" << endl;
                }

                if(myconfig.exists("Password"))
                {
                        if(myMap[PASSWORD].empty())
                        {
                                myMap[PASSWORD] = myconfig.getStringValue("Password");
                        }
                        else
                        {
                                string s = myconfig.getStringValue("Password");
                                if(s.compare(myMap[PASSWORD])!=0)
                                {
                                        if(myMap[DAEMONMODE] == "true")
                                        {
                                                writeToLog("ERROR: Password has been changed");
                                                closerFile();
                                                exit(1);
                                        }
                                        else
                                        {
                                                cout << "Error in parseConfigFile: Password changed" << endl;
                                        }
                                }
                        }
                }
                else
                {
                        cout << "Password definition missing." << endl;
                }
                if(myconfig.exists("NumVersions"))
                {
                        myMap[NUMVERSION] = myconfig.getStringValue("NumVersions");
                }
                else
                {
                        cout << "NumVersions definition missing." << endl;
                }
                if(myconfig.exists("WatchDir"))
                {
                        if(myMap[WATCHDIR].empty())
                        {
                        myMap[WATCHDIR] = myconfig.getStringValue("WatchDir");
                        }
                        else
                        {
                                string s = myconfig.getStringValue("WatchDir");
                                if(s.compare(myMap[WATCHDIR]))
                                {
                                         if(myMap[DAEMONMODE] == "true")
                                         {
                                               writeToLog("ERROR: Password has been changed");
                                                 closerFile();                                                                                                 exit(1);
                                                                                                                                                 }

                                else
                                {
                                        cout<<"error in paseConfigFile: watch dir changed"<<endl;
                                }
                                }

                        }
                }
                else
                {
                        cout << "WatchDir definition  missing." << endl;
                }
                }
        }
        else
        {
                cout << "Error loading input file." << endl;
        }
}
