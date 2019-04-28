#include<iostream>
using namespace std;
class transaction
{
public:
    static double amount;
    static int accountnumber;

    void getaccountno()
    {
        cout<<"enter account no";
        cin>>accountnumber;
        amount=0;
    }
    virtual void execute()=0;
};
double transaction::amount;
int transaction::accountnumber;
class balanceinquiry:public transaction
{
    public:
    void execute()
    {
        cout<<"account number is:"<<transaction::accountnumber<<endl;
        cout<<"Your current balance is:"<<transaction::amount<<endl;
    }
};
class withdrawal:public transaction
{
        double a;
    public:
void execute()
    {
        cout<<"how many money you have withdrawn:"<<endl;
        cin>>a;
        transaction::amount-=a;
    }

};

class deposit:public transaction
{
    double a;
public:
    deposit()
    {

    }
    void execute()
    {
        cout<<"how much you deposit"<<endl;
        cin>>a;
        transaction::amount=transaction::amount+a;
    }
};
class customer:public balanceinquiry,public withdrawal,public deposit
{

};
int main()
{
    customer c;
    c.deposit::getaccountno();
    c.deposit::execute();
    c.withdrawal::execute();
    c.balanceinquiry::execute();
}
