#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	//ask for a filename and open the file
	string fName;
	cout << "Please enter a filename." << endl;
	cin >> fName;

	ifstream iFile;
	iFile.open(fName);
	//verify file opened correctly
	while (!iFile.is_open()) {
		cout << "Please enter a valid filename." << endl;
		cin >> fName;
		iFile.open(fName);
	}

	int iPos = 0; // counter for number of numbers
	double firstVal=0;
	double secondVal=0;
	double sLastVal=0;
	double lastVal=0;
	double bufferVal = 0;
	
	while (iFile >> bufferVal) { //start reading values left to right until the end of the file
		if (!iFile.fail()) { // while a double is sucessfully stored (not character or whitespace)
			if (iPos == 0) {                          //first number will be stored, the second to last value will be the same if there is only one number
				firstVal = bufferVal;
				sLastVal = firstVal;
			}
			if (iPos == 1) {                          //second number will be stored, the last value will be the same as the second value if there are only two numbers
				secondVal = bufferVal;
				lastVal = secondVal;
			}
			else {                                    //for any other numbers, the second to last value will be whatever the last value was
				sLastVal = lastVal;                   //then the last value will be what the current value is
				lastVal = bufferVal;
			}
			iPos++; // increment the amount of numbers
		}
	}


	// after the loop has reached the end of the file
	cout << firstVal << endl; // output the first value
	cout << secondVal << endl; // output the second value
	cout << sLastVal << endl; // output whatever the second to last value was
	cout << lastVal << endl; // output what the last value is

	cout << "There are " << iPos << " numbers in the file." << endl; // and output the total amount of numbers in the file

    return 0;
}