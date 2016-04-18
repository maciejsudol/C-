/**
* \file matrix.h
* \author Maciej Sudol & Pawel Inglot
* \date 14.05.2015
* \version 1.0
* \brief Definicja szablonowej klasy aghMatrix, umozliwiajacej implementacje macierzy dla dowolnego tpypu danych
*/
// -----------------------------------------------------------------------------------------------

#ifndef matrix_h
#define matrix_h
// -----------------------------------------------------------------------------------------------

#include <stdarg.h>
#include "aghException.h"
#include <iostream>
#include <string.h>
using namespace std;
// -----------------------------------------------------------------------------------------------

/**
* \class aghMatrix
* \author Maciej Sudol & Pawel Inglot
* \date 14.05.2015
* \brief Definicja szablonowej klasy aghMatrix, umozliwiajacej implementacje macierzy dla dowolnego tpypu danych
*/
template <class typ>
class aghMatrix
{
public:

    /// \brief Konstruktor domyslny
    aghMatrix();

    /// \brief Konstruktor klasy
    ///
    /// \param r - liczba wierszy
    /// \param c - liczba kolumn
    aghMatrix(int r, int c);

    /// \brief Konstruktor kopiujacy
    ///
    /// \param prototype - obiekt zrodlowy
    aghMatrix(const aghMatrix &prototype);

    /// \brief Destruktor klasy
    ~aghMatrix();


    /**
     * \fn  void aghMatrix::setItem(int r, int c, typ data);
     *
     * \brief   Wpisuje podana wartosc do komorki macierzy o wsppolrzednych [r,c].
     *
     * \author  Maciej Sudol & Pawel Inglot
     * \date    2015-05-14
     *
     * \param   r       - wiersz.
     * \param   c       - kolumna.
     * \param   data    - dane.
     *
     * ### return   Nie zwraca wartosci.
     */
    void setItem(int r, int c, typ data);

    /**
     * \fn  void aghMatrix::setItems(typ *data);
     *
     * \brief   WypeÂ³nia macierz podanymi danymi.
     *
     * \author  Maciej Sudol & Pawel Inglot
     * \date    2015-05-14
     *
     * \param   *data   - wskaznik do  tablicy z danymi.
     */
    void setItems(typ *data);

    /**
     * \fn  void aghMatrix::setItems(int r, int c, ...);
     *
     * \brief   WypeÂ³nia macierz podanymi danymi.
     *
     * \author  Maciej Sudol & Pawel Inglot
     * \date    2015-05-14
     *
     * \param   r   - liczba wierszy.
     * \param   c   - liczba kolumn.
     * \param   ... - dane.
     */
    void setItems(int r, int c, ...);

    /**
     * \fn  void aghMatrix::print();
     *
     * \brief   Wyswietla zawartosc macierzy na ekranie.
     *
     * \author  Maciej Sudol & Pawel Inglot
     * \date    2015-05-14
     */
    void print();


    /**
     * \fn  aghMatrix aghMatrix::&operator= (const aghMatrix &wzor);
     *
     * \brief   Operator przypisania.
     *
     * \author  Maciej Sudol & Pawel Inglot
     * \date    2015-05-14
     *
     * \param   wzor    Obiekt zrodlowy.
     *
     * \return  Kopia obiektu.
     */
    aghMatrix &operator= (const aghMatrix &wzor);

    /**
     * \fn  aghMatrix aghMatrix::operator+ (const aghMatrix &y) const;
     *
     * \brief   Operator dodawania.
     *
     * \author  Maciej Sudol & Pawel Inglot
     * \date    2015-05-14
     *
     * \param   y   Obiekt z ktorym ma byc zsumowany obiekt, dla ktorego wywolano funkcje.
     *
     * \return  Obiekt wynikowy.
     */
    aghMatrix operator+ (const aghMatrix &y) const;

    /**
     * \fn  aghMatrix aghMatrix::operator* (const aghMatrix &y) const;
     *
     * \brief   Operator mnozenia.
     *
     * \author  Maciej Sudol & Pawel Inglot
     * \date    2015-05-14
     *
     * \param   y   Obiekt, ktory jest moznikiem obiektu, dla ktorego wywolano funkcje.
     *
     * \return  Obiekt wynikowy.
     */
    aghMatrix operator* (const aghMatrix &y) const;

    /**
     * \fn  bool aghMatrix::operator== (const aghMatrix &wzor) const;
     *
     * \brief   Operator porownania.
     *
     * \author  Maciej Sudol & Pawel Inglot
     * \date    2015-05-14
     *
     * \param   wzor    Obiekt, z ktorym porownywany jest obiekt.
     *
     * \return  Prawda lub falsz.
     */
    bool operator== (const aghMatrix &wzor) const;

    /**
     * \fn  bool aghMatrix::operator!= (const aghMatrix &wzor) const
     *
     * \brief   Operator ro¿nicowy.
     *
     * \author  Maciej Sudol & Pawel Inglot
     * \date    2015-05-14
     *
     * \param   wzor    Obiekt, z ktorym porownywany jest obiekt.
     *
     * \return  Prawda lub falsz.
     */
    bool operator!= (const aghMatrix &wzor) const { return !(*this == wzor); }

    /**
     * \fn  typ aghMatrix::operator() (int r, int c);
     *
     * \brief   Operator ().
     *
     * \author  Maciej Sudol & Pawel Inglot
     * \date    2015-05-14
     *
     * \param   r   Numer wiersza.
     * \param   c   Numer kolumny.
     *
     * \return  Zwraca zawartosc komorki macierzy o wspolrzednych [r,c].
     */
    typ operator() (int r, int c);

// -----------------------------------------------------------------------------------------------
private:

    int rows;       //<Prechowuje liczbe wierszyz macierzy
    int columns;    //<Przechowuje liczbe kolumn macierzy
    typ **matrix;   //< Przechowuje dwuwymiarowa tablice, implementujaca macierz

    /// \brief Zmienia wymiary macierzy na podane w parametrach
    ///
    //  \param r - nowa liczba wierszy
    //  \param c - nowa liczba kolumn
    /// \return Nie zwraca wartosci
    void resize(int r, int c);

    /// \brief Skleja napisy wybierajac wystepujace w jednym lub drugim lancuchucuchu litery
    ///
    //  \param *tmp1 - pierwszy argument sumy
    //  \param *tmp2 - drugi argument sumy
    /// \return Zwraca wskaznik do powstalego lancucha
    char *add(char *tmp1, char *tmp2) const;

    /// \brief Skleja napisy wybierajac wystepujace w obu lancuchach litery
    ///
    //  \param *tmp1 - pierwszy argument sumy
    //  \param *tmp2 - drugi argument sumy
    /// \return Zwraca wskaznik do powstalego lancucha
    char *mul(char *tmp1, char *tmp2) const;
};




//---Konstruktory i destruktor----------------------------------------------------------------

template <class typ>
aghMatrix<typ>::aghMatrix()
{
    rows = 0;
    columns = 0;
    matrix = NULL;
}
// -------------------------------------------------------------------------------

template <class typ>
aghMatrix<typ>::aghMatrix(int r, int c)
{
    if ((r >= 0) && (c >= 0))     //walidacja podanych wymiarow
    {
        rows = r;
        columns = c;

        matrix = new typ*[rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new typ[columns];
    }

    else
    {
        rows = 0;
        columns = 0;
        matrix = NULL;

        cout << "Nie udalo sie utworzyc macierzy, bledne wymiary" << endl;
    }
}
// -------------------------------------------------------------------------------

template <class typ>
aghMatrix<typ>::aghMatrix(const aghMatrix &prototype)
{
    rows = prototype.rows;
    columns = prototype.columns;

    matrix = new typ*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new typ[columns];

        for (int j = 0; j < columns; j++)
            matrix[i][j] = prototype.matrix[i][j];
    }
}
// -------------------------------------------------------------------------------

template <class typ>
aghMatrix<typ>::~aghMatrix()
{
    if (matrix != NULL)     //destruktor uruchamiany tylko w przypadku, gdy macierz nie jest pusta
    {
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;

        matrix = NULL;
    }
}
// -------------------------------------------------------------------------------




//---setItem/s--------------------------------------------------------------------------------

template <class typ>
void aghMatrix<typ>::setItem(int r, int c, typ data)
{
    if ((r >= 0) && (c >= 0))         //walidacja podanych rozmiarow
    {
        if (matrix != NULL)         //warunek zapobiegajacy naruszeniu pamieci
            matrix[r][c] = data;
    }

    else
        cout << "Nie udalo sie wypelnic podanego elementu, bledne wspolrzedne" << endl;

}
// -------------------------------------------------------------------------------

template <class typ>
void aghMatrix<typ>::setItems(typ *data)
{
    if (data != NULL)                                   //sprawdzamy, czy tablica nie jest pusta
    {
        int _rows = 0, _columns = 0;                    //pomocnicze zmienne iteracyjne
        for (int i = 0; i < (rows*columns); i++)        //petla dla (r*c) elementow
        {
            if ((_rows < rows) && (_columns < columns)) //dopoki nr wiersza/kolumny mniejszy od wymiarow macierzy
            {
                matrix[_rows][_columns] = data[i];
                _columns++;                             //zapisuj w kolejnych komorkach wiersza
            }
            else
            {
                _rows++;                                //w przeciwnym razie zmien wiersz
                _columns = 0;                           //rozpoczynamy iterowanie _columns od poczatku
                matrix[_rows][_columns] = data[i];
                _columns++;
            }
        }
    }

    else
        cout << "Nie udalo sie wypelnic macierzy, tablica danych nie istnieje" << endl;

}
// -------------------------------------------------------------------------------

template <class typ>
void aghMatrix<typ>::setItems(int r, int c, ...)
{
    if ((r >= 0) && (c >= 0))                                   //walidacja podanych wymiarow
    {
        resize(r, c);                                           //zmiana wymiarow
        int counter = r*c;                                      //pomocnicze zmienne
        int _rows = 0, _columns = 0;                            //pomocnicze zmienne

        va_list values;                                         //typ przechowujacy informacje o zmiennych argumentach
        va_start(values, c);                                    //inicjalizacja listy zmiennych argumentow
        for (int i = 0; i < counter; i++)
        {
            if ((_rows < rows) && (_columns < columns))         //dopoki nr wiersza/kolumny mniejszy od wymiarow macierzy
            {
                matrix[_rows][_columns] = va_arg(values, typ);
                _columns++;                                     //zapisuj w kolejnych komorkach wiersza
            }

            else
            {
                _rows++;                                        //w przeciwnym razie zmien wiersz
                _columns = 0;                                   //rozpoczynamy iterowanie _columns od poczatku
                matrix[_rows][_columns] = va_arg(values, typ);
                _columns++;
            }
        }
        va_end(values);                                         //zamkniecie listy zmiennych argumentow
    }

    else
        cout << "Nie udalo sie wypelnic macierzy, bledne wymiary" << endl;
}




//---Metody prywatne--------------------------------------------------------------------------

template <class typ>
void aghMatrix<typ>::resize(int r, int c)
{
    if ((r >= 0) && (c >= 0))               //walidacja pdanych wymiarow
    {
        this -> ~aghMatrix();               //jawne wywo³anie destruktora
        rows = r;                           //wpisanie nowychh wartosci
        columns = c;                        //wpisanie nowych wartosci

        matrix = new typ*[rows];            //dynamiczna alokacja pamieci dla macierzy [r,c]
        for (int i = 0; i < rows; i++)
            matrix[i] = new typ[columns];
    }

    else
    {
        cout << "Podano zle wymiary" << endl;

        this -> ~aghMatrix();
        rows = 0;
        columns = 0;
    }
}
// -------------------------------------------------------------------------------

template <class typ>
void aghMatrix<typ>::print()
{
    if (matrix != NULL)     //sprawdz, czy macierz istnieje
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

    else
        cout << "Macierz nie istnieje" << endl;
}
// -------------------------------------------------------------------------------

template <class typ>
char *aghMatrix<typ>::add(char *tmp1, char *tmp2) const
{
    int length1 = strlen(tmp1), length2 = strlen(tmp2); //pomocnicze zmienne
    char *wynik = new char[(length1 + length2)];        //zmienna wwynikowa
    int position = 0;                                   //pozycja nowej litery
    bool add = true;                                    //pomocnicze zmienne

    for (int k = 0; k < length1; k++)                   //petla dla pierwszego lancucha
    {
        for (int l = 0; l < k; l++)
            if (tmp1[k] == tmp1[l])                     //jezeli litera juz wystapila
            {
                add = false;                            //nie dodawaj
                break;
            }

        if (add)                                        //jezeli add == true dodaj litere do lancucha wynikowego
        {
            wynik[position] = tmp1[k];
            position++;                                 //zmien pozycje nastepnej litery w lancuchu
        }
        add = true;                                     //zmien, aby dopisac nastepna litere do lancucha, jezeli spelnia warunek
    }

    for (int k = 0; k < length2; k++)                   //petla dla drugiego lancucha
    {
        for (int l = 0; l < position; l++)
            if (tmp2[k] == wynik[l])                    //jezeli litera wystepuje w lancuchu wynikowym
            {
                add = false;                            //nie dodawaj
                break;
            }

        if (add)
        {
            wynik[position] = tmp2[k];
            position++;                                 //analogicznie do pierwszej petli
        }
        add = true;                                     //analogicznie do pierwszej petli
    }
    wynik[position] = '\0';                             //wskazujemy, gdzie konczy sie lancuch

    return wynik;
}
// -------------------------------------------------------------------------------

template <class typ>
char *aghMatrix<typ>::mul(char *tmp1, char *tmp2) const
{
    int length1 = strlen(tmp1), length2 = strlen(tmp2), length; //pomocnicze zmienne

    if (length1 < length2)
        length = length1;
    else
        length = length2;                                       //wybieramy krotszy lancuch, poniewaz czesc wspolna zbiorow, to maksymalnie
                                                                //caly mniejszy zbior
    char *wynik = new char[length];                             //zmienna wynikowa
    int position = 0;                                           //pozycja nowej litery
    bool add = false, check = true;                             //pomocnicze zmienne

    for (int k = 0; k < length1; k++)
    {
        for (int l = 0; l < length2; l++)
        {
            for (int m = 0; m < position; m++)
                if (tmp1[k] == wynik[m])
                    check = false;

            if ((tmp1[k] == tmp2[l]) && check)                  //jezeli litera nie wystepuje w wynikowym lancuchu i spelnia warunek rownosci
            {
                add = true;                                     //dodaj do ³ancucha
                break;
            }
        }

        if (add)
        {
            wynik[position] = tmp1[k];
            position++;                                         //ustaw pozycje nastepnej litery
        }
        add = false;                                            //resetuj
        check = true;                                           //resetuj
    }
    wynik[position] = '\0';                                     //wskazujemy, gdzie konczy sie lancuch

    return wynik;
}
// -------------------------------------------------------------------------------




//­---Operatory--------------------------------------------------------------------------------

/// \brief szablon funkcji przeladowujacej operator przypisania dla klasy aghMatrix
///
/// \param wzor - referencja do obiektu klasy aghMatrix sluzacego za wzor
/// \return referencja do obiektu klasy aghMatrix z nowa zawartoscia
template <class typ>
aghMatrix<typ>& aghMatrix<typ>::operator= (const aghMatrix &wzor)
{
    if (this == &wzor) return *this;            //w przypadku proby przypisania obiektu do siebie samego zwroc ten obiekt
    this -> ~aghMatrix();                       //etap destrukcji obiektu, do ktorego bedzie przypisana nowa wartosc

    rows = wzor.rows;
    columns = wzor.columns;
    matrix = new typ*[rows];                    //rezerwuje pamiec potrzebna na nowy obiekt klasy aghMatrix
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new typ[columns];
        for (int j = 0; j<columns; j++)
            matrix[i][j] = wzor.matrix[i][j];   //przypisuje wartosci kolejnym elementom macierzy
    }

    return *this;
}
// -------------------------------------------------------------------------------

/// \brief szablon funkcji przeladowujacej operator dodawania dla klasy aghMatrix
///
/// \param y - referencja do obiektu klasy aghMatrix sluzacego za skladnik sumy
/// \return obiekt klasy aghMatrix zawierajacy sume macierzy
template <class typ>
aghMatrix<typ> aghMatrix<typ>::operator+ (const aghMatrix &y) const
{
    if (rows != y.rows || columns != y.columns)     //kontrola mozliwosci dodawania
        throw aghException(0, "inadequate matrices sizes", "matrix.h", 542);

    else
    {
        aghMatrix<typ> wynik(rows, columns);        //stworzenie obiektu do przechowywania sumy

        for (int i = 0; i<wynik.rows; i++)
            for (int j = 0; j<wynik.columns; j++)
                wynik.matrix[i][j] = matrix[i][j] + y.matrix[i][j];     //obliczenie i przypisanie wartosci kolejnym el. macierzy

        return wynik;
    }
}
// -------------------------------------------------------------------------------

/// \brief szablon funkcji przeladowujacej operator mnozenia dla klasy aghMatrix
///
/// \param y - referencja do obiektu klasy aghMatrix zawierajacego macierz do wymnozenia
/// \return obiekt klasy aghMatrix zawierajacy iloczyn macierzy
template <class typ>
aghMatrix<typ> aghMatrix<typ>::operator* (const aghMatrix &y) const
{
    if (columns != y.rows)          //kontrola mozliwosci mnozenia danych macierzy
        throw aghException(0, "inadequate matrices size", "matrix.h", 565);

    else
    {
        aghMatrix<typ> wynik(rows, y.columns);      //stworzenie obiektu do przechowywania iloczynu
        for (int i = 0; i<rows; i++)
            for (int j = 0; j<y.columns; j++)
                {
                    wynik.matrix[i][j] = 0;         //inicjalizacja macierzy zerami
                    for (int k = 0; k<columns; k++)
                        wynik.matrix[i][j] = wynik.matrix[i][j] + (matrix[i][k] * y.matrix[k][j]);      //obliczenie i przypisanie kolejnych el. macierzy
                }
        return wynik;
    }
}
// -------------------------------------------------------------------------------

/// \brief szablon funkcji przeladowujacej operator porownania dla klasy aghMatrix
///
/// \param wzor - referencja do obiektu klasy aghMatrix bedacego zawierajacego macierz do porownania
/// \return true jesli macierze sa takie same; false w przeciwnym wypadku
template <class typ>
bool aghMatrix<typ>::operator== (const aghMatrix &wzor) const
{
    if ((matrix == NULL) || (wzor.matrix == NULL))      //jesli ktoras macierz nie istnieje zwroc false
        return false;
    if (this == &wzor)                                  //jesli macierze pokazuja na to samo miejsce w pamieci zwroc true
        return true;
    if (this->rows != wzor.rows || this->columns != wzor.columns)   //jesli rozne wymiary - false
        return false;

    for (int i = 0; i<rows; i++)
        for (int j = 0; j<columns; j++)
             if (matrix[i][j] != wzor.matrix[i][j])     //porownanie kolejnych elementow macierzy
                 return false;
    return true;
}
// -------------------------------------------------------------------------------

/// \brief szablon funkcji przeladowujacej operator (), sluzacej do pobrania wybranego obiektu macierzy
///
/// \param r - nr wiersza
/// \param c - nr kolumny
/// \return wybrany obiekt typu 'typ'
template <class typ>
typ aghMatrix<typ>::operator() (int r, int c)
{
    if (r<0 || r>rows || c<0 || c>columns)      //kontrola zakresu
        throw aghException(0, "inadequate matrices size", "matrix.h", 613);
    else
        return matrix[r][c];
}




//----Operatory specjalizowane---------------------------------------------------------------

/// \brief szablon funkcji specjalizowanej dla napisow, przeladowujacej operator dodawania
/// \brief napisy traktowane sa jako zbiory; napis wynikowy to litery wystepujace w  jedym kub drugim napisie
///
/// \param to_add - referencja do obiektu aghMatrix ze skladnikiem sumy
/// \return macierz wynikowa zawierajaca sume napisow
template<>
aghMatrix<char*> aghMatrix<char*>::operator+ (const aghMatrix &to_add) const;
// -------------------------------------------------------------------------------

/// \brief szablon funkcji specjalizowanej dla napisow, przeladowujacej operator mnozenia
/// \brief napisy traktowane sa jako zbiory; napis wynikowy to litery wystepujace jednoczesnie w obu skladnikch iloczynu
///
/// \param to_mul - referencja do obiektu aghMatrix ze skladnikiem iloczynu
/// \return macierz wynikowa zawierajaca iloczyn napisow
template<>
aghMatrix<char*> aghMatrix<char*>::operator* (const aghMatrix &to_mul) const;
// -------------------------------------------------------------------------------

/// \brief szablon funkcji specjalizowanej dla napisow, przeladowujacej operator porownania
/// \brief funkcja zwraca prawde, gdy kolejnosc liter w napisach jest identyczna, napisy maja taka sama dlugosc lub przekazany obiekt pokazuje na to samo miejsce w pamieci
///
/// \param wzor - referencja do obiektu aghMatrix, z ktorym mamy porownac przechowywany napis
/// \return true jesli napisy sa takie same; false w przeciwnym wypadku
template <>
bool aghMatrix<char*>::operator== (const aghMatrix &wzor) const;
// -------------------------------------------------------------------------------

/// \brief szablon funkcji przeladowujacej operator ()
/// \brief funkcja sluzy do pobrania wybranego napisu macierzy
///
/// \param r - nr wiersza
/// \param c - nr kolumny
/// \return kopia wybranego napisu macierzy o wpolrzednych [r,c]
template <>
char* aghMatrix<char*>::operator() (int r, int c);
// -------------------------------------------------------------------------------

/// \brief szablon funkcji specjalizowanej dla typu znakowego, przeladowujacej operator dodawania
/// \brief litery sa interpretowane jako kolejne liczby naturalne, poczynajac od 0 dla 'a'. nastepnie macierze sa dodawane w normalny sposob
///
/// \param to_add - referencja do obiektu aghMatrix ze skladnikiem sumy
/// \return macierz wynikowa zawierajaca male litery
template<>
aghMatrix<char> aghMatrix<char>::operator+ (const aghMatrix &to_add) const;
// -------------------------------------------------------------------------------

/// \brief szablon funkcji specjalizowanej dla typu znakowego, przeladowujacej operator mnozenia
/// \brief litery sa interpretowane jako kolejne liczby naturalne, poczynajac od 0 dla 'a'. nastepnie macierze sa mnozone w normalny sposob
///
/// \param to_add - referencja do obiektu aghMatrix ze skladnikiem sumy
/// \return macierz wynikowa zawierajaca male litery
template<>
aghMatrix<char> aghMatrix<char>::operator* (const aghMatrix &mult) const;
// -------------------------------------------------------------------------------

/// \brief szablon funkcji specjalizowanej dla typu znakowego, umozliwiajacej przeslanie zmiennej liczby argumentow
///
/// \param r - ilosc wierszy macierzy
/// \param c - ilosc kolumn macierzy
/// \param ... - zmienna liczba kolejnych elementow macierzy
/// \return void
template <>
void aghMatrix<char>::setItems(int r, int c, ...);
// -------------------------------------------------------------------------------


/// \brief Konstruktor kopiujacy specjalizowany dla char*
///
/// \param prototype - obiekt zrodlowy

template <>
aghMatrix<char*>::aghMatrix(const aghMatrix &prototype);

// -------------------------------------------------------------------------------------------------------------
#endif
