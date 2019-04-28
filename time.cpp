#include<iostream>
#include<cstring>

using namespace std;
class h12;
class h24
{

public:
    int hh,mm,sec;
    void getdata()
    {
        cout<<"24 hr time:"<<endl;
        cout<<"enter hh mm sec"<<endl;
        cin>>hh>>mm>>sec;
    }
    void putdata()
    {
        cout<<hh<<":"<<mm<<":"<<sec;
    }

    h24(){}
    h24 (h12 aa)
    {
        if(aa.pm==1)
        {
            hh=12;
        }
        hh=hh+aa.hrs;
        mm=aa.mm;
        sec=0;
    }

};
class h12
{
    public:
    bool pm;
    int hrs;
    int min;
    h12():pm(true),hrs(0),min(0){}
    h12(bool am,int h,int m):pm(am),hrs(h),min(m){}
    h12(h24 a)
    {
        if(a.hh>12)
        {
            pm=true;
            hrs=a.hh-12;

        }
        if(a.hh<=12)
        {
            pm=false;
            hrs=a.hh;

        }

        min=a.mm;
    }
    void putdata()
    {
        cout<<hrs<<":"<<min<<":";
        cout<<pm?cout<<"pm":cout<<"am";
    }
    void getdata()
    {
        string a;
        cout<<"enter hours in h12:";
        cin>>hrs;
        cout<<"enter min";
        cin>>min;

            cout<<"enter am/pm";
            cin>>a;
            if(a=="pm")
            {
                pm=true;
            }
            else if(a=="am")
            {
                pm=false;
            }
            else
            {
                cout<<"type am/pm again";

            }
    }
    friend h24;
};
int main()
{
    h12 a;
    h24 b;
    int s;
    cout<<"1.to convert 12 hrs to 24 hrs"<<endl;
    cout<<"2.to convert 24 hrs to 12 hrs"<<endl;
    cout<<"type your choice";
    cin>>s;

       if(s==1)
    {
        a.getdata();
        b=a;
        cout<<"converted to 24 hrs"<<endl;
        b.putdata();
    }
    if(s==2)
    {
        b.getdata();
        a=b;
        cout<<"converted to 12 hrs"<<endl;
        a.putdata();
    }
    cout<<endl<<"ending program successfully"<<endl;
    return 0;
}
