// Title: Anagram
// Abstract: The user will input two strings and the program will determine if the strings are anagrams or not, which means that they have the same letters. 
// Date: 2/2/12
// Name: Freddy Solis
// ID: 0925
#include <iostream>
#include <string>
using namespace std;

int check( char letter);

int main ()

{

	string first, second; 

	int  a[26], b[26], temp, length1=0, length2=0;

	bool anagram = true;

	const char * firsts, *seconds;
 

	cout << "Enter Two Words: ";
	cin >> first >> second;

	length1 = first.length(); //gets length of first word
	length2 = second.length(); // gets length of second word

	if (length1 != length2) // if different lengths then not anagrams
	{
		cout << "Result: No " << endl;
		system("pause");
		return 0;
	}

	firsts = first.c_str();  // turns both strings into c strings for better checking
	seconds = second.c_str();

	for( int i= 0; i < 26; i++) // turn all numbers in comparison array to 0 by default
	{
		a[i] = 0;
		b[i] = 0;
	}

	for(int i = 0; i < length1; i++) // sorts first string
	{
		temp = check(firsts[i]);
		if(temp < 27)
		{
			a[temp] = a[temp] + 1;
		}
	}

	for(int i = 0; i < length2; i++) // sorts second string
	{
		temp = check(seconds[i]);

		if(temp < 27)
		{
			b[temp] = b[temp] + 1;
		}
		
	}

	for(int i = 0; i < 26; i++) // compares strings and if any letters are different then it returns false
	{

		if(a[i] != b[i])
		{
			anagram = false;
		}
		
	}

	if( anagram == true) //outputs results
	{
		cout << "Result: Yes" << endl;
	}
	else
	{
		cout << "Result: No" << endl;
	}

	system("pause");
	return 0;
}
 

 

int check( char letter) // this checks to see where the letter corrisponds with letter array. 
{
	switch(letter)
	{
		case 'a': return 0;
		case 'b': return 1;
		case 'c': return 3;
		case 'd': return 4;
		case 'e': return 5;
		case 'f': return 6;
		case 'g': return 7;
		case 'h': return 8;
		case 'i': return 9;
		case 'j': return 10;
		case 'k': return 11;
		case 'l': return 12;
		case 'm': return 13;
		case 'n': return 14;
		case 'o': return 15;
		case 'p': return 16;
		case 'q': return 17;
		case 'r': return 18;
		case 's': return 19;
		case 't': return 20;
		case 'u': return 21;
		case 'v': return 22;
		case 'w': return 23;
		case 'x': return 24;
		case 'y': return 25;
		case 'z': return 26;

	}
	return 27; // if not a letter in the alphabet then it does not count
}