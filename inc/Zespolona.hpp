#ifndef ZESPOLONA_HPP
#define ZESPOLONA_HPP

#include<iostream>

/*
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*
 * Modeluje pojecie liczby zespolonej
 */
class  Zespolona_t 
{
	double   re;    // Pole repezentuje czesc rzeczywista.
	double   im;    // Pole repezentuje czesc urojona.

public:
	Zespolona_t  operator+(const Zespolona_t&);
	Zespolona_t  operator-(const Zespolona_t&);
	Zespolona_t  operator*(const Zespolona_t&);
	Zespolona_t  operator/(const Zespolona_t&);
	bool		 operator==(const Zespolona_t&);
	bool		 operator!=(const Zespolona_t&);
	Zespolona_t  operator/(double);

	Zespolona_t(double, double);
	Zespolona_t(const Zespolona_t& z);
	Zespolona_t();

	double Re() const { return re; }
	double Im() const { return im; }

	friend std::istream& operator>>(std::istream& strumien, Zespolona_t& z);
};


Zespolona_t Sprzezenie(const Zespolona_t& z);
double		Modul(const Zespolona_t& z);
std::ostream& operator<<(std::ostream& strumien, const Zespolona_t& z);
std::istream& operator>>(std::istream& strumien, Zespolona_t& z);


#endif
