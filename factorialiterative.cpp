#include<stdio.h>
int main()
{
    int n;
    int f=1;
    int i=1;
    int count=0;
    count++;
    scanf("%d",&n);
    while(i!=n+1)
    {
        f=f*i;
        i++;
        count++;
    };
    printf("%d",f);
    printf(" count %d",count);
}
