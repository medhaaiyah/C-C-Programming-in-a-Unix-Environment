/*
 * Filename:             inotifyFunctions.cc
 * Date:                 04/18/2020
 * Author:               Medha Aiyah
 * Email:                mva170001@utdallas.edu
 * Version:              1.0
 * Copyright:            2020, All Rights Reserved
 *
 * Description:
 *      This file will trigger the daemon to make the a time-stamp copy of a file.
 *
*/

#include "program5.h"
#include <sstream>

void inotifyStart()
{
    //declare variables

    size_t buffsize = (1024*(sizeof(struct inotify_event) + 16));
    struct inotify_event *event = (struct inotify_event *) malloc(buffsize);
    int length; 
    int watchDir;
    int fileDesc= inotify_init();
    int acc = 0;

    //If file descriptor returns error print it
    
    if(fileDesc < 0)
    {
        cerr << "INOTIFY ERROR: FILE DESCRIPTOR ERROR" << endl;
        return;
    }

    //Start watching the user inputted directory and begin reading
   
    watchDir = inotify_add_watch(fileDesc, myMap[WATCHDIR].c_str(), IN_MODIFY | IN_CREATE | IN_DELETE);
    length = read(fileDesc, event, buffsize);

    //If there is an error reading then print and error and exit
   
    if(length < 0)
    {
        cerr << "INOTIFY ERROR: READ ERROR" << endl;
        return;
    }

    int versionCounter = 0;
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);

    //This function is run every time an event happens
    
    while(acc < length)
    {
        //while the event has a length

        if(event->len)
        {
	    string fileName = event->name;
	    
	    //These are the integer variables holding the numbers
	    
    	    int year = 1900 + local_time->tm_year;
	    int month = 1 + local_time->tm_mon;
	    int hour = local_time->tm_hour;
	    int min = 1 + local_time->tm_min;
	    int sec = 1 + local_time->tm_sec;
	    int day = local_time->tm_mday;

	    //The stringstream will convert the ints to strings	    

	    stringstream s;
	    s << year;
	    string year_final;
	    s >> year_final;

	    s.clear();
	    s.str("");
	    s << month;
	    string month_final;
	    s >> month_final;	    
	
	    s.clear();
	    s.str("");
	    s << day;
	    string day_final;
	    s >> day_final;

	    s.clear();
	    s.str("");
	    s << hour;
	    string hour_final;
	    s >> hour_final;

	    s.clear();
	    s.str("");
	    s << min;
	    string min_final;
	    s >> min_final;	    

	    s.clear();
	    s.str("");
	    s << sec;
	    string sec_final;
	    s >> sec_final;

	    //The folder variable will make a copy and put it in the .versions folder	    

	    string folder = "cp ./" + fileName + " " + myMap[WATCHDIR] + "/.versions";
	    
	    //The move variable will rename the file name and set the timestamp

	    string move = "mv ./.versions/" + fileName + " " + "./.versions/"  + fileName + "." +year_final+"."+month_final+"."+day_final+"-"+hour_final+":"+min_final+":"+sec_final; 
            
	    //If an object is created in the watch directory, log it
            
	    if(event->mask & IN_CREATE)
            {
		fileName = fileName + " has been created";
		writeToLog(fileName);
		system(folder.c_str());
                versionCounter = versionCounter + 1;
		system(move.c_str());		
	    
	    }
            
	    //If an object is deleted in the watch directory, log it
            
	    if(event->mask & IN_DELETE)
            {
             	fileName = fileName + " has been deleted";
                writeToLog(fileName);
                system(folder.c_str());
                versionCounter = versionCounter + 1;
		system(move.c_str());
            }
            
	    //If an object is modified in the watch directory, log it
            
	    if(event->mask & IN_MODIFY)
            {
                fileName = fileName + " has been modified";
                writeToLog(fileName);
                system(folder.c_str());
	        versionCounter = versionCounter + 1;
		system(move.c_str());
            }
	    // versionCounter++;
	     cout << "The number of versions of(2nd) " << fileName << ":" << versionCounter << endl;
	            }
        acc += sizeof(struct inotify_event) + event->len;
    }

    //Close inotify, the file discriptor, deallocate the point memory, and exit
   
    inotify_rm_watch(fileDesc, watchDir);
    close(fileDesc);
    free(event);
    return;
}
