#!/bin/bash

#
# Filename: compile.sh
# Date: 1.26.2019
# Author: Medha Aiyah
# Email: mva170001@utdallas.edu
# Course: CS 3377.501 Spring 2020
# Version 1.0
# Copyright 2020, All Rights Reserved
# 
# Description: This shell script is used to compile the program.
#              There will be two shell scripts and this one will
#              specifically compile the two source files.
# 
#

# Used to compile the first source file

#echo "Setting TEMPDIR environment variable to /scratch"
#TMPDIR=/scratch;export TMPDIR
echo "Compiling main.cc"
g++ -c main.cc

#Used to compile the second source file

echo "Compiling procedure.cc"
g++ -c procedure.cc

#Used to link both the object files

echo "Linking files to create executionable Assignment_1"
g++ main.o procedure.o -o Assignment_1 

#Notify that everything is compiled and linked

echo "Done"

