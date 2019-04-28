#include<iostream>
#include<cstdio>
using namespace std;
class dist
{
    int feet;
    float inches;
    public:
    void getdata()
    {
        cout<<"enter feet and inches"<<endl;
         cin>>feet>>inches;
    }
    void putdata()
    {
        cout<<feet<<"'"<<inches<<"''"<<endl;
    }
    dist add(dist b)
    {
        dist c;
        c.feet=feet+b.feet;
        c.inches=inches+b.inches;
        return c;
    }
};
int main()
{
    dist d1,d2,d3;
    d1.getdata();
    d1.putdata();
    d2.getdata();
    d2.putdata();
    d3=d1.add(d2);
    cout<<"addition is  >><< ";
    d3.putdata();
}
