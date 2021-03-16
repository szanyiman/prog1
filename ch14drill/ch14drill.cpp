#include "std_lib_facilities.h"


/*
1. Define a class B1 with a virtual function vf() and a non-virtual function f().
Define both of these functions within class B1. Implement each function
to output its name (e.g., B1::vf()). Make the functions public.
*/
class B1 {
public:
    virtual void vf()
    {
        cout << "B1::vf()" << endl;
    }
 
    void f()
    {
        cout << "B1::f()" << endl;
    }
    virtual void pvf() {cout << "D2::pvf()" << endl;}
};

/*
2. Derive a class D1 from B1 and override vf(). Make a D1 object and call vf()
and f() for it.
*/
class D1 : public B1 {
public:
    void vf()
    {
        cout << "D1::vf()" << endl;
    }
 
    void f()
    {
        cout << "D1::f()" << endl;
    }
};

//6. Define a class D2 derived from D1 and override pvf() in D2.

class D2 : public D1 {
public:
    void pvf() { cout << "D2::pvf()" << endl; }
};

//7. Define a class B2 with a pure virtual function pvf().

class B2 {
public:
	virtual void pvf() = 0;
};

/*
7./a Define a class D21
with a string data member and a member function that overrides pvf();
D21::pvf() should output the value of the string.
*/

class D21 : public B2 {
public:
    void pvf() { cout << k << endl; }
    string k;
};

/*
7./b Define a class D22 that is just like D21
except that its data member is an int.
*/

class D22 : public B2 {
public:
    void pvf() { cout << sz << endl; }
    int sz;
};

/*
7./c Define a function f() that takes a B2& argument
and calls pvf()for its argument. Call f() with a D21 and a D22.
*/

void f(B2& b2)
{
    b2.pvf();
}

int main() {

	//1. Make a B1 object and call each function. 

    B1 b1;
    b1.vf();
    b1.f();

    //2. Make a D1 object and call vf() and f() for it.

    D1 d1;
    d1.vf();
    d1.f();

    /*3. Define a reference to B1 (a B1&) and initialize that to the D1 object you
	  just defined. Call vf() and f() for that reference.*/

    B1& br = d1;
    br.vf();
    br.f();

    //6. Make an object of class D2 and invoke f(), vf(), and pvf() for it

    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();

    //7./d Call f() with a D21 and a D22.

    D21 d21;
    d21.k = "d21";
    D22 d22;
    d22.sz = 532;
    f(d21);
    f(d22);
}