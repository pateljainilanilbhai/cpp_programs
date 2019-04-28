#include<iostream>
using namespace std;
int prime(int b)
{
    int i=0;
    int j=0;
    int count=0;

    for(i=2;i<=b;i++)
    {

        for(j=2;(j<i);j++)
        {
            if(i%j==0)
            {
                goto aa;
            }
        }

        count++;
        aa:{}

    }

    return count;
}
bool isprime(int i)
{
    if(i==0&&i==1)
    {
        return false;
    }

        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                goto bb;
            }
        }
        return true;
            bb:
            return false;

}
int main()
{
    //looping
    int n;
    cin>>n;
    int a[n];
    int k;
    for(k=0;k<n;k++)
    {
        a[k]=0;
        int b,c;
        cin>>b>>c;

        for(int i=b;i<=c;i++)
        {

            if(isprime(prime(i))==1)
            {
                a[k]++;
            }
        }
            }
             for(k=0;k<n;k++)
             {
                 cout<<a[k]<<"\n";
             }

    }
