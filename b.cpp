#include<iostream>
#include<cmath>
using namespace std;
long int fact(int n);
int main()
{
    int n;
    int k;
    cin>>n>>k;

    int sum=0;
    for(int i=0;i<=k;i++)
    {
        if((i%2)==0)
        {
            sum=sum+(fact(n)/((fact(n-i))*fact(i)));
        }
    }
    cout<<sum;
    return 0;
}
long int fact(int n)
{
    long int s=1;
    for(int i=1;i<=n;i++)
    {
        s=s*i;
    }
    return s;
}
