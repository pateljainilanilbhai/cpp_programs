#include<iostream>
using namespace std;
int con(int x)
{
    int  a, i, t, j;
    int y=6;
int sum=0;
 // x as the number in base-10 and x, as the destination base
a = x;
while (x >= y)
{
    t = 1;
    for (i = 0; x > y; i++)
    {
        x /= y;
    }
    sum=sum+x;
    for (j = 0; j < i; j++)
    {
        t *= y;
    }
    a = a - (t*x);
    x = a;
}
sum=sum+x;
return sum;
}
int main()
{
    int dragon=0;
    int terms;
    char b;
    cin>>terms;
    int a[terms];
    for(int i=0;i<terms;i++)
    {
        cin>>a[i];
        if(i<terms-1)
        cin>>b;
    }
    for(int i=0;i<terms;i++)
    {
        a[i]=con(a[i]);
    }
     for(int i=0;i<terms;i++)
     {
         for(int j=0;j<i;j++)
            if(a[i]<a[j])
                dragon++;
     }
    cout<<dragon;
}
