#include<iostream>
#include<cstring>
using namespace std;
int value(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

int toDecimalconversion(char *str, int base)
{
    int len = strlen(str);
    int power = 1;
    int num = 0;
    int i;


    for (i = len - 1; i >= 0; i--)
    {

        if (value(str[i]) >= base)
        {

           return -1;
        }

        num += value(str[i]) * power;
        power = power * base;
    }

    return num;
}
bool isprime(int i)
{
    if(i==0)
    {
        return false;
    }
    if(i==1)
    {
        return false;
    }

     int flag=0;
        for(int j=2;(j<i)&&flag==0;j++)
        {
            if(i%j==0)
            {
                flag=1;
            }
        }
        if(flag==0)
        {return true;}
        else
        {
            return false;
        }
}
int test(char b,char c)
{
    char a[]={b,c};
    int flag=0;
    for(int i=2;i<37;i++)
    {
        int k=0;
        k=toDecimalconversion(a,i);
        if(k==-1)
            goto aa;
        if(isprime(k))
           {
               cout<<i<<" ";
               flag=1;
           }
        aa:{}
    }
    cout<<"\b";
    if(flag==0)
    {
        cout<<"NONE"<<"\n";goto cc;
    }
    cout<<"\n";
    cc:{}

}
int main()
{
    int q;
    cin>>q;
    char a[q][2];
    for(int z=0;z<q;z++){
    cin>>a[z];
    }
    for(int z=0;z<q;z++)
    {
        test(a[z][0],a[z][1]);
    }

}
