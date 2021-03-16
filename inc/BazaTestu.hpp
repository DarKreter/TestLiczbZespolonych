#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include "WyrazenieZesp.hpp"
#include <vector>


/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
class BazaTestu_t 
{
	std::vector<WyrazenieZesp_t>  pytania;   /* Wskaznik na tablice zawierajaca pytania testu */

public:
	unsigned int size();
	BazaTestu_t(std::string sNazwaTestu);

	WyrazenieZesp_t operator[](unsigned int);

};



#endif
