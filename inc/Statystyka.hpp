#ifndef STATYSTYKA_H
#define STATYSTYKA_H
#include <iostream>

//Klasa odpowiedzialna za obliczenia statystyczne
class Statystyka_t
{
	uint8_t correctAnswers;
	uint8_t wrongAnswers;
	uint8_t questionsAmount;

public:
	/*
		@brief Funkcja pozwalaj¹ca obliczyc procent poprawnych odpowiedzi

		@return Procent poprawnych odpowiedzi
	*/
	float Calculate();

	/*
		@brief glowny kontruktor
	*/
	Statystyka_t() : correctAnswers{ 0 }, wrongAnswers{ 0 }, questionsAmount{ 0 } {;}

	/*
		@brief Funkcja zwiekszajaca ilosc poprawnych odpowiedzi o jeden

		@return zawsze 0 (nie uzywane)
	*/
	uint8_t operator++(int);

	/*
		@brief Funkcja zwiekszajaca ilosc blednych odpowiedzi o jeden

		@return zawsze 0 (nie uzywane)
	*/
	uint8_t operator--(int);

	//Przyjazn z operatorem wypisywania
	friend std::ostream& operator<<(std::ostream& strumien, Statystyka_t s);
};

/*
	@brief Przeladowany operator, zeby wypisac statystke w prosty sposob

	@param strumien na ktory wypisywac
	@param obiekt statystyki do wypisania
	@return strumien przyjety pierwszym argumentem
*/
std::ostream& operator<<(std::ostream& strumien, Statystyka_t s);

#endif
