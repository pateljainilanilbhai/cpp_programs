#include<iostream>
#include<cstdio>
using namespace std;
class date
{
    int dd,mm,yyyy;
    public:
    void getdata()
    {
        cout<<"enter date in dd mm yyyy format:";
        cin>>dd>>mm>>yyyy;
    }
    void putdata()
    {
        cout<<dd<<"/"<<mm<<"/"<<yyyy<<endl;
    }
    friend void swapdates(date &a,date &b)
    {
        date c;
        c=a;
        a=b;
        b=c;
    }
};
int main()
{
    date a,b;
    a.getdata();
    b.getdata();
    cout<<"date before swapping:"<<endl;
    a.putdata();
    b.putdata();
    swapdates(a,b);
    cout<<"date after swapping"<<endl;
    a.putdata();
    b.putdata();
}
