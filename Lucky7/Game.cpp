#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double const Game::coeff[10] = { 1, 1.2, .8, .75, .9, .7, .5, 1.8, 0, 0 };

Game::Game()
{
	srand(time(NULL));

	//Init results table
	for(int i(0); i<10; i++)
		m_results[i] = 0;

	//Calc EV Table
	for(int k(9); k!=0; k--)
	{
		if (k >= 7)
			m_EV[k] = coeff[k];
		else
			m_EV[k] = (m_EV[k + 1] + m_EV[k + 2] + m_EV[k + 3]) / 3;
	}
}

void Game::play()
{
	int position(0);
	while (position < 7)
	{
		position += (rand() % 3 + 1);
		//Check for best move
		if (coeff[position] > m_EV[position])
			break;
	}
	m_results[position - 1]++;
}

void Game::getStats() const
{
	double average(0);
	int total(0);
	cout << endl << "Coeff:	|Hits:" << endl;
	for (int a(0); a < 9; a++)
	{
		cout << coeff[a + 1] << "	|" << m_results[a] << endl;
		average += coeff[a + 1] * m_results[a];
		total += m_results[a];
	}
	cout << endl << "Payout: " << average / total * 100 << "%" << endl;
}