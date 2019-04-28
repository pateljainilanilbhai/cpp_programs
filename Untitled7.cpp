#include<iostream>
using namespace std;
inline int add(int,int);
inline int sub(int,int);
inline int mul(int,int);
int main()
{
    int a,b,c;
    cout<<"enter two number"<<endl;
    cin>>a>>b;
    c=add(a,b);
    cout<<"addition is "<<c<<endl;
    c=sub(a,b);
    cout<<"subtraction is "<<c<<endl;
    c=mul(a,b);
    cout<<"multiplication is "<<c<<endl;
}
inline int add(int a,int b)
{
    return a+b;
}
inline int sub(int a,int b)
{
    return a-b;
}
inline int mul(int a,int b)
{
    return a*b;
}
