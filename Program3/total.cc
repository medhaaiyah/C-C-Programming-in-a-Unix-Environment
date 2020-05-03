/*
 *Filename: total.cc
 *Date: 2.24.2020
 *Author: Medha Aiyah
 *Email: mva170001@utdallas.edu
 *Course: CS 3377.501 Spring 2020
 *Version 1.0
 *Copyright 2020, All Rights Reserved
 *
 *Description: This file will first print out the contents of the gawk version we are using. From there, it will take
 *             the gawk.code output and print out the output formed from gawk.code, the specific some from column one
 *             and the specific sum from column 4. 
 *
*/


#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include "header.h"

using namespace std;

//This is the function where it will print out the two calls

int allSums(int argc, char ** argv)
{
  ofstream myOutputFile;
  myOutputFile.open("output.txt");

  //This is going to print the commands that can be used to get the gawk, shellcmd1, and shellcmd2

  cout << "gawk at:/home/012/m/mv/mva170001/Program3/bin/gawk" << endl;
  cout << "shellcmd1: /home/012/m/mv/mva170001/Program3/bin/gawk --version" << endl;
  cout << "shellcmd2:/home/012/m/mv/mva170001/Program3/bin/gawk -f gawk.code numbers.txt" << endl << endl;

  myOutputFile << "gawk at:/home/012/m/mv/mva170001/Program3/bin/gawk" << endl;
  myOutputFile  << "shellcmd1: /home/012/m/mv/mva170001/Program3/bin/gawk --version" << endl;
  myOutputFile << "shellcmd2:/home/012/m/mv/mva170001/Program3/bin/gawk -f gawk.code numbers.txt" << endl << endl;
  

  //This is just setting the buffer size to 1024  

  char buff[1024];
  
  //This is going to be dealing with the first call

  cout << "The first call to gawk returned" << endl << endl;

  myOutputFile << "The first call to gawk returned" << endl << endl;

  //This inpipe is going to be used to open and retrive the version through the popen function

  FILE * inpipe = popen("./bin/gawk -V", "r");

  //This is what will happen when there is nothing set to the inpipe

  if(inpipe == NULL)
  {
    cout << "There is an error so it cannot create a pipe stream" << endl;
    myOutputFile << "There is an error so it cannot create a pipe stream" << endl;
  }

  //This while loop will print out the contents of the inpipe  

  while(fgets(buff, 1024, inpipe))
  {
    cout << buff;
    myOutputFile << buff;
  }

  //This will close the inpipe since we are done with the first call  

  pclose(inpipe);

  //This is what will happen for the second call

  //Since this is the second call, we are setting up inpipe to open a different thing

  inpipe = popen("./bin/gawk -f gawk.code numbers.txt", "r");

  //This is the what will happen if there is no contents in the inpipe

  if(inpipe == NULL)
  {
    cout << "Error creating pipe stream" << endl;
    myOutputFile << "Error creating pipe stream" << endl;
  }

  //This is what will happen if it cannot receive the data from the inpipe

  if(fgets(buff, 1024, inpipe) == NULL)
  {
    cout << "Error when receiving data on pipe" << endl;
    myOutputFile << "Error when receiving data on pipe" << endl;
    pclose(inpipe);
    return -3;
  }

  //It will retrieve the contents and close the pipe

  pclose(inpipe);

  //It will use the information and parse it through istringstream

  istringstream istream(buff);

  //This is going to use the contents from the gawk.output and set it to 2 variables  

  int sum1, sum4;
  istream >> sum1 >> sum4;

  //This will print out the gawk output, and the sum of column 1, and the sum of column 4  

  cout << "The second call to gawk returned: " << sum1 << " " << sum4 << endl;
  cout << endl;
  cout << "The sum of Column 1 is: " << sum1 << endl;
  cout << "The sum of Column 4 is: " << sum4 << endl;

  myOutputFile << "The second call to gawk returned: " << sum1 << " " << sum4 << endl;
  myOutputFile << endl;
  myOutputFile << "The sum of Column 1 is: " << sum1 << endl;
  myOutputFile << "The sum of Column 4 is: " << sum4 << endl;

  int total;

  //This will add the two sums to get the total and will print it out  

  total = sum1 + sum4;
  cout << "The sum of the two numbers: "  << total << endl;
  myOutputFile << "The sum of the two numbers: "  << total << endl;
  
  myOutputFile.close();
  return 0;
}
