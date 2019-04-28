#include<iostream>
#include <sstream>
#include<string>
#include<math.h>
using namespace std;
class q
{
    public:
    int f=-1;
    int r=-1;
    char a[5];

    void anque(char x)
    {
        if(r!=50){
        if(f==-1)
        {
            f=0;

        }
        r++;
        a[r]=x;
        }
        else
        {
            cout<<"overflow";
        }
    }
    char dequee()
    {
        if(f==r+1)
        {
            f=-1;
            r=-1;


            return '/';
            cout<<"underflow occured \n";
        }
        else
        {
            f++;
            return a[f-1];

        }
    }

};
int main()
{
    q a;
    q b;
    q c;
    a.anque('1');
    a.anque('2');
    a.anque('3');
    a.anque('4');
    a.anque('5');
    b.anque('6');
    b.anque('7');
    c.anque('8');
    c.anque('9');
    c.anque('10');
    for(int i=0;i<3;i++)
    {
        b.anque(a.dequee());
    }
    for(int i=0;i<4;i++)
    {
        c.anque(b.dequee());
    }
    for(int i=0;i<5;i++)
    {
        c.dequee();
    }
    char d;
    d=a.dequee();
    cout<<"\n queue a :\n";
    while(d!='/')
    {

        cout<<d<<" ";
         d=a.dequee();
    }
     d=b.dequee();
    cout<<"\n queue b :\n";
    while(d!='/')
    {

        cout<<d<<" ";
        d=b.dequee();
    }
    d=c.dequee();
    cout<<"\n queue c :\n";
    while(d!='/')
    {

        cout<<d<<" ";
         d=c.dequee();
    }
}
