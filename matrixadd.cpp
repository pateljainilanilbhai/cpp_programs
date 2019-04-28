#include<iostream>
using namespace std;
static int count;

int main()
{
    int n,m;
    int count=0;
    cout<<"enter size of matrix:";
    cin>>n;
    cin>>m;
    int a[n][m];
    int b[n][m];
    int c[n][m];
    cout<<"enter matrix 1:";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
     cout<<"enter matrix 2:";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>b[i][j];
        }
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
            count++;
        }
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"count is "<<count;

}
