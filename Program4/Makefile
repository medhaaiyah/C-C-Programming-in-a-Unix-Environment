#!/usr/bin/make -f
#
# Filename:             Makefile
# Date:                 03/28/2020
# Author:               Medha Aiyah
# Email:                mva170001@utdallas.edu
# Version:              1.0
# Copyright:            2020, All Rights Reserved
#
# Description:
#       Builds a quick Makefile for Program 4. This makefile will 
#       be in the form of a C compiler and will create two exe bits.

# Flags for the C implicit rules

CC = gcc
CCFLAGS = -Werror
CPPFLAGS =

# Flags for the Lex implicit rules

LEX = /bin/flex
LFLAGS =

# Flags for the Bison implicit rules

YACC = /bin/bison
YFLAGS = -dy

# PROJECTNAME is a descriptive name used for the backup target

PROJECTNAME = Program4

EXEC = program4

OBJS = parse.o  scan.o myproject.o main.o

# Because we are insane, keep the intermediate files so we can look at
# them If we comment this out (or remove it), the intermediate scan.c
# file is automatically deleted.

.PRECIOUS: scan.c

# This will create the executable that will link to either the scanner or parser

all: $(EXEC)

# This will clean certain aspects of the file

clean:
	rm -f $(OBJS) $(EXEC) y.tab.h parse.c parser  scanner scan.c *~ \#*

# This will link the appropriate object files to the scanner and the parser

$(EXEC):    $(OBJS)
	$(CC) -o $@ $(OBJS)
	ln -s $(EXEC) scanner
	ln -s $(EXEC) parser

# This will be used to create the backup file.

backup:
	@make clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename "`pwd`"))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME) 2> /dev/null
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!

