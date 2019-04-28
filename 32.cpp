#include<iostream>
#include<cstdio>
using namespace std;
class money
{
    int rs;
    int p;
    public:
    money(){};
    money(int x)
    {
        rs=x/100;
        p=x%100;
    }
    void putdata()
    {
        cout<<rs<<" rupee "<<p<<" paisa ";
    }

};
int main()
{
    money m1;
    m1=115;
    m1.putdata();
}
