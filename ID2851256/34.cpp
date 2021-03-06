// ID2851256.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <time.h>

using namespace std;


int main()
{
	srand(time(NULL));

	const int strLength = 999, board = rand() % 20 + 50;
	char str[strLength] = { 0 };

	for (int j = 0; j < board; ++j)
	{
		str[j] = rand() % 2 + 97;
	}

	cout << "Source string :" << endl;
	puts(str);

	int count, stringLen, newStrLength;
	for (stringLen = 0; str[stringLen] != '\0'; ++stringLen);

	for (int i = 0, j; i < stringLen; ++i)
	{
		count = 0;
		for (j = i + 1; str[j] != '\0' && str[j] == str[j - 1]; ++j);
		--j;

		/* Количесво букв равно разности иднекса конца слова
		и начала слова (+1 т.к. нумерация идет с 0)
		*/
		count += j - i + 1;

		switch (count)
		{
			case 1: break;
			case 2:
				str[i + 1] = '2';
				break;
			case 3:
				str[i + 1] = '3';
				break;
			case 4:
				str[i + 1] = '4';
				break;
			case 5:
				str[i + 1] = '5';
				break;
			case 6:
				str[i + 1] = '6';
				break;
			case 7:
				str[i + 1] = '7';
				break;
			case 8:
				str[i + 1] = '8';
				break;
			case 9:
				str[i + 1] = '9';
				break;
			default:
				exit(1);
		}

		if (count > 2) 
		{
			int k, p;
			for (k = j + 1; str[k] != '\0'; ++k)
			{
				str[k - count + 2] = str[k];
			}
			str[k - count + 2] = '\0';
			newStrLength = k - count + 2;
		}
	}

	// Тут мы имеем сжатую строку, но после первого символа конца строки в ней находится мусор
	// поэтому далее мы создадим новую строку с меньшей длинной, чтобы избавиться от мусора
	cout << endl << "Source string with trash :" << endl;
	for (int j = 0; j < board; ++j)
	{
		cout << str[j];
	}
	cout << endl;

	char* collapsedStr = NULL;
	if (collapsedStr = new char[newStrLength])
	{
		for (int i = 0; str[i] != '\0'; ++i)
		{
			collapsedStr[i] = str[i];
		}
		collapsedStr[newStrLength] = '\0';
	}
	else
		cout << "Memoty leack";
	
	// Чистим поток ввода от энтеров(да, он иногда забивается, и у меня забивается именно на этой строке)
	cin.clear();

	cout << endl << "Collapsed string : " << endl;
	puts(collapsedStr);
	
    return 0;
}

