/*
 *
 *
 * Filename:            header.h
 * Date:                04/28/2020
 * Author:              Medha Aiyah
 * Email:               mva170001@utdallas.edu
 * Version:             1.0
 * Copyright:           2019, All Rights Reserved
 *
 * Description:
 *
 *      This file contains all of the needed include statments and the two classes. It also includes the
 *	prototypes for this project.
 */


#ifndef __HEADER_H__
#define __HEADER_H__

#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include<bits/stdc++.h>
#include <stdint.h>
#include <iomanip>
using namespace std;

class BinaryFileHeader
{
        public:
                uint32_t magicNumber;
                uint32_t versionNumber;
                uint64_t numRecords;
};

const int maxRecordStringLength = 25;

class BinaryFileRecord
{
        public:
                uint8_t strLength;
                char stringBuffer[maxRecordStringLength];
};


void CDKError();
void ClosingBinaryFileError();
void BinaryFileOpeningError();

#endif /*header.h*/
