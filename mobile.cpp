#include<iostream>
#include<iomanip>
#include<cstdio>
using namespace std;
int main()
{
    float chargeremain=100;
    int charging=0;
    float rate;
    float x;
    char a[100];
    cin>>a;
    int i=0;
   for(i=0;i<100;i++)
   {
       if(a[i]=='O')
       {
           rate=1;
           if(chargeremain<=20||charging==1)
           {
               rate=-25;
               charging=1;
           }
       }
       else if(a[i]=='C')
       {
           if(((100-chargeremain)*0.1)>=2.0)
           {
               rate=((100-chargeremain)*0.1);charging=0;

           }
           else {rate=2;charging=0;}
       }
        else if(a[i]=='B')
       {
           if(((100-chargeremain)*0.1)*2>=4.0)
           {
               rate=((100-chargeremain)*0.1)*2;charging=0;
           }
           else {rate=4;charging=0;}
       }
       else
       {
           rate=0;
           charging=0;
       }

       chargeremain=chargeremain-rate;
   }

   printf("%2.2f",chargeremain);


}
