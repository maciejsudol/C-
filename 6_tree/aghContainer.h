/**
* \file aghContainer.h
* \author Maciej Sudol & Pawel Inglot
* \date 24.05.2015
* \version 1.0
* \brief Definicja abstrakcyjnej klasy szablonowej aghContainer, bedacej interfejsem dla innych klas
*/
// ---------------------------------------------------------------------------------------------------
#ifndef AGHCONTAINER_H
#define AGHCONTAINER_H
// -----------------------------------------------------

#include <iostream>
using namespace std;
// -----------------------------------------------------

/**
* \class aghContainer
* \author Maciej Sudol & Pawel Inglot
* \date 24.05.2015
* \brief Definicja abstrakcyjnej klasy szablonowej aghContainer, bedacej interfejsem dla innych klas
*/

template <class T>
class aghContainer
{
public:
// ---Metody czysto wirtualne-------------------------------------------------------------------------

    /// \brief Destruktor
    virtual ~aghContainer() {}
// -----------------------------------------------------

    /**
     * \fn      virtual T& at(int) const = 0;
     *
     * \brief   funkcja czysto wirtualna; podaje, co znajduje sie w danym miejscu pojemnika
     * \param   indeks obiektu z pojemnika, do ktorego chcemy sie odniesc; indeksowanie wartosci rozpoczynamy od zera.
     * \return  referencja do obiektu z pojemnika o danym indeksie
     */
    virtual T& at(int) const = 0;
// -----------------------------------------------------

    /**
     * \fn      virtual bool insert(int, T const&) = 0;
     *
     * \brief   funkcja czysto wirtualna; dodaje element do pojemnika
     * \param   idx - indeks, pod ktorym zostanie wstawiony obiekt
     * \param   obiekt - obiekt do wstawienia
     * \return  true jezeli podane miejsce wstawienia jest prawidlowe, w przeciwnym wypadku false.
     */
    //Metoda wstawiania elementu do pojemnika.
    //Wstawiaja obiekt typu T w wybrane miejsce. Zwraca
    virtual bool insert(int idx, T const& obiekt) = 0;
// -----------------------------------------------------

    /**
     * \fn      virtual bool remove(int) = 0;
     *
     * \brief   funkcja czysto wirtualna; usuwa wybrany element
     * \param   indeks usuwanego elementu
     * \return  true jezeli podane miejsce usuniecia jest prawidlowe, w przeciwnym wypadku false.
     */
    virtual bool remove(int) = 0;
// -----------------------------------------------------

    /**
     * \fn      virtual int size(void) const = 0;
     *
     * \brief   funkcja czysto wirtualna zwracajaca liczbe elementow w pojemniku
     * \return  liczba el. w pojemniku
     */
    virtual int size(void) const = 0;


// ---Pozostale metody--------------------------------------------------------------------------------

    /**
     * \fn      void append(T const&);
     *
     * \brief   //Metoda dodajaca obiekt na koniec pojemnika.
     * \param   referencja do dodawanego obiektu
     */
    //Metoda dodajaca podany jako argument obiekt typu T na koniec pojemnika.
    void append(T const&);
// -----------------------------------------------------

    /**
     * \fn      void clear(void);
     *
     * \brief   metoda usuwajaca wszystkie elementy z pojemnika
     */
    void clear(void);
// -----------------------------------------------------

    /**
     * \fn      bool contains(T const& _value, int _from = 0) const;
     *
     * \brief   Metoda sprawdzajaca czy dany element jest juz w pojemniku.
     * \param   _value - referencja do poszukiwanego obiektu
     * \param   _from - element, od ktorego rozpoczyna sie wyszukiwanie. domyslnie 0;
     * \return      //Zwraca true je¿eli element o wartoœci _value znajduje siê w pojemniku inaczej zwraca false.
     */
    //Metoda sprawdzajaca czy dany element jest ju¿ w pojemniku.
    //Zwraca true je¿eli element o wartoœci _value znajduje siê w pojemniku inaczej zwraca false. Wyszukiwanie rozpoczyna siê od elelmetnu _from.
    bool contains(T const& _value, int _from = 0) const;
// -----------------------------------------------------

    /**
     * \fn      int indexOf(T const& _value, int _from = 0) const;
     *
     * \brief   Metoda wyszukujaca element w pojemniku przez wartosc, od zadanego momentu.
     * \param   _value - referencja do poszukiwanego obiektu
     * \param   _from - element, od ktorego rozpoczyna sie wyszukiwanie. domyslnie 0;
     * \return  indeks poszukiwanego elementu lub -1, gdy nie znaleziono
     */

    int indexOf(T const& _value, int _from = 0) const;
// -----------------------------------------------------

    /**
     * \fn   bool isEmpty(void);
     *
     * \brief   Metoda sprawdzajaca czy pojemnik jest pusty.
     * \return  Zwraca true jezeli pojemnik jest pusty, inaczej false.
     */
    bool isEmpty(void);
// -----------------------------------------------------

    /**
     * \fn          bool replace(int, T const&);
     *
     * \brief   Metoda podmiany elementu w pojemniku.
     * \param   idx - indeks podmienianego elementu
     * \param   obiekt - obiekt do podmiany
     * \return  Zwraca true jezeli podane miejsce podmiany jest prawidlowe, w przeciwnym wypadku zwraca false.
     */
    bool replace(int idx, T const& obiekt);


// ---------------Operatory---------------------------------------------------------------------------------------

    /**
     * \fn     aghContainer<T>& operator=(aghContainer<T> const& right);
     *
     * \brief   Operator przypisania.
     * \brief   Nie jest dziedziczony przez klasy pochodne. Aby funkcjonowal prawidlowo nalezy w klasie pochodnej wywolywac operator z klasy bazowej.
     * \param   ref. do obiektu bedacy wzorem do przypisania
     * \return  ref. do obiektu wynikowego
     */
    aghContainer<T>& operator=(aghContainer<T> const& right);
// -----------------------------------------------------

    /**
     * \fn      bool operator==(aghContainer<T> const& right);
     *
     * \brief   Operator porównania.
     * \param   ref. do obiektu bedacy wzorem do porownania
     * \return  true, gdy obiekty jednakowe; false gdy rozne
     */

    //Sprawdza czy zawartoœæ pojemników jest taka sama.
    bool operator==(aghContainer<T> const& right);
// -----------------------------------------------------

    /**
     * \fn      bool operator!=(aghContainer<T> const& right);
     *
     * \brief   operator nierownosci
     * \param   ref. do obiektu bedacy wzorem do porownania
     * \return  true, gdy obiekty rozne; false gdy jednakowe
     */
    bool operator!=(aghContainer<T> const& right);
// -----------------------------------------------------

    /**
     * \fn      T& operator[](int n) const;
     *
     * \brief   Zwraca element o indeksie n.
     * \param   indeks wybranego elementu
     * \return  referencja do obiektu o wskazanym indeksie
     */
    T& operator[](int n) const;
// -----------------------------------------------------

    /**
     * \fn      aghContainer<T>& operator+=(aghContainer<T> const& right);
     *
     * \brief   Operator +=. Dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this.
     * \param   pojemnik dopisywany do biezacego
     * \return  pojemnik wynikowy
     */
    aghContainer<T>& operator+=(aghContainer<T> const& right);
// -----------------------------------------------------

    /**
     * \fn
     *
     * \brief   Operator +=. Dodaje pojedynczy element do pojemnika i zwraca referencje do this.
     * \param   element do dodania
     * \return  pojemnik wynikowy
     */
    aghContainer<T>& operator+=(T const& element);
// -----------------------------------------------------

    /**
     * \fn      aghContainer<T>& operator<<(T const& element);
     *
     * \brief   Operator +=. Dodaje pojedynczy element do pojemnika i zwraca referencje do this.
     * \param   element do dodania
     * \return  pojemnik wynikowy
     */
    aghContainer<T>& operator<<(T const& element);
// -----------------------------------------------------

    /**
     * \fn      aghContainer<T>& operator<<(aghContainer<T> const& right);
     *
     * \brief   Operator +=. Dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this.
     * \param   pojemnik dopisywany do biezacego
     * \return  pojemnik wynikowy
     */
    aghContainer<T>& operator<<(aghContainer<T> const& right);
// -----------------------------------------------------

    /**
     * \fn      friend ostream& operator<<(ostream& out, aghContainer<T> const& right)
     *
     * \brief   zaprzyjazniona funkcja inline, wypisuje zawartosc pojemnika na strumien.
     * \param   out - strumien wyjsiowy
     * \param   right - referencja do kontenera do wypisania
     * \return  referencja do strumienia wynikowego
     */
    friend ostream& operator<<(ostream& out, aghContainer<T> const& right)
    {
        for (int i = 0; i < right.size(); i++)
        {
            if (i != (right.size() - 1))
                out << right.at(i) << " ";
            else
                out << right.at(i) << endl;
        }
        return out;
    }
};
// ---------------------------------------------------------------------------------------------------



// ----------Implementacja metod klasy--------------------------------------------------------------------------------

template <class T>
void aghContainer<T>::append(T const& obiekt)
{
    insert(size(), obiekt);
}
// -----------------------------------------------------

template <class T>
bool aghContainer<T>::contains(T const& _value, int _from) const
{
    if (indexOf(_value, _from) == -1)
        return false;
    else
        return true;
}
// -----------------------------------------------------

template <class T>
void aghContainer<T>::clear()
{
    while (!(isEmpty()))
        remove(0);
}
// -----------------------------------------------------

template <class T>
int aghContainer<T>::indexOf(T const& _value, int _from) const
{
    for (int idx = _from; idx < size(); idx++)
        if (at(idx) == _value)
            return idx;
    return -1;
}
// -----------------------------------------------------

template <class T>
bool aghContainer<T>::isEmpty()
{
    if (size() == 0)
        return true;
    else
        return false;
}
// -----------------------------------------------------

template <class T>
bool aghContainer<T>::replace(int pozycja, T const& obiekt)
{
    if ((pozycja < 0) || (pozycja > size()))
        return  false;
    else
    {
        remove(pozycja);
        insert(pozycja, obiekt);
        return true;
    }
}
// -----------------------------------------------------




// ---Operatory---------------------------------------------------------------------------------------

template <class T>
aghContainer<T>& aghContainer<T>::operator=(aghContainer<T> const& right)
{
    if (this == &right)                 //jesli oba wskazniki pokazuja na ten sam obiekt, zwroc pierwszy z nich
        return *this;

    clear();
    for (int i = 0; i<right.size(); i++)
        append(right.at(i));
    return *this;
}
// -----------------------------------------------------

template <class T>
bool aghContainer<T>::operator==(aghContainer<T> const& right)
{
    if (this == &right)                                                 //zwroc prawde, jezeli to ten sam obiekt
        return true;

    if (this-> size() != right.size())                                   //zwroc falsz, jezeli rozmiary tablic sie roznia
        return false;

    for (int i = 0; i < size(); i++)
        if (this-> at(i) != right.at(i))                                 //zwroc falsz, jezeli elementy sie roznia
            return false;

    return true;                                                        //w przeciwnym wypadku zwroc prawde
}
// -----------------------------------------------------

template <class T>
bool aghContainer<T>::operator!=(aghContainer<T> const& right)
{
    return (!(this-> operator==(right)));
}
// -----------------------------------------------------

template <class T>
T& aghContainer<T>::operator[](int n) const
{
    return (at(n));
}
// -----------------------------------------------------

template <class T>
aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const& right)
{
    for (int i = 0; i < right.size(); i++)
        append(right[i]);
    return *this;
}
// -----------------------------------------------------

template <class T>
aghContainer<T>& aghContainer<T>::operator+=(T const& element)
{
    append(element);
    return *this;
}
// -----------------------------------------------------

template <class T>
aghContainer<T>& aghContainer<T>::operator<<(T const& element)
{
    this-> operator+=(element);
    return *this;
}
// -----------------------------------------------------

template <class T>
aghContainer<T>& aghContainer<T>::operator<<(aghContainer<T> const& right)
{
    this-> operator+=(right);
    return *this;
}

// ---------------------------------------------------------------------------------------------------
#endif // AGHCONTAINER_H
