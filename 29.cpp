#include<iostream>
using namespace std;
class complex
{
    int real,img;
public:
    void getdata()
    {
        cout<<"enter real and imaginary part"<<endl;
        cin>>real>>img;
    }
    void putdata()
    {
        cout<<real<<"+"<<"("<<img<<")"<<"i";
    }
    complex(){real=0,img=0;}
    complex(int x,int y){real=x;img=y;}
    friend void operator -(complex &c);

};
 void operator -(complex &c)
    {
        c.real=-c.real;
        c.img=-c.img;

    }
int main()
{
    complex c1;
    c1.getdata();
    -c1;
    c1.putdata();
}
