//This file will call the main function and there will be another function that will use the gawk code and output that value

/*
 *Filename: main.cc
 *Date: 2.24.2020
 *Author: Medha Aiyah
 *Email: mva170001@utdallas.edu
 *Course: CS 3377.501 Spring 2020
 *Version 1.0
 *Copyright 2020, All Rights Reserved
 *
 *Description: This files consists of the main function that will call allSums to print out the two different calls
 *             and output the appropriate values.
 *
*/ 

#include <iostream>
#include <stdio.h>
#include <sstream>
#include "header.h"

//This is the main function

int main(int argc, char ** argv)
{

  //It is calling the function where the magic happens
  //This function is located in the total.cc file

  allSums(argc, argv);
  return 0;
}
