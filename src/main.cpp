#include <iostream>
#include "BazaTestu.hpp"
#include "Zespolona.hpp"
#include "Statystyka.hpp"

using namespace std;



int main(int argc, char **argv)
{
    while (true)
    {
        try
        {
            Zespolona_t z;
            cin >> z;
            cout << z;
        }
        catch (std::logic_error& e)
        {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        catch (...)
        {
            cerr << "xD?" << endl;
        }
    }


    return 0;
  /*if (argc < 2) 
  {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }*/

    try
    {
        BazaTestu_t   bazaT("xD");
        Statystyka_t  statistics( bazaT.size() );
        Zespolona_t answer, correctAnswer;
        int proba = 0;

        for (int i = 0; i < bazaT.size(); i++)
        {
            try
            {
                correctAnswer = bazaT[i].Calculate();

                if(!proba)
                    cout << "Podaj wynik operacji: " << bazaT[i] << " = " << endl;
                cout << "Twoja odpowiedz: ";
                cin >> answer;


                if (answer == correctAnswer)
                {
                    proba = 0;
                    cout << "Odpowiedz poprawna" << endl << endl;
                    statistics++;
                }
                else
                {
                    cout << "Blad. Prawidlowym wynikiem jest: " << correctAnswer << endl << endl;
                    statistics--;
                }

            }
            catch (std::logic_error& e)
            {
                if (proba < 2)
                {
                    i--; proba++;
                    cerr << endl << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl << endl;
                }
                else
                {
                    statistics--; proba = 0;
                    cerr << endl << "Blad zapisu liczby zespolonej. Prawidlowym wynikiem jest: " << correctAnswer << endl << endl;
                }

                cin.clear();
                cin.ignore(10000, '\n');
            }
            catch (...)
            {
                throw;
            }

        }

        cout << "Koniec testu!" << endl << statistics;

    }
    catch (std::logic_error& e)
    {
        cerr << e.what() << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    catch (...)
    {
        cerr << "xD?" << endl;
    }


}
