#include<iostream>
#include<cmath>
using namespace std;
long long int fib(int count,long long int array[],int a)
{


    long long int resultf[a];
    for(int i=0;i<count;i++)
    {
        resultf[i]=array[i];
    }
    for(int i=count;i<a;i++)
    {
        long long int intermediate=1;
        for(int j=0;j<count;j++)
        {
            intermediate=((intermediate*resultf[i-j-1]))%1000000007;
        }
        resultf[i]=intermediate%1000000007;
    }

    return resultf[a-1];
}

int main()
{
    int testcases;
    cin>>testcases;
    long long int result[testcases];
    for(int i=0;i<testcases;i++)
    {
        int k;
        int n;
        cin>>n;
        cin>>k;
        long long int a[k];
        for(int j=0;j<k;j++)
        {
            cin>>a[j];
        }
        result[i]=fib(k,a,n);
    }
    for(int i=0;i<testcases;i++)
    {
        cout<<result[i]%1000000007;
        if(i!=testcases-1)
        {
            cout<<"\n";
        }
    }
}
