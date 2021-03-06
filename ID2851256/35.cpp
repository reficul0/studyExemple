// ID2851256.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

struct Node
{
	int key = 0;
	Node* next = NULL;
};

struct List
{
	Node* head = NULL;
	Node* tail = NULL;
	int count = 0;

	void Push(Node* node)
	{
		if (node)
		{
			if (head)
			{
				Node* current = head;
				while (current->next)
				{
					current = current->next;
				}
				current->next = node;
			}
			else
			{
				head = node;
			}
			tail = node;

			node->key = ++count;
		}
		else
			cout << "Wrong input data" << endl;
	}
	
	void Pop(int number)
	{
		if (number > 0 && number <= count)
		{
			if (head)
			{
				Node* node = head;
				for (int i = 1; i < number; node = node->next)
					++i;
				
				if(node == head)
					if (node == tail)
					{
						head = NULL;
						tail = NULL;
					}
					else
						head = node->next;
				else
				{
					Node* var = head;
					while (var->next != node)
						var = var->next;

					if (node == tail)
					{
						var->next = NULL;
						tail = var;
					}
					else
						var->next = node->next;
				}
				--count;
				delete node;
			}
			else
				cout << "List is empty" << endl;
		}
		else
			cout << "Wrong input data" << endl;
	}

	void Print()
	{
		if (head)
		{
			cout << "Current least :" << endl;
			for (Node* current = head; current; current = current->next)
			{
				cout << current->key << ' ';
			}
			cout << endl;
		}
		else
			cout << "List is empty" << endl;
	}

	int CheckOnLast()
	{
		if (head)
		{
			if (head == tail)
				return 1;
			return 0;
		}
		else
			return -1;
	}
};



int main()
{
	srand(time(NULL));

	List* list;
	if (!(list = new List))
		exit(1);

	int board = rand() % 10 + 3;
	for (int i = 0/*, board = rand() % 20*/; i < board; ++i)
	{
		Node* node;
		if (node = new Node)
			list->Push(node);
		else
			cout << "Memory leack" << endl;
	}
	cout << "Count of the elements if the least : " << board << endl;
	list->Print();

	while (true)
	{
		int var;
		cout << "Enter the number the human which must leave the circul :" << endl;
		cin >> var;
		list->Pop(var);
		list->Print();

		if (list->CheckOnLast() == 1)
		{
			cout << "Number of the last human is a " << list->head->key << endl;
			break;
		}
		
	}
	return 0;
}
