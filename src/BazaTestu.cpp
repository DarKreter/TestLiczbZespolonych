#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <limits>
#include "BazaTestu.hpp"

using namespace std;

BazaTestu_t::BazaTestu_t(std::string sNazwaTestu)
{
    //Tworzymy strumien plikowy z ktorego bedziemy wczytywac
    ifstream plik;
    //Otwieramy plik o przyslanej nazwie o rozszerzeniu .dat
    plik.open(sNazwaTestu + ".dat");
    //Jesli plik nie istnieje badz byl problem z otwarciem to wrzuacmy wyjatek
    if(!plik.good())
        throw std::logic_error("Otwarcie testu '" + sNazwaTestu + "' nie powiodlo sie.");

    WyrazenieZesp_t temp;

    //Wczytujemy dopoki nie nastapi koniec pliku
    while (!plik.eof())
    {
        try
        {   
            //Wczytujemy wyrazenie zespolone
            plik >> temp >> ws;
            //Dodajemy je do bazy pytan
            pytania.push_back(temp);
        }
        //Jesli wystapil blad to pomijamy jedna linie i wypisujemy komunikat o bledzie
        catch (std::logic_error& e)
        {
            cerr << "Napotkano bledne wyrazenie. Zostalo ono pominiete." << endl;
            plik.clear();
            plik.ignore(numeric_limits<int>::max(), '\n');
        }
        //Jesli blad byl powazniejszy rzucamy wyjatek dalej
        catch (...)
        {
            //pamietamy o zakmnieciu pliku
            plik.close();
            throw;
        }

    }
    //pamietamy o zakmnieciu pliku
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