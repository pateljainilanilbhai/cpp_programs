#include<iostream>
using namespace std;
bool isprime(long int i)
{
    if(i==0||i==1)
    {        return false;    }

     long int k=i/2+1;
        for(long int j=2;(j<k);j++)
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

    for(long int i=0;;i++)
    {
        if(isprime(i)&&isprime(i+2))
        {
            cout<<i<<" "<<i+2<<"\n";
        }
    }
}
