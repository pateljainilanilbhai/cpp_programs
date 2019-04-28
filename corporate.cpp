#include<iostream>
using namespace std;
class education;
class corporate
{
    string nameofemployee;
    float salary;
    public:
    friend compare(corporate c,education e);
    getdata()
    {
        cout<<"enter name of corporate employee"<<endl;
        cin>>nameofemployee;
        cout<<"enter salary of corporate employee"<<endl;
        cin>>salary;
    }
    putdata()
    {
        cout<<"name:"<<nameofemployee<<" salary:"<<salary<<endl;
    }
};
class education
{
    string nameofemployee;
    float salary;
    public:
    friend compare(corporate c,education e);
    getdata()
    {
        cout<<"enter name of corporate employee"<<endl;
        cin>>nameofemployee;
        cout<<"enter salary of corporate employee"<<endl;
        cin>>salary;
    }
     putdata()
    {
        cout<<"name:"<<nameofemployee<<" salary:"<<salary<<endl;
    }

};
compare(corporate c,education e)
{
    if(c.salary==e.salary)
    {
        cout<<"both salary are equal";
    }
    else if(c.salary>e.salary)
    {
        cout<<"corporate salary is higher than education salary"<<endl;
        c.putdata();
    }
    else
    {

        cout<<"education salary is higher than corporate salary"<<endl;
        e.putdata();
    }
}
int main()
{
    corporate c;
    education e;
    c.getdata();
    e.getdata();
    compare(c,e);
    return 0;
}
