#include<iostream>
using namespace std;
int max(int *p, int n)
{int a=0, b=n-1;
while (b!=a)
{
if (p[a] <= p[b])
{
a = a+1;
}else
{b = b-1;
}
}
return p[a];
}
int main()
{

    int a[]={5,6,7,2,5,1,5,2,3};
    cout<<max(a,9);
}
