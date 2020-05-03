#!/bin/bash

#Filename: run.sh
#Date: 1.26.2020
#Author: Medha Aiyah
#Email: mva170001@utdallas.edu
#Course: CS 3377.502 Spring 2020
#Version 1.0
#Copyright 2020, All Rights Reserved
#
#Description: This shell script is used run the program. It will
#             also append the stdout to the stdout.log file and the
#             stderr to the stderr.log file.
#

#This is what will happen when it runs the executable for the first argument

echo "Running Assignment_1 with 0 arguments:"
echo -e "\t stdout append to stdout.log"
echo -e "\t stderr append to stderr.log"

#it will clear the stdout.log and the stderr.log 

echo -n > stdout.log
echo -n> stderr.log

#It will execute the file and send the output to the appropriate log files

./Assignment_1 >> stdout.log 2>> stderr.log

#This is what will happen when it runs the executable for the second argument

echo "Running Assignment_1 with 1 arguments:"

#It will include the numbers in the stdout.log and stderr.log

echo -e "\t stdout append to stdout.log"
echo -e "\t stderr append to stderr.log"

#It will execute the file and send the output to the appropriate log files

./Assignment_1 abc >> stdout.log 2>> stderr.log

#This is what will hapen when it runs the executable for the third argument

echo "Running Assignment_1 with 5 arguments:"

#It will include the numbers in the stdout.log and the stderr.log

echo -e "\t stdout append to stdout.log"
echo -e "\t stderr append to stderr.log"

#It will execute the file and send the output to the appropriate log files

./Assignment_1 a b c d e >> stdout.log 2>> stderr.log

