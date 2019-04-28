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
    char a[50];

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
            cout<<"underflow occured";
        }
        else
        {
            f++;
            return a[f-1];

        }
    }

}qq;
int main()
{

    int x;

    while(1)
    {
        cout<<"enter 1 for anque"<<"\n";
    cout<<"enter 2 for deque"<<"\n";
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
            cout<<qq.dequee()<<"\n";
        }

    }
}
