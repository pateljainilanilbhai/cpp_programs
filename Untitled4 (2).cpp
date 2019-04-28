#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;
int convert(int a);
float convert(float b);
char convert(char c);
int main()
{
    cout<<"enter rupees"<<endl;
    int r,p;
    cin>>r;
    p=convert(r);
    cout<<"paisa ="<<p<<endl;



    cout<<"enter metre"<<endl;
    int m,cm;
    cin>>m;
    cm=convert(m);
    cout<<"centimetre="<<cm<<endl;


     cout<<"enter char in lower case"<<endl;
    char c,d;
    cin>>c;
    d=convert(c);
    cout<<"upper case=  "<<d<<endl;



}
int convert(int a)
{
    return a*100;
}

float convert(float b)
{
    return b*100;
}
char convert(char c)
{
    return c-32;
}
