#include<iostream>
using namespace std;
class invoice
{
    string number;
    string description;
    int quantity;
    double priceperitem;
    public:
    invoice()
    {
        number="0";
        description="0";
        quantity=0;priceperitem=0;
    }
    void set()
    {
        cout<<"number:";
        cin>>number;
        cout<<"descciption:";
        cin>>description;
        cout<<"quantity:";
        cin>>quantity;
        if (quantity<0)
            quantity=0;
        cout<<"price per item:";
        cin>>priceperitem;
        if (priceperitem<0)
            priceperitem=0;
    }
    double getinvoice()
    {
        double d=quantity*priceperitem;
        return d;
    }
    void get()
    {
        cout<<number<<" "<<description<<" quantity:"<<quantity<<" price per item:"<<priceperitem;
        cout<<" total cost:"<<getinvoice();
    }

};
int main()
{
    invoice a;
    a.set();
    a.get();
}
