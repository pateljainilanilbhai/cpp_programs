#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
template <class T>
void swapp(T &a,T &b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}
template <class T>
void bubble(T v[],int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
    {
        if(v[i]>v[j])
        swapp(v[i],v[j]);
    }
}

int main()
{
    long double a[100000];
    for(long double i=0;i<100000;i++)
    {
        a[(int)i]=i*i*i*i;
    }
    ofstream f("four.txt");
    for(long double i=0;i<100000;i++)
    {
        f<<i;
        f<<setw(30)<<fixed<<a[(int)i]<<" \n";
    }
}

