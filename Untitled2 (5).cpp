#include<iostream>
using namespace std;
int main()
{
    bool a = 321, b;
    cout << "Bool a Contains : " << a<<endl;
    int c = true;
   int d = false;
    cout<<"c = "<<c <<endl<<"d = "<<d;
    c = a + a;
    cout << "\nInteger c contain : " << c;
    b = c + a;
    cout << "\nBool b contain : " <<b;
    return 0;
}
