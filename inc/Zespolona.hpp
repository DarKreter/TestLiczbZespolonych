#ifndef ZESPOLONA_HPP
#define ZESPOLONA_HPP

#include<iostream>

/*
	Plik zawiera definicje struktury Zesplona oraz zapowiedzi
	przeciazen operatorow arytmetycznych i pomocnych funkcji skladowych
	dzialajacych na tej strukturze.
*/


/*
 * Modeluje pojecie liczby zespolonej
 */
class  Zespolona_t 
{
	double   re;    // Pole repezentuje czesc rzeczywista.
	double   im;    // Pole repezentuje czesc urojona.

public:
	//OPERATORY:
	/*
		@brief Operator dodajacy dwie liczby zespolone

		@param liczba zespolona do dodania
		@return Suma dwoch liczb zespolonych
	*/
	Zespolona_t  operator+(const Zespolona_t&)  const;

	/*
		@brief Operator odejmujacy dwie liczby zespolone

		@param liczba zespolona do odjecia
		@return Roznica dwoch liczb zespolonych
	*/
	Zespolona_t  operator-(const Zespolona_t&)  const;

	/*
		@brief Operator mnozacy dwie liczby zespolone

		@param liczba zespolona do pomnozenia
		@return Iloczyn dwoch liczb zespolonych
	*/
	Zespolona_t  operator*(const Zespolona_t&)  const;

	/*
		@brief Operator dzielacy dwie liczby zespolone

		@param liczba zespolona przez ktora bedziemy dzielic
		@return Iloraz dwoch liczb zespolonych
	*/
	Zespolona_t  operator/(const Zespolona_t&)  const;

	/*
		@brief Operator porownujacy dwie liczby zespolone

		@param liczba zespolona do porownania
		@return Zwraca true jesli dwie liczby sa sobie rowne i false jesli sa rozne
	*/
	bool		 operator==(const Zespolona_t&) const;

	/*
		@brief Operator roznosci

		@param Liczba zespolona do porownania
		@return Zwraca false jesli dwie liczby sa sobie rowne i true jesli sa rozne
	*/
	bool		 operator!=(const Zespolona_t&) const;

	/*
		@brief Operator dzielenia przez liczbe rzeczywista

		@param Liczba rzeczywista przez ktora bedziemy dzielic
		@return Zwraca liczbe zespolona podzielona przez liczbe rzeczywista
	*/
	Zespolona_t  operator/(double)			    const;

	//KONSTRUKTORY
	/*
		@brief Kontruktor na podczasie czesci rzeczywistej i urojonej

		@param Czesc rzeczywista
		@param Czesc urojona
	*/
	Zespolona_t(double, double);

	/*
		@brief Kontruktor kopiujacy

		@param Inna liczba rzeczywista na podstawie ktorej ma sie stworzyc liczba zespolona
	*/
	Zespolona_t(const Zespolona_t& z);

	/*
		@brief Kontruktor kopiujacy

		@param Konstruktor domyslny - ustawia czesc rzeczywista i urojona na 0
	*/
	Zespolona_t();

	//FUNKCJE DOSTEPOWE:
	/*
		@brief Funkcja dostepowa do czesci rzeczywistej

		@return Czesc rzeczywista liczby zespolonej
	*/
	double Re() const { return re; }

	/*
		@brief Funkcja dostepowa do czesci urojonej

		@return Czesc urojona liczby zespolonej
	*/
	double Im() const { return im; }

	//Przyjazn z operatorem wczytywania ze strumienia istream
	friend std::istream& operator>>(std::istream& strumien, Zespolona_t& z);
};

/*
	@brief Funkcja tworzaca sprzezenie z liczby zespolonej

	@param Liczba zespolona z ktorej ma byc obliczone sprzezenie
	@return Sprzezenie przyslanej liczby
*/
Zespolona_t Sprzezenie(const Zespolona_t& z);

/*
	@brief Funkcja liczaca modul z liczby zespolonej

	@param Liczba zespolona z ktorej ma byc wyliczony modul
	@return Modul przyslanej liczby
*/
double		Modul(const Zespolona_t& z);

/*
	@brief Operator wypisywania na strumieniu liczby zespolonej

	@param Strumien na ktorym bedziemy wypisywac
	@param Liczba zespolona do wypisania
	@return Strumien przyslany jako pierwszy argument
*/
std::ostream& operator<<(std::ostream& strumien, const Zespolona_t& z);

/*
	@brief Operator wczytywania ze strumienia liczby zespolonej

	@param Strumien z ktorego bedziemy wczytywac
	@param Liczba zespolona do wczytania
	@return Strumien przyslany jako pierwszy argument
*/
std::istream& operator>>(std::istream& strumien, Zespolona_t& z);


#endif
