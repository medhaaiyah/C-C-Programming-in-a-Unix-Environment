/*Filename: main.cc
 *Date: 1.25.2020
 *Author: Medha Aiyah
 *Email: mva170001@utdallas.edu
 *Course: CS 3377.501 Spring 2020
 *Version: 1.0
 *Copyright 2020, All Rights Reserved
 *
 *Description: This .cc file was created to displau the count of the command
 *	      line arguments to stdout. It will display the value of each command line.
*/ 

#include "header.h"
#include <iostream>
using namespace std;

/*
 *In the main function, there are two parameter: an argument
 *and the array for where each argument is stored. It will
 *print out the number of the argument. It will then print 
 *out the contents in the array.
 *
*/

int main(int argument,const char *args[])
{

//This line will print out the number of arguments

cout << "argc was: " << argument << endl;

//This while loop will print out the argument contents

int i = 0;
while(i < argument)
{

cout << args[i] << endl;
i++; 

}

//After it prints out the arguments then it will print "Done!"

cout <<"Done!" << endl;

//It will call the procedure function

procedure();

//Since the main is an int, I am returning 0.

return 0;

}
