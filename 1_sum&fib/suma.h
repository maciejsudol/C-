/**
* \file suma.h
* \author Pawel Inglot & Maciej Sudol
* \date 29.04.2015
* \version 1.0
* \brief Plik naglowkowy zawierajacy definicje szablonu funkcji suma oraz deklaracje funkcji specjalizowanej dla char **
*/
// -------------------------------------------------------------------------

#ifndef SUMA_H
#define SUMA_H
// -------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

/**
* \brief Szablon funkcji sumujacej kolejne elementy podanej jako argument tablicy
*
* \param tab - argument zawierajacy dane potrzebne do wykonania funkcji
* \param ile - argument przechowujacy ilosc elementow
* \return - zwracana (double) suma elementow argumentu tab
*/
template <class typ>
double suma (typ tab, int ile)
{
    double wynik= 0;
    //Petla sumujaca kolejne elementy
    for(int i=0; i<ile; i++)
    {
        //Sumowanie
        wynik+= double(tab[i]);
        if(i != (ile-1))
            cout << tab[i] << " + ";
        else
            //Dla ostatniego elementu wyswietlanie '=' i wyniku
            cout << tab[i] << " = " << wynik << endl;
    }

    return wynik;
}

// ------------------------------------------------------------------------
///
/// \brief Specjalizowana funkcja sumujaca dla tablic zawierajacych stringi (char **)
///
/// \param **tab - argument zawierajacy dane potrzebne do wykonania funkcji
/// \param ile - argument przechowujacy ilosc elementow
/// \return - zwracana (int) suma elementow argumentu char tab**
///
int suma(char **tab, int ile);

#endif // SUMA_H
