#include<iostream>
using namespace std;
class manager;
class customer
{
    public:
    string name;
    int number;
    public:
    void getdata()
    {
        cout<<"enter customer name"<<endl;
        cin>>name;
        cout<<"enter number"<<endl;
        cin>>number;
    }
     friend manager::void get_cust_data(customer);

};
class manager
{
    string name;
    int id;
    public:
     void getdata()
    {
        cout<<"enter manager name"<<endl;
        cin>>name;
        cout<<"enter id"<<endl;
        cin>>id;
    }

     void get_cust_data(customer c);
};
void manager::get_cust_data(customer c)
    {
        cout<<"customer name is:"<<c.name<<endl<<"customer number is:"<<c.number<<endl;
    }
int main()
    {
        customer c;
        manager m;
        c.getdata();
        m.getdata();
        m.get_cust_data(c);
        return 0;
    }
