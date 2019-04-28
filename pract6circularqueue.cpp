
#include<iostream>
#include <sstream>
#include<string>
#include<math.h>
using namespace std;
class cirqularqueue
{
    public:
    int f=-1;
    int r=-1;
    char a[10];

    void anque(char x)
    {
        if((f==0&&r==9)||f==(r+1))
        {
             cout<<"overflow occured \n";
        }
        else if(f==-1)
        {
            f++;
            r++;
            a[r]=x;

        }
        else if(r==9&&f!=0)
        {
            r=0;
            a[r]=x;
        }

        else{
        r++;
        a[r]=x;}

        cout<<"front is at"<<f<<" rear is at "<<r <<"\n";

        for(int i=0;i<10;i++)
        {
            cout<<a[i];
        }
        cout<<"\n";
    }
    char dequee()
    {
        if((f>r)&&f==9)
        {
            f=0;
        }
        if(f==r)
        {
            int p=f;
            f=-1;
            r=-1;
            cout<<"front is at"<<f<<" rear is at "<<r <<"\n";
            return(a[p]);

        }
        else
        {
            f++;
            cout<<"front is at"<<f<<" rear is at "<<r <<"\n";
            return a[f-1];

        }
        if(f==-1&&r==-1)
        {

            cout<<"underflow occured \n";
            cout<<"front is at"<<f<<" rear is at "<<r <<"\n";
            return('/');
        }
    }

}qq;
int main()
{

    int x;

    while(1)
    {
        cout<<"enter 1 for enqueue"<<"\n";
    cout<<"enter 2 for dequeue"<<"\n";
    cin>>x;
        if(x==1)
        {
            cout<<"enter character \n";
            char c;
            cin>>c;
            qq.anque(c);
        }
        if(x==2)
        {
            cout<<qq.dequee()<<" returned \n";
        }

    }

}
