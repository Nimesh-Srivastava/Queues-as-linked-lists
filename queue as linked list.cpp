#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<process.h>

using namespace std;

struct node
{
	int info;
	node*next;
}*ptr,*newptr,*save,*front,*rear;

node*create_new_node(int);
void insert(node*);
void remove_node();
void display(node*);

int main()
{
	front = rear = NULL;
	int inf;
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		system("cls");
		cout << "\n\tEnter information for new node : ";
		cin >> inf;
		newptr = create_new_node(inf);
		if (newptr == NULL)
		{
			cout << "\n\n\tCannot create new node!! Aborting!!";
			_getch();
			exit(1);
		}
		insert(newptr);
		cout << "\n\n\tNow the linked queue (front-to-rear) is :\n";
		display(front);
		cout << "\n\n\tPress Y to enter more nodes, N to begin deletion : ";
		cin >> ch;
	}
	system("cls");
	cout << "\n\n\tNow starting the deletion\n\n\n\n";
	system("pause");
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		system("cls");
		remove_node();
		cout << "\n\n\tThe linked queue now (front-to-rear) is :\n";
		display(front);
		cout << "\n\n\tWant to delete more(y/n) : ";
		cin >> ch;
	}
	return 0;
}

node*create_new_node(int n)
{
	ptr = new node;
	ptr->info = n;
	ptr->next = NULL;
	return ptr;
}

void insert(node*np)
{
	if (front == NULL)
	{
		front = rear = np;
	}
	else
	{
		rear->next = np;
		rear = np;
	}
}

void display(node*np)
{
	cout << "\n\t";
	while (np != NULL)
	{
		cout << np->info << " <- ";
		np = np->next;
	}
	cout << "!!!";
}

void remove_node()
{
	if (front == NULL)
	{
		cout << "\n\n\tUnderflow";
	}
	else
	{
		ptr = front;
		front = front->next;
		delete ptr;
	}
}