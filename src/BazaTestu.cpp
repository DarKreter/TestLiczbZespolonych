#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include "BazaTestu.hpp"

using namespace std;


BazaTestu_t::BazaTestu_t(std::string sNazwaTestu)
{
    ifstream plik;
    plik.open(sNazwaTestu + ".dat");
    if(!plik.good())
        throw std::logic_error("Otwarcie testu '" + sNazwaTestu + "' nie powiodlo sie.");

    WyrazenieZesp_t temp;

    while (!plik.eof())
    {
        try
        {
            plik >> temp >> ws;
            temp.Calculate();
            pytania.push_back(temp);
        }
        catch (std::logic_error& e)
        {
            cerr << "Napotkano bledne wyrazenie. Zostalo ono pominiete." << endl;
            plik.clear();
            plik.ignore(10000, '\n');
        }
        catch (...)
        {
            throw;
        }

    }
    plik.close();

}


unsigned int BazaTestu_t::size()
{
    return pytania.size();
}

WyrazenieZesp_t BazaTestu_t::operator[](unsigned int ktory)
{
    return pytania[ktory];
}