#include<iostream>
using namespace std;
int main()
{
    int a[10];
    cout<<"enter 10 elements"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
    {
        if(a[i]<a[j])
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }

    }
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
}

