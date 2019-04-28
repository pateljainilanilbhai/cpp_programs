
#include<iostream>

using namespace std;

class base {

public:

    base() { cout << "c"; }

    virtual ~base() { cout << "~c"; }

};

class derived : public base {

public:

    derived() {	cout << "d"; }

    ~derived() { cout << "~d"; }

};

int main(void)

{

    {

        derived *d = new derived();

        base *b = d;

        delete b;

    }

    return 0;

}
