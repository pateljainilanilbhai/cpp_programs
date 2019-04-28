#include<iostream>
#include<cmath>
using namespace std;
int fact(int n)
{
    long int s=1;
    for(int i=1;i<=n;i++)
    {
        s=s*i;
    }
    return s;
}
int com(int n,int r)
{
    return(fact(n)/((fact(n-r))*fact(r)));
}
int main()
{
    int n;
    int k;
    cin>>n>>k;

    long int sum=0;
    for(int i=0;i<=k;i++)
    {
        if((i%2)==0)
        {
            sum=sum+com(n,i);
        }
    }
    cout<<sum;
    return 0;
}
