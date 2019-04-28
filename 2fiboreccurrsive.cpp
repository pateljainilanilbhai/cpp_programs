#include<iostream>

using namespace std;

int count;
int fibonacci(int n)
{
    if((n==1)||(n==0))
    {
        return(n);
    }
    else
    {
        count++;
        return(fibonacci(n-1)+fibonacci(n-2));
    }
}

int main()
{
    int n,i=0;
    cout<<"Input the number of terms for Fibonacci Series:";
    cin>>n;
    cout<<"\nFibonacci Series is as follows\n";

    while(i<n)
    {
        cout<<" "<<fibonacci(i);
        i++;
    }
    cout<<"Count is"<<count;
    return 0;
}
