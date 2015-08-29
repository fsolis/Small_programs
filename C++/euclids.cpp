/* 
* Freddy Solis
* Feb, 2014
* Elucids Algorithm
* Finds greatest common divisor
* gcd(m,n) = gcd(n,m mod n)
*/

#include <iostream>
using namespace std;

int euclid(int num1, int num2);

int main()
{	
	int num1=0, num2=0;
	cout << "Welcome to Euclid's Algorithm. " << endl;
	cout << "Enter Two Non-Negative Number" << endl;
	cout << "1st Number: ";
	cin >> num1;
	cout << "2nd Number: ";
	cin >> num2;
	cout << "Greatest Common Divisor between " << num1 << " and " << num2 <<" is : " << euclid(num1,num2)<<endl;
	
}

int euclid(int m, int n)
{
	int r=0; //remainder
	while(n != 0)
	{
		r = m % n;
		m = n;
		n = r;
	}

	return m;
}
