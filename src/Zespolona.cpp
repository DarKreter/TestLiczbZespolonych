#include "Zespolona.hpp"
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

Zespolona_t::Zespolona_t(double r, double i): re{r}, im{i}{}
Zespolona_t::Zespolona_t(): re{0}, im{0}	{}
Zespolona_t::Zespolona_t(const Zespolona_t& z): Zespolona_t(z.re, z.im)
{}

Zespolona_t  Zespolona_t::operator+(const Zespolona_t& z) const
{
	return Zespolona_t(re + z.re, im + z.im);
}
Zespolona_t  Zespolona_t::operator-(const Zespolona_t& z) const
{
	return Zespolona_t(re - z.re, im - z.im);
}
Zespolona_t  Zespolona_t::operator*(const Zespolona_t& z) const
{
	return Zespolona_t(re * z.re - im * z.im, re * z.im + im * z.re);
}
Zespolona_t  Zespolona_t::operator/(double x) const
{
	//Na wypadek dzielenia przez zero
	if (x == 0)
		throw std::domain_error("Can't divide by zero!");
		
	return Zespolona_t(re / x, im / x);
}
Zespolona_t  Zespolona_t::operator/(const Zespolona_t& z) const
{
	double a = pow(Modul(z), 2);
	//Na wypadek dzielenia przez zero
	if (a == 0)
		throw std::domain_error("Can't divide by zero!");

	Zespolona_t temp = (*this) * Sprzezenie(z);
	temp = temp / a;

	return temp;
}
bool  Zespolona_t::operator==(const Zespolona_t& z) const
{
	return re == z.re && im == z.im;
}


double  Modul(const Zespolona_t& z)
{
	return sqrt(pow(z.Re(), 2) + pow(z.Im(), 2));
}
Zespolona_t  Sprzezenie(const Zespolona_t& z)
{
	return Zespolona_t(z.Re(), -z.Im());
}


std::ostream& operator<<(std::ostream& strumien, const Zespolona_t& z)
{
	//Zawsze wypisujemy (
	strumien << "(";
	//Jesli i Re i Im sa zerami to wypisujemy tylko zero
	if (!z.Re() && !z.Im())
		strumien << 0;
	//Jesli czesc urojona wypisujemy po prostu liczbe
	else if (!z.Im())
		strumien << z.Re();
	else
	{
		//Jesli rzeczywista nie jest zerem to ja wypisujemy
		if (z.Re())
			strumien << z.Re();

		//Jesli Im jest rowne 1 lub -1 (zeby wypisac wtedy -i badz i)
		if (fabs(z.Im()) == 1)
		{
			//Jesli Im wynosi 1 i Re istnieje wypisujemy plus
			if (z.Im() > 0 && z.Re())
				strumien << "+";
			//Wypisujemy minus jesli Im jest rowne -1
			else
				strumien << "-";
		}
		//Jesli Im nie jest rowne {-1, 0, 1}
		else
		{
			//Jesli Re jest rozne od 0 wypisujemy znak Im
			if (z.Re())
				strumien << std::showpos;

			strumien << z.Im() << std::noshowpos;
		}

		//Konczymy Im wypisujac 'i'
		strumien << "i";
	}

	//Konczymy wypisywanie znakiem ')'
	strumien << ")";

	return strumien;
}

std::istream& operator>>(std::istream& strumien, Zespolona_t& z)
{
	//Opcje: (a+bi)  (a+i) (-a+i) (a-i) (bi) (-bi)  (a) (-a)  (+i)  (-i)  (i)

	string temp; char a, b = 'f';
	
	//Wczytujemy pierwszy znak
	strumien >> ws >> a;
	//Jesli nie jest to ( to jest to blad
	if(a != '(')
		throw std::logic_error("Blednie podana liczba zespolona");


	strumien >> ws >> a;
	//Przypadek (i)
	if (a == 'i')
	{
		z.re = 0; z.im = 1;

		strumien >> ws >> a;
		if (a != ')')
			throw std::logic_error("Blednie podana liczba zespolona");

		return strumien;
	}
	//Jesli najpierw wystapil znak
	else if (a == '+' || a == '-')
	{
		b = a; //Zapamietujemy na pozniej
		strumien >> ws >> a;
		//Przypadek (+i) lub (-i)
		if (a == 'i')
		{
			z.re = 0; z.im = (b == '+' ? 1 : -1);

			strumien >> ws >> a;
			if (a != ')')
				throw std::logic_error("Blednie podana liczba zespolona");

			return strumien;
		}
	}
	//Jesli to nie byl znak ani i wkladamy do spowrotem
	//Jesli to byl znak to w srodku jest jeszcze jedno wczytanie i je wlasnie wkladamy spowrotem
	strumien.putback(a);
	//Wczytujemy liczbe
	strumien >> z.re;
	if(strumien.fail())
		throw std::logic_error("Blednie podana liczba zespolona");
	//Jesli przed liczba byl znak '-' to zmieniamy znak wczytanej liczby
	if (b == '-')
		z.re *= -1;
	b = 'f';

	strumien >> ws >> a;
	//Przypadek (+a) (a) (-a) gdzie a to liczba rzeczywista
	if (a == ')')
		return strumien;
	//Przypadek (+ai) (ai) (-ai) gdzie a to liczba rzeczywista
	else if (a == 'i')
	{
		//Wczytana liczbe wpisujemy jednak do czesci urojonej
		z.im = z.re;  z.re = 0;

		strumien >> ws >> a;
		if (a != ')')
			throw std::logic_error("Blednie podana liczba zespolona");

		return strumien;
	}
	//Jesli po pierwszej liczbe(Re) podajemy Im - musi pomiedzy nimi wystapic znak
	else if (a == '+' || a == '-')
	{
		b = a;
		strumien >> ws >> a;
		//Przypadek ({+,-, } a {+,-} i)
		if (a == 'i')
		{
			z.im = (b == '+' ? 1 : -1);

			strumien >> ws >> a;
			if (a != ')')
				throw std::logic_error("Blednie podana liczba zespolona");

			return strumien;
		}

		strumien.putback(a);
	
	}
	else
	{
		throw std::logic_error("Blednie podana liczba zespolona");
	}
	//Przypadki ({+,-, } a {+,-}bi)

	//Wczytujemy druga liczbe
	strumien >> z.im;
	if (strumien.fail())
		throw std::logic_error("Blednie podana liczba zespolona");
	//Jesli poprzednio wystapil znak minus to zmieniamy znak liczby
	if (b == '-')
		z.im *= -1;

	//Potem musi wystapic 'i'
	strumien >> ws >> a;
	if (a != 'i')
		throw std::logic_error("Blednie podana liczba zespolona");

	//Na koniec musi wystapic ')'
	strumien >> ws >> a;
	if (a != ')')
		throw std::logic_error("Blednie podana liczba zespolona");

	return strumien;

}
