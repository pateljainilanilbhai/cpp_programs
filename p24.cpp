#include<iostream>
using namespace std;
class customer;
class manager
{
    char name[30];
    int id=10;
public:
    void getdata()
    {
        cout<<"Enter manager name  ";
        cin>>name;
        cout<<"Enter manager number  ";
            }
     void get_cust_data(customer a);
};
class customer
{
    char name[30];
    int cno;
public:
    void getdata()
    {
        cout<<"Enter customer name  ";
        cin>>name;
        cout<<"Enter customer number  ";
        cin>>cno;
    }
    friend void manager::get_cust_data(customer a);
};

 void manager::get_cust_data(customer a)
{

        cout<<"The customer name is  "<<a.name<<endl;
        cout<<"the customer number is "<<a.cno<<endl;

}
int main()
{
    customer a,a2;
    manager b,b2;
    a.getdata();
    b.getdata();
    b.get_cust_data(a);
    a2.getdata();
    b2.getdata();
    b2.get_cust_data(a2);

}
