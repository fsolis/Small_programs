#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	first=last=NULL;
}
void LinkedList::insert(ElementType data)
{
	Node *newNode;
	newNode = new Node();
	newNode->data.copyClient(data);

	if(first==NULL) //inserts at the front
	{
		cout<<"Inserting " << newNode->data.getfirst() << " " << newNode->data.getLast() << endl;
		newNode->next=NULL;
		first = newNode;
		last = newNode;
		return;
	}
	else
	{
		Node *current,*previous;
		current=previous=first;
		while(current !=NULL)
		{
			if(current->data.getLast().compare(data.getLast()) >= 0)//data is lower value then current
			{
				if(current==first)//inserts at first, handles first pointer
				{
					cout<<"Inserting " << newNode->data.getfirst() << " " << newNode->data.getLast() << endl;
					newNode->next=current;
					first=newNode;
					return;
				}
				cout<<"Inserting " << newNode->data.getfirst() << " " << newNode->data.getLast() << endl;
				newNode->next=current; 
				previous->next=newNode;
				return;
			}
			if(current->next==NULL) //inserts at end;
			{
				cout<<"Inserting " << newNode->data.getfirst() << " " << newNode->data.getLast() << endl;
				current->next=newNode;
				newNode->next=NULL;
				last = newNode;
				return;
			}
			previous = current;   //moves to next node to enter check
			current = current->next;
		}
	}


}
void LinkedList::remove(ElementType data)
{
	Node *current, *previous;
	current=previous=first;
	if(first==NULL)
	{
		cout<<"List is Empty" << endl;
		return;
	}
	while(current!=NULL)
	{
		if(current->data.getfirst().compare(data.getfirst()) == 0 && current->data.getLast().compare(data.getLast()) == 0) //data found
		{
			if(first==current)//removes from front
			{
				first=current->next;
				delete current;
				cout<< data.getfirst() << " Deleted. " << endl;
				return;
			}
			else if(current==last)//removes from back
			{
				previous->next = current->next;
				last = previous;
				delete current;
				cout<< data.getfirst() << " Deleted. " << endl;
				return;
			}
			else//removes from middle of list
			{
			previous->next = current->next;
			delete current;
			cout<< data.getfirst() << " Deleted. " << endl;
			return;
			}
		}

		previous = current;   //moves to the next
		current = current->next;
	}

	if(current == NULL) //if item not found
	{
		cout <<data.getfirst() << " is not in the list." << endl;
	}
}
void LinkedList::print()
{
	
	Node *current;
	current=first;
	if(first==NULL)
	{
		cout << "List is empty." << endl;
	}
	else
	{
		cout<<"Printing List: " << endl;
		while(current!=NULL)
		{
			cout << current->data.getfirst() << " " << current->data.getLast() << endl;
			current = current->next;
		}
	}
}
int LinkedList::getSize()
{
    int size = 0;
    if(first==NULL)
    {
        return size;
    }
    Node *current;
    current = first;
    while(current != NULL)
    {
        size++;
        current = current->next;
    }
    return size;
}
