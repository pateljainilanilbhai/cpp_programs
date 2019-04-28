#include<iostream>
using namespace std;
int Partition(int a[], int beg, int end)
{
    int p = beg, pivot = a[beg], loc;

    for (loc = beg + 1; loc <= end; loc++)
    {
        if (pivot > a[loc])
        {
            a[p] = a[loc];
            a[loc] = a[p + 1];
            a[p + 1] = pivot;

            p = p + 1;
        }
    }
    return p;
}
void QuickSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int p = Partition(a, beg, end);
        QuickSort(a, beg, p - 1);
        QuickSort(a, p + 1, end);
    }
}
int prefixsum(int i[],int k,int length)
{
    int sum=0;
    for(int j=0;j<=k;j++)
    {
        sum=sum+i[j];

    }


    return sum;
}
int suffixsum(int i[],int k,int length)
{
    int sum=0;
    for(int j=length-1;j>=k;j--)
    {
        sum=sum+i[j];
    }
    return sum;

}
int main()
{
    int iteration;
    cin>>iteration;
    int ans[iteration];
    for(int z=0;z<iteration;z++){

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum[n];
    for(int i=0;i<n;i++)
    {
        sum[i]=prefixsum(a,i,n)+suffixsum(a,i,n);
    }
    int s[n];
    for(int i=0;i<n;i++)
    {
        s[i]=sum[i];
    }
    QuickSort(sum,0,n);
    int kk[n];
    {
        for(int i=0;i<n;i++)
        {
                if(s[i]==sum[0])
                {
                    ans[z]=i+1;
                    break;
                }
        }
    }
    }

    for(int z=0;z<iteration;z++)
    {
        cout<<ans[z]<<"\n";
    }

}
