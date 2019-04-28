
#include<iostream>
using namespace std;
int k=0;
void convert10tob(int N, int b)
{
     if (N == 0)
        return;
     int x = N % b;
     N /= b;
     if (x < 0)
        N += 1;
     convert10tob(N, b);
     k=k+( x < 0 ? x + (b * -1) : x);
     return;
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
        convert10tob(a[i],6);
        a[i]=k;
        k=0;
    }
     for(int i=0;i<terms;i++)
     {
         for(int j=0;j<i;j++)
            if(a[i]<a[j])
                dragon++;
     }
    cout<<dragon;
}
