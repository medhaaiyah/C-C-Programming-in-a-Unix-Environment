/*
 * Filename:             parseCommandLine.cc
 * Date:                 04/18/2020
 * Author:               Medha Aiyah
 * Email:                mva170001@utdallas.edu
 * Version:              1.0
 * Copyright:            2020, All Rights Reserved
 *
 * Description:
 *      This file will use TCLAP library and will call the tidbits that are used to run the daemon.
 *
*/

#include <map>
#include <iostream>
#include "tclap/CmdLine.h"
#include "program5.h"

using namespace std;

//This function is created to form the TCLAP tidbits and parse through the file

void command_line(int argc,char **argv)
{

//This is the try portion. If it exists then this section will execute

	try
	{

		//This is the command line variable

		TCLAP::CmdLine cmd("CS", ' ', "1.0");

		//These two are the switch case arguments to run in daemon mode

		TCLAP::SwitchArg daemon("d", "daemon", "Run in daemon mode", cmd, false);

		//This is the unlabled value arg will focus on dealing with the existing input file

		TCLAP::UnlabeledValueArg<string> configFileArg("configfile", "config filename", false, "cs3377dirmond.conf", "config filename");
		cmd.add(configFileArg);

		//This is going to parse the command variable

		cmd.parse(argc,argv);

		//These two boolean variables will get the contents stored for the TCLAP tidbits

		bool dFlag = daemon.getValue();

		//This variable will help store the value to the map

		string present = "false";

		//It will store true if the daemon flag exists

		if(dFlag)
		{
			present = "true";
			myMap[DAEMONMODE] = present;
		}

		//It will store false if the daemon flag does not exist

		else
		{
			present = "false";
			myMap[DAEMONMODE] = present;
		}

		//It will store the appropriate input and output contents to the map

		myMap[CONFIGFILENAME] = configFileArg.getValue();

	}

	//This is the catch statement that will print out the following statements if there are errors in the code

	catch(TCLAP::ArgException &e)
	{
		cerr << "error: " << e.error() << " for arg " << e.argId() << endl;
	}

	return;
}
