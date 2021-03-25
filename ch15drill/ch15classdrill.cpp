// g++ ch15classdrill.cpp -o main
#include "Simple_window.h"
#include "Graph.h"
//1. Define a struct Person containing a string name and an int age.
struct Person {
//4. Give Person a constructor initializing name and age,
    Person() : first_n(""), second_n(""), a(0) { }
/*7. Modify the constructor to check that age is [0:150) and that name doesn’t
contain any of the characters ; : " ' [ ] * & ^ % $ # @ !. Use error() in case
of error. Test.*/
    Person(string fn, string sn, int age) :first_n(fn), second_n(sn), a(age)
    {
        const string helyt_kar = ";:\"'[]*&^%$#@!";
        for (int i = 0; i<fn.size(); ++i)
            for (int j = 0; j<helyt_kar.size(); ++j)
                if (fn[i]==helyt_kar[j]) error("helytelen karakter: ",string(1,fn[i]));
        for (int i = 0; i<sn.size(); ++i)
            for (int j = 0; j<helyt_kar.size(); ++j)
                if (sn[i]==helyt_kar[j]) error("helytelen karakter: ",string(1,sn[i]));
        if (a<0 || a>=150) error("helytelen megadott kor");
    }
/*5. Make the representation of Person private, and provide const member.
functions name() and age() to read the name and age.*/
/*9. Change the representation of Person to have first_name and second_name
instead of name. Make it an error not to supply both a first and a second
name. Be sure to fix >> and << also. Test.*/
    string first_name() const { return first_n; }
    string second_name() const { return second_n; }
    int age() const { return a; }
private:
    string first_n;
    string second_n;
    int a;
};

istream& operator>>(istream& is, Person& p)
{
    string fname, sname;
    int age;
    is >> fname >> sname >> age;
    if (!is) return is;
    p = Person(fname,sname,age);
    return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
    return os << "Név: " << p.first_name() << ' ' <<
        p.second_name() << ", kor: " << p.age();
}

int main(){
/*2. Define a variable of type Person, initialize it with “Goofy” and 63, and
    write it to the screen (cout).*/
/*  Person p;
    p.n = "Goofy";
    p.a = 63;
    cout << "Név: " << p.n << ", kor: " << p.a << endl;
*/

/*3. Define an input (>>) and an output (<<) operator for Person; read in a
Person from the keyboard (cin) and write it out to the screen (cout).*/
    cout << "Kérem adja meg a nevét és korát: ";
    Person p2;
    cin >> p2;
    cout << p2 << endl;


//6. Modify >> and << to work with the redefined Person.
/*  Person p3;
    while (cin>>p3) {cout << p3 << endl;}
*/
/*8. Read a sequence of Persons from input (cin) into a vector<Person>;
write them out again to the screen (cout). Test with correct and erroneous input.*/
    cout << "Adjon meg neveket és korokat: " << endl;
    vector<Person> persons;
    Person p4;
    while (cin>>p4) {persons.push_back(p4);cout<<"Adja meg a következő személy nevét, korát: " << endl;}
    for (int i = 0; i<persons.size(); ++i)
        cout << persons[i] << endl;
    keep_window_open("~");
}