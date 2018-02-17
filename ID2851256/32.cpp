// ID2851256.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

void PointWhenLetter(char* string)
{
	if (string != NULL)
	{
		bool flag = false;
		for (int i = 0; string[i] != '\0'; ++i)
		{
			if (string[i+1] && (string[i] >= 97 && string[i] <= 122) && 
							  !(string[i+1] >= 97 && string[i+1] <= 122))
				flag = true;
			if (flag)
			{
				int j;
				for (j = i + 1; string[j] != '\0'; ++j)
				{
					string[j] = '.';
				}
				i = j - 1;
			}
		}
	}
}

int main()
{
	const int length = 999;
	char string[length] = { 0 };

	gets_s(string, length - 1);

	PointWhenLetter(string);

	puts(string);

    return 0;
}

