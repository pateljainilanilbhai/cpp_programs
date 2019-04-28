#include<iostream>

using namespace std;

class shape
{
    string shapename;
public:
    void getdatas()
    {
        cout<<"enter shape:";
        cin>>shapename;
    }
    void putdatas()
    {
        cout<<shapename<<endl;
    }
};
class circle:public shape
{
    public:
    float radius;

    void getr()
    {
        cout<<"enter radius:";
        cin>>radius;
    }
    void putr()
    {
        cout<<radius<<endl;
    }


};
class area:public circle
{
    float area;

    public:
    void display()
    {
         area=radius*radius*3.14;
        cout<<"area="<<area<<endl;;
    }

};
int main()
{
    area a;
    a.getdatas();
    a.getr();
    a.putdatas();
    a.putr();
    a.display();

}
