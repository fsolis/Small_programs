/* 
* Freddy Solis
* Feb 2014
* Sieve of Eratosthenes
* Finds prime numbers from 0 to N, N being user input number
*/


#include <iostream>
#include <math.h>
using namespace std;

void sieve(int n);

int main()
{
	int n=0;
        cout << "Welcome to Sieve of Eratosthenes" << endl;
	cout << "Enter a positive integer: ";
	cin >> n;
	sieve(n);
}

void sieve(int n)
{
	int * l;
	int j=0,i=0;
	l = new int[n+1];
	for(i=0;i<=n;i++)
	{
		l[i]=i;
	}
	l[0]=0;
	l[1]=0;
	for(i=0;i<n;i++)
	{
		if (l[i] != 0)
		{	
			j=i*i;
			while(j <= n)
			{
				l[j]=0;
				j= j+i;
			}	
		}
	}
	cout << "Prime Numbers up to " << n << " are:";
	for(i=0;i<n;i++)
	{
		if(l[i] != 0)
		{
			cout << " " << l[i];
		}
	}
	cout << endl;
	
}

