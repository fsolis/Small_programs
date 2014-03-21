#include <iostream>
#include "Client.h"
using namespace std;

typedef Client ElementType;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
private:
	struct Node
	{
	public: 
		ElementType data;
		Node *next;
		Node(){next=NULL;}
	};
public:
	Node *first;
	Node *last;
	LinkedList();
	void insert(ElementType data);
	void remove(ElementType data);
	void print();
    int getSize();
};

#endif