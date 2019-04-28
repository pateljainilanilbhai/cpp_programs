#include<iostream>
using namespace std;
class vehicle
{
    public:
    float average;
    virtual void getdata()=0;
    virtual void putdata()=0;
};
class car:public vehicle
{
    string fuel;
    int noofwheels;
    public:
    void getdata()
    {
        cout<<"enter average of car"<<endl;
        cin>>average;
        cout<<"enter fuel type of car"<<endl;
        cin>>fuel;
        cout<<"enter number of wheels"<<endl;
        cin>>noofwheels;
    }
    void putdata()
    {
        cout<<"average of car="<<average<<endl<<"fuel of car="<<fuel<<endl<<"no of wheels of car"<<noofwheels<<endl;
    }
};
class truck:public vehicle
{

    string fuel;
    int noofwheels;
    public:
    void getdata()
    {
        cout<<"enter average of truck"<<endl;
        cin>>average;
        cout<<"enter fuel type of truck"<<endl;
        cin>>fuel;
        cout<<"enter number of truck"<<endl;
        cin>>noofwheels;
    }
     void putdata()
    {
         cout<<"average of truck="<<average<<endl<<"fuel of truck="<<fuel<<endl<<"no of wheels of truck"<<noofwheels<<endl;
    }
};
int main()
{
    truck t;
    car c;
    car d;
    c.getdata();
    c.putdata();
    d.getdata();
    d.putdata();
    t.getdata();
    t.putdata();

}
