#pragma once
class Game
{
public:
	Game();
	void play();
	void getStats() const;

private:
	int m_results[9];
	static double const coeff[10];
	double m_EV[10];
};