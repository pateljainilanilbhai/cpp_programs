#include<iostream>
using namespace std;
int main()
{
    //6881004
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int *p;
    int q;
    p=&q;
    p=&p;
    cout<<(int)&p;


}
