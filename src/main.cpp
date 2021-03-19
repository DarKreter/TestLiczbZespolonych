#include <iostream>
#include <limits>
#include "BazaTestu.hpp"
#include "WyrazenieZesp.hpp"
#include "Statystyka.hpp"

using namespace std;


int main(int argc, char **argv)
{

    //Sprawdzam czy napewno zostal przyslany argument wywolania programu
    if (argc < 2) 
    {
        cout << endl;
        cout << " Brak opcji okreslajacej rodzaj testu." << endl;
        cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
        cout << endl;
        return 1;
    }

    try
    {
        //Jako nazwe pliku zakladam pierwszy argument wywolania
        //Konstruktor BazaTestu_t wczytuje od razu dane z pliku
        BazaTestu_t   bazaT(argv[1]);
        //Struktura na potrzeby zliczania odpowiedzi i wypisywania podsumowania na koniec
        Statystyka_t  statistics;
        //Pomocniczne zmienne
        Zespolona_t answer, correctAnswer;
        int proba = 0;

        //Przechodzimy po wszystkich pytaniach z bazy
        for (unsigned int i = 0; i < bazaT.size(); i++)
        {
            try
            {
                //Obliczamy wartosc wyrazenia dla konkretnego pytania
                //Nastepuje tu odwolanie przez przeladowany operator nawiasow kwadratowych ktory zwraca kolejne wyrazenia zespolone
                //Na wyrazeniu zespolonych wywolujemy .Calculate zwracajace liczbe zespolona
                correctAnswer = bazaT[i].Calculate();

                //Jesli to nie jest pierwsza proba to nie pytamy od nowa tylko ponawiamy pytanie
                if(!proba)
                    cout << "Podaj wynik operacji: " << bazaT[i] << " = " << endl;
                cout << "Twoja odpowiedz(proba " << proba + 1 << " z 3): ";
                //Wczytanie odpowiedzi poprzez przeladowany operator >>
                cin >> answer;

                proba = 0;
                //Jesli uzytkownik odpowiedzial prawidlowo
                if (answer == correctAnswer)
                {
                    //Zerujemy numer proby
                    cout << "Odpowiedz poprawna" << endl << endl;
                    //Zwiekszamy ilosc poprawnych odpowiedzi poprzez przeladowany operator postinkremantacji
                    statistics++;
                }
                else
                {
                    cout << "Blad. Prawidlowym wynikiem jest: " << correctAnswer << endl << endl;
                    //Zwiekszamy ilosc blednym operacji poprzez przeladowany operator post dekrementacji
                    statistics--;
                }

            }
            //Lapanie wyjatkow ktore oznaczaja blad podczas wczytywania liczby zespolonej przez uzytkownika
            catch (std::logic_error& e)
            {
                //Jesli uzytkownik ma jeszcze jakies proby
                if (proba < 2)
                {
                    //Powtarzamy to samo pytanie i zwiekszamy jego numer proby o jeden
                    i--; proba++;
                    cerr << endl << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl << endl;
                }
                //Jesli to byla 3 proba
                else
                {
                    //Dodajemy mu bledna odpowiedz i zerujmy ilosc prob(bo przechodzimy do kolejnego pytania)
                    statistics--; proba = 0;
                    cerr << endl << "Blad zapisu liczby zespolonej. Prawidlowym wynikiem jest: " << correctAnswer << endl << endl;
                }
                //Skoro wystapil blad musimy wyczyscic flagi bledu bufora
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
            }
            //Jesli byl to jakis inny blad rzucamy go dalej
            catch (...)
            {
                throw;
            }

        }

        cout << "Koniec testu!" << endl << statistics;

    }
    //Lapanie bledow krytycznych ktore nie pozwalaja programowi dalej kontynuowac
    catch (std::logic_error& e)
    {
        cerr << e.what() << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return 2;
    }
    catch (...)
    {
        cerr << "Unknown error" << endl;
    }

    return 0;
}
