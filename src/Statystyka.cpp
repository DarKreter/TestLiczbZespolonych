#include "Statystyka.hpp"

using namespace std;

std::ostream& operator<<(std::ostream& strumien, Statystyka_t s)
{
	strumien << "Ilosc dobrych odpowiedzi: " << (int)s.correctAnswers << endl;
	strumien << "Ilosc blednych odpowiedzi: " << (int)s.wrongAnswers << endl;
	strumien << "Wynik procentowy poprawnych odpowiedzi: " << s.Calculate() << "%" << endl;

	return strumien;
}

float Statystyka_t::Calculate()
{
	return (static_cast<float>(correctAnswers) / static_cast<float>(questionsAmount)) * 100.;
}

uint8_t Statystyka_t::operator++(int)
{
	//Zwiekszamy ilosc poprawnych odpowiedzi oraz ilosc wszystkich odpowiedzi 
	correctAnswers++;		questionsAmount++;
	return 0;
}

uint8_t Statystyka_t::operator--(int)
{
	//Zwiekszamy ilosc blednych odpowiedzi oraz ilosc wszystkich odpowiedzi 
	wrongAnswers++;		questionsAmount++;
	return 0;
}