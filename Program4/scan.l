/*
 * Filename:            scan.l
 * Date:                03/28/2020
 * Author:              Medha Aiyah
 * Email:               mva170001@utdallas.edu
 * Version:             1.0
 * Copyright:           2020, All Rights Reserved
 *
 * Description:
 * 	This file is used to scan the infilename.txt and associate certain parts of file
 *	to a specific token.
 *
*/

/*These are the warnings that will be omitted when scanning*/

%option noyywrap
%option nounput
%option noinput

/*This is the header file that was created through the parse.y function.*/

%{
  #include "y.tab.h"
%}

/*These are the defitions. For every token we call, there is a particular regex that is defined with it*/
/*The particular regex for the token is shown in this segment of the file*/

%%


[ \t\r]+                        { /* eat up whitespace */ }
[A-Z](\.)?                      { return NAME_INITIAL_TOKEN; }
I{1,4}(V)?                      { return ROMANTOKEN; }
[A-Za-z][a-zA-Z]+               { return NAMETOKEN; }
"Jr."                           { return JRTOKEN; }
"Sr."                           { return SRTOKEN; }
[\n]                            { return EOLTOKEN; }
[0-9]+                          { yylval = atoi(yytext); return INTTOKEN; }
"#"                             { return HASHTOKEN; }
[\,]                            { return COMMATOKEN; }
"-"                             { return DASHTOKEN; }
[A-Za-z0-9]+			{ return IDENTIFIERTOKEN; }

%%

/*
 * This section is empty on purpose. I included the main() in the routine in myproject.c
 *
*/

