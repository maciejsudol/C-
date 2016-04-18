/**
* \file aghComplex.h
* \author Maciej Sudol & Pawel Inglot
* \date 14.05.2015
* \version 1.0
* \brief Definicja klasy aghComplex, przechowujacej liczby zespolone
*/


#ifndef aghComplex_H
#define aghComplex_H

// -------------------------------------------------------------------------------
/**
* \class aghComplex
* \author Maciej Sudol & Pawel Inglot
* \date 14.05.2015
* \brief Klasa do przechowywania liczb zespolonych
*/

class aghComplex{
private:
    double  re,     ///< czesc rzeczywista
            im;     ///< czesc zespolona

public:
    ///\brief konstruktor parametrowy klasy, zawierajacy argumenty domyslne
    ///
    /// \param re - czesc rzeczywista (domyslnie 0)
    /// \param im - czesc urojona (domyslnie 0)
    aghComplex(double re = 0, double im = 0);

    /// \brief funkcja wypisujaca na ekran
    ///
    /// \return void
    void print() const;

    /// \brief przeladowany operator dodawania liczb zespolonych
    ///
    /// \param y - referencja do obiektu klasy aghComplex zawierajacego drugi skladnik sumy
    /// \return obiekt klasy aghComplex reprezentujacy sume liczb zespolonych
    aghComplex operator+ (const aghComplex &y) const;

    /// \brief przeladowany operator mnozenia liczb zespolonych
    ///
    /// \param y - referencja do obiektu klasy aghComplex zawierajacego drugi czynnik iloczynu
    /// \return obiekt klasy aghComplex reprezentujacy iloczyn liczb zespolonych
    aghComplex operator* (const aghComplex &y) const;

    /// \brief przeladowany operator przypisania dla klasy aghComplex
    ///
    /// \param y - referencja do obiektu klasy aghComplex, ktory ma posluzyc jako wzor
    /// \return referencja do obiektu klasy aghComplex z nowa wartoscia
    aghComplex& operator= (const aghComplex &y);
/*
    /// \brief przeladowany operator przypisania dla klasy aghComplex, ktory przypisuje wartosci poczatkowe
    ///
    /// \param y - referencja do obiektu klasy aghComplex, ktory ma posluzyc jako wzor
    /// \return referencja do obiektu klasy aghComplex z nowa wartoscia
  //  aghComplex& operator= (const int &value);
  */

    /// \brief przeladowany operator porownania dla klasy aghComplex
    ///
    /// \param y - referencja do obiektu klasy aghComplex, ktory ma posluzyc do porownania
    /// \return true gdy obiekty maja rowne wartosci rzeczywiste i urojone; w przeciwnym razie false
    bool operator== (const aghComplex &y) const;

    /// \brief przeladowany operator 'rozny od' dla klasy aghComplex
    ///
    /// \param y - referencja do obiektu klasy aghComplex, ktory ma posluzyc do porownania
    /// \return true gdy obiekty maja roznia sie wartoscia rzeczywista lub urojona; w przeciwnym razie false
    bool operator!= (const aghComplex &y) const;
};


// -------------------------------------------------------------------------------
#endif // aghComplex_H
