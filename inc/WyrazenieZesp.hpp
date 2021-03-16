#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "Zespolona.hpp"


 /*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum class Operator: uint8_t 
{ 
	Dodawanie = 43, Odejmowanie = 45, Mnozenie = 42, Dzielenie = 47
};


/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
class WyrazenieZesp_t 
{
	Zespolona_t   arg1;   // Pierwszy argument wyrazenia arytmetycznego
	Zespolona_t   arg2;   // Drugi argument wyrazenia arytmetycznego

	Operator op;     // Opertor wyrazenia arytmetycznego


	friend std::istream& operator>>(std::istream& strumien, WyrazenieZesp_t& z);

public:
	Zespolona_t Calculate();

	Zespolona_t Arg1() const	{ return arg1; }
	Zespolona_t Arg2() const	{ return arg2; }
	Operator Op()	   const	{ return op; }
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

std::ostream& operator<<(std::ostream& strumien, const WyrazenieZesp_t& z);
std::istream& operator>>(std::istream& strumien, Operator& z);
std::istream& operator>>(std::istream& strumien, WyrazenieZesp_t& z);

#endif
