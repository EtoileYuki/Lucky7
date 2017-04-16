#include "Game.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "How many times ?" << endl;
	cin >> n;

	Game Lucky7;
	for (int i(0); i < n; i++)
		Lucky7.play();
	Lucky7.getStats();

	return 0;
}