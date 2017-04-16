#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Coeff table
static double const coeff[10] = { 1, 1.2, .8, .75, .9, .7, .5, 1.8, 0, 0 };

void game()
{
	char play;
	int bet(0), position(0), roll(0);

	cout << "How much to bet?" << endl;
	cin >> bet;

	while (position < 7)
	{
		roll = (rand() % 3 + 1);
		position += roll;
		if (position >= 7)
		{
			cout << "You landed on " << position << ". ";
			break;
		}
		cout << "You rolled " << roll << ". You're now in position " << position << " . Your payout will be " << bet*coeff[position] << ". Continue? y/n" << endl;
		cin >> play;
		if (play == 'n')
			break;
	}
	cout << "You won " << bet*coeff[position] << "." << endl;
}

int main()
{
	cout << "Welcome to Lucky7 game. How many games do you want to play ?" << endl;
	int n;
	cin >> n;
	
	//Game
	srand(time(NULL));
	for (int i(0); i < n; i++)
		game();
	
	return 0;
}