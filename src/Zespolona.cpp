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
	strumien << "(";
	if (!z.Re() && !z.Im())
		strumien << 0;
	else if (!z.Im())
		strumien << z.Re();
	else
	{
		if (z.Re())
			strumien << z.Re();

		if (fabs(z.Im()) == 1)
		{
			if (z.Im() > 0)
			{
				if (z.Re())
					strumien << "+";
				else
					;
			}
			else
				strumien << "-";
		}
		else
		{
			if (z.Re())
				strumien << std::showpos;
			else
				;

			strumien << z.Im() << std::noshowpos;
		}

		strumien << "i";
	}

	strumien << ")";

	return strumien;
}
std::istream& operator>>(std::istream& strumien, Zespolona_t& z)
{
	//Opcje: (a+bi)  (a+i) (-a+i) (a-i)                         (bi) (-bi)  (a) (-a)  (+i)  (-i)  (i)

	string temp; char a, b = 'f';
	
	strumien >> ws >> a;
	if(a != '(')
		throw std::logic_error("Blednie podana liczba zespolona");


	strumien >> ws >> a;
	if (a == 'i')
	{
		z.re = 0; z.im = 1;

		strumien >> ws >> a;
		if (a != ')')
			throw std::logic_error("Blednie podana liczba zespolona");

		return strumien;
	}
	else if (a == '+' || a == '-')
	{
		b = a;
		strumien >> ws >> a;
		if (a == 'i')
		{
			z.re = 0; z.im = (b == '+' ? 1 : -1);

			strumien >> ws >> a;
			if (a != ')')
				throw std::logic_error("Blednie podana liczba zespolona");

			return strumien;
		}
	}
	strumien.putback(a);
	strumien >> z.re;
	if(strumien.fail())
		throw std::logic_error("Blednie podana liczba zespolona");
	if (b == '-')
		z.re *= -1;

	b = 'f';
	strumien >> ws >> a;
	if (a == ')')
		return strumien;
	else if (a == 'i')
	{
		z.im = z.re;  z.re = 0;

		strumien >> ws >> a;
		if (a != ')')
			throw std::logic_error("Blednie podana liczba zespolona");

		return strumien;
	}
	else if (a == '+' || a == '-')
	{
		b = a;
		strumien >> ws >> a;
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


	strumien >> z.im;
	if (strumien.fail())
		throw std::logic_error("Blednie podana liczba zespolona");
	if (b == '-')
		z.im *= -1;

	strumien >> ws >> a;
	if (a != 'i')
		throw std::logic_error("Blednie podana liczba zespolona");


	strumien >> ws >> a;
	if (a != ')')
		throw std::logic_error("Blednie podana liczba zespolona");

	return strumien;

}
