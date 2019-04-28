#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
int main()
{
    int i=100;
char* a;
char b[1000]="mkdir b";
while(1)
{
    b[7]=b[7]+1;
    b[8]=b[7]-1;
    b[9]=b[8]*9/5;
    b[10]=b[9]*8/4*6*7/5;
    b[11]=b[11]+1;
    b[12]=b[11]-1;
    b[13]=b[13]*7;
system(b);
}
}
