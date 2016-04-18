/**
* \file    node.h
* \author  Maciej Sudol & Pawel Inglot
* \date    2015-05-25
* \brief   Deklaracja i definicja szablonowej klasy node, umozliwiajacej implementacje elementu przechowujacego dane.
*/
// -----------------------------------------------------------------------------------------------

#ifndef NODE_H
#define NODE_H
// -----------------------------------------------------

template <class T>      //deklaracje szablonow klas umozliwiaja ich
class aghDlist;         //pozniejsze wykorzystanie jako przyjaciol klasy node

template <class T>
class aghSlist;

/**
 * \class   node
 * \brief   Deklaracja szablonowej klasy node.
 * \tparam  T   Typ parametryczny.
 */
template <class T>
class node
{
private:

    friend class aghDlist<T>;       //deklaracje przyjazni
    friend class aghSlist<T>;

// --- Zmienne -----------------------------------------------------------------------------------

    /** \brief   Zmienna przechowujaca dane. */
    T data;

    /** \brief   Wskaznik do poprzedniego elemntu pojemnika. */
    node *previous;

    /** \brief   Wskaznik do nastepnego elementu pojemnika. */
    node *next;

public:

// --- Konstruktory i destruktor -----------------------------------------------------------------

    /**
     * \fn  node::node();
     * \brief   Konstruktor bezparametrowy.
     */
    node();

    /**
     * \fn  node::~node();
     * \brief   Destruktor.
     */
    ~node();

};
// -----------------------------------------------------------------------------------------------





// --- Konstruktory i destruktor -----------------------------------------------------------------

template <class T>
node<T>::node()
{
    previous = NULL;
    next = NULL;
}
// -----------------------------------------------------

template <class T>
node<T>::~node()
{
    previous = NULL;
    next = NULL;
}
// -----------------------------------------------------

// -----------------------------------------------------------------------------------------------
#endif  //NODE_H
