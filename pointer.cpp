/*Write a C++ program to add two floating numbers using pointer. The result should contain only two digits after the decimal.
Use fixed, scientific and setprecision () manipulators for controlling the precision of floating point numbers.*/
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int main()
{
    float a,b,c;
    float *p,*q,*r;
    p=&a;
    q=&b;
    r=&c;
    cout<<"enter first number"<<endl;
    cin>>*p;
    cout<<"enter second number"<<endl;
    cin>>*q;
    *r=*p+*q;
    cout<<fixed<<*r<<endl;
    cout<<scientific<<*r<<endl;
    cout<<fixed<<setprecision(2)<<*r<<endl;
    return 0;

}
