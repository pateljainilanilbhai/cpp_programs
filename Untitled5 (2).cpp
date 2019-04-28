#include<iostream>
using namespace std;
void swap(char &a,char &b);
void swap(int &a,int &b);
void swap(float &a,float &b);
void swap(double &a,double &b);
int main()
{
    int a,b;
    cout<<"enter two integer"<<endl;
    cin>>a>>b;
    swap(a,b);
    cout<<"swapped integer are"<<a<<" "<<b<<endl;

    float e,f;
    cout<<"enter two floating  value"<<endl;
    cin>>e>>f;
    swap(e,f);
    cout<<"swapped float are"<<e<<" "<<f<<endl;

    double p,q;
    cout<<"enter two double value"<<endl;
    cin>>p>>q;
    swap(p,q);
    cout<<"swapped integer are"<<p<<" "<<q<<endl;

    char x,y;
    cout<<"enter two characters"<<endl;
    cin>>x>>y;
    swap(x,y);
    cout<<"swapped integer are"<<x<<" "<<y<<endl;

    return 0;
}

void swap(char &a,char &b)
{
    char t;
    t=a;
    a=b;
    b=t;
}

void swap(int &a,int &b)
{
    int t;
    t=a;
    a=b;
    b=t;
}
void swap(float &a,float &b)
{
    float t;
    t=a;
    a=b;
    b=t;
}
void swap(double &a,double &b)
{
    double t;
    t=a;
    a=b;
    b=t;
}
