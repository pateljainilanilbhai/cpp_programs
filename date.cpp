#include<iostream>
using namespace std;
class date
{
    int dd,mm,yyyy;
    public:
    getdata()
    {
    cout<<"enter date in dd mm yyyy format:";
    cin>>dd>>mm>>yyyy;
    }
    putdata()
    {
        cout<<dd<<":"<<mm<<":"<<yyyy<<endl;
    }
    friend swapdates(date &a,date &b)
    {
        date t;
        t=a;
        a=b;
        b=t;
    }
};
int main()
{
    date a,b;
    a.getdata();
    b.getdata();
    swapdates(a,b);
    cout<<"after swapping"<<endl;
    a.putdata();
    b.putdata();
}
