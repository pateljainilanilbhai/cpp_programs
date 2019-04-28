#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int sum=0;
    int i,j;
    int n;
    cin>>n;
    for(i=0;pow(2,i)<=n;i++)
    {
              for(j=0;j<=n;j++)
        {
            sum=sum+pow(2,(pow(2,i)+(2*j)));

        }

    }
    int q;
    q=sum%10;
    cout<<q;
    return 0;
}
