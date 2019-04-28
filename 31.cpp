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
        cout<<"enter metre"<<endl;
        cin>>metre;
        cout<<"enter centimetre"<<endl;
        cin>>cm;
    }
    void put()
    {
        cout<<"metre "<<metre<<"centimetre "<<cm<<endl;
    }
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
    int n,cm;
    measure ans;
    ans.metre=m1.metre-(int)f;
    n=(int)f;
    cm=(f-n)*100;
    ans.cm=m1.cm-cm;
    return ans;
}
measure operator +(float f,measure m1)
{
    float z=m1.metre+((float)m1.cm/100);
    float y=f+z;
     int n,cm;
    measure ans;
    ans.metre=m1.metre+(int)f;
    n=(int)f;
    cm=(f-n)*100;
    ans.cm=m1.cm+cm;
    return ans;
}
measure operator -(float f,measure m1)
{
    float z=m1.metre+((float)m1.cm/100);
    float y=f-z;
    int n,cm;
    measure ans;
    ans.metre=-m1.metre+(int)f;
    n=(int)f;
    cm=(f-n)*100;
    ans.cm=-m1.cm+cm;
    return ans;
}
int main()
{
    measure m1,m2,m3,m4;
    cout<<"for m2"<<endl;
    m2.get();
    cout<<"for m4"<<endl;
    m4.get();
    m1=m2+15;
    cout<<"for m1=m2+15"<<endl;
    m1.put();
    m3=m1-4.5;
    cout<<"for m3=m1-4.5"<<endl;
    m3.put();
    m1=5.0+m2;
    cout<<"for m1=5.0+m2"<<endl;
    m1.put();
    m3=2.0-m4;
    cout<<"for m3=2.0-m4"<<endl;
    m3.put();
}
