/*
 * Filename:             program5.h
 * Date:                 04/18/2020
 * Author:               Medha Aiyah
 * Email:                mva170001@utdallas.edu
 * Version:              1.0
 * Copyright:            2020, All Rights Reserved
 *
 * Description:
 *      Calls some of the include statements needed for the other files, with the enum,
 *      and the function prototypes. 
*/

#ifndef __PROGRAM5_H__
#define __PROGRAM5_H__

#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cstdlib>
#include <csignal>
#include <fstream>
#include <iostream>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>

using namespace std;

//This is creating the map keys that will be used to store the contents in the pa

enum _mapKeys{CONFIGFILENAME, DAEMONMODE, VERBOSE, LOGFILE, PASSWORD, NUMVERSION, WATCHDIR};

//This is the global map variable

extern map<int, string> myMap;

//These are the function prototypes

void command_line(int, char**);
void parse_config_file();

int processControl();
bool FileExists(const string& name);
void removePid();
void create_pid_file(int);

void createLog();
void writeToLog(string message);
void closerFile();

void sigHand();
void signalHandling(int signum);

void inotifyStart();

#endif
 
