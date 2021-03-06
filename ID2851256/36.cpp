// ID2851256.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

//472 в
int FindMinAbsNumberInFile(ifstream &fin)
{
	if (fin)
	{
		if (!(fin.is_open()))
			throw false;

		int minVal = INT_MAX, inputNumber = 0, i = 1;
		for (int absInputNumber; !(fin.eof()); ++i)
		{
			fin >> inputNumber;
			absInputNumber = abs(inputNumber);
			if (i % 2 && absInputNumber < abs(minVal))
				minVal = inputNumber;
		}

		fin.clear();
		fin.seekg(0);

		return minVal;
	}
	else
		throw false;
}

//472 г
int FindSumm_of_Min_and_MaxNumbers_in_File(ifstream &fin)
{
	if (!(fin.is_open()))
		throw false;

	int minVal = INT_MAX, maxVal = INT_MIN, inputNumber = 0;
	while(!(fin.eof()))
	{
		fin >> inputNumber;
		if (inputNumber < minVal)
			minVal = inputNumber;
		if (inputNumber > maxVal)
			maxVal = inputNumber;
	}

	fin.clear();
	fin.seekg(0);

	return maxVal + minVal;			
}

//472 д
int FindSubtraction_of_First_and_LastNumbers_in_File(ifstream &fin)
{
	if (!(fin.is_open()))
		throw false;

	int firstNumb = 0, lastNumb = 0, inputNumber = 0;
	
	fin >> firstNumb;
	lastNumb = firstNumb;

	while (!(fin.eof()))
		fin >> lastNumb;

	fin.clear();
	fin.seekg(0);

	return firstNumb - lastNumb;
}

int main()
{
	try
	{
		ifstream fin("InputData.txt");

		int minAbsNumb = FindMinAbsNumberInFile(fin);
		cout << "Least abs value in the file is " << minAbsNumb << endl;

		int minPlusMaxVal = FindSumm_of_Min_and_MaxNumbers_in_File(fin);
		cout << "Summ of min and max values in the file is " << minPlusMaxVal << endl;

		int firstSubtructionLastVal = FindSubtraction_of_First_and_LastNumbers_in_File(fin);
		cout << "Subtraction of first and last values in the file is " << firstSubtructionLastVal << endl;
	}
	catch (...)
	{
		puts("Error");
	}




	return 0;
}
