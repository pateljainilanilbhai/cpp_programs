#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

void convert10tob(int N, int b)
{

     if (N == 0)
        return ;
     int x = N % b;
     N /= b;
     if (x < 0)
        N += 1;
     convert10tob(N, b);


     cout<< x < 0 ? x + (b * -1) : x;
     return ;
}
int main()
{
 int num;
    int base;
    cout<<"enter a number in decimal:";
    cin>>num;
    cout<<"enter base:";
    cin>>base;

    convert10tob(num,base);

}
