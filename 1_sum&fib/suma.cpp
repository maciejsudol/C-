#include "suma.h"

int suma(char **tab, int ile)
{
    string wynik;
    //Petla sklejajaca kolejne stringi
    for(int i=0; i<ile; i++)
    {
        //Sklejanie
        wynik+= tab[i];
        if(i != (ile-1))
            cout << tab[i] << " + ";
        else
            //Dla ostatniego elementu wyswietlanie '=' i wyniku
            cout << tab[i] << " = " << wynik << "(" << wynik.length() << ")" << endl;
    }

    return (wynik.length());
}
