#include<stdio.h>

int prime(int b)
{
    int i=0;
    int j=0;
    int count=0;
    int k;

    for(i=2;i<=b;i++)
    {

        k=i/2+1;
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
int isprime(int i)
{
    int j;
    if(i==0||i==1)
    {        return 0;    }

     int k=i/2+1;
        for(j=2;(j<k);j++)
        {
            if(i%j==0)
            {
               goto aa;

            }
        }

        {return 1;}
       aa:
        {return 0;}
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int k;
    int i;
    for(k=0;k<n;k++)
    {
        a[k]=0;
        int b,c;
       scanf("%d",&b);
       scanf("%d",&c);
        for(i=b;i<=c;i++)
        {
            int z=prime(i);
            if(isprime(z))
            {
                a[k]++;
            }
        }
        printf("%d \n",a[k]);
        return 0;

    }



}

