/*
 * Filename:            myproject.c
 * Date:                03/28/2020
 * Author:              Medha Aiyah
 * Email:               mva17000@utdallas.edu
 * Version:             1.0
 * Copyright:           2020, All Rights Reserved
 *
 * Description:
 *
 *      Call the yylex() function generated by flex and the yyparse() function generated by Bison.
 */

//These are the headers files that will be used in this C file

#include <stdio.h>         
#include "y.tab.h"         

//These are the global variables that will be used in myproject.c
 
int yylex(void);
extern char *yytext;

//This is where it will assess the file and print out the things appropriate for the scanner

int scan()
{
  //These are the variables that are used in this function

  int token;
  
  printf("Operating in scan mode\n");
  printf("\n");
  
  token = yylex();

  //This is the while statement that will look at each token in the infilename.txt  

  while(token)
    {

      //This switch case is used to print out the appropriate output for a particular token in the file      

      switch(token)
        {
        case HASHTOKEN:
	{
          printf("yylex returned HASHTOKEN token ");
          printf("(265)\n");
	  break;
	}
	case COMMATOKEN:
        {
	  printf("yylex returned COMMATOKEN token ");	
          printf("(266)\n");
          break;
	}
        case DASHTOKEN:
        {
	  printf("yylex returned DASHTOKEN token ");
          printf("(268)\n");
          break;
	}
        case SRTOKEN:
        {
	  printf("yylex returned SRTOKEN token ");
          printf("(%s)\n", yytext);
          break;
	}
        case JRTOKEN:
        {
	  printf("yylex returned JRTOKEN token ");
          printf("(%s)\n", yytext);
          break;
	}
        case INTTOKEN:
        {
	  printf("yylex returned INTTOKEN token ");
          printf("(%s)\n", yytext);
          break;
	}
        case NAMETOKEN:
        {
	  printf("yylex returned NAMETOKEN token ");
          printf("(%s)\n", yytext);
          break;
	}
	case IDENTIFIERTOKEN:
	{ 
	 printf("yylex returned IDENTIFIERTOKEN token ");
          printf("(%s)\n", yytext);
	  break;
	}
	case NAME_INITIAL_TOKEN:
        {
	  printf("yylex returned NAME_INITIAL_TOKEN token ");
          printf("(%s)\n", yytext);
          break;
	}
	case ROMANTOKEN:
        { 
	  printf("yylex returned ROMANTOKEN token ");
          printf("(262)\n");
          break;
	}
	case EOLTOKEN:
        {
	  printf("yylex returned EOLTOKEN token ");
          printf("(267)\n");
          break;
	}
        default:
        {
	  printf("UNKNOWN\n");
	  break;
	}
        }

      //It will reinitialize the token after printing the output      

      token = yylex();
    }

  //This is what it will print out after it is finished scanning  

  printf("Done\n");
  return 0;
}

int parse()
{
  printf("Operating in parse mode\n");
  printf("\n");
  switch(yyparse())
  {
    case 0:
      printf("Parse Successful!\n");
      break;
    case 1:
      printf("Parse failed\n");
      break;
    case 2:
      printf("Out of memory\n");
      break;
    default:
      printf("Unknown failure\n");
      break;
  }
}
