#include<iostream>
using namespace std;


 class Base {

protected:

    int marker;

public:

    Base(int m = 4) : marker(m) {}

    virtual ~Base() {};

    virtual void Action() { ++marker; }

};

class Derived : public Base {

public:

    void Action() {

        static_cast<Base>(*this).Action();

        marker *= 2;

        cout << marker << endl;

    }

};



int main() {

    Base *p = new Derived;

    p->Action();

    return 0;

}
