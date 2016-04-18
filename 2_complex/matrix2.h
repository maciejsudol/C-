#ifndef matrix_h
#define matrix_h

#include <stdarg.h>
#include "aghException.h"
#include <iostream>
#include <string.h>
using namespace std;

template <class typ>
class aghMatrix
{
public:
    aghMatrix();
    aghMatrix(int r, int c);
    aghMatrix(const aghMatrix &prototype);
    ~aghMatrix();


    void setItem(int r, int c, typ data);
    void setItems(typ *data);
    void setItems(int r, int c, ...);
    void print();


    aghMatrix &operator= (const aghMatrix &wzor);
    aghMatrix operator+ (const aghMatrix &y) const;
    aghMatrix operator* (const aghMatrix &y) const;
    bool operator== (const aghMatrix &wzor) const;
    bool operator!= (const aghMatrix &wzor) const { return !(*this == wzor); }
    typ operator() (int r, int c);


private:
    int rows, columns;
    typ **matrix;
    void resize(int r, int c);
    char *add(char *tmp1, char *tmp2) const;
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

template <class typ>
aghMatrix<typ>::aghMatrix(int r, int c)
{
    rows = r;
    columns = c;

    matrix = new typ*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new typ[columns];

 //       for (int j = 0; j < columns; j++)
   //         matrix[i][j] = NULL;
    }
}

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

template <class typ>
aghMatrix<typ>::~aghMatrix()
{
    if (matrix != NULL)
    {
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
//        delete[] matrix;
        matrix = NULL;
    }
}

//---setItem/s--------------------------------------------------------------------------------

template <class typ>
void aghMatrix<typ>::setItem(int r, int c, typ data)
{
    matrix[r][c] = data;
}

template <class typ>
void aghMatrix<typ>::setItems(typ *data)
{
    int _rows = 0, _columns = 0;
    for (int i = 0; i < (rows*columns); i++)
    {
        if ((_rows < rows) && (_columns < columns))
        {
            matrix[_rows][_columns] = data[i];
            _columns++;
        }
        else
        {
            _rows++;
            _columns = 0;
            matrix[_rows][_columns] = data[i];
            _columns++;
        }
    }

}

template <class typ>
void aghMatrix<typ>::setItems(int r, int c, ...)
{
    resize(r, c);
    int counter = r*c;
    typ value;
    int _rows = 0, _columns = 0;

    va_list values;
    va_start(values, c);
    for (int i = 0; i < counter; i++)
    {
     /*   if (typeid(value) == typeid(a)) value = va_arg(values, int);          // BARDZIEJ ELEGANCKIE ROZWIAZANIE?
        if (typeid(value) == typeid(char*)) value = va_arg(values, int);
        else value = va_arg(values, typ);
    */
        value = va_arg(values, typ);
        if ((_rows < rows) && (_columns < columns))
        {
            matrix[_rows][_columns] = value;
            _columns++;
        }
        else
        {
            _rows++;
            _columns = 0;
            matrix[_rows][_columns] = value;
            _columns++;
        }
    }
    va_end(values);
}

//---Metody prywatne--------------------------------------------------------------------------

template <class typ>
void aghMatrix<typ>::resize(int r, int c)
{
    if (matrix != NULL)
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];

    rows = r;
    columns = c;

    matrix = new typ*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new typ[columns];
}

template <class typ>
void aghMatrix<typ>::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

template <class typ>
char *aghMatrix<typ>::add(char *tmp1, char *tmp2) const
{
    int length1 = strlen(tmp1), length2 = strlen(tmp2);
    /*
    for (int k = 0; tmp1[k] != '\0'; k++)
        length1++;
    for (int k = 0; tmp2[k] != '\0'; k++)
        length2++;
*/
    char *tmp_wynik = new char[(length1 + length2)];
    int position = 0;
    bool add = true;

    for (int k = 0; k < length1; k++)
    {
        for (int l = 0; l < k; l++)
            if (tmp1[k] == tmp1[l])
            {
                add = false;
                break;
            }

        if (add)
        {
            tmp_wynik[position] = tmp1[k];
            position++;
        }

        add = true;

    }

    for (int k = 0; k < length2; k++)
    {
        for (int l = 0; l < position; l++)
            if (tmp2[k] == tmp_wynik[l])
            {
                add = false;
                break;
            }

        if (add)
        {
            tmp_wynik[position] = tmp2[k];
            position++;
        }

        add = true;

    }

    char *wynik_koncowy = new char[position];
    for (int k = 0; k < position; k++)
        wynik_koncowy[k] = tmp_wynik[k];
    wynik_koncowy[position] = '\0';
    delete[] tmp_wynik;

    return wynik_koncowy;
}

template <class typ>
char *aghMatrix<typ>::mul(char *tmp1, char *tmp2) const
{
    int length1 = 0, length2 = 0, length;
    for (int k = 0; tmp1[k] != '\0'; k++)
        length1++;
    for (int k = 0; tmp2[k] != '\0'; k++)
        length2++;

    if (length1 < length2)
        length = length1;
    else
        length = length2;

    char *tmp_wynik = new char[length];
    int position = 0;
    bool add = false, check = true;

    for (int k = 0; k < length1; k++)
    {
        for (int l = 0; l < length2; l++)
        {
            for (int m = 0; m < position; m++)
                if (tmp1[k] == tmp_wynik[m])
                    check = false;

            if ((tmp1[k] == tmp2[l]) && check)
            {
                add = true;
                break;
            }
        }

        if (add)
        {
            tmp_wynik[position] = tmp1[k];
            position++;
        }

        add = false;
        check = true;
    }

    char *wynik_koncowy = new char[position];
    for (int k = 0; k < position; k++)
        wynik_koncowy[k] = tmp_wynik[k];
    wynik_koncowy[position] = '\0';
    delete[] tmp_wynik;

    return wynik_koncowy;
}

//нннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннн---Operatory--------------------------------------------------------------------------------

template <class typ>
aghMatrix<typ>& aghMatrix<typ>::operator= (const aghMatrix &wzor)
{
    if (this == &wzor) return *this;
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
    rows = wzor.rows;
    columns = wzor.columns;
    matrix = new typ*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new typ[columns];
    for (int i = 0; i<rows; i++)
        for (int j = 0; j<columns; j++)
            matrix[i][j] = wzor.matrix[i][j];
    return *this;
}

template <class typ>
aghMatrix<typ> aghMatrix<typ>::operator+ (const aghMatrix &y) const
{
    if (rows != y.rows || columns != y.columns)
    {
        throw aghException(0, "inadequate matrices size", "matrix.h", 203);
    }
    else
    {
        aghMatrix<typ> wynik(rows, columns);

        for (int i = 0; i<wynik.rows; i++)
            for (int j = 0; j<wynik.columns; j++)
                wynik.matrix[i][j] = matrix[i][j] + y.matrix[i][j];
        return wynik;
    }
}

template <class typ>
aghMatrix<typ> aghMatrix<typ>::operator* (const aghMatrix &y) const
{
    if (columns != y.rows)
    {
        throw aghException(0, "inadequate matrices size", "matrix.h", 221);
    }
    else
    {
        aghMatrix<typ> wynik(rows, y.columns);
        for (int i = 0; i<rows; i++)
            for (int j = 0; j<y.columns; j++)
                {
                    wynik.matrix[i][j] = 0;
                    for (int k = 0; k<columns; k++)
                        wynik.matrix[i][j] = wynik.matrix[i][j] + (matrix[i][k] * y.matrix[k][j]);
                }
        return wynik;
    }
}

template <class typ>
bool aghMatrix<typ>::operator== (const aghMatrix &wzor) const
{
    if ((matrix == NULL) || (wzor.matrix == NULL))
        return false;
    if (this == &wzor)
        return true;
    if (this->rows != wzor.rows || this->columns != wzor.columns)
        return false;

    for (int i = 0; i<rows; i++)
        for (int j = 0; j<columns; j++)
             if (matrix[i][j] != wzor.matrix[i][j])
                 return false;
    return true;
}

template <class typ>
typ aghMatrix<typ>::operator() (int r, int c)
{
    if (r<0 || r>rows || c<0 || c>columns)
        throw aghException(0, "inadequate matrices size", "matrix.h", 261);
    else
        return matrix[r][c];
}

//нннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннннн----Operatory specjalizowane---------------------------------------------------------------

template<>
aghMatrix<char*> aghMatrix<char*>::operator+ (const aghMatrix &to_add) const;

template<>
aghMatrix<char*> aghMatrix<char*>::operator* (const aghMatrix &to_mul) const;

template <>
bool aghMatrix<char*>::operator== (const aghMatrix &wzor) const;

template <>
char* aghMatrix<char*>::operator() (int r, int c);

template<>
aghMatrix<char> aghMatrix<char>::operator+ (const aghMatrix &to_add) const;

template<>
aghMatrix<char> aghMatrix<char>::operator* (const aghMatrix &mult) const;

template <>
void aghMatrix<char>::setItems(int r, int c, ...);

#endif
