#include<stdio.h>

int main()
{
    int *p;
    p=&p;
    *p=655321;
    *p=99999;
    printf("\n %d",p);
}
