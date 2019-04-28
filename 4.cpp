#include<iostream>
using namespace std;
class employee
{
    string firstname;
    string lastname;
    double salary;
    public:
    employee()
    {
        firstname="*";
        lastname="*";
        salary=0;
    }
    void set()
    {
        cout<<"enter your name eg. firstname lastname:";
        cin>>firstname>>lastname;
        cout<<"enter salary";
        cin>>salary;
        if(salary<0)
        {
            salary=0.0;
        }
    }
    void get()
    {
        cout<<firstname<<" "<<lastname<<" :"<<"rs"<<salary;
    }
     void raise()
    {
        salary=salary+(salary*0.1);
        salary=salary*12;

    }
};
int main()
{
    employee e[2];
    for(int i=0;i<2;i++)
    {
    e[i].set();
    e[i].get();
    e[i].raise();
    e[i].get();
    }
}
