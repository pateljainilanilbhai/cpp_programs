#include<iostream>
using namespace std;
class savingaccount
{
private:
    double savingbalance;
public:
    savingaccount()
    {
    }
    savingaccount(float x)
    {
        savingbalance=x;
    }
    static float annualinterestrates;
    void getbalance()
    {
        cout<<"enter balance"<<endl;
        cin>>savingbalance;
    }
    void monthlyinterest()
    {
        savingbalance=savingbalance+(savingbalance*annualinterestrates/12);
    }
    static modifyinterestrates(int b)
    {
        annualinterestrates=b;
    }
    void putdata()
    {
        cout<<"your current balance is :"<<savingbalance<<endl;
    }
};
float savingaccount::annualinterestrates;
int main()
{
    savingaccount saver1(2000);
    savingaccount saver2(3000);
    cout<<"interest rate is 4%"<<endl;
    saver1.modifyinterestrates(4);
    saver2.modifyinterestrates(4);
    saver1.monthlyinterest();
    saver2.monthlyinterest();
    cout<<"for saver1 new balance is:";
    saver1.putdata();
    cout<<"for saver2 new balance is:";
    saver2.putdata();
    cout<<"interest rate is 5%"<<endl;
    saver1.modifyinterestrates(5);
    saver2.modifyinterestrates(5);
    saver1.monthlyinterest();
    saver2.monthlyinterest();
    cout<<"for saver1 new balance is:";
    saver1.putdata();
    cout<<"for saver2 new balance is:";
    saver2.putdata();
}
