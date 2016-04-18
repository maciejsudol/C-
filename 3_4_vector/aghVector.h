/**
 * \file    aghVector.h
 * \author  Maciej Sudol & Pawel Inglot
 * \date    2015-05-24
 * \brief   Deklaracja i definicja szablonowej klasy aghVector, umozliwiajacej implementacje pojemnika wektorowego na dane
 */
// -----------------------------------------------------------------------------------------------

#ifndef AGHVECTOR_H
#define AGHVECTOR_H
// -----------------------------------------------------

#include "aghContainer.h"
// -----------------------------------------------------


/**
 * \class   aghVector
 * \brief   Deklaracja szablonowej klasy aghVector.
 * \author  Maciej Sudol & Pawel Inglot
 * \date    2015-05-24
 * \param  T   Typ parametryczny.
 */
template <class T>
class aghVector :public aghContainer<T>
{
private:

// ---Zmienne-------------------------------------------------------------------------------------

    /** \brief   Tablica przechowujaca dane. */
    T* tab;

    /** \brief   Tymczsowa pojemnosc pojemnika, zapewniajaca optymalizacje pracy programu. */
    int rozmiar;

    /** \brief   Liczba juz zajetych pol wektora. */
    int zajete;


    /** \brief   Wartosc o jaka zmieniana jest pojemnosc pojemnika. */
    static const int delta_roz = 5;

// ---Funkcje pomocnicze--------------------------------------------------------------------------

    /**
     * \fn  void aghVector::resize(int o_ile);
     * \brief   Funkcja dynamicznie zarzadzajaca pamiecia pojemnika
     * \param   o_ile   Wartosc, o jaka ma zostac zmieniona pojemnosc pojemnika
     */
    void resize(int o_ile);

    /**
     * \fn  void aghVector::rozsun(int idx);
     * \brief   Funkcja zwalniajaca miejsce pojemnika o indeksie idx
     * \param   idx Indeks wybranego miejsca.
     */
    void rozsun(int idx);

    /**
     * \fn  void aghVector::zsun(int idx);
     * \brief   Funkcja zapelniajaca miejsce pojemnika o indeksie idx
     * \param   idx Indeks wybranego miejsca.
     */
    void zsun(int idx);



public:

// ---Konstruktory i destruktor-------------------------------------------------------------------

    /**
     * \fn  aghVector::aghVector();
     * \brief   Konstruktor bezparametrowy
     */
    aghVector();

    /**
     * \fn  aghVector::aghVector(const aghContainer<T>& wzor);
     * \brief   Konstruktor kopiujacy.
     * \brief   Obsluguje zarono argumenty typu aghVector, jak rowniez aghContainer.
     * \param   wzor    Obiekt zrodlowy typu aghVector lub aghContainer.
     */
    aghVector(const aghContainer<T>& wzor);

    /**
     * \fn  aghVector::~aghVector();
     * \brief   Destruktor.
     */
    ~aghVector();


// ---Metody i operator =-------------------------------------------------------------------------

    /**
     * \fn  aghContainer<T>& aghVector::operator=(const aghVector<T>& wzor);
     * \brief   Operator przypisania. Operator przywoluje obsluge operatora = z klasy bazowej.
     * \param   wzor    Obiekt zrodlowy.
     * \return  Kopia obiektu podanego jako parametr konstruktora.
     */
    aghContainer<T>& operator=(const aghVector<T>& wzor);

    /**
     * \fn  T& aghVector::at(int) const;
     * \brief   Metoda zwracajaca wartosc elementu. Zwraca wartosc w pojemniku. Zakladamy ze
     *          indeksowanie wartosci rozpoczynamy od zera.
     * \param   parameter1  Indeks wybranego miejsca tablicy.
     * \return  Referencja do wybranego elementu w tablicy.
     */
    T& at(int) const;

    /**
     * \fn  bool aghVector::insert(int, T const&);
     * \brief   Metoda wstawiania elementu do pojemnika. Wstawiaja obiekt typu T w wybrane miejsce.
     * \param   parameter1  Indeks wybranego miejsca tablicy.
     * \param   parameter2  Obiekt, ktory ma zostac wstawiony w wybrane miejsce.
     * \return  Zwraca true jezeli podane miejsce wstawienia jest prawidlowe, w przeciwnym wypadku
     *          zwraca false.
     */
    bool insert(int, T const&);

    /**
     * \fn  bool aghVector::remove(int);
     * \brief   Metoda usuwajaca wybrany element. Usuwa element na danym miejscu.
     * \param   parameter1  Indeks elementu tablicy, ktory ma zostac usuniety.
     * \return  Zwraca true jezeli
     *          podane miejsce usuniecia jest prawidlowe, w przeciwnym wypadku zwraca false.
     */
    bool remove(int);

    /**
     * \fn  int aghVector::size(void) const;
     * \brief   Metoda zwracajaca ilosc elementow.
     * \return  Zwraca ilosc elementow w pojemniku.
     */
    int size(void) const;

};
// -----------------------------------------------------------------------------------------------





// ---Konstruktory i destruktor-------------------------------------------------------------------

template <class T>
aghVector<T>::aghVector()
{
    rozmiar = delta_roz;    //Nadawanie domyslnych rozmiarow pojemnosci poejmnika
    zajete = 0;
    tab = new T[rozmiar];
}
// -----------------------------------------------------

template <class T>
aghVector<T>::aghVector(const aghContainer<T>& wzor)
{
    rozmiar = delta_roz;    //
    zajete = 0;             //Poczatkowa inicjalizacja zmiennych w celu umozliwienia wlasciwej pracy konstruktora
    tab = new T[rozmiar];   //Konstruktor wywola operator "=", ktory pracuje na zmiennych teraz podanych. W przeciwnym wypadku pracowalby na randomowych wartosciach zmiennych

    this-> operator=(static_cast<const aghVector<T>&> (wzor)); //Wywolanie operatora "=" po uprzednim rzutowaniu obiektu wzor na aghVector
}
// -----------------------------------------------------

template <class T>
aghVector<T>::~aghVector()
{
    rozmiar = 0;
    zajete = 0;
    delete[] tab;   //Zwalnanie pamieci
}
// -----------------------------------------------------




// ---Metody i operator =-------------------------------------------------------------------------

template <class T>
aghContainer<T>& aghVector<T>::operator=(const aghVector<T>& wzor)
{
    return aghContainer<T>::operator=(wzor);    //Wywolanie operatora "=" z klasy bazowej
}
// -----------------------------------------------------

template <class T>
T& aghVector<T>::at(int idx) const
{
    if ((idx < zajete) && (idx >= 0))   //Walidacja poprawnnosci indeksu
        return tab[idx];                //Jezeli wlasciwy, zwroc referencje to elementu tablicy o indeksie "idx"
    else
        throw aghException(0, "Wyjscie poza zakres tablicy", "aghVector.h", 191);   //W przeciwnym razie rzczuc wyjatek
}
// -----------------------------------------------------

template <class T>
bool aghVector<T>::insert(int pozycja, T const& obiekt)
{
    if ((pozycja < 0) || (pozycja > zajete))    //Walidacja poprawnnosci indeksu
        return false;                           //Jezeli bledny, zwroc falsz

    if (zajete == rozmiar)                      //Jezeli pojemnosc pojemnika sie konczy
        resize(delta_roz);                      //Zwieksz ja o "delta_roz"

    rozsun(pozycja);                            //Zrob miejsce dla elementu w miejscu tablicy o indeksie "pozycja"
    tab[pozycja] = obiekt;                      //Wpisz obiekt
    zajete++;                                   //Inkrementuj liczbe obiektow w pojemniku

    return true;                                //Po wykonaniu wszystkich operacji zwroc prawde
}
// -----------------------------------------------------

template <class T>
bool aghVector<T>::remove(int pozycja)
{
    if ((pozycja < 0) || (pozycja > zajete))    //Walidacja poprawnnosci indeksu
        return false;                           //Jezeli bledny, zwroc falsz

    zsun(pozycja);                              //Zwolnij miejsce indeksie "pozycja"
    zajete--;                                   //Dekrementuj liczbe obiektow w pojemniku

    if ((rozmiar - zajete) > delta_roz)         //Jezeli pojemnosc pojemnika jest wieksza, niz "delta_roz"
        resize((-1) * delta_roz);               //Zmniejsz ja o "delta_roz"

    return true;                                //Po wykonaniu wszystkich operacji zwroc prawde
}
// -----------------------------------------------------

template <class T>
int aghVector<T>::size(void) const
{
    return zajete;  //Zwroc liczbe elementow w tablicy
}
// -----------------------------------------------------




// ---Funkcje pomocnicze--------------------------------------------------------------------------

template <class T>
void aghVector<T>::resize(int o_ile)
{
    if ((rozmiar + o_ile) > 0)          //Walidacja podanej roznicy
    {
        aghVector tmp(*this);           //Tworze pomocnicza kopie wektora

        //this -> ~aghVector();         //Blad!!! Nie można wywolywac destruktora, poniewaz pozniejsza praca na obiekcie jest niemozliwa! Program probuje wywolywac funkcje czysto wirtualne
        this-> clear();
        delete[] tab;                   //Zwalnianie pamieci
        rozmiar = tmp.rozmiar + o_ile;  //Przepisanie nowych wymairow
        tab = new T[rozmiar];           //Alokacja pamieci

        for (int i = 0; i < tmp.zajete; i++)
            insert(i, tmp.at(i));       //Przepisanie starych danych
    }
    else
        cout << "Podano zle wymiary" << endl;

}
// -----------------------------------------------------

template <class T>
void aghVector<T>::rozsun(int idx)
{
    for (int i = zajete; i > idx; i--)
        tab[i] = tab[i-1];      //Przepisz wszystkie elementy o jedno miejsce dalej
}
// -----------------------------------------------------

template <class T>
void aghVector<T>::zsun(int idx)
{
    for (int i = idx; i < zajete; i++)
        tab[i] = tab[i+1];      //Przepisz wszystkie elementy o jedno miejce wstecz
}
// -----------------------------------------------------

// -----------------------------------------------------------------------------------------------
#endif // AGHVECTOR_H
