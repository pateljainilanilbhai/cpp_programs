#include<iostream>
using namespace std;
int main()
{
    int a;
    int count=0;
    float b;
    cin>>a>>b;
    for(int i=1;i<a;i++)
    {
        for(int j=1;j<a-i;j++)
        {
            if((i*(i-1))/(1.0*(i+j)*(i+j-1))==b)
            {
                count++;
            }
        }

    }
    cout<<count<<"\n";
}
