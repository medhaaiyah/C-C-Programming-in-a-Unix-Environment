/*
 *Filename: header.h
 *Date: 2.13.2020
 *Author: Medha Aiyah
 *Email: mva170001@utdallas.edu
 *Course: CS 3377.501 Spring 2020
 *Version 1.0
 *Copyright 2020, All Rights Reserved
 *Description:This is the header file where we are initializing the map
*/

#ifndef __HEADER_H__
#define __HEADER_H__

using namespace std;

//This is creating the map keys that will be used to store the contents in the pa

enum _mapKeys{OUTPUTFILE,INPUTFILE,UFLAG,LFLAG};

//This is the global map variable

extern map<int, string> myMap;

//These are the function prototypes

void command_line(int, char**);
void file_work(map<int, string>);
void print_map(map<int, string>);

#endif
 
