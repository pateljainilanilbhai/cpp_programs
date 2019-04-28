#include<iostream>
#include<cstdio>
using namespace std;
class dist
{
    float inches;
    float feet;
    public:
    void getdata()
    {
        cout<<"enter feet"<<endl;
        cin>>feet;
        cout<<"enter inches"<<endl;
        cin>>inches;
    }
    void putdata()
    {
        cout<<feet<<"'"<<inches<<"''";
    }
    void scale(dist &a,float b)
    {
        a.feet*=b;
        a.inches*=b;
    }

};
int main()
    {
        dist d1;
        float f;
        d1.getdata();
        cout<<"enter scale value::";
        cin>>f;
        d1.scale(d1,f);
        d1.putdata();
    }
