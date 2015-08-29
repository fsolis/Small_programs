//Freddy Solis
//April 10, 2013
//ID:0925
//Abstract: This program creates a heap from numbers entered by the user, the heap is maintained and numbers can
//be added or deleted,only maximum value may be deleted, and heap is still maintained. 

#include <iostream>
using namespace std;

void heapMake(int a[], int size);
void printOptions();
void printHeap(int a[], int size);
void findMax(int a[]);
void insert(int a[],int size);
void deleteMax(int a[],int size);

int main ()
{
	int size = 0,heap[100], ans = 0;
	
	cout <<"Enter heap size: ";
	cin >> size;
	heap[0]=0;
	cout <<"Enter " << size << " numbers: ";
	size++;
	for(int i =1; i <size;i++)
	{
		cin >> heap[i];
	}
	
	heapMake(heap,size);
	cout<< "Heap Constructed: ";
	printHeap(heap,size);
	while(ans != 4)
	{
		printOptions();
		cin>>ans;
		if(ans ==1)
		{
			findMax(heap);
		}
		else if(ans == 2)
		{
			insert(heap,size);
		}
		else if(ans == 3)
		{
			deleteMax(heap,size);
			size--;
		}
	}
	
	cout << "Bye" << endl;
	
	return 0;
}


void heapMake(int a[], int size)
{
	bool reset = false;
	int temp = 0;
	for(int i=size/2;i>0;i--)
	{
		if((i*2 < size) && (i*2+1 < size))
		{
			if(a[i*2] >= a[i*2+1])
			{
				if(a[i*2] > a[i])
				{		
					temp = a[i];
					a[i] = a[i*2];
					a[i*2] = temp;
					reset = true;
				}
			}
			else
			{
				if(a[i*2+1] > a[i])
				{
					temp = a[i];
					a[i] = a[i*2+1];
					a[i*2+1] = temp;
					reset = true;
				}
			}
		}
		else if((i*2 < size))
		{
			if(a[i*2] > a[i])
			{		
				temp = a[i];
				a[i] = a[i*2];
				a[i*2] = temp;
				reset = true;
			}
		}
		else if((i*2+1 < size))
		{
			if(a[i*2+1] > a[i])
			{
				temp = a[i];
				a[i] = a[i*2+1];
				a[i*2+1] = temp;
				reset = true;
			}
		}
		if(reset == true)
		{
			i = size/2;
			reset = false;
		}
	}

}


void printOptions()
{
	cout << "Select Option (1: Find Max, 2: Insert, 3: Delete Max, 4: Exit): ";

}

void printHeap(int a[], int size)
{
	for(int i = 1;i<size;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void findMax(int a[])
{
	cout <<"Current Max: " << a[1] << " \n";
}
void insert(int a[],int size)
{
	int num=0;
	if(size >= 100)
	{
		cout <<"Heap Full. "<<endl;
		return;
	}
	else
	{
		cout <<"New element to be inserted: ";
		cin >> num;
		a[size]=num;
		heapMake(a,size+1);
		cout <<"Heap Updated: ";
		printHeap(a,size+1);
	}
	
}
void deleteMax(int a[],int size)
{
	a[1] = a[size];
	heapMake(a,size-1);
	cout <<"Heap Updated: ";
	printHeap(a,size);
}
