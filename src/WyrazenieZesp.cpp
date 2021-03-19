#include "WyrazenieZesp.hpp"


std::ostream& operator<<(std::ostream& strumien, const WyrazenieZesp_t::Operator& z)
{
	//Rzutujemy zeby otrzymac znak zamiast wartosci liczbowej tego znaku
	strumien << static_cast<char>(z);

	return strumien;
}

std::istream& operator>>(std::istream& strumien, WyrazenieZesp_t::Operator& z)
{
	char x;
	//Wczytujemy wszystkie biale znaki oraz jednego chara
	strumien >> std::ws >> x;

	switch (x)
	{
	//Jesli jest to ktorys z operatorow narazie nie robimy nic
	case char(WyrazenieZesp_t::Operator::Dodawanie): case char(WyrazenieZesp_t::Operator::Odejmowanie):
	case char(WyrazenieZesp_t::Operator::Mnozenie): case char(WyrazenieZesp_t::Operator::Dzielenie):
			break;
	default:
		//Jesli to jakis inny znak rzucamy wyjatek
		throw std::logic_error("Blednie podane wyrazenie zespolone!");
	}

	//Rzutujemy wczytanego chara na operator
	z = static_cast<WyrazenieZesp_t::Operator>(x);

	return strumien;
}

Zespolona_t WyrazenieZesp_t::Calculate()
{
	Zespolona_t temp;

	//Zaleznie od operatora wykonujemy dana operacje matematyczna
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

	//Zwracamy wynik
	return temp;
}

std::ostream& operator<<(std::ostream& strumien, const WyrazenieZesp_t& z)
{
	//Wypisujemy kolejno liczbe zespolona operator i druga liczbe zespolona
	strumien << z.Arg1() << z.Op() << z.Arg2();

	return strumien;
}

std::istream& operator>>(std::istream& strumien, WyrazenieZesp_t& z)
{
	//Zeby wczytac WyrazenieZespolone musimy kolejno wczytac liczbe zespolona, operator i druga liczbe zespolona
	strumien >> z.arg1;
	strumien >> z.op;
	strumien >> z.arg2;

	return strumien;
}