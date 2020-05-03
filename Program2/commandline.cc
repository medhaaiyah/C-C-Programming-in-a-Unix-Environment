/*
 *Filename: commandline.cc
 *Date: 2.13.2020
 *Author: Medha Aiyah
 *Email: mva170001@utdallas.edu
 *Course: CS 3377.501 Spring 2020
 *Version 1.0
 *Copyright 2020, All Rights Reserved
 *Description: This file will deal with the TCLAP tidbits and store the parsed contents into the map
*/ 

#include <map>
#include <iostream>

#include "tclap/CmdLine.h"
#include "header.h"

using namespace std;

//This function is created to form the TCLAP tidbits and parse through the file

void command_line(int argc,char **argv)
{

//This is the try portion. If it exists then this section will execute

try
{

//This is the command line variable

TCLAP::CmdLine cmd("CS", ' ', "1.0");

//This is the tidbit that will deal with creating the output file

TCLAP::ValueArg<string> outFile("o","outfile","The name of the output file", false, "output.txt", "output filename");
cmd.add(outFile);

//These two are the switch case arguments that will convert the text to either lowercase or uppercase

TCLAP::SwitchArg upper("u", "upper", "Convert to upper", cmd, false);
TCLAP::SwitchArg lower("l", "lower", "convert to lower", cmd, false);

//This is the unlabled value arg will focus on dealing with the existing input file

TCLAP::UnlabeledValueArg<string> inFileArg("infile", "input filename", true, "inFile.txt", "input filename", false);
cmd.add(inFileArg);

//This is going to parse the command variable

cmd.parse(argc,argv);

//These two boolean variables will get the contents stored for the TCLAP tidbits

bool lFlag = lower.getValue();
bool uFlag = upper.getValue();

//This variable will help store the value to the map

string present = "false";

//It will store true if the lower flag exists

if(lFlag)
{
present = "true";
myMap[LFLAG] = present;
}

//It will store false if the lower flag does not exist

else
{
present = "false";
myMap[LFLAG] = present;
}

//It will store true if the upper flag exists

if(uFlag)
{
present = "true";
myMap[UFLAG] = present;
}

//It will store false if the upper flag does not exist

else
{
present = "false";
myMap[UFLAG] = present;
}

//It will store the appropriate input and output contents to the map

myMap[OUTPUTFILE] = outFile.getValue();
myMap[INPUTFILE] = inFileArg.getValue();

}

//This is the catch statement that will print out the following statements if there are errors in the code

catch(TCLAP::ArgException &e)
{
cerr << "error: " << e.error() << " for arg " << e.argId() << endl;
}

return;
}
