//plik zawierajacy definicje metod klasy aghComplex

#include "aghComplex.h"
#include<iostream>
using namespace std;
// -------------------------------------------------------------------------------
//konstruktor parametrowy (argumenty domyslne 0 i 0)
aghComplex::aghComplex(double x, double y) : re(x), im(y){}

// -------------------------------------------------------------------------------
//funkcja wypisujaca
void aghComplex::print() const{
    cout.width(3);
    if (im != 0) cout << re << "i" << im;
    else cout << re;
}
// -------------------------------------------------------------------------------
//przeladowany operator dodawania
aghComplex aghComplex::operator+ (const aghComplex &y) const{       //skladniki nie beda modyfikowane
    aghComplex suma;
    suma.re = re + y.re;
    suma.im = im + y.im;
    return suma;
}

// -------------------------------------------------------------------------------
//przeladowany operator mnozenia
aghComplex aghComplex::operator* (const aghComplex &y) const{
    aghComplex iloczyn;
    iloczyn.re = re*y.re - im*y.im;
    iloczyn.im = re*y.im + im*y.re;
    return iloczyn;
}
// -------------------------------------------------------------------------------
//przeladowany operator porownania
bool aghComplex::operator== (const aghComplex &y) const{
    if (re == y.re && im == y.im) return true;
    return false;
}
// -------------------------------------------------------------------------------
//przeladowany operator przypisania
aghComplex& aghComplex::operator= (const aghComplex &y){
    if (this == &y) return *this;
    else
    {
        re = y.re;
        im = y.im;
        return *this;
    }
}
// -------------------------------------------------------------------------------
/*
aghComplex& aghComplex::operator= (const int &value)
{
    re = 0;
    im = 0;

    return *this;
}*/
// -------------------------------------------------------------------------------
//przeladowany operator 'rozny od'
bool aghComplex::operator!= (const aghComplex &y) const{
    return !(*this == y);       //wykorzystuje wczesniej zdefiniowany operator porownania
}
