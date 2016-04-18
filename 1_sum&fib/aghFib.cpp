//plik definiujacy metode klasy aghFib
#include "aghFib.h"

aghFib::aghFib()
{
    static tab = NULL;     //inicjalizacja wskaünika NULL'em w konstruktorze klasy
}
int aghFib::operator[](int idx)
{
    tab = new int[idx+1];
    //Wykorzystujemy programowanie dynamiczne
    //Rezerwacja pamieci dla idx + 1 elementow (poniewaz zaczynamy od wyrazu zerowego ciagu)
   // tab = new int[idx+1];
    //Inicjalizacja dwoch pierwszych komorek tablicy zgodnie ze wzorem rekurencyjnym
    tab[0]= 0;
    tab[1]= 1;

    //Dynamiczne obliczanie ciagu Fibonacciego zgodnie ze wzorem rekurencyjnym
    for(int i=2; i<=idx; i++)
        tab[i]= tab[i-1] + tab[i-2];

    //Zwracanie poszukiwanego elementu ciagu
     return tab[idx];
}

aghFib::~aghFib()
{
    delete [] tab;      //zwolnienie pamieci
}
