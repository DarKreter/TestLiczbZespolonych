#ifndef STATYSTYKA_H
#define STATYSTYKA_H
#include <iostream>

class Statystyka_t
{
	uint8_t correctAnswers;
	uint8_t wrongAnswers;
	uint8_t questionsAmount;

public:
	float Calculate();
	Statystyka_t(uint8_t q) : correctAnswers{ 0 }, wrongAnswers{ 0 }, questionsAmount{ q } {;}
	uint8_t operator++(int);
	uint8_t operator--(int);
	friend std::ostream& operator<<(std::ostream& strumien, Statystyka_t s);
};

std::ostream& operator<<(std::ostream& strumien, Statystyka_t s);

#endif
