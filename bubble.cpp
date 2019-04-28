#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    while(true){
    int count=0;
    int n;
    cout<<"Enter number";
    cin>>n;
    bool swap=false;
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=rand();
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i]>a[j])
            {
                int temp;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                swap=true;
                count++;
            }
            count++;
        }
        count++;
        if(swap==false)
        {
            break;
        }
        count++;
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"Count is"<<count;
    }
}
