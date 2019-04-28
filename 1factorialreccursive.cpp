#include<iostream>
using namespace std;
static int count;
int fact(int n)
{
    if(n==1)
    {
        return 1;
    }

    count=0;
    n=n*fact(n-1);
    count++;
    return n;
}
int main()
{
    int n;
    cin>>n;
   long int x=fact(n);
   cout<<x;
   cout<<"count is"<<count;
}
