#include<iostream>
using namespace std;
double a[5];
double & setvalue(int i);
int main()
{

    int num;
    cout<<"enter a array of 5 double variable"<<endl;
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];

    cout<<"\n\n\n"<<endl;

    cout<<"enter a index to be changed"<<endl;
    cin>>num;

    setvalue(num);

    cout<<"new array is:"<<endl;
    int i;
    for (i=0;i<5;i++)
    {
        cout<<a[i]<<"   ";
    }
}
double & setvalue(int i)
{
    double t;
    cout<<"give exchanged value of index "<<i<<endl;
    cin>>t;
    a[i]=t;
    return a[i];
}
