/**
* \file    aghSlist.h
* \author  Maciej Sudol & Pawel Inglot
* \date    2015-05-25
* \brief   Deklaracja i definicja szablonowej klasy aghSlist, umozliwiajacej implementacje pojemnika listowego jednokierunkowego na dane.
*/
// -----------------------------------------------------------------------------------------------

#ifndef AGHSLIST_h
#define AGHSLIST_h
// -----------------------------------------------------

#include "aghContainer.h"
#include "aghException.h"
#include "node.h"
// -----------------------------------------------------



/**
 * \class   aghSlist
 * \brief   Deklaracja szablonowej klasy aghSlist.
 * \tparam  T   Typ parametryczny.
 */
template <class T>
class aghSlist : public aghContainer<T>
{
public:

// ---Konstruktory i destruktor-------------------------------------------------------------------

    /**
     * \fn  aghSlist::aghSlist();
     * \brief   Konstruktor bezparametrowy.
     */
    aghSlist();

    /**
     * \fn  aghSlist::aghSlist(const aghContainer<T>& source);
     * \brief   Konstruktor kopiujacy.
     * \brief   Obsluguje zarono argumenty typu aghVector, jak rowniez aghContainer.
     * \param   source  Obiekt zrodlowy.
     */
    aghSlist(const aghContainer<T>& source);

    /**
     * \fn  aghSlist::~aghSlist();
     * \brief   Destruktor.
     */
    ~aghSlist();


// ---Metody i operator =-------------------------------------------------------------------------

    /**
     * \fn  aghContainer<T>& aghSlist::operator=(const aghSlist<T>& source);
     * \brief   Operator przypisania. Operator przywoluje obsluge operatora = z klasy bazowej.
     * \param   source  Obiekt zrodlowy.
     * \return  Kopia obiektu podanego jako parametr konstruktora.
     */
    aghContainer<T>& operator=(const aghSlist<T>& source);

    /**
     * \fn  T& aghSlist::at(int idx) const;
     * \brief   Metoda zwracajaca wartosc elementu. Zwraca wartosc w pojemniku. Zakladamy ze
     *          indeksowanie wartosci rozpoczynamy od zera.
     * \param   idx Indeks wybranego miejsca tablicy.
     * \return  Referencja do wybranego elementu w tablicy.
     */
    T& at(int idx) const;

    /**
     * \fn  bool aghSlist::insert(int idx, T const& source);
     * \brief   Metoda wstawiania elementu do pojemnika. Wstawiaja obiekt typu T w wybrane miejsce.
     * \param   idx     Indeks wybranego miejsca tablicy.
     * \param   source  Obiekt, ktory ma zostac wstawiony w wybrane miejsce.
     * \return  Zwraca true jezeli podane miejsce wstawienia jest prawidlowe, w przeciwnym wypadku
     *          zwraca false.
     */
    bool insert(int idx, T const& source);

    /**
     * \fn  bool aghSlist::remove(int idx);
     * \brief   Metoda usuwajaca wybrany element. Usuwa element na danym miejscu.
     * \param   idx Indeks elementu tablicy, ktory ma zostac usuniety.
     * \return  Zwraca true jezeli podane miejsce usuniecia jest prawidlowe, w przeciwnym wypadku
     *          zwraca false.
     */
    bool remove(int idx);

    /**
     * \fn  int aghSlist::size(void) const;
     * \brief   Metoda zwracajaca ilosc elementow.
     * \return  Zwraca ilosc elementow w pojemniku.
     */
    int size(void) const;

private:
// --- pola skladowe -----------------------------------------------------------------------------------

    /** \brief   Wskaznik na poczatek listy. */
    node<T> *head;

    /** \brief   Liczba elementow w pojemniku. */
    int counter;

// --- Funkcje pomocnicze ------------------------------------------------------------------------

    /**
     * \fn  node<T>* aghSlist::find_pointer(int idx) const;
     * \brief   Wyszukuje wezel o podanym indeksie.
     * \param   idx Indeks szukanego elementu.
     * \return  Wskaznik do wezla o indeksie "idx".
     */
    node<T>* find_pointer(int idx) const;

};
// -----------------------------------------------------------------------------------------------





// ---Konstruktory i destruktor-------------------------------------------------------------------

template <class T>
aghSlist<T>::aghSlist()
{
    counter = 0;    //Nadawanie domyslnych wartosci pojemnika
    head = NULL;
}
// -----------------------------------------------------

template <class T>
aghSlist<T>::aghSlist(const aghContainer<T>& source)
{
    head = NULL;
    counter = 0;

    this-> operator=(static_cast<const aghSlist<T>&> (source));
}
// -----------------------------------------------------

template <class T>
aghSlist<T>::~aghSlist()
{
    this->clear();
    head = NULL; //czy to konieczne?
}
// -----------------------------------------------------




// ---Metody i operator =-------------------------------------------------------------------------

template <class T>
aghContainer<T>& aghSlist<T>::operator=(const aghSlist<T>& source)
{
    return aghContainer<T>::operator=(source);    //Wywolanie operatora "=" z klasy bazowej
}
// -----------------------------------------------------

template <class T>
T& aghSlist<T>::at(int idx) const
{
    if ((idx>=0) && (idx < counter))    //Walidacja poprawnnosci indeksu
        return find_pointer(idx)->data;       //Jezeli wlasciwy, zwroc referencje to elementu listy o indeksie "idx"
    else
        throw aghException(0, "Wyjscie poza zakres");   //wyjatek, gdy niewlasciwy indeks
}
// -----------------------------------------------------

template <class T>
bool aghSlist<T>::insert(int idx, T const& source)
{
    if ((idx < 0) || (idx > counter))
        return false;

    node<T>* nowy = new node<T>;
    nowy->data = source;
    counter++;

    if (head == NULL)       //jesli lista jest pusta
    {
        nowy->next = NULL;
        head = nowy;
        return true;
    }

    if (idx == 0)           //jesli dodajemy na poczatek niepustej listy
    {
        nowy->next = head;
        head = nowy;
        return true;
    }
                                        //pozostale przypadki
    node<T>* tmp = find_pointer(idx-1);    //wyszukuje element o 1 mniejszy niz indeks do wstawienia, aby miec mozliwosc ustawienia wskaznikow
    nowy->next = tmp->next;
    tmp->next = nowy;

    return true;
}
// -----------------------------------------------------

template <class T>
bool aghSlist<T>::remove(int idx)
{
    if ((idx < 0) || (idx >= counter))
        return false;

    counter--;

    if (head->next == NULL)     //jesli usuwam jedyny element listy
    {
        delete head;
        head = NULL;
        return true;
    }

    if (idx == 0)               //jesli usuwam pierwszy, lecz niejedyny element listy
    {
        node<T>* tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }

    node<T>* tmp = find_pointer(idx-1);
    node<T>* tmp2 = tmp->next;
    tmp->next = tmp2->next;
    delete tmp2;
    return true;
}
// -----------------------------------------------------

template <class T>
int aghSlist<T>::size(void) const
{
    return counter; //Zwroc liczbe elementow w pojemniku
}

// --- Funkcje pomocnicze ------------------------------------------------------------------------

template <class T>
node<T>* aghSlist<T>::find_pointer(int idx) const
{
    node<T> *result = head;         //Zmienna pomocnicza
    for (int i = 0; i < idx; i++)
        result = result->next;

    return result;                  //Zwroc wskaznik do szukanego elemntu
}
// -----------------------------------------------------

// -----------------------------------------------------------------------------------------------
#endif  //AGHSLIST_h
