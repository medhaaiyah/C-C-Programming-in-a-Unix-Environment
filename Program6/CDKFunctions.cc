/*
 *
 * Filename:            CDKFunctions.cc
 * Date:                04/28/2020
 * Author:              Medha Aiyah
 * Email:               mva170001@utdallas.edu
 * Version:             1.0
 * Copyright:           2019, All Rights Reserved
 *
 * Description:
 *
 *      This file will read the appropriate binary file and create a visual using the CDK library
 */

#include "cdk.h"
#include "header.h"


#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

int main()
{
	//This is the two variables to refer to the classes

	BinaryFileRecord *fourWords= new BinaryFileRecord[4];
	BinaryFileHeader *fileHeader = new BinaryFileHeader();

	WINDOW *window;	
	CDKSCREEN *cdkscreen;
	CDKMATRIX *myMatrix;

	const char *rowTitles[MATRIX_HEIGHT+1] = {"R0", "a", "b", "c"};
	const char *columnTitles[MATRIX_WIDTH+1] = {"C0" , "a"  , "b", "c", "d", "e"};

	int boxWidths[MATRIX_WIDTH +1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
	int boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

	ifstream binaryFile("/scratch/perkins/cs3377.bin", ios::in | ios::binary);

	if(!binaryFile)
	{
        	BinaryFileOpeningError();
	}


	binaryFile.read(reinterpret_cast<char*> (fileHeader), sizeof(BinaryFileHeader));

	stringstream s_1;
	s_1<<std::hex<<fileHeader->magicNumber;	
	string result(s_1.str());
	transform(result.begin(), result.end(), result.begin(), ::toupper);
	result="Magic: 0x"+result;

	int intVersion = fileHeader->versionNumber;
	stringstream s_2;
	s_2<<intVersion;
	string resultVersion(s_2.str());

	resultVersion="Version: "+resultVersion;

	s_2.str("");
	s_2<<fileHeader->numRecords;
	string resultRecords(s_2.str());
	resultRecords="NumRecords: "+resultRecords;

	binaryFile.read(reinterpret_cast<char*>(fourWords), sizeof(BinaryFileRecord)*4);
	binaryFile.close();

	if(binaryFile.is_open())
	{
       		ClosingBinaryFileError();
	}

	window= initscr();
	cdkscreen = initCDKScreen(window);

	initCDKColor();


	myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_NAME_STRING, (char **)columnTitles, (char**) rowTitles, boxWidths, boxTypes, 1, 1, ' ', ROW, true, true, false);

	if(myMatrix == NULL)
	{
        	CDKError();
	}

	drawCDKMatrix(myMatrix, true);

	stringstream ss;
	string length1;
	int convert = int( fourWords[0].strLength);
	ss<<convert;
	ss>>length1;
	string length = "strlen: " +length1;
	setCDKMatrixCell(myMatrix, 2,1,length.c_str());

	ss.clear();
	length1="";
	ss.str("");
	convert =int(fourWords[1].strLength);
	ss<<convert;
	ss>>length1;
	length = "strlen: " +length1;
	setCDKMatrixCell(myMatrix, 3,1,length.c_str());

	ss.clear();
	length1="";
	ss.str("");
	convert=int(fourWords[2].strLength);
	ss<<convert;
	ss>>length1;
	length = "strlen: " +length1;
	setCDKMatrixCell(myMatrix, 4,1,length.c_str());

	ss.clear();
	ss.str("");
	length1="";
	convert = int(fourWords[3].strLength);
	ss<<convert;
	ss>>length1;
	length = "strlen: " +length1;
	setCDKMatrixCell(myMatrix, 5,1,length.c_str());


	setCDKMatrixCell(myMatrix, 2,2,fourWords[0].stringBuffer);
	setCDKMatrixCell(myMatrix, 3,2,fourWords[1].stringBuffer);
	setCDKMatrixCell(myMatrix, 4,2,fourWords[2].stringBuffer);
	setCDKMatrixCell(myMatrix, 5,2,fourWords[3].stringBuffer);

	setCDKMatrixCell(myMatrix, 1,1,(result.c_str()));
	setCDKMatrixCell(myMatrix, 1,2,resultVersion.c_str());
	setCDKMatrixCell(myMatrix, 1,3,resultRecords.c_str());

	drawCDKMatrix(myMatrix, true);

	sleep(10);

	endCDK();

	return 0;
}

