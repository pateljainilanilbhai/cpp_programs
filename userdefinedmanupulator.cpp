#include<iostream>
using namespace std;
class cust
{
    int accountno;
    int initialbalance=0;
    int credits;
    int totalcredits=0;
    int totalbill=0;
    int temp;
    int savebalance;
public:
cust(){}
    cust(int a)
    {
        accountno=a;
    }
    void getdata()
    {
            cout<<"welcome ";
            cout<<"paying cash to your card or press 0:\n";
            cin>>temp;
            initialbalance=temp+initialbalance;
            cout<<"enter total bill\n";
            cin>>totalbill;
            credits=0.1*totalbill;
            totalcredits=totalcredits+credits;
            if(totalcredits>5000)
            {
                cout<<"credits limit extended \n";
                cout<<"your credits are 5000 now\n";
                totalcredits=5000;
            }
            else
            {
                cout<<"credits are "<<totalcredits;
            }
            initialbalance=initialbalance-totalbill+totalcredits;
            cout<<"\n your last balance: "<<initialbalance;
            if(initialbalance<0)
            {
                int a;
                cout<<"you have to pay forcefully:"<<-initialbalance;
                cin>>a;
                initialbalance=initialbalance+a;
            }
            savebalance=initialbalance;
    }
    int getno()
    {
        return accountno;
    }
};
int main()
{
    int no;
    start:

        cout<<"\nenter your customer no"<<endl;
        cin>>no;
    cust c[10];
    c[no]=no;
    c[no].getdata();
    cout<<"\n enter 1 to proceed and 2 to end";
    cin>>no;
    if(no==1)
    {
        goto start;
    }

}
