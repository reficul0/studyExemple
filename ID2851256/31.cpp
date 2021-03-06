// ID2851256.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

bool CheckStringOnWorldsAndSpase(const char* string, bool& error)
{
	if (string != NULL)
	{
		for (int i = 0; string[i] != '\0'; ++i)
			if (!(string[i] >= 97 && string[i] <= 122 || string[i] == ' '))
				return true;
		return false;
	}
	error = true;
}

int main()
{
	const int length = 999;
	char string[length] = { 0 };

	gets_s(string, length - 1);

	bool error = false;

	bool result = CheckStringOnWorldsAndSpase(string, error);

	if (error != true)
	{
		if (result == true)
			cout << "The sentence contains characters other than letters and spaces" << endl;
		else
			cout << "The sentence contains only letters and / or spaces" << endl;
	}
	else
		cout << "Wrong input data" << endl;

    return 0;
}

