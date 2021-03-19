#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "Zespolona.hpp"


/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
class WyrazenieZesp_t 
{
	Zespolona_t   arg1;		// Pierwszy argument wyrazenia arytmetycznego
	Zespolona_t   arg2;		// Drugi argument wyrazenia arytmetycznego

	 /*!
	 * Modeluje zbior operatorow arytmetycznych.
	 * Maj¹ one konretne wartoœci odpowiadaj¹ce konkretnych znakom w tablicy ASCII
	 */
	enum class Operator : uint8_t
	{
		Dodawanie = 43, Odejmowanie = 45, Mnozenie = 42, Dzielenie = 47
	};

	Operator op;			// Opertor wyrazenia arytmetycznego


	//Przyjazn z funcja wczytujaca WyrazenieZesp ze strumienia
	friend std::istream& operator>>(std::istream& strumien, WyrazenieZesp_t& z);
	friend std::istream& operator>>(std::istream& strumien, WyrazenieZesp_t::Operator& z);
	friend std::ostream& operator<<(std::ostream& strumien, const WyrazenieZesp_t::Operator& z);

public:
	/*
		@brief Funkcja obliczajaca wartosc wyrazenia zespolonego

		@return Zwraca wynik w postaci liczby zespolonej
	*/
	Zespolona_t Calculate();

	/*
		@brief Funkcja dostepowa do pierwszego argumentu wyrazenia zespolonego

		@return Zwraca pierwszego argumentu wyrazenia zespolonego
	*/
	Zespolona_t Arg1() const	{ return arg1; }

	/*
		@brief Funkcja dostepowa do drugiego argumentu wyrazenia zespolonego

		@return Zwraca drugi argumentu wyrazenia zespolonego
	*/
	Zespolona_t Arg2() const	{ return arg2; }

	/*
		@brief Funkcja dostepowa do operatora wyrazenia zespolonego

		@return Zwraca opeartor wyrazenia zespolonego
	*/
	Operator Op()	   const	{ return op; }
};

/*
	@brief  Operator wczytywania wyrazenia zespolonego

	@param  Strumien z ktorego bedziemy wczytywac
	@param  wyrazenie zespolone do wczytania
	@return Strumien przyslany pierwszym argumentem
*/
std::istream& operator>>(std::istream& strumien, WyrazenieZesp_t& z);

/*
	@brief  Operator wypisywania wyrazenia zespolonego

	@param  Strumien na ktorym bedziemy wypisywac
	@param  Wyrazenie zespolone do wypisania
	@return Strumien przyslany pierwszym argumentem
*/
std::ostream& operator<<(std::ostream& strumien, const WyrazenieZesp_t& z);

/*
	@brief  Operator wypisywania operatora matematycznego

	@param  Strumien na ktorym bedziemy wypisywac
	@param  Operatora matematyczny do wypisania
	@return Strumien przyslany pierwszym argumentem
*/
std::ostream& operator<<(std::ostream& strumien, const WyrazenieZesp_t::Operator& z);

/*
	@brief  Operator wczytywania operatora matematycznego

	@param  Strumien z ktorego bedziemy wczytywac
	@param  Operator matematyczny do wczytania
	@return Strumien przyslany pierwszym argumentem
*/
std::istream& operator>>(std::istream& strumien, WyrazenieZesp_t::Operator& z);


#endif
