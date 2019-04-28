#include<iostream>
#include<cstdio>
using namespace std;
class mobile
{
    int year;
    float price;
public:

    void getdata()
    {
        cout<<"enter year of manufacturing:";
        cin>>year;
        cout<<"enter price:";
        cin>>price;
    }
    void putdata()
    {
        cout<<"year:"<<year<<"           "<<"price:"<<price<<endl;
    }
    int validity()
    {
        if(year<2005)
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
    mobile m[4];
    for(int i=0;i<4;i++)
    {
        m[i].getdata();
    }
    cout<<"OLDER MOBILES ARE :"<<endl;
    for(int i=0;i<4;i++)
    {
        if((m[i].validity())==1)
        {
            m[i].putdata();
        }
    }
}
