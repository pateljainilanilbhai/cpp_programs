#include<cstring>
#include<iostream>
using namespace std;
class String;
class dist
{
    public:
    int feet;
    int inches;

    void getdata()
    {
        cout<<"enter feet"<<endl;
        cin>>feet;
        cout<<"enter inches"<<endl;
        cin>>inches;
    }
    void putdata()
    {
        cout<<feet<<" "<<inches<<endl;
    }
    dist operator +(dist a)
    {
        dist b;
        b.feet=feet+a.feet;
        b.inches=inches+a.inches;
        return b;
    }
};
class String
{
    public:
    char a[50];

    void getdata()
    {
        cout<<"enter string"<<endl;
        cin>>a;
    }
    void putdata()
    {
        cout<<a;
    }
    String operator +(String b)
    {
        String c;
        strcat(a,b.a);
        strcpy(c.a,a);

        return c;
    }
};
int main()
{
    dist d1,d2,d3;
    d1.getdata();
    d2.getdata();
    d3=d1+d2;
    d3.putdata();
    String s1,s2,s3;
    s1.getdata();
    s2.getdata();
    s3=s1+s2;
    s3.putdata();
    return 0;

}

