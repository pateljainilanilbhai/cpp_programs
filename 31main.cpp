/*Create a class Measure having members: meter and cm. The class has

get( ) and put( ) functions. Overload operator + and – such that they

support M1=M2+15 and M3=M1 – 4.5. Also overload + and – such

that they support M1=5.0+M2 and M3=2.0 – M4. Write a main( ) to

test the class.

Use the concept of Overloading Binary Operators with friend

function.*/

#include<iostream>
#include<cstdio>
using namespace std;
class measure
{
    int metre;
    int cm;
    public:
    void get()
    {
        cout<<"enter metre:";
        cin>>metre;
        cout<<"enter centimetre:";
        cin>>cm;
        start:
        if(cm>100)
        {
            int x;
            x=cm/100;
            metre=metre+x;
            cm=cm%100;
            goto start;
        }
        else
        {
            cout<<"you have entered "<<metre<<" metre "<<cm<<" centimetre "<<endl;
        }
    }
    void put()
    {
        cout<<metre<<" metre "<<cm<<" centimetre "<<endl;
    }
   friend void display(measure m1,measure m2,measure m3,measure m4);
   friend measure operator +(measure m,int x);
   friend measure operator -(measure m1,float f);
   friend measure operator +(float f,measure m1);
   friend measure operator -(float f,measure m1);

};
measure operator +(measure m,int x)
{
    m.metre=m.metre+x;
    return m;
}
measure operator -(measure m1,float f)
{
    float z=m1.metre+((float)m1.cm/100);
    float y=z-f;
    cout<<y<<"m ";
    measure ans;
    ans.metre=(int)y;
    ans.cm=(y-(int)y)*100;
    return ans;
}
measure operator +(float f,measure m1)
{
    float z=m1.metre+((float)m1.cm/100);
    float y=f+z;
    cout<<y<<"m ";
    measure ans;
    ans.metre=(int)y;
    ans.cm=(y-(int)y)*100;
    return ans;
}
measure operator -(float f,measure m1)
{
    float z=m1.metre+((float)m1.cm/100);
    float y=f-z;
    cout<<y<<"m ";
    measure ans;
    ans.metre=(int)y;
    ans.cm=(y-(int)y)*100;
    return ans;
}
void display(measure m1,measure m2,measure m3,measure m4)
{
    cout<<"m1:"<<m1.metre<<"."<<m1.cm<<"m"<<endl;
    cout<<"m2:"<<m2.metre<<"."<<m2.cm<<"m"<<endl;
    cout<<"m3:"<<m3.metre<<"."<<m3.cm<<"m"<<endl;
    cout<<"m4:"<<m4.metre<<"."<<m4.cm<<"m"<<endl;

}
int main()
{
    measure m1,m2,m3,m4;
    cout<<" for m2"<<endl;
    m2.get();
    cout<<" for m4"<<endl;
    m4.get();
    m1=m2+15;
    cout<<" for m1=m2+15"<<endl;
    m1.put();
    m3=m1-4.563;
    cout<<" for m3=m1-4.5"<<endl;
    m3.put();
    m1=5.0+m2;
    cout<<" for m1=5.0+m2"<<endl;
    m1.put();
    m3=2.0-m4;
    cout<<" for m3=2.0-m4"<<endl;
    m3.put();
    cout<<"LAST DISPLAY:"<<endl;
    display(m1,m2,m3,m4);
    return 0;
}
