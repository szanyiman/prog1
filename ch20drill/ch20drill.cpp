#include "std_lib_facilities.h"

template<typename T>
class PrintElements
{
public:
    void operator()(T& elm) const {cout << elm << ' ';}
};

// 6. feladat: írjunk egy szimpla érték másolót
template<class Iter1, class Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    while (f1!=e1) {
        *f2 = *f1;
        ++f1;
        ++f2;
    }
    return f2;
}

int main()
{
    PrintElements<int> print_it;
	// 1. feladat: definiáljunk egy tömböt tíz elemmel
	const int meret = 10;
    array<int,meret> tomb;
    for (int i = 0; i<tomb.size(); ++i) tomb[i] = i;
    cout << "1. feladat:\ntömb elemei: ";
    for_each(tomb.begin(),tomb.end(), print_it);
    cout << endl;
    // 2. feladat: definiáljunk int vektort ezzel a tíz elemmel
    vector<int> vektor;
    for (int i = 0; i<10; ++i) vektor.push_back(i);
    cout << "2. feladat:\nvektor elemei: ";
    for_each(vektor.begin(),vektor.end(), print_it);
    cout << endl;
    // 3. feladat: definiáljunk int listát ezzel a tíz elemmel
    list<int> li;
    for (int i = 0; i<10; ++i) li.push_back(i);
    cout << "3. feladat:\nlista elemei: ";
    for_each(li.begin(),li.end(), print_it);
    cout << endl;
 	// 4. feladat: definiáljunk mindenből egy másodikat és másoljuk az elemeket
 	// a fentiekből
    
    array<int,meret> tomb_c = tomb;
    vector<int> vektor_c = vektor;
    list<int> li_c = li;
    cout << "4. feladat:\nmásolt tömb elemei: ";
    for_each(tomb_c.begin(),tomb_c.end(), print_it);     cout << endl;
    cout << "másolt vektor elemei: ";
    for_each(vektor_c.begin(),vektor_c.end(), print_it);     cout << endl;
    cout << "másolt lista elemei: ";
    for_each(li_c.begin(),li_c.end(), print_it);     cout << endl;

    // 5. feladat: adjunk a tömb elemeihez 2-t, a vektor elemeihez 3-at
    // a lista elemeihez pedig 5-öt

    for (array<int,meret>::iterator p = tomb.begin(); p!=tomb.end(); ++p)
        *p += 2;
    cout << "5. feladat:\nnövelt tömb elemei: ";
    for_each(tomb.begin(),tomb.end(), print_it);    cout << endl;

    for (vector<int>::iterator p = vektor.begin(); p!=vektor.end(); ++p)
        *p += 3;
    cout << "növelt vektor elemei: ";
    for_each(vektor.begin(),vektor.end(), print_it);     cout << endl;

    for (list<int>::iterator p = li.begin(); p!=li.end(); ++p)
        *p += 5;
    cout << "növelt lista elemei: ";
    for_each(li.begin(),li.end(), print_it);     cout << endl;

    // 7. feladat: használjuk a copy-t
    vector<int>::iterator v_it = my_copy(tomb.begin(),tomb.end(),vektor.begin());
    array<int,meret>::iterator tomb_it = my_copy(li.begin(),li.end(),tomb.begin());

    if (v_it!=vektor.begin() && tomb_it!=tomb.begin()) {
    cout << "7. feladat:\ntömb másolt a listából: ";
    for_each(tomb.begin(),tomb.end(), print_it);     cout << endl;
    cout << "vektor másolt a tömbből: ";
    for_each(vektor.begin(),vektor.end(), print_it);     cout << endl;
    cout << "lista: ";
    for_each(li.begin(),li.end(), print_it);     cout << endl;
    }

    // 8. használjunk a find()-ot hogy megtaláljuk az értékeket
    v_it = find(vektor.begin(),vektor.end(),3);
    if (v_it != vektor.end())
        cout << "A vektorban van 3-as érték, indexe: " << v_it-vektor.begin() << ".\n";

    list<int>::iterator l_it = find(li.begin(),li.end(),27);

    if (l_it!=li.end()) {
        int idx = 0;
        for (list<int>::iterator iter = li.begin(); iter!=l_it; ++iter)
            ++idx;
        cout << "A listában van 27-es érték, indexe: " << idx << ".\n";
    }
    else
        cout << "A lista nem tartalmazza a 27-es értéket\n";

}