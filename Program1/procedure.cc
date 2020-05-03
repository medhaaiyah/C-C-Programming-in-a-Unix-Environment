/*Filename: procedure.cc
 *Date: 1.26.2020
 *Author: Medha Aiyah
 *Email: mva170001@utdallas.edu
 *Course: CS 3377.501 Spring 2020
 *Version 1.0
 *Copyright 2020, All Rights Reserved
 *
 *Description: This file is used to display the log message that states
 *             you are inside the procedure.
 *
*/

#include "header.h"
#include <iostream>
using namespace std;

/*
 *This function does not have a parameter. The main
 *purpose of this function is to print out a logging 
 *message.
*/

int procedure()
{

//This is the logging message that will be printed out for every argument

cerr << "Inside proc1() as stderr" << endl;

//Since this function is an integer, it will return 0 to show that this function is done

return 0;

}
