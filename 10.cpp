#include<iostream>
using namespace std;
class date
{
    public:
        bool leapYear(int year)
{
    return(year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}
    int dd,mm,yy;
    date()
    {

    }
    date (int x)
    {
        dd=x;
    }
    date(int x,int y,int z)
    {
        dd=x;
        mm=y;
        yy=z;
    }
    void getdata()
    {
        cout<<"enter date in dd mm yyyy format:";
        cin>>dd>>mm>>yy;
    }
    void putdata()
    {
        cout<<dd<<"/"<<mm<<"/"<<yy<<endl;
    }
    void operator ++()
    {
        ++dd;
    }
    date operator ++(int x)
    {
        dd++;
        return date(dd);
    }
        void operator --()
    {
        --dd;
    }
    date operator --(int x)
    {
        dd--;
        return date(dd);
    }
    void check()
    {
        if(dd==0&&mm==1)
        {
            dd=31;
            mm=12;
            yy=yy-1;
        }
        if(dd==32&&mm==1)
        {
            dd=1;
            mm=2;
        }
        if(dd=29&&mm==2&&leapYear(yy)==0)
        {
            dd=1;
            mm=2;
        }
        if(dd==0&&mm==2)
        {
            dd=31;
            mm=1;
        }
        if(dd==30&&mm==2)
        {
            dd=1;
            mm=3;
        }
        if(dd==0&&(mm==3)&&leapYear(yy)==1)
        {
            dd=29;
            mm=2;
        }
           if(dd==0&&(mm==3)&&leapYear(yy)==0)
        {
            dd=28;
            mm=2;
        }
        if(dd==32&&(mm==3||mm==5||mm==7||mm==8||mm==10))
        {
            dd=1;
            mm=mm+1;
        }
            if(dd==31&&(mm==4||mm==6||mm==9||mm==11))
        {
            dd=1;
            mm=mm+1;
        }
        if(dd==0&&(mm==5||mm==10||mm==12))
        {
            dd=30;
            mm=mm-1;
        }
            if(dd==0&&(mm==4||mm==6||mm==9||mm==11))
        {
            dd=31;
            mm=mm-1;
        }
        if(dd==0&&mm==7)
        {
            dd=30;
            mm=6;
        }
        if(dd==0&&mm==8)
        {
            dd=31;
            mm=7;
        }
        if(dd==32&&mm==12)
        {
            yy=yy+1;
            mm=1;
            dd=1;
        }
    }
};
int main()
{
    date d1;
    d1.getdata();
    d1--;
    d1.check();
    cout<<"after d1--:";
    d1.putdata();
    d1++;
    d1.check();
    cout<<"after d1++:";
    d1.putdata();
}

