#include "std_lib_facilities.h"

template<class T> struct S {
// 2. feladat: Adjunk meg egy konstruktort, hogy bevezethessük T-vel
    S() : val(T()) { }
    S(T d) : val(d) { }
 // 10. feladat: a set()-et cseréljük ki az alábbira
    T& operator=(const T&);
// 5. feladat: Adjunk meg egy függvény template-et get() névvel, ami
// a val-nak egy referenciáját adja vissza
// 11. feladat: legyen a get()-nek konstans verziója
    T& get();
    const T& get() const;
// 9. feladat: Adjunk meg egy függvény template-et set() névvel, amivel
// meg tudjuk változtatni a val-t
    void set(const T& d);
// 7. feladat: Legyen val privát
private:
    T val;
};

template<class T> T& S<T>::operator=(const T& d)
{
    val = d;
    return val;
}

// 5. feladat: Adjunk meg egy függvény template-et get() névvel, ami
// a val-nak egy referenciáját adja vissza
// 6. feladat: a get() legyen osztályon kívül
// 11. feladat: legyen a get()-nek konstans verziója
template<class T> T& S<T>::get() { return val; }
template<class T> const T& S<T>::get() const { return val; }

// 9. feladat: Adjunk meg egy függvény template-et set() névvel, amivel
// meg tudjuk változtatni a val-t
template<class T> void S<T>::set(const T& d) { val = d; }

// 12. feladat: Definiáljunk egy függvényt ami cin-ből olvas v-be
template<class T> istream& operator>>(istream& is, S<T>& ss)
{
    T v;
    cin >> v;
    if (!is) return is;
    ss = v;
    return is;
}

template<class T> void read_val(T& v)
{
    cin >> v;
}

// 14. feladat: Definiáljunk kimeneti és bemeneti operátorokat vector<T>-nek
// Legyen a formátum -> { val, val, val }
template<class T> ostream& operator<<(ostream& os, const vector<T>& d)
{
    os << "{ ";
    for (int i = 0; i<d.size(); ++i) {
        os << d[i];
        if (i<d.size()-1) os << ',';
        os << ' ';
    }
    os << "}";
    return os;
}

// 14. feladat: Definiáljunk kimeneti és bemeneti operátorokat vector<T>-nek
// Legyen a formátum -> { val, val, val }
template<class T> istream& operator>>(istream& is, vector<T>& d)
{
    char ch1;
    char ch2;
    T temp;
    vector<T> v_temp;
    is >> ch1;
    if (!is) return is;
    if (ch1!='{') {
        is.clear(ios_base::failbit);
        return is;
    }
    while (cin>>temp>>ch2 && ch2==',') {
        v_temp.push_back(temp);
    }
    if (ch2!='}') {
        is.clear(ios_base::failbit);
        return is;
    }
    v_temp.push_back(temp); // ch2=='}', utolsó értéket olvassuk

// Most másoljuk csak át a vektort, így d nem változik ha rossz a bemeneti érték
    d = v_temp;
    return is;
}

int main()
{
// 3. feladat: Definiáljunk típus változókat:S<int>, S<char>, S<double>, S<string>, és
// S<vector<int>>; adjunk nekik értékeket
    S<int> s_int(64);
    S<char> s_char('o');
    S<double> s_dbl(6.21);
    S<string> s_strg("Szöveg");
    vector<int> vi;
    vi.push_back(3);
    vi.push_back(8);
    vi.push_back(10);
    S< vector<int> > s_v_int(vi);

// 4. feladat: Olvassuk be a megadott értékeket és írassuk ki őket
/*
    cout << "4. feladat: a 3. feladatban megadott értékeket kiíratjuk" <<endl;
	cout << "s_int: " << s_int.val << "\n";
    cout << "s_char: " << s_char.val << "\n";
    cout << "s_dbl: " << s_dbl.val << "\n";
    cout << "s_strg: " << s_strg.val << "\n";
    for (int i = 0; i<s_v_int.val.size(); ++i)
         out << "s_v_int[" << i << "]: " << s_v_int.val[i] << "\n";
*/

// 8. feladat: Ismételjük meg a kiírást a get() függvényt használva
    cout << "\n8. feladat: megismételjük a 4. feladatot a get() függvény használatával\n";
    cout << "s_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n";
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";
    cout << s_v_int.get() << "\n";

// 9. feladat: Szemléltető
    cout << "\n9 feladat: set() függvény szemléltető" << endl;
    s_int.set(12);
    s_char.set('f');
    s_dbl.set(34.3);
    s_strg.set("Szöveg2");
    vi[1] = 54;
    s_v_int.set(vi);
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n";
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";
    cout << s_v_int.get() << "\n";

// 10. feladat: Szemléltető
    cout << "\n10. feladat: set() helyett S<T>::operator=(const T&) használata\n";
    s_int = 32;
    s_char = 'w';
    s_dbl = 5.6;
    s_strg = "Szöveg3";
    vi[1] = 75;
    s_v_int = vi;
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n";
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";
    cout << s_v_int.get() << "\n";


// 11. feladat: Szemléltető
    cout << "\n11. feladat: konstans, nem konstans get() szemléltető\n";
    const S<int> c_s_int(7);
    cout << "\nc_s_int: " << c_s_int.get() << "\n";

// 13. feladat: Szemléltető
    cout << "\n13. feladat: read_val() használatával adjunk értékeket a változókba, kivéve a S<vector<int>> változót\n";
    cout << "\ns_int: ";
    read_val(s_int);
    cout << "s_char: ";
    read_val(s_char);
    cout << "s_dbl: ";
    read_val(s_dbl);
    cout << "s_strg: ";
    read_val(s_strg);
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n\n";


// 14. feladat: Szemléltető
    cout << "\n14. feladat: read_val() már tud S<vector<int>> változót is kezelni";
    cout << "\nA vektor megadásakor használja a következő formátumot: {val,val,val}";
    cout << "\ns_v_int: ";
    read_val(s_v_int);
    cout << "\ns_v_int: " << s_v_int.get() << "\n";

}