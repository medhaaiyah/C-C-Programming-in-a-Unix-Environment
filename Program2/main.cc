/*
 *Filename: main.cc
 *Date: 2.13.2020
 *Author: Medha Aiyah
 *Email: mva170001@utdallas.edu
 *Course: CS 3377.501 Spring 2020
 *Version 1.0
 *Copyright 2020, All Rights Reserved
 *Description: This main file is going to look at the contents of the map and place the parsed contents into the output file
*/

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "header.h"
map <int, string> myMap;

//This main file will execute the functions that are called.

int main(int argc, char *argv[])
{
  command_line(argc, argv);
  file_work(myMap);
  print_map(myMap);
  return 0;
}

//This file will deal with storing the contents from the map into the file

void file_work(map<int, string> myMap)
{
  
  //These are the variables to deal with the file I/O
  
  ifstream myInputFile;
  ofstream myOutputFile;

  //These variables are going to aid us in the process to store the contents into the output file

  string input = " ";
  string outputFile = myMap[OUTPUTFILE];
  string inputFile = myMap[INPUTFILE];

  //We will use the filestream variables and use the c-style string to deal with the output and input stuff from the map

  myOutputFile.open(outputFile.c_str());
  myInputFile.open(inputFile.c_str());

  //This is what will happen if the upper flag and the lower flag will both be true

  if(myMap[UFLAG] == "true" && myMap[LFLAG] == "true")
  {
    cout << "It will not be able to change to uppercase and lowercase at the same time" << endl;
  }
  
  //This is what will happen if one is true and the other is false

  else
  {
   
    //THis is what will happen once we open the inputFile 
  
    if(myInputFile.is_open())
    {
      while(!myInputFile.eof())
      {
        getline(myInputFile, input);
        
        //This is what will happen if only the upper flag is true        

        if(myMap[UFLAG] == "true")
        {
         
         //This where we will convert to upper form 
         
          for(int i = 0; i < input.size(); i++)
          {
            input.at(i) = toupper(input.at(i));
          }
          
          //This is going to store the upper case contents into the output file
          
          myOutputFile << input << endl;
        }

        //This is what will happen if the lower flag is true

        else if(myMap[LFLAG] == "true")
        {
          
          //This is where it will convert all the letters to lowercase
          
          for(int i = 0; i < input.size(); i++)
          {
            input.at(i) = tolower(input.at(i));
          } 
          
         //This is where it will store the updated lowercase contents to the output file
          
          myOutputFile << input << endl;
        }
        
        //This is what will happen if both the uppercase and lowercase are false 

        else
        {
          //It will print the normal contents into the output file
          
          myOutputFile << input << endl;
        }
      }
    }
  }

  //It will close both the input and output files  

  myInputFile.close();
  myOutputFile.close();
}

//This function will print the contents that is stored in the map to the terminal screen

void print_map(map<int, string> myMap)
{
  
  //This will print out the inputfile, outputfile, the lower flag value, and the upper flag value
  
  cout << "The value of the map include: " << endl;
  cout << "The input file name is: " << myMap[INPUTFILE] << endl;
  cout << "The output file name is: " << myMap[OUTPUTFILE] << endl;
  cout << "The lower case instruction is: " << myMap[LFLAG] << endl;
  cout << "The upper case instruction is: " << myMap[UFLAG] << endl;
}
