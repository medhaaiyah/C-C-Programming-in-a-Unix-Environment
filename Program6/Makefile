# Filename:            Makefile
# Date:                04/28/2020
# Author:              Medha Aiyah
# Email:               mva170001@utdallas.edu
# Version:             1.0
# Copyright:           2019, All Rights Reserved
#
# Description:
#
#      This file is used to run/compile the project
 


CXX = g++
CXXFLAGS =
CPPFLAGS = -Wall -g -I/scratch/perkins/include
LDFLAGS = -L/scratch/perkins/lib
LDLIBS = -lcdk -lcurses

# Executable Name
EXECFILE = program6

# Auto include all .cc files
SOURCES := $(wildcard *.cc)
OBJS = $(SOURCES:.cc=.o)

# Rely on implicit rules for compilation

all: $(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) *~ \#*


$(EXECFILE): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

backup:
	@mkdir -p ~/backups; chmod 700 ~/backup
	@$(eval CURDIRNAME := $(shell basename "`pwd`"))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME) 2> /dev/nul
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!


