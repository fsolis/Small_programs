//Name:Freddy Solis
//ID:0925
//Date: 03/26/13
//Abstract: This program will ask the user for a number and it will output the
//number of permutation from 1 to that number. 


#include <iostream>
using namespace std;
void heapPermute(int size);

int *heap;
int originSize;
int main()
{
	int size=0,init=1;
	cout << "Enter a number: ";
	cin >> size;
	originSize = size;
	heap = new int[size];
	for(int i=0;i<size;i++,init++)
	{
		heap[i] = init;
	}
	heapPermute(size);

	return 0;

}


void heapPermute(int size)
{
	int temp = 1;
	if(size==1)
	{
		for(int i=0;i<originSize;i++)
		{
			cout << heap[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for(int i=0;i<size;i++)
		{
			heapPermute(size-1);
			if((size%2)==1)
			{
				temp = heap[1];
				heap[1] = heap[size-1];
				heap[size-1] = temp;
			}
			else
			{
				temp = heap[i];
				heap[i] = heap[size-1];
				heap[size-1] = temp;
			}
		}
		
	}

}
