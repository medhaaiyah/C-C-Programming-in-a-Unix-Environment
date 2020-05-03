#!/usr/bin/make -f

#Filename: Makefile
#Date: 2.24.2020
#Author: Medha Aiyah
#Email: mva170001@utdallas.edu
#Course: CS 3377.501 Spring 2020
#Version 1.0
#Copyright 2020, All Rights Reserved
#
#Description: This file is used to generate the executable bits and used
#             for compiling the code.
#     


#These are the flag variables that I am using

CXX = g++
CXXFLAGS = -Wall
SRCS = total.cc main.cc
OBJS = $(SRCS:.cc=.o)
EXEC = program3
PROJECTNAME = Program3
EXCLUDE = bin etc gawk include lib libexec share

#This is showing that all and clean are the phony targets

.PHONY: all clean

#This is using the pattern rule is matching the filenames

%o:%cc
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -O $< -o $@

#This is showing what the executable bit is going to be

all: $(EXEC)

#This is going to remove all of the object files in program3 to regenerate

clean:
	rm -f $(OBJS) *~ $(EXEC)

#This is what is going to happen to create the program3 executable bit

$(EXEC): $(OBJS)
	$(CXX) -o $@ $(OBJS)

#This target field is used to clean the directory and create a backup

tarball: clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename `pwd`))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME) --exclude='./bin/*'--exclude='./etc/*' --exclude=./include/*'--exclude=./lib/*'--exclude=./libexec/*' --exclude=./share/*'  
	@chmod 600 $(MKBKUPNAME)
	@echo
 
