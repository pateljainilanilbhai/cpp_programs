#include<iostream>
#include<cstdio>
using namespace std;
class num
{
    int a;
    int b;
    public:
    void getdata()
    {
        cout<<"enter a and b"<<endl;
        cin>>a>>b;
    }
    void putdata()
    {
        cout<<"a= "<<a<<"  b= "<<b<<endl;
    }
    num operator -(num n)
    {
        num sub;
        sub.a=a-n.a;
        sub.b=b-n.b;
        return sub;
    }
    int operator ==(num n2)
    {
        if(a==n2.a&&b==n2.b)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

};
int main()
{
    num n1,n2,n3;
    cout<<"for number 1"<<endl;
    n1.getdata();
    cout<<"for number 2"<<endl;
    n2.getdata();
    n3=n1-n2;
    cout<<"after n3=n1-n2"<<endl;
    n3.putdata();
    if(n1==n2)
    {
        cout<<"object are same";
    }
    else
    {
        cout<<"object are different";
    }

    return 0;
}



