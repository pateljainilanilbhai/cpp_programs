#include<iostream>
using namespace std;
int a[]={2,6,7,1,4,2};
int temp;


int partition(int a[],int p,int r)
{
    int x=a[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(a[j]<=x)
        {
            i++;
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
         int temp=a[r];
            a[r]=a[i+1];
            a[i+1]=temp;
            return (i+1);

    }



int quicksort(int a[],int p,int r)
{
    if(p<r)
    {
        int q;
        q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

int main()
{
    quicksort(a,0,5);
    for(int i=0;i<=5;i++)
    {
        cout<<a[i]<<",";
    }
}
