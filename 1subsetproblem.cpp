
#include<iostream>
#include<math.h>
using namespace std;
int count=0;
void subset(int num,int n, int x[])
{ count++;
    int i;
  for(i=1;i<=n;i++)
    x[i]=0;
  for(i=n;num!=0;i--)
    { x[i]=num%2;
     num=num/2; }
}
int main()
{
        int a[10];
        int x[10];
        int n,d,sum,present=0;
        int j;
        cout<<"enter the number of elements of set";
        cin>>n;
        cout<<"enter the elements of set";
        for(int i=1;i<=n;i++)
        cin>>a[i];

        cout<<"enter the positive integer sum";
        cin>>d;

    if(d>0)
        {
            for(int i=1;i<=pow(2,n)-1;i++)
                {
                    count++;
                   // subset(i,n,x);
                    sum=0;
                    for(j=1;j<=n;j++)
                    if(x[j]==1)
                        sum=sum+a[j];
                    if(d==sum)
                        {
                            cout<<"Subset={";
                            present=1;
                            for(j=1;j<=n;j++)
                                if(x[j]==1)
                                    cout<<a[j]<<",";
                            cout<<"}="<<d;
                            cout<<"\n";
                        }
                }
        }
    if(present==0)
        cout<<"Solution does not exists";

        cout<<" \n count is "<<count;
}
