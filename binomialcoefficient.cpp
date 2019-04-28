#include<iostream>
using namespace std;


int main()
{
    int n,r;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter r:";
    cin>>r;
    long long unsigned int a[n+1][r+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<r+1;j++)
        {
            a[i][j]=0;
        }
    }
     for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<r+1;j++)
        {
            if(j==0||i==j)

            {
                a[i][j]=1;
            }
        }
    }
    for(int j=1;j<r+1;j++)
    {
        for(int i=2;i<n+1;i++)
        {
            a[i][j]=a[i-1][j]+a[i-1][j-1];
        }
    }

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<r+1;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<n<<"C"<<r<<" is "<<a[n][r];
}

