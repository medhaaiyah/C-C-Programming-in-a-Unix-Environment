/*
 *
 *
 * Filename:            BinaryFileErrors.cc
 * Date:                04/28/2020
 * Author:              Medha Aiyah
 * Email:               mva170001@utdallas.edu
 * Version:             1.0
 * Copyright:           2019, All Rights Reserved
 *
 * Description:
 *
 *      This file contains all of the appropriate error messages for this project
 */

#include "header.h"

//This is the function to print out the error message for opening a file

void BinaryFileOpeningError()
{
        cout << "There is an error with opening binary file" << endl;
        exit(1);
}

//This is the function to print out the error message for closing a file

void ClosingBinaryFileError()
{
        cout << "There is an error with closing binary file" << endl;
        exit(1);
}

//This is the function to print out the error message if there is an error with the CDK matrix

void CDKError()
{

        cout << "There is an error with creating CDK matrix" << endl;
        exit(1);
}
