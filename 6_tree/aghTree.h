/**
* \file    aghTree.h
* \author  Maciej Sudol & Pawel Inglot
* \date    2015-05-30
* \brief   Deklaracja i definicja szablonowej klasy aghTree, umozliwiajacej implementacje pojemnika w postaci drzewa BST na dane.
*/
// -----------------------------------------------------------------------------------------------

#ifndef AGHTREE_H
#define AGHTREE_H
// -----------------------------------------------------

#include "branch.h"
#include "aghContainer.h"
#include "aghException.h"
#include "aghVector.h"
// -----------------------------------------------------



/**
 * \class   aghTree
 * \brief   Deklaracja szablonowej klasy aghTree.
 * \tparam  T   Typ parametryczny.
 */
template <class T>
class aghTree :public aghContainer<T>
{
public:

// --- Konstruktory i destruktor -----------------------------------------------------------------

    /**
     * \fn  aghTree::aghTree();
     * \brief   Konstruktor bezparametrowy.
     */
    aghTree();

    /**
     * \fn  aghTree::aghTree(const aghContainer<T>& source);
     * \brief   Konstruktor kopiujacy.
     * \brief   Obsluguje zarono argumenty typu aghTree, jak rowniez aghContainer.
     * \param   source  Obiekt zrodlowy.
     */
    aghTree(const aghContainer<T>& source);

    /**
     * \fn  aghTree::~aghTree();
     * \brief   Destruktor.
     */
    ~aghTree();


// --- Metody i operator = -----------------------------------------------------------------------

    /**
     * \fn  aghContainer<T>& aghTree::operator=(const aghTree<T>& source);
     * \brief   Operator przypisania. Operator przywoluje obsluge operatora = z klasy bazowej.
     * \param   source  Obiekt zrodlowy.
     * \return  Kopia obiektu podanego jako parametr konstruktora.
     */
    aghContainer<T>& operator=(const aghTree<T>& source);

    /**
     * \fn  T& aghTree::at(int idx) const;
     * \brief   Metoda zwracajaca wartosc elementu. Zwraca wartosc w pojemniku. Zakladamy ze
     *          indeksowanie element�w w drzewie jest okre�lana przez kolejno�� odwiedzania wezlow
     *          metoda in-order rozpoczynajac od lewego poddrzewa.
     * \param   idx Indeks wybranego elementu.
     * \return  Referencja do wybranego elementu.
     */
    T& at(int idx) const;

    /**
     * \fn  bool aghTree::insert(int idx, T const& source);
     * \brief   Metoda wstawiania elementu do pojemnika. Parametr indeksowy jest pomijany.
     * \param   idx     Indeks wybranego miejsca; jest ignorowany.
     * \param   source  Obiekt, ktory ma zostac wstawiony.
     * \return  Zwraca true jezeli udalo sie wstawic obiekt, w przeciwnym wypadku zwraca false.
     */
    bool insert(int idx, T const& source);

    /**
     * \fn  bool aghTree::remove(int idx);
     * \brief   Metoda usuwajaca wybrany element. Usuwa element, ktorego indeks to kolejnosc dodania.
     * \param   idx Indeks elementu, ktory ma zostac usuniety.
     * \return  Zwraca true jezeli udalo sie usunac wybrany obiekt, w przeciwnym wypadku zwraca false.
     */
    bool remove(int idx);

    /**
     * \fn  bool aghTree::replace(int idx, T const& source);
     * \brief   Metoda podmiany elementu w pojemniku.
     * \param   idx     Indeks wybranego elementu.
     * \param   source  Obiekt do podmiany.
     * \return  Zwraca true jezeli udalo sie podmienic obiekt, w przeciwnym wypadku zwraca false.
     */
    bool replace(int idx, T const& source);

    /**
     * \fn  int aghTree::size(void) const;
     * \brief   Metoda zwracajaca ilosc elementow.
     * \return  Zwraca ilosc elementow w pojemniku.
     */
    int size(void) const;

private:

// --- Zmienne -----------------------------------------------------------------------------------

    /** \brief   Liczba elementow w pojemniku. */
    int counter;

    /** \brief   Wskaznik na korzen drzewa. */
    branch<T> *root;


// --- Funkcje pomocnicze ------------------------------------------------------------------------

    /**
     * \fn  branch<T>* aghTree::inorder_search(int idx) const;
     * \brief   Wyszukuje elementu o podanym indeksie metoda inorder.
     * \param   idx Indeks szukanego elementu.
     * \return  Wskaznik do elementu o indeksie "idx".
     */
    branch<T>* inorder_search(int idx) const;

    /**
     * \fn  branch<T>* aghTree::find_parent(branch<T> *child) const;
     * \brief   Wyszukuje rodzica podanego elementu.
     * \param   child Potomek szukanego elementu.
     * \return  Wska�nik do szukanego elementu.
     */
    branch<T>* find_parent(branch<T> *child) const;

    /**
     * \fn  void aghTree::remove_0(branch<T> *parent, branch<T> *to_remove);
     * \brief   Usuwa element, gdy ten nie ma dzieci.
     * \param   parent      Element poprzedzajacy wybrany do usuniecia.
     * \param   to_remove   Element wybrany do usuniecia.
     */
    void remove_0(branch<T> *parent, branch<T> *to_remove);

    /**
     * \fn  void aghTree::remove_1(branch<T> *parent, branch<T> *to_remove);
     * \brief   Usuwa element, gdy ten ma jedno dziecko.
     * \param   parent      Element poprzedzajacy wybrany do usuniecia.
     * \param   to_remove   Element wybrany do usuniecia.
     */
    void remove_1(branch<T> *parent, branch<T> *to_remove);

    /**
     * \fn  void aghTree::remove_2(branch<T> *parent, branch<T> *to_remove);
     * \brief   Usuwa element, gdy ten ma dwojke dzieci.
     * \param   parent      Element poprzedzajacy wybrany do usuniecia.
     * \param   to_remove   Element wybrany do usuniecia.
     */
    void remove_2(branch<T> *to_remove);

};
// -----------------------------------------------------------------------------------------------





// --- Konstruktory i destruktor -----------------------------------------------------------------

template <class T>
aghTree<T>::aghTree()
{
    counter = 0;    //Nadawanie domyslnych wartosci pojemnika
    root = NULL;
}
// -----------------------------------------------------

template <class T>
aghTree<T>::aghTree(const aghContainer<T>& source)
{
    counter = 0;    //Poczatkowa inicjalizacja zmiennych w celu umozliwienia wlasciwej pracy konstruktora
    root = NULL;    //Konstruktor wywola operator "=", ktory pracuje na zmiennych teraz podanych. W przeciwnym wypadku pracowalby na randomowych wartosciach zmiennych

    this->operator=(static_cast<const aghTree<T>&> (source));
}
// -----------------------------------------------------

template <class T>
aghTree<T>::~aghTree()
{
    this->clear();      //Zwolneienie pamieci wszystkich elementow pojemnika
    counter = 0;
    root = NULL;
}
// -----------------------------------------------------------------------------------------------




// --- Metody i operator = -----------------------------------------------------------------------

template <class T>
aghContainer<T>& aghTree<T>::operator=(const aghTree<T>& source)
{
    return aghContainer<T>::operator=(source);      //Wywolanie operatora "=" z klasy bazowej
}
// -----------------------------------------------------

template <class T>
T& aghTree<T>::at(int idx) const
{
    if ((idx >= 0) && (idx < counter))      //Walidacja poprawnnosci indeksu
        return  inorder_search(idx)->data;    //Zwrocenie szukanego elementu
    else
        throw aghException(0, "Wyjscie poza zakres");   //Jezeli niewlasciwy, rzczuc wyjatek
}
// -----------------------------------------------------

template <class T>
bool aghTree<T>::insert(int idx, T const& source)
{
    if ((idx < 0) || (idx > counter))       //Walidacja poprawnnosci indeksu
        return false;                       //Jezeli niewlasciwy, zwroc false

    branch<T> *tmp = root;  //Zmienna pomocnicza
    branch<T> *_new = new branch<T>;    //Nowa zmienna dopisywana do pojemnika
    _new->data = source;    //
    _new->left = NULL;      //
    _new->right = NULL;     //Inicjlizacja nowej zmiennej

    if (counter == 0)       //Jezeli dodajemy pierwszy element
    {
        root = _new;        //Ustawiamy korzen
        counter++;

        return true;        //Zwroc prawde
    }
    else
    {
        while (true)
        {
            if (source > tmp->data)     //Szuakmy odpowiedniego miejsca dla nowego elementu,
            {                           //zgodnie z zalozeniem: po lewej "<=", po prawej ">"
                if (tmp->right)         //Jezli rozne od NULL'a
                    tmp = tmp->right;
                else
                    break;
            }
            else
            {
                if (tmp->left)          //Jezeli rozne od NULL'a
                    tmp = tmp->left;
                else
                    break;
            }
        }
        if (source > tmp->data)         //Znajdz odpowiednie miejsce na nowy element
            tmp->right = _new;
        else
            tmp->left = _new;
        counter++;

        return true;                    //Zwroc prawde
    }
}
// -----------------------------------------------------

template <class T>
bool aghTree<T>::remove(int idx)
{
    if ((idx < 0) || (idx >= counter))  //Walidacja poprawnnosci indeksu
        return false;                   //Jezeli niewlasciwy, zwroc false

    branch<T> *tmp = inorder_search(idx);       //Pomocnicza zmienna
    if (tmp == root)                            //Gdy usuwamy korzen
    {
        if ((tmp->left == NULL) && (tmp->right == NULL))    //Jezeli korzen nie ma potomkow
        {
            root = NULL;                                    //Jezeli tak, wyzeruj "root"
            delete tmp;
            counter--;
            return true;
        }

        if (((tmp->left != NULL) && (tmp->right == NULL)) || ((tmp->left == NULL) && (tmp->right != NULL)))     //Jezeli korzen ma jednego potmoka
        {
            branch<T> *tmp_parent = new branch<T>;          //Pomocnicza zmienna, ktora pokazuje na korzen
            tmp_parent->left = tmp;
            remove_1(tmp_parent, tmp);
            root = tmp_parent->left;

            tmp_parent->left = NULL;
            delete tmp_parent;
            return true;

        }
    }
    else
    {
        branch<T> *tmp_parent = find_parent(tmp);           //Jezeli nie jest korzeniem, znajdz rodzica podanego elementu

        if ((tmp->left == NULL) && (tmp->right == NULL))    //Jezeli usuwany element jest koncem drzewa
        {
            remove_0(tmp_parent, tmp);
            return true;
        }

        if (((tmp->left != NULL) && (tmp->right == NULL)) || ((tmp->left == NULL) && (tmp->right != NULL)))     //Jezeli usuwany element ma jedno dziecko
        {
            remove_1(tmp_parent, tmp);
            return true;
        }

        if ((tmp->left != NULL) && (tmp->right != NULL))    //Jezeli usuwany element ma dwojke dzieci
        {
            remove_2(tmp);
            return true;
        }
    }
    return false;       //W przeciwnych wypadkach(jakich??) zwroc false
}
// -----------------------------------------------------

template <class T>
bool aghTree<T>::replace(int idx, T const& source)
{
    if (idx<0 || idx>=counter) return false;

    remove(idx);        //Usuwamy podany element, by moc go zastapic nowym
    insert(0, source);  //Nowy element zazwyczej nie bedzie mial takiego sammego indeksu, jak usuwany
    return true;
}
// -----------------------------------------------------

template <class T>
int aghTree<T>::size(void) const
{
    return counter; //Zwroc liczbe elementow w pojemniku
}
// -----------------------------------------------------------------------------------------------




// --- Funkcje pomocnicze ------------------------------------------------------------------------

template <class T>
branch<T>* aghTree<T>::inorder_search(int idx) const
{
    branch<T> *result = root;
    aghVector<branch<T>*> stack;    //Pomocniczy stos wskaznikow
    int tmp = 0;                    //Zmienna pokazujaca, ktory z kolej wypisywany jeset element metoda inorder

    while ((result != NULL) || (!stack.isEmpty()))  //Szukaj elementu dopoki tymczasowa galaz jest rozna od zera lub stos nie jest pusty
    {
        if (result != NULL)                         //Jezeli tymczasowa galaz nie jest pusta
        {
            stack.insert(0, result);                //Zapamietaj rodzica
            result = result->left;                  //Przejdz do lewego poddrzewa
        }
        else
        {
            result = stack.at(0);                   //W przeciwnym wypadku wroc do rodzica
            stack.remove(0);

            if (tmp == idx)                         //Jezeli jest to szukany element, przerwij
            break;

            tmp++;                                  //Inkrementuj zmienna indeksowa
            result = result->right;                 //Jezeli to nie jest szukany element, przejdz do prawego poddrzewa
        }
    }

    stack.clear();
    return result;
}
// -----------------------------------------------------

template <class T>
branch<T>* aghTree<T>::find_parent(branch<T> *child) const
{
    branch<T> *result = root;
    aghVector<branch<T>*> stack;    //Pomocniczy stos wskaznikow

    while ((result != NULL) || (!stack.isEmpty()))  //Szukaj elementu dopoki tymczasowa galaz jest rozna od zera lub stos nie jest pusty
    {
        if (result != NULL)                         //Jezeli tymczasowa galaz nie jest pusta
        {
            stack.insert(0, result);                //Zapamietaj rodzica
            result = result->left;                  //Przejdz do lewego poddrzewa
        }
        else
        {
            result = stack.at(0);                   //W przeciwnym wypadku wroc do rodzica
            stack.remove(0);

            if ((result->left == child) || (result->right == child))    //Jezeli jednym z potomkow rodzica jest szukany element
                break;                                                  //Przerwij

            result = result->right;                                     //W przeciwnym wypadku przejdz do prawego poddrzewa
        }
    }

    stack.clear();
    return result;
}
// -----------------------------------------------------

template <class T>
void aghTree<T>::remove_0(branch<T> *parent, branch<T> *to_remove)
{
    if (parent->left == to_remove)      //Znajdz po ktorej stronie rodzica sie znajdowal
        parent->left = NULL;            //Wyzeruj wlascia strone
    else
        parent->right = NULL;           //Wyzeruj wlascia strone

    delete to_remove;                   //Usun element
    counter--;
}
// -----------------------------------------------------

template <class T>
void aghTree<T>::remove_1(branch<T> *parent, branch<T> *to_remove)
{
    if ((to_remove->left != NULL) && (to_remove->right == NULL))    //Znajdz po ktorej stronie usuwany element ma potomstwo
    {
        if (parent->left == to_remove)          //Znajdz po ktorej stronie rodzica znajduje sie usuwany element
            parent->left = to_remove->left;     //Przepisz potomstwo usuwanego elementu
        else
            parent->right = to_remove->left;    //Przepisz potomstwo usuwanego elementu
    }
    else
    {
        if (parent->left == to_remove)          //Znajdz po ktorej stronie rodzica znajduje sie usuwany element
            parent->left = to_remove->right;    //Przepisz potomstwo usuwanego elementu
        else
            parent->right = to_remove->right;   //Przepisz potomstwo usuwanego elementu
    }

    delete to_remove;       //Usun element
    counter--;
}
// -----------------------------------------------------

template <class T>
void aghTree<T>::remove_2(branch<T> *to_remove)
{
    branch<T> *trm_right = to_remove->right;
    if ((trm_right->left == NULL) && (trm_right->right == NULL))    //Jezeli prawy potomek usuwanego elementu nie ma potomstwa
    {
        to_remove->data = trm_right->data;              //Przepisz przechowywane informacje potomka do elementu, ktory "ma byc usuniety"
        to_remove->right = NULL;                        //Prawy potomek zostaje usuniety, a jego informacje sa w "usuwanym elemencie"
        delete trm_right;                               //Usun prawego potomka
    }
    else                                                //Jezeli prawy potomek usuwanego elementu ma potomstwo
    {
        if (trm_right->left != NULL)                    //Jezeli znajduje sie ono po lewej stronie
        {
            branch<T> *trm__left_parent = trm_right;    //Tymczasowy rodzic
            branch<T> *trm__left = trm_right->left;     //Tymczasowe dziecko

            while (trm__left->left != NULL)             //Znajdz najdalszego potomka usuwanego elementu, znajdujacego sie w lewym poddrzewie
            {
                trm__left_parent = trm__left;           //Przesun rodzica
                trm__left = trm__left->left;            //Przesun na nastepny element
            }
            to_remove->data = trm__left->data;          //Prepisz informacje do usuwanego elementu ze znalezionego potomka
            trm__left_parent->left = trm__left->right;  //"Prawe potomstwo znalezionego rodzica przypisz do lewego poddrzewa rodzica

            delete trm__left;                           //Usun znaleziony element
        }
        else                                            //Jezeli zanjduje sie ono po lewej stronie
        {
            to_remove->data = trm_right->data;          //Przepisz informacje z prawego potomka
            to_remove->right = trm_right->right;        //Przypisz potomstwo prawego potomka

            delete trm_right;                           //Usun prawego potomka
        }
    }

    counter--;
}
// -----------------------------------------------------------------------------------------------

// -----------------------------------------------------------------------------------------------
#endif  //AGHTREE_H
