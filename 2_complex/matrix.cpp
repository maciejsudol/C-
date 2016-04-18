/**
* \file matrix.cpp
* \author Maciej Sudol & Pawel Inglot
* \date 14.05.2015
* \version 1.0
* \brief Deklaracja specjalizowanych funkcji szablonowych klasy aghMatrix, umozliwiajacej implementacje macierzy dla dowolnego tpypu danych
*/
// -----------------------------------------------------------------------------------------------

#include "matrix.h"
#include <iostream>
using namespace std;
// -------------------------------------------------------------------------------

//szablon funkcji specjalizowanej dla napisow, przeladowujacej operator dodawania
template<>
aghMatrix<char*> aghMatrix<char*>::operator+ (const aghMatrix &to_add) const
{
    if ((rows != to_add.rows) || (columns != to_add.columns))                   //walidacja poprawnosci rozmiarow macierzy
        throw aghException(0, "inadequate matrices sizes", "matrix.cpp", 17);

    else
    {
        aghMatrix<char*> wynik(rows, columns);                                  //storzenie obiektu wynikowego

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                wynik.setItem(i, j, add(matrix[i][j], to_add.matrix[i][j]));    //dodawanie kolejnch elementow

        return wynik;
    }
}
// -------------------------------------------------------------------------------

//szablon funkcji specjalizowanej dla napisow, przeladowujacej operator mnozenia
template<>
aghMatrix<char*> aghMatrix<char*>::operator* (const aghMatrix &to_mul) const
{
    if (columns != to_mul.rows)                                                 //walidacja poprawnosci rozmiarow macierzy
        throw aghException(0, "inadequate matrices sizes", "matrix.cpp", 37);

    else
    {
        aghMatrix<char*> wynik(rows, to_mul.columns);                           //storzenie obiektu wynikowego
        char **tmp_wynik = new char*[columns];                                  //pomocnicza tablica danych przechowujaca taka liczbe elementow
                                                                                //ile wynosi liczba mnozen danych macierzy
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < to_mul.columns; j++)
            {
                for (int k = 0; k < columns; k++)
                    tmp_wynik[k] = mul(matrix[i][k], to_mul.matrix[k][j]);      //pomnoz i wpisz do tablicy danych

                for (int k = 0; k < columns; k++)
                    tmp_wynik[0] = add(tmp_wynik[0], tmp_wynik[k]);             //zsumuj wszystkie napisy w tablicy danych

                wynik.setItem(i, j, tmp_wynik[0]);                              //wpisz napis wynikowy do komorki macierzy o wpolrzednych [i,j]
            }
        delete[] tmp_wynik;                                                     //zwolnij pamiec, ale pozostaw znajdujace sie w niej wskazniki,
                                                                                //ktore znajduja sie teraz w macierzy wynikowej
        return wynik;
    }
}
// -------------------------------------------------------------------------------

//szablon funkcji specjalizowanej dla napisow, przeladowujacej operator porownania
template <>
bool aghMatrix<char*>::operator== (const aghMatrix &wzor) const
{
    if (this == &wzor)                                                  //zwroc prawde, jezeli porownywany obiekt
        return true;                                                    //pokazuje na to samo miejsce w pamieci

    if ((this->rows != wzor.rows) || (this->columns != wzor.columns))   //zwroc falsz, jezeli rozmiary macierzy sie roznia
        return false;

    if ((matrix == NULL) || (wzor.matrix == NULL))                      //zwroc falsz, jezeli jedna, albo druga macierz jest pusta
        return false;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
        {
            int length1 = strlen(matrix[i][j]), length2 = strlen(wzor.matrix[i][j]);    //p=dlugosci napisow
            if (length1 != length2)                                     //zwroc falsz, jezeli dlugosci napisow sie roznia
                return false;

            for (int k = 0; k < length1; k++)
                if (matrix[i][j][k] != wzor.matrix[i][j][k])
                    return false;                                       //zwroc falsz, jezeli kolejne litery sie roznia
        }

    return true;                                                        //w przeciwnych wypadkach zwroc prawde
}
// -------------------------------------------------------------------------------

//szablon funkcji specjalizowanej dla typu znakowego, przeladowujacej operator ()
template <>
char* aghMatrix<char*>::operator() (int r, int c)
{
    if (r<0 || r>rows || c<0 || c>columns)          //walidacja podanych wspolrzednych
        throw aghException(0, "inadequate matrices sizes", "matrix.cpp", 96);

    else
    {
        int length = strlen(matrix[r][c]);          //zapamietaj dlugosc napisu

        char *wynik = new char[length];             //zaalokuj pamiec dla nowego napisu
        for (int i = 0; i < length; i++)
            wynik[i] = matrix[r][c][i];                      //skopiuj napis
        wynik[length] = '\0';                       //zakoncz napis

        return wynik;
    }
}
// -------------------------------------------------------------------------------

//szablon funkcji specjalizowanej dla typu znakowego, przeladowujacej operator dodawania
template<>
aghMatrix<char> aghMatrix<char>::operator+ (const aghMatrix &to_add) const
{
    if (rows != to_add.rows || columns != to_add.columns)       //kontrola zgodnosci rozmiarow
        throw aghException(0, "inadequate matrices sizes", "matrix.cpp", 118);

    else
    {
        aghMatrix<char> wynik(rows, columns);   //stworzenie macierzy na wynik
        for (int i = 0; i<rows; i++)
            for (int j = 0; j<columns; j++)
                wynik.matrix[i][j] = char( ( ( int(matrix[i][j]) + int(to_add.matrix[i][j]) - 194)% 26) + 97 );
                                                //zrzutowanie liter na int i dodanie kodow ASCII
                                                    //odjecie 194, by uzyskac uklad a=0, b=1 ...
                                                        //obliczenie reszty z dzielenia przez 26 (liczba wszystkich znakow)
                                                            //dodanie 97 by powrocic do kodu ASCII i zrzutowanie na char oraz wpisanie do macierzy
        return wynik;
    }
}
// -------------------------------------------------------------------------------

//szablon funkcji specjalizowanej dla typu znakowego, przeladowujacej operator mnozenia
template<>
aghMatrix<char> aghMatrix<char>::operator* (const aghMatrix &mult) const
{
    if (columns != mult.rows)       //kontrola zgodnosci rozmiarow macierzy
    {
        throw aghException(0, "inadequate matrices size", "matrix.cpp", 140);
    }
    else
    {
        aghMatrix<char> wynik(rows, mult.columns);  //stworzenie macierzy na wynik
        for (int i = 0; i<rows; i++)
            for (int j = 0; j<mult.columns; j++)
            {
                wynik.matrix[i][j] = 'a';           //wypelniam macierz literami 'a', ktore symbolizuja zera (bo ponizej odejmujemy 97)
                for (int k = 0; k<columns; k++)
                    wynik.matrix[i][j] = char( ((int(wynik.matrix[i][j])-97 + ((int(matrix[i][k])-97) * (int(mult.matrix[k][j])-97))) % 26) + 97);
            }                               //sumowanie kolejnych iloczynow, zgodniez regulami mnozenia macierzy
                                                //reszta procedury analogiczna do dodawania (patrz wyzej)
        return wynik;
    }
}
// -------------------------------------------------------------------------------

// szablon funkcji specjalizowanej dla typu znakowego, umozliwiajacej przeslanie zmiennej liczby argumentow
// koniecznosc specjalizacji wynika z tego, ze w przypadku funkcji va_arg char jest domyslnie konwertowany do inta
// wiec nie mozna go bezposrednio przekazac
template <>
void aghMatrix<char>::setItems(int r, int c, ...)
{
    resize(r, c);                   //zmiana rozmiarow
    int counter = r*c;
    int _rows = 0, _columns = 0;    //zmienne pomocnicze, do kontroli liczby argumentow

    va_list values;
    va_start(values, c);
    for (int i = 0; i < counter; i++)
    {
        if ((_rows < rows) && (_columns < columns))         //dopoki nr wiersza/kolumny mniejszy od wymiarow macierzy
        {
            matrix[_rows][_columns] = va_arg(values, int);  //!!!!!!!!!! tu nie moga byc przekazane zmienne typu char
            _columns++;                                     //zapisuj w kolejnych komorkach wiersza
        }

        else
        {
            _rows++;                                        //w przeciwnym razie zmien wiersz
            _columns = 0;
            matrix[_rows][_columns] = va_arg(values, int);
            _columns++;
        }
    }
    va_end(values);
}
// -------------------------------------------------------------------------------

//specjalizowany konstruktor kopiujacy dla char* (w celu unikniêcia wskazywania na to samo miejsce w pamiêci przez now¹ macierz i wzorcow¹ macierz)
template <>
aghMatrix<char*>::aghMatrix(const aghMatrix &prototype)
{
    rows = prototype.rows;
    columns = prototype.columns;

    matrix = new char**[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new char*[columns];

        for (int j = 0; j < columns; j++)
        {
            int length = strlen(prototype.matrix[i][j]);
            matrix[i][j] = new char[length+1];      //rezerwacja odpowiedniej ilosci pamieci na wyraz i znak koncowy
            for (int k=0; k<length; k++)
                matrix[i][j][k] = prototype.matrix[i][j][k];    //skopiowanie kolejnych liter
            matrix[i][j][length] = '\0';            //zakonczenie wyrazu
        }

    }
}
