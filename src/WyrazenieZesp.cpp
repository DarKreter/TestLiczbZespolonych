#include "WyrazenieZesp.hpp"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
std::ostream& operator<<(std::ostream& strumien, const WyrazenieZesp_t& z)
{
	strumien << z.Arg1() << static_cast<char>(z.Op()) << z.Arg2();

	return strumien;
}

Zespolona_t WyrazenieZesp_t::Calculate()
{
	Zespolona_t temp;

	switch (op)
	{
	case Operator::Dodawanie:
		temp = arg1 + arg2;
		break;
	case Operator::Odejmowanie:
		temp = arg1 - arg2;
		break;
	case Operator::Mnozenie:
		temp = arg1 * arg2;
		break;
	case Operator::Dzielenie:
		temp = arg1 / arg2;
		break;
	}

	return temp;
}

std::istream& operator>>(std::istream& strumien, Operator& z)
{
	char x;
	strumien >> std::ws >> x;

	switch (x)
	{
	case char(Operator::Dodawanie): case char(Operator::Odejmowanie):
	case char(Operator::Mnozenie): case char(Operator::Dzielenie):
			break;
	default:
		throw std::logic_error("Blednie podane wyrazenie zespolone!");
	}

	z = static_cast<Operator>(x);

	return strumien;
}

std::istream& operator>>(std::istream& strumien, WyrazenieZesp_t& z)
{
	strumien >> z.arg1;
	strumien >> z.op;
	strumien >> z.arg2;

	return strumien;
}