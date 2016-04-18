/**
* \file    aghDlist.h
* \author  Maciej Sudol & Pawel Inglot
* \date    2015-05-25
* \brief   Deklaracja i definicja szablonowej klasy aghDlist, umozliwiajacej implementacje pojemnika listowego dwukierunkowego na dane.
*/
// -----------------------------------------------------------------------------------------------

#ifndef AGHDLIST_H
#define AGHDLIST_H
// -----------------------------------------------------

#include "aghContainer.h"
#include "aghException.h"
#include "node.h"
// -----------------------------------------------------



/**
* \class   aghdlist
* \brief   Deklaracja szablonowej klasy aghDlist.
* \tparam  T   Typ parametryczny.
*/
template <class T>
class aghDlist :public aghContainer<T>
{
public:

// --- Konstruktory i destruktor -----------------------------------------------------------------

    /**
     * \fn  aghDlist::aghDlist();
     * \brief   Konstruktor bezparametrowy.
     */
    aghDlist();

    /**
     * \fn  aghDlist::aghDlist(const aghContainer<T>& source);
     * \brief   Konstruktor kopiujacy.
     * \brief   Obsluguje zarono argumenty typu aghVector, jak rowniez aghContainer.
     * \param   source  Obiekt zrodlowy.
     */
    aghDlist(const aghContainer<T>& source);

    /**
     * \fn  aghDlist::~aghDlist();
     * \brief   Destruktor.
     */
    ~aghDlist();


// --- Metody i operator = -----------------------------------------------------------------------

    /**
     * \fn  aghContainer<T>& aghDlist::operator=(const aghDlist<T>& source);
     * \brief   Operator przypisania. Operator przywoluje obsluge operatora = z klasy bazowej.
     * \param   source  Obiekt zrodlowy.
     * \return  Kopia obiektu podanego jako parametr konstruktora.
     */
    aghContainer<T>& operator=(const aghDlist<T>& source);

    /**
     * \fn  T& aghDlist::at(int idx) const;
     * \brief   Metoda zwracajaca wartosc elementu. Zwraca wartosc w pojemniku. Zakladamy ze
     *          indeksowanie wartosci rozpoczynamy od zera.
     * \param   idx Indeks wybranego miejsca tablicy.
     * \return  Referencja do wybranego elementu w tablicy.
     */
    T& at(int idx) const;

    /**
     * \fn  bool aghDlist::insert(int idx, T const& source);
     * \brief   Metoda wstawiania elementu do pojemnika. Wstawiaja obiekt typu T w wybrane miejsce.
     * \param   idx     Indeks wybranego miejsca tablicy.
     * \param   source  Obiekt, ktory ma zostac wstawiony w wybrane miejsce.
     * \return  Zwraca true jezeli podane miejsce wstawienia jest prawidlowe, w przeciwnym wypadku
     *          zwraca false.
     */
    bool insert(int idx, T const& source);

    /**
     * \fn  bool aghDlist::remove(int idx);
     * \brief   Metoda usuwajaca wybrany element. Usuwa element na danym miejscu.
     * \param   idx Indeks elementu tablicy, ktory ma zostac usuniety.
     * \return  Zwraca true jezeli podane miejsce usuniecia jest prawidlowe, w przeciwnym wypadku
     *          zwraca false.
     */
    bool remove(int idx);

    /**
     * \fn  int aghDlist::size(void) const;
     * \brief   Metoda zwracajaca ilosc elementow.
     * \return  Zwraca ilosc elementow w pojemniku.
     */
    int size(void) const;

private:

// --- Zmienne -----------------------------------------------------------------------------------

    /** \brief   Liczba elementow w pojemniku. */
    int counter;

    /** \brief   Wskaznik na poczatek listy. */
    node<T> *head;

    /** \brief   Wskaznik na kkoniec listy. */
    node<T> *tail;


// --- Funkcje pomocnicze ------------------------------------------------------------------------

    /**
     * \fn  node<T>* aghDlist::find_pointer(int idx) const;
     * \brief   Wyszukuje elementu o podanym indeksie.
     * \param   idx Indeks szukanego elementu.
     * \return  Wskaznik do elementu o indeksie "idx".
     */
    node<T>* find_pointer(int idx) const;

};
// -----------------------------------------------------------------------------------------------





// --- Konstruktory i destruktor -----------------------------------------------------------------

template <class T>
aghDlist<T>::aghDlist()
{
    counter = 0;    //Nadawanie domyslnych wartosci pojemnika
    head = NULL;
    tail = NULL;
}
// -----------------------------------------------------

template <class T>
aghDlist<T>::aghDlist(const aghContainer<T>& source)
{
    counter = 0;    //Poczatkowa inicjalizacja zmiennych w celu umozliwienia wlasciwej pracy konstruktora
    head = NULL;    //
    tail = NULL;    //Konstruktor wywola operator "=", ktory pracuje na zmiennych teraz podanych. W przeciwnym wypadku pracowalby na randomowych wartosciach zmiennych

    this-> operator=(static_cast<const aghDlist<T>&> (source)); //Wywolanie operatora "=" po uprzednim rzutowaniu obiektu "source" na aghDlist
}
// -----------------------------------------------------

template <class T>
aghDlist<T>::~aghDlist()
{
    this->clear();        //Zwolneienie pamieci wszystkich elementow pojemnika
    head = NULL;
    tail = NULL;
    counter = 0;
}
// -----------------------------------------------------




// --- Metody i operator = -----------------------------------------------------------------------

template <class T>
aghContainer<T>& aghDlist<T>::operator=(const aghDlist<T>& source)
{
    return aghContainer<T>::operator=(source);    //Wywolanie operatora "=" z klasy bazowej
}
// -----------------------------------------------------

template <class T>
T& aghDlist<T>::at(int idx) const
{
    if ((idx >= 0) && (idx < counter))      //Walidacja poprawnnosci indeksu
        return  find_pointer(idx)->data;                   //Zwrocenie szukanego elementu
    else
        throw aghException(0, "Wyjscie poza zakres");   //Jezeli niewlasciwy, rzczuc wyjatek
}
// -----------------------------------------------------

template <class T>
bool aghDlist<T>::insert(int idx, T const& source)
{
    if ((idx < 0) || (idx > counter))       //Walidacja poprawnnosci indeksu
        return false;                       //Jezeli niewlasciwy, zwroc false

    node<T> *tmp = find_pointer((idx - 1)); //Zmienna pomocnicza
    node<T> *_new = new node<T>;            //Nowa zmienna dopisywana do pojemnika
    _new->data = source;                    //Inicjlizacja zmiennej przzechowywujacej dane

    if (idx != 0)                           //Jezeli nie wstawiamy elementu na poczatku listy
    {
        if (tmp->next != NULL)              //Sprawdz, czy tmp nie jest ostatnim elementem
            tmp->next->previous = _new;     //Jezeli tak, dodaj element noralnie
        else
            tail = _new;                    //W przeciwnym wypadku ustaw "tail" na nowy element

        _new->next = tmp->next;             //
        _new->previous = tmp;               //
        tmp->next = _new;                   //Standardowe zamiany wskaznikow
    }
    else
    {                                       //W przeciwnym wypadku, gdy pojemnik jest pusty
        _new->next = tmp;                   //
        _new->previous = NULL;              //Standardowe zmiany wskaznikow
        head = _new;                        //Ustaw head'a na nowy element

        if (tail == NULL)                   //Jezeli dodsawany element jest pierwszy w pojemniku
            tail = _new;                    //Ustaw tail'a na nowy element

        if (tmp != NULL)                    //Jezeli element o podanym ideksie istnieje
            tmp->previous = _new;           //Ustaw jego poprzednik na nowy element
    }

    counter++;                              //Inkrementuj liczbe elementow pojemnika
    return true;                            //Po wykonanych operacjach zwroc prawde
}
// -----------------------------------------------------

template <class T>
bool aghDlist<T>::remove(int idx)
{
    if ((idx < 0) || (idx >= counter))              //Walidacja poprawnnosci indeksu
        return false;                               //Jezeli niewlasciwy, zwroc false

    node<T> *tmp;                                   //Zmienna pomocnicza
    if (idx != 0)                                   //Jezeli nie usuwamy elementu z poczatku listy
    {
        tmp = find_pointer(idx);                    //Znajdz szukany element

        tmp->previous->next = tmp->next;            //Standardowe zamiany wskaznikow
        if (tmp->next != NULL)                      //Jezeli szuakny element nie jest ostatnim w pojemniku
            tmp->next->previous = tmp->previous;    //Standardowe zamiany wskaznikow
        else
            tail = tmp->previous;                   //W przeciwnym wypadku, ustaw tail'a na przedostatni element pojemnika

        delete tmp;                                 //Usun szuakny element
    }
    else
    {                                               //Jezeli usuwamy element z poczatku listy
        tmp = head;                                 //Ustaw zmienna pomocnicza na head'a

        if (head == tail)                           //Jezeli lista byla pusta, lub zawierala jeden element
        {
            head = NULL;                            //
            tail = NULL;                            //Standardowe zamiany wskaznikow
        }
        if (head != NULL)                           //Sprawdz, czy head nie jest pusty
            head = head->next;                      //Jezeli prawda, nowym head'em jest jego nastepnik

        delete tmp;                                 //Usun szukany element

    }

    counter--;                                      //Dekrementuj liczbe elementow w pojemniku
    return true;                                    //Po wykonanyvh operacjach zwroc prawde
}
// -----------------------------------------------------

template <class T>
int aghDlist<T>::size(void) const
{
    return counter; //Zwroc liczbe elementow w pojemniku
}
// -----------------------------------------------------




// --- Funkcje pomocnicze ------------------------------------------------------------------------

template <class T>
node<T>* aghDlist<T>::find_pointer(int idx) const
{
    node<T> *result;                                //Zmienna pomocnicza
    if (idx <= (counter / 2))                       //Warunek optymalizujacy
    {                                               //Jezeli prawda, poszukiwania elementu zacznij od poczatku listy
        result = head;
        for (int i = 0; i < idx; i++)
            result = result->next;
    }
    else
    {                                               //Jezeli falsz, poszukiwania elementu zacznij od konca listy
        result = tail;
        for (int i = (counter - 1); i > idx; i--)
            result = result->previous;
    }

    return result;                                  //Zwroc wskaznik do szukanego elemntu
}
// -----------------------------------------------------

// -----------------------------------------------------------------------------------------------
#endif  //AGHDLIST_H
