#include<iostream>
using namespace std;
int prime(int b)
{
    int i=0;
    int j=0;
    int count=0;

    for(i=2;i<=b;i++)
    {

        int k=i/2+1;
        for(j=2;(j<k);j++)
        {
            if(i%j==0)
            {

                goto bb;
            }
        }

        count++;
        bb:
            {

            }

    }

    return count;
}
bool isprime(int i)
{
    if(i==0||i==1)
    {        return false;    }

     int k=i/2+1;
        for(int j=2;(j<k);j++)
        {
            if(i%j==0)
            {
               goto aa;

            }
        }

        {return true;}
       aa:
        {return false;}
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int k;
    for(k=0;k<n;k++)
    {
        a[k]=0;
        int b,c;
        cin>>b;
        cin>>c;
        for(int i=b;i<=c;i++)
        {
            int z=prime(i);
            if(isprime(z))
            {
                a[k]++;
            }
        }cout<<a[k]<<"\n";
    }



}
