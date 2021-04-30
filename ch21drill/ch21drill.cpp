// g++ ch21drill.cpp -o main

#include "std_lib_facilities.h"
#include <map>
#include <numeric>

// 1.1. feladat: Definiáljuk a következő struktúrát

struct Item {
    string name;
    int iid;
    double value;
    Item() :name(), iid(0), value(0) { }
    Item(string n, int i, double v) :name(n), iid(i), value(v) { }
};

// Bemenet definiálása

istream& operator>>(istream& is, Item& it)
{
    string name;
    int iid;
    double value;
    is >> name >> iid >> value;
    if (!is) return is;
    it = Item(name,iid,value);
    return is;
}

// Kimenet definiálása

ostream& operator<<(ostream& os, const Item& it)
{
    return os << it.name << '\t' << it.iid << '\t' << it.value;
}

// Összehasonlítás név alapján

struct  Comp_by_name {
    bool operator()(const Item& a, const Item& b) const
    {
        return a.name < b.name;
    }
};

// Összehasonlítás iid alapján

struct Comp_by_iid {
    bool operator()(const Item& a, const Item& b) const
    {
        return a.iid < b.iid;
    }
};

// Összehasonlítás érték alapján

bool comp_by_value(const Item& a, const Item& b)
{
    return a.value < b.value;
}

// Megtalálás név alapján

class Find_by_name {
    string name;
public:
    Find_by_name(const string& s) :name(s) { }
    bool operator()(const Item& it) const
    {
        return it.name == name;
    }
};

// Megtalálás iid alapján

class Find_by_iid {
    int iid;
public:
    Find_by_iid(int i) :iid(i) { }
    bool operator()(const Item& it) const
    {
        return it.iid == iid;
    }
};

// Kiírás

template<class iter>
void print(iter first, iter last)
{
    while (first!=last) {
        cout << *first << '\n';
        ++first;
    }
}

void f1()
{
    cout << "Első rész vektorral\n";
    vector<Item> vi;
    const string ifname = "ch21drill_vector.txt";

    // 1.1. feladat: Töltsük fel a vektort 10 adattal fájlból

    cout << "1.1.: Feltöltés fájlból:\n";
    {
        ifstream ifs(ifname.c_str());
        if (!ifs) error("nem megnyitható fájl ",ifname);
        Item i;
        while (ifs>>i) vi.insert(vi.end(),i);
    }
    print(vi.begin(),vi.end());

    // 1.2. feladat: rendezzük név szerint

    cout << "\n1.2.: Rendezés név szerint\n";
    sort(vi.begin(),vi.end(),Comp_by_name());
    print(vi.begin(),vi.end());

    // 1.3. feladat: rendezzük iid szerint

    cout << "\n1.3.: Rendezés iid szerint\n";
    sort(vi.begin(),vi.end(),Comp_by_iid());
    print(vi.begin(),vi.end());

    // 1.4. feladat: rendezzük érték szerint csökkenő sorrendben

    cout << "\n1.4.: Rendezés érték szerint csökkenő sorrendben\n";
    sort(vi.begin(),vi.end(),comp_by_value);
    reverse(vi.begin(),vi.end());
    print(vi.begin(),vi.end());

    // 1.5. feladat: adjuk hozzá a következő értékeket

    cout << "\n1.5.: Adjuk hozzá a következő értékeket\n";
    vi.insert(vi.end(),Item("horse shoe",99,12.34));
    vi.insert(vi.end(),Item("Canon S400",9988,499.95));
    sort(vi.begin(),vi.end(),comp_by_value);
    reverse(vi.begin(),vi.end());
    print(vi.begin(),vi.end());

    // 1.6. feladat: töröljünk két item-et név alapján

    cout << "\n1.6.: Töröljünk két item-et név alapján\n";
    vector<Item>::iterator vi_it = find_if(vi.begin(),vi.end(),Find_by_name("Sony"));
    vi.erase(vi_it);
    vi_it = find_if(vi.begin(),vi.end(),Find_by_name("Xiaomi"));
    vi.erase(vi_it);
    print(vi.begin(),vi.end());

    // 1.7. feladat: töröljünk két item-et név alapján

    cout << "\n1.7.: Töröljünk két item-et iid alapján\n";
    vi_it = find_if(vi.begin(),vi.end(),Find_by_iid(32566));
    vi.erase(vi_it);
    vi_it = find_if(vi.begin(),vi.end(),Find_by_iid(213));
    vi.erase(vi_it);
    print(vi.begin(),vi.end());
}

void f2()
{
    cout << "\nElső rész megismétlése listával\n" << endl;
    list<Item> li;
    const string ifname = "ch21drill_list.txt";

    // 1.1. feladat: Töltsük fel a listát 10 adattal fájlból

    cout << "1.1.: Feltöltés fájlból:\n";
    {
        ifstream ifs(ifname.c_str());
        if (!ifs) error("nem megnyitható fájl ",ifname);
        Item i;
        while (ifs>>i) li.insert(li.end(),i);
    }
    print(li.begin(),li.end());

    // 1.2. feladat: rendezzük név szerint

    cout << "\n1.2.: Rendezés név szerint\n";
    li.sort(Comp_by_name());
    print(li.begin(),li.end());

    // 1.3. feladat: rendezzük iid szerint

    cout << "\n1.3.: Rendezés iid szerint\n";
    li.sort(Comp_by_iid());
    print(li.begin(),li.end());

    // 1.4. feladat: rendezzük érték szerint csökkenő sorrendben

    cout << "\n1.4.: Rendezés érték szerint csökkenő sorrendben\n";
    li.sort(comp_by_value);
    reverse(li.begin(),li.end());
    print(li.begin(),li.end());

    // 1.5. feladat: adjuk hozzá a következő értékeket

    cout << "\n1.5.: Adjuk hozzá a következő értékeket\n";
    li.insert(li.end(),Item("horse shoe",99,12.34));
    li.insert(li.end(),Item("Canon S400",9988,499.95));
    li.sort(comp_by_value);
    reverse(li.begin(),li.end());
    print(li.begin(),li.end());

    // 1.6. feladat: töröljünk két item-et név alapján

    cout << "\n1.6.: Töröljünk két item-et név alapján\n";
    list<Item>::iterator li_it = find_if(li.begin(),li.end(),Find_by_name("water"));
    li.erase(li_it);
    li_it = find_if(li.begin(),li.end(),Find_by_name("bread"));
    li.erase(li_it);
    print(li.begin(),li.end());

    // 1.7. feladat: töröljünk két item-et iid alapján

    cout << "\n1.7.: Töröljünk két item-et iid alapján\n";
    li_it = find_if(li.begin(),li.end(),Find_by_iid(6));
    li.erase(li_it);
    li_it = find_if(li.begin(),li.end(),Find_by_iid(5));
    li.erase(li_it);
    print(li.begin(),li.end());
}

// Beolvasás konzolról

void read_pair(map<string,int>& msi)
{
    string s;
    int i;
    cin >> s >> i;
    if (!cin) error("Nem sikerült beolvasni az értéket");
    msi[s] = i;
}

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T,U>& p)
{
    os << setw(12) << left << p.first << '\t' << p.second;
    return os;
}

// Érték csere

template<class T>
struct Map_add {
    T operator()(T v, const pair<string,T>& p)
    {
        return v + p.second;
    }
};

void f3()
{
	cout << "\nmsi map feladatok" << endl;
    // 2.1. feladat: definiáljuk a map<string,int> msi-t

    map<string,int> msi;

    // 2.2. feladat: adjunk hozzá 10 pár adatot (nevet,értéket)

    msi["lecture"] = 21;
    msi["school"] = 10;
    msi["books"] = 6;
    msi["teacher"] = 546;
    msi["board"] = 65;
    msi["desks"] = 57;
    msi["students"] = 97;
    msi["grade"] = 240;
    msi["exams"] = 84;
    msi["lessons"] = 13;

    // 2.3. feladat: Írassuk ki tetszés szerint ezeket az értékpárokat

	cout << "\n2.3.: Írassuk ki tetszés szerint a megadott értékpárokat\n";
    print(msi.begin(),msi.end());

    // 2.4. feladat: Törüljük ki a párokat az msi-ből

    cout << "\n2.4.: Törüljük ki a párokat az msi-ből\n";
    typedef map<string,int>::const_iterator MI;
    MI p = msi.begin();
    while (p!=msi.end()) p = msi.erase(p);
    if(msi.size()==0)
    {
    	cout << "Az értékpárok törlése sikeres\n" << endl;
    }


    // 2.6. feladat: kérjünk be 10 értékpárat az eljárás segítségével az msi-be

    cout << "Adjon meg 10 (string,int) értékpárat, szóközzel elválasztva:\n";
    for (int i = 0; i<10; ++i)
        read_pair(msi);

    // 2.7. feladat: írassuk ki az msi értékeit

    cout << "\n2.7.: Írassuk ki az msi értékeit";
    cout << '\n';
    print(msi.begin(),msi.end());

    // 2.8. feladat: írassuk ki a megadott értékekből a számok összegét
    cout << "\n2.8.: Írassuk ki a megadott értékekből a számok összegét";
    int msi_sum = 0;
    msi_sum = accumulate(msi.begin(),msi.end(),msi_sum,Map_add<int>());
    cout << "\nmsi számainak összege: " << msi_sum << '\n';

    // 2.9. feladat: definiáljuk a map<int,string> mis-t

    map<int,string> mis;

    // 2.10. feladat: adjuk meg msi értékpárait mis-nek megfelelően

    for (p = msi.begin(); p!=msi.end(); ++p)
        mis[p->second] = p->first;

    // 2.11. Írjuk ki mis értékeit

    cout << "\n2.11.: Írassuk ki az mis értékeit";
    cout << "\nmis értékpárjai::\n";
    print(mis.begin(),mis.end());
}

template<class T>
class Less_than {
    T v;
public:
    Less_than(T val) :v(val) { }
    bool operator()(T x) const { return x < v; }
};

void f4()
{
    // 3.1. feladat: olvassunk be lebegő-pontos értékeket (min. 16 db) fájlból vd vektorba
    
    const string fname = "ch21drill_float.txt";
    ifstream ifs(fname.c_str());
    if (!ifs) error("nem megnyitható fájl ",fname);
    vector<double> vd;
    double d;
    while (ifs>>d) vd.push_back(d);

    // 3.2. feladat: írassuk ki vd elemeit

    cout << "\n3.2.: Írassuk ki vd elemeit";
    cout << "\nvd:\n";
    print(vd.begin(),vd.end());

    // 3.3. feladat: hozzuk létre vector<int> vi-t vd méretével, másoljuk át vd elemeit

    vector<int> vi(vd.size());
    copy(vd.begin(),vd.end(),vi.begin());

    // 3.4. feladat: írassuk ki vd és vi párjait

    cout << "\n3.4.: Írassuk ki vd  és vi párjait";
    cout << "\n(vd,vi) párjai:\n";
    for (int i = 0; i<vd.size(); ++i) {
        cout << '(' << vd[i] << ',' << vi[i] << ")\n";
    }

    // 3.5. feladat: összegezzük vd elemeit és írassuk ki

    cout << "\n3.5.: Összegezzük vd elemeit és írassuk ki";
    double sum_vd = 0;
    sum_vd = accumulate(vd.begin(),vd.end(),sum_vd);
    cout << "\nvd elemeinek összege: " << sum_vd << '\n';

    // 3.6. írassuk ki vd és vi elemeinek összegének a különbségét

    cout << "\n3.5.: Összegezzük vd elemeit és írassuk ki";
    int sum_vi = 0;
    sum_vi = accumulate(vi.begin(),vi.end(),sum_vi);
    cout << "\nvd elemösszegének és vi elemösszegének különbsége: " << sum_vd - sum_vi << '\n';

    // 3.7. feladat: fordítsuk meg vd elemeit és írassuk ki

    cout << "\n3.7.: Fordítsuk meg vd elemeit és írassuk ki";
    reverse(vd.begin(),vd.end());
    cout << "\nvd forgatás után:\n";
    print(vd.begin(),vd.end());

    // 3.8. feladat: adjuk meg vd számtani közepét

	cout << "\n3.8.: Adjuk meg vd számtani közepét";
    double vd_mean = sum_vd / vd.size();
    cout << "\nSzámtani közepe a vd-nek: " << vd_mean << '\n';

    // 3.9. feladat: hozzuk létre vector<double> vd2-t
    // másoljuk át vd elemei közül azokat amik kevesebbek mint vd átlaga

    cout << "\n3.9.: Másoljuk át vd elemei közül azokat amik kevesebbek mint vd átlaga";
    vector<double> vd2(count_if(vd.begin(),vd.end(),Less_than<double>(vd_mean)));
    copy_if(vd.begin(),vd.end(),vd2.begin(),Less_than<double>(vd_mean));
    cout << "\nvd2:\n";
    print(vd2.begin(),vd2.end());

    // 3.10. feladat: rendezzük ismét vd-t és írassuk ki
    
    cout << "\n3.10.: Rendezzük ismét vd-t és írassuk ki";
    sort(vd.begin(),vd.end());
    cout << "\nvd:\n";
    print(vd.begin(),vd.end());
}

int main()
{
    f1();

    f2();

    f3();

    f4();
}