#include<iostream>
using namespace std;



class X {

public:

    virtual void f() { cout<<"1"; } //1

    void g() { cout<<"2"; } //2

};



class Y : public X {

public:

    void f() { cout<<"3" ;} //3

    virtual void g() {cout<<"4" ; }//4

};



int main() {

    X x; Y y;

    X& rx = y;

    x.f();

    x.g();

    rx.f();

    rx.g();

    return 0;

}
