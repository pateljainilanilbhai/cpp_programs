#include<iostream>
using namespace std;
class cust
{
    int initialbalance;
    int credits;
    int totalcredits;
    int totalbill;
    int temp;
    int savebalance;
public:
     int accountno;
    cust(){
         accountno=0;
         credits=0;
        temp=0;
        savebalance=0;
        initialbalance=0;
        totalcredits=0;
        totalbill=0;

        }

    void getdata()
    {
            cout<<"welcome "<<accountno<<endl;
            cout<<"paying cash to your card or press 0:\n";
            cin>>temp;
            initialbalance=temp+initialbalance;
            cout<<"enter total bill\n";
            cin>>totalbill;
            credits=0.1*totalbill;
            totalcredits=totalcredits+credits;
            if(totalcredits>5000)
            {
                cout<<"total cretits were"<<totalcredits;
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
                cout<<"\nyou have to pay forcefully:"<<-initialbalance;
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
        cust c[10];
        for(int i=0;i<10;i++)
        {
            c[i].accountno=i;
        }
    start:
    cout<<"enter your customer no"<<endl;
        cin>>no;
    c[no].getdata();
    cout<<"\n enter 1 to proceed and 2 to end";
    cin>>no;
    if(no==1)
    {
        goto start;
    }
}
