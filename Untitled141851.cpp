#include<iostream>
using namespace std;
int main()
{
    int n; int i=0;
    cout<<"ENTER THE NUMBER OF ARRAY"<<endl;
    int *p,*q;
    cin>>n;
    p=new int[n];
    q=p;
    for(i=0;i<n;i++)
    {
        cout<<"enter value of a\["<<i<<"\]"<<endl;
        cin>>*p;
        p++;
    }
    p=q;
    for(i=0;i<n;i++)
    {
        *p=*p+2;
        p++;
    }
    cout<<"ADDING 2 TO ALL POINTER VARIABLE"<<endl;
    p=q;
    for(i=0;i<n;i++)
    {
        cout<<*p<<endl;
        p++;

    }
    delete []p;
    delete q;
}
