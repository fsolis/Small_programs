#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int turn();
int roll();
int main()
{
    int player1=0, player2=0;
    int iturn =1, temp = 0;
    while (player1 < 100 && player2 < 100)
    {
	temp = 0;
	if(iturn % 2 == 1)
	{
    	    cout << "Player 1, Its your turn!"<< endl;
	    temp += turn();
	    if(temp == -1)
	    {
		player1 = 0;
	    }
	    else
	    {
	        player1 += temp;
	    }
	    cout << "Player 1, your score is " << player1 << " so far" << endl;
	    cout << endl;
	}
	else
	{
	    cout << "Player 2, Its your turn!" << endl;
	    temp += turn();
            if(temp == -1)
            {
                player2 = 0;
            }
            else
            {
                player2 += temp;
            }

	    cout << "Player 2, your score is " << player2 << " so far" << endl;
	    cout << endl;
	}
	iturn ++;
    }
    if(iturn % 2 == 0)
    {
	cout << "Player 2, Its your turn!"<< endl;
	temp += turn();
            if(temp == -1)
            {
                player2 = 0;
            }
            else
            {
                player2 += temp;
            }

            cout << "Player 2, your score is " << player2 << " so far" << endl;
            cout << endl;
    }
    if(player1 > player2)
    {
	cout << "Player 1 You Win!" << endl;
    }
    else if(player2 > player1)
    {
	cout << "Player 2 You Win!" << endl;
    }
    return 0;
}

int roll()
{
	int dice1, dice2;
	dice1 = (rand() % 6) + 1;
	dice2 = (rand() % 6) + 1;
	
	if(dice1 == 1 && dice2 ==1)
	{
		cout << "You Rolled Two 1's, Your Score is Now 0"<< endl;
		return -2;
	}
	else if(dice1 == 1 || dice2 ==1)
	{
		cout << "You rolled " << dice1 << " and " << dice2 << endl;
		cout << "Your Rolled A 1, You get 0 Points for this turn."<< endl;
		return -1;
	}
	else
	{

		cout << "You rolled " << dice1 << " and " << dice2<<endl;
		return (dice1 + dice2);
	}
}


int turn()
{	
	int temp=0,sum = 0;
	char check = 'y';
	
	while(check == 'y')
	{
		temp = roll();
		if(temp == -1)
		{
			return 0;
		}	
		else if(temp == -2)
		{
			return -1;
		}
		else
		{
			sum +=temp;
			cout << "Would you like to roll again? (y/n) ";
			cin >> check;
		}
	}
	return sum;
}
