
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
   float n1,n2,*p1,*p2;
   cout<<"Enter n1:";
   cin>>n1;
   cout<<"Enter n2:";
   cin>>n2;
   p1=&n1;
   p2=&n2;
   float sum=*p1+*p2;
   cout<<"sum:"<<fixed<<setprecision(2)<<scientific<<sum<<endl;
   return 0;
}
