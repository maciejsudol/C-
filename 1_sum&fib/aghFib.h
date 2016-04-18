/**
* \file aghFib.h
* \author Pawel Inglot & Maciej Sudol
* \date 29.04.2015
* \version 1.0
* \brief Plik naglowkowy klasy generujacej wyrazy ciagu Fibonacciego
*/
// -------------------------------------------------------------------------

#ifndef AGHFIB_H
#define AGHFIB_H
#include <iostream>

// -------------------------------------------------------------------------
/**
* \class aghFib
* \author Pawel Inglot & Maciej Sudol
* \date 29.04.2015
* \brief Klasa generujaca wybrany wyraz ciagu Fibonacciego
*/
class aghFib{
    private:
        int *tab;   ///< wskaznik do przechowywania tablicy, w ktorej beda obliczane kolejne wyrazy ciagu Fibonacciego
    public:
        /// \brief konstruktor domyslny klasy
        aghFib();
        /// \brief destruktor klasy
        ~aghFib();
        ///
        /// \brief Przeladowany operator [] obliczajacy dany wyraz ciagu Fibonacciego
        ///
        /// \param idx - indeks wybranego wyrazu ciagu Fibonacciego
        /// \return - zwracany (int) wybrany wyraz ciagu Fibonacciego
        ///
        int operator [](int idx);
};
// -------------------------------------------------------------------------
#endif
