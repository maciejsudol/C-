/**
* \file    branch.h
* \author  Maciej Sudol & Pawel Inglot
* \date    2015-05-30
* \brief   Deklaracja i definicja szablonowej klasy branch, umozliwiajacej implementacje elementu przechowujacego dane.
*/
// -----------------------------------------------------------------------------------------------

#ifndef BRANCH_H
#define BRANCH_H
// -----------------------------------------------------

template <class T>      //deklaracja szablonu klasy umozliwiaja jej
class aghTree;         //pozniejsze wykorzystanie jako przyjaciel klasy branch

/**
 * \class   branch
 * \brief   Deklaracja szablonowej klasy branch.
 * \tparam  T   Typ parametryczny.
 */
template <class T>
class branch
{
private:

    friend class aghTree<T>;       //deklaracja przyjazni

    // --- Zmienne -----------------------------------------------------------------------------------

    /** \brief   Zmienna przechowujaca dane. */
    T data;

    /** \brief   Wskaznik do "lewego" elemntu pojemnika. */
    branch *left;

    /** \brief   Wskaznik do "prawego" elementu pojemnika. */
    branch *right;

public:

    // --- Konstruktory i destruktor -----------------------------------------------------------------

    /**
     * \fn  branch::branch();
     * \brief   Konstruktor bezparametrowy.
     */
    branch();

    /**
     * \fn  branch::~branch();
     * \brief   Destruktor.
     */
    ~branch();

};
// -----------------------------------------------------------------------------------------------





// --- Konstruktory i destruktor -----------------------------------------------------------------

template <class T>
branch<T>::branch()
{
    left = NULL;
    right = NULL;
}
// -----------------------------------------------------

template <class T>
branch<T>::~branch()
{
    left = NULL;
    right = NULL;
}
// -----------------------------------------------------

// -----------------------------------------------------------------------------------------------
#endif  //BRANCH_H
