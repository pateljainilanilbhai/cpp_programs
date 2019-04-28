#include<iostream>
using namespace std;
void con(int x,int y)
{
    int  a, i, t, j;

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
    cout<<x;
    for (j = 0; j < i; j++)
    {
        t *= y;
    }
    a = a - (t*x);
    x = a;
    cout<<x;
}

}
int main()
{
    int num;
    int base;
    cout<<"enter a number in decimal";
    cin>>num;
    cout<<"enter base";
    cin>>base;
    con(num,base);
}
