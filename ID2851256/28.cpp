// ID2851256.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <time.h>

using namespace std;



struct Date
{
	unsigned int year;
	unsigned int month;
	unsigned int day;
};

struct Student
{
	Date date;
	char name[999] = { 0 };
};

void PrintDate(const Date date)
{
	cout << date.day << "." << date.month << "." << date.year << endl;
}

void PrintStudent(const Student student)
{
	cout << student.name << "\t";
	PrintDate(student.date);
}

bool NamesCompare(const char* firstName, const char* secondName)
{

	// Если ввести для поиска одну букву, то выдаст всех студентов с такой же 
	// начальной буквой, и то же самое для 2-хБ 3-х букв и т.п.
	for (int j = 0; secondName[j] != '\0'; ++j)
	{
		if (firstName[j] != secondName[j])
		{
			return false;
		}
	}
	return true;
}

/*
Суть алгорима поиска по имени заключается в прохождении каждого элемента массива
и сравнении имени элемента с пришедшим именем, по которому мы проводим поиск.
*/
void NameFilter(const Student* students, const int countOfStudents, const char* nameForSearch)
{
	bool flagOfFoundStudent, flagAtLeastOnce = false;

	for (int i = 0; i < countOfStudents; ++i)
	{
		flagOfFoundStudent = NamesCompare(students[i].name, nameForSearch);

		if (flagOfFoundStudent == true)
		{
			cout << "Found by the name a student : ";
			PrintStudent(students[i]);
			
			if (flagAtLeastOnce == false)
			{
				flagAtLeastOnce = true;
			}
		}
	}

	if (flagAtLeastOnce == false)
	{
		cout << "Students by this name are not found" << endl;
	}
}
/*
Суть алгорима поиска по дате заключается в простом сравнении дат, каждого элемента массива
с датой по которой проводится поиск
*/
bool DatesCompare(const Date firstDate, const Date secondDate)
{
	if (firstDate.year == secondDate.year &&
		firstDate.month == secondDate.month &&
		firstDate.day == secondDate.day)
		return true;
	else
		return false;
}

void DateFilter(const Student* students, const int countOfStudents, const Date dateForSearch)
{
	bool flagOfFoundStudent, flagAtLeastOnce = false;

	for (int i = 0; i < countOfStudents; ++i)
	{
		flagOfFoundStudent = DatesCompare(students[i].date, dateForSearch);

		if (flagOfFoundStudent == true)
		{
			cout << "Found by the name a student : ";
			PrintStudent(students[i]);
			if (flagAtLeastOnce == false)
			{
				flagAtLeastOnce = true;
			}
		}
	}

	if (flagAtLeastOnce == false)
	{
		cout << "Students by this date are not found" << endl;
	}
}

/*
Суть алгоритма поиска по дате и по имени заключается в том, что сначала мы проверяем дату конкретного элемента массива,
после, если эта дата совпала с той, что мы используем для поиска, мы начинаем сравнивать совпавший элемент по имени с тем и иенем,
по которому проводится поиск
*/
void DateAndNameFilter(const Student* students, const int countOfStudents, const Date dateForSearch, const char* nameForSearch)
{
	bool flagOfFoundStudentOfName, flagOfFoundStudentOfDate, flagAtLeastOnce = false;

	for (int i = 0; i < countOfStudents; ++i)
	{
		flagOfFoundStudentOfDate = DatesCompare(students[i].date, dateForSearch);

		if (flagOfFoundStudentOfDate == true)
		{
			flagOfFoundStudentOfName = NamesCompare(students[i].name, nameForSearch);

			if (flagOfFoundStudentOfName == true)
			{
				cout << "Found by name and date the student : ";
				PrintStudent(students[i]);

				if (flagAtLeastOnce == false)
				{
					flagAtLeastOnce = true;
				}
			}
		}
	}

	if (flagAtLeastOnce == false)
	{
		cout << "Students by this date are not found" << endl;
	}
}


int main()
{
	const int countOfStudents = 10;
	Student students[countOfStudents];

	srand(time(NULL));

	// Рандомим поля структуры(лень запонять вручную)
	for (int i = 0; i < countOfStudents; ++i)
	{
		students[i].date.day = rand() % 32;
		students[i].date.month = rand() % 13;
		students[i].date.year = rand() % 118 + 1901;
		for (int j = 0, board = rand() % 5 + 3; j < board; ++j)
		{
			students[i].name[j] = rand() % 26 + 97;
		}
	}
	// Просто печаем студентов в консоль
	for (int i = 0; i < countOfStudents; ++i)
	{
		PrintStudent(students[i]);
	}

	const int nameLength = 999;
	char nameForSearch[nameLength] = { 0 };

	cout << endl << "Enter a name for search : ";
	gets_s(nameForSearch, nameLength - 1);

	NameFilter(students, countOfStudents, nameForSearch);

	Date dateForSearch;
	cout << endl << "Enter date for the search" << endl ;

	cout << "Enter day : "; cin >> dateForSearch.day;
	cout << "Enter month : "; cin >> dateForSearch.month;
	cout << "Enter year : ";  cin >> dateForSearch.year;
	
	DateFilter(students, countOfStudents, dateForSearch);

	// Обнуляем нашу строку
	for (int i = 0; nameForSearch[i] != '\0'; ++i)
		nameForSearch[i] = '\0';

	// Чистим поток ввода от энтеров(да, он иногда забивается, и у меня забивается именно на этой строке)
	cin.clear();
	while (cin.get() != '\n');

	cout << endl << "Enter a name for search : ";
	gets_s(nameForSearch, nameLength - 1);

	cout << "Enter date for the search" << endl;

	cout << "Enter day : "; cin >> dateForSearch.day;
	cout << "Enter month : "; cin >> dateForSearch.month;
	cout << "Enter year : ";  cin >> dateForSearch.year;

	DateAndNameFilter(students, countOfStudents, dateForSearch, nameForSearch);
	
    return 0;
}

