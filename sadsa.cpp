#include<iostream>
using namespace std;
class date
{
    int dd,mm,yy;
public:
    void getdata()
    {
        cout<<"enter date in dd mm yyyy fomat:";
        cin>>dd>>mm>>yy;
    }
    friend void swap(date& a,date& b);

    void putdata()
    {
        cout<<dd<<":"<<mm<<":"<<yy<<"\n";
    }
};
void swap(date &a,date &b)
    {
        date temp;
        temp=a;
        a=b;b=temp;
    }
int main()
{
    date a,b;
    a.getdata();
    b.getdata();
    swap(a,b);
    a.putdata();
    b.putdata();
}
