#include<iostream>
using namespace std;
class employee
{
    public:
        float fixedsalary;
    float salary;
    int hourworked;
    float itemsold;
    float itemprice;
    float totalsell;
    float salaryperhour=10;
    float overtimeperhour=10;
    virtual void calculate()=0;
    virtual void putdata()
    {
        cout<<"\nsarary of employee is "<<salary;
    }
    virtual void gethour()
    {
        cout<<"\nenter hour worked :\n";
        cin>>hourworked;
    }
    virtual void getitemsold()
    {
        cout<<"\nenter item sold by employee :\n";
        cin>>itemsold;
        cout<<"\nenter price of each item:\n";
        cin>>itemprice;
    }
};
class salaried:public employee
{
     public:
         void calculate()
         {
             fixedsalary=5000;
             salary=fixedsalary;
             putdata();
         }
};
class commission:public employee
{
     public:
         void calculate()
         {
             fixedsalary=0;
             getitemsold();
             totalsell=itemsold*itemprice;
             salary=0.10*totalsell;
             putdata();
         }
};
class hourly:public employee
{
     public:
         void calculate()
         {
             gethour();
             if(hourworked<=40)
             {salary=salaryperhour*hourworked;}
             if(hourworked>40)
             {
                 float d=hourworked-40;
                 salary=salaryperhour*hourworked;
                 salary=salary+salaryperhour*overtimeperhour;
             }
             putdata();

         }
};
class basepluscommission:public employee
{
     public:
         void calculate()
         {
             fixedsalary=0;
             getitemsold();
             totalsell=itemsold*itemprice;
             salary=0.10*totalsell;
             salary=salary+5000;
             putdata();
         }
};
int main()
{
    salaried s;
    cout<<"\nsalary employee:"<<endl;
    s.calculate();
    commission c;
    cout<<"\ncommission employee :"<<endl;
    c.calculate();
    hourly h;
    cout<<"\nhourly payed employee :"<<endl;
    h.calculate();
    basepluscommission b;
    cout<<"\nbase plus commission employee :"<<endl;
    b.calculate();
}
