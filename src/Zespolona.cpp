#include "Zespolona.hpp"
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

Zespolona_t::Zespolona_t(double r, double i): re{r}, im{i}{}
Zespolona_t::Zespolona_t(): re{0}, im{0}	{}
Zespolona_t::Zespolona_t(const Zespolona_t& z): Zespolona_t(z.re, z.im)
{}

Zespolona_t  Zespolona_t::operator+(const Zespolona_t& z)
{
	return Zespolona_t(re + z.re, im + z.im);
}
Zespolona_t  Zespolona_t::operator-(const Zespolona_t& z)
{
	return Zespolona_t(re - z.re, im - z.im);
}
Zespolona_t  Zespolona_t::operator*(const Zespolona_t& z)
{
	return Zespolona_t(re * z.re - im * z.im, re * z.im + im * z.re);
}
Zespolona_t  Zespolona_t::operator/(double x)
{
	if (x == 0)
		throw std::domain_error("Can't divide by zero!");
		
	return Zespolona_t(re / x, im / x);
}
Zespolona_t  Zespolona_t::operator/(const Zespolona_t& z)
{
	double a = pow(Modul(z), 2);
	if (a == 0)
		throw std::domain_error("Can't divide by zero!");

	Zespolona_t temp = (*this) * Sprzezenie(z);
	temp = temp / a;

	return temp;
}

bool  Zespolona_t::operator==(const Zespolona_t& z)
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

// TODO: £adniejsze wypisywanie dla zer itp.
std::ostream& operator<<(std::ostream& strumien, const Zespolona_t& z)
{
	strumien << "(" << z.Re() << std::showpos << z.Im() << std::noshowpos << "i)";
	return strumien;
}
std::istream& operator>>(std::istream& strumien, Zespolona_t& z)
{
	string temp; char brac;
	
	strumien >> ws >> brac;

	if(brac != '(')
		throw std::logic_error("Blednie podana liczba zespolona");

	strumien >> ws >> brac;
	if (brac != '+' && brac != '-')
		if (isdigit(brac) == false)
			throw std::logic_error("Blednie podana liczba zespolona");
		else
			strumien.putback(brac);

	strumien >> z.re;
	if (strumien.fail())
		throw std::logic_error("Blednie podana liczba zespolona");
	if (brac == '-')
		z.re = -z.re;

	strumien >> ws >> brac;
	if (brac != '+' && brac != '-')
		throw std::logic_error("Blednie podana liczba zespolona");

	strumien >> z.im;

	if (strumien.fail())
		throw std::logic_error("Blednie podana liczba zespolona");
	if (brac == '-')
		z.im = -z.im;

	strumien >> ws >> brac;
	if (brac != 'i')
		throw std::logic_error("Blednie podana liczba zespolona");

	strumien >> ws >> brac;
	if (brac != ')')
		throw std::logic_error("Blednie podana liczba zespolona");

	return strumien;
}
