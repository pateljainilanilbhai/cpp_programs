#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double start[n];
     for(int i=0;i<n;i++)
    {
        cin>>start[i];
    }

     for(int i=0;i<n;i++)
    {
        if(start[i]==0)
        {
            cout<<0<<endl;
        }
        else if(start[i]==1)
        {
            cout<<1<<endl;
        }
        else if(start[i]==2)
        {
            cout<<1<<endl;
        }
        else if(start[i]==3)
        {
            cout<<1<<endl;
        }
        else if(start[i]==4)
        {
            cout<<2<<endl;
        }
        else if(start[i]==5)
        {
            cout<<2<<endl;
        }
        else if(start[i]==6)
        {
            cout<<3<<endl;
        }
        else
        {
            cout<<2<<endl;
        }

    }

}
