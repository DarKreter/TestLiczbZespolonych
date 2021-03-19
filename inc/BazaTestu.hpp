#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include "WyrazenieZesp.hpp"
#include <vector>


/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy z bazy.
 */
class BazaTestu_t 
{
	std::vector<WyrazenieZesp_t>  pytania;   // Wektor wszystkich pytan

public:
	/*
		@brief  Zwraca ilosc pytan w wektorze

		@return Ilosc pytan
	*/
	unsigned int size();

	/*
		@brief Konstruktor wczytujacy od razu wektor wyrazen zespolonych do wektora,
			jesli natrafi na bledne wyrazenie zespolone wypisze informacje o errorze i pominie ta linie

		@param Nazwa pliku z ktorego wczytamy wyrazenia zespolone do testu
	*/
	BazaTestu_t(std::string sNazwaTestu);

	/*
		@brief Dostepowy operator[] ktory zwraca odpowiednie w kolejnosci wyrazenie zespolone

		@param numer wyrazenia zespolonego ktore ma byc zwrocone
		@return odpowiednie WyrazenieZesp z wektora
	*/
	WyrazenieZesp_t operator[](unsigned int);

};



#endif
