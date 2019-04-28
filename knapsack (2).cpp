#include<iostream>
using namespace std;



int main()
{
    int n,capacity;
    cout<<"Enter total number of items";
    cin>>n;
    cout<<"Enter profit weight of each object\n";
    int p[n+1];
    int w[n+1];
    p[0]=0;
    w[0]=0;
    for(int i=1;i<n+1;i++)
    {
        cin>>p[i];
        cin>>w[i];
    }
    cout<<"Enter capacity of knapsack";
    cin>>capacity;
    int a[n+1][capacity+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<capacity+1;j++)
        {
            a[i][j]=0;
        }
    }


    cout<<"PROFIT WEIGHT"<<"\n";
    for(int i=0;i<=n;i++)
    {
        cout<<p[i]<<"  "<<w[i]<<" \n";
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=capacity;j++)
        {
            if(j>=w[i]){
            a[i][j]=max(a[i-1][j] , p[i]+a[i-1][j-w[i]]);
            }
            else
            {
                a[i][j]=a[i-1][j];
            }
        }
    }

    cout<<"\n GENERATED MATRIX IS \n";

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<capacity+1;j++)
        {
            cout<<a[i][j]<<"  ";
        }
        cout<<"\n";
    }


cout<<"include ";
    int res=a[n][capacity];
    int ww=capacity;
    for(int i=n;i>0&&res>0;i--)
    {
        if(res==a[i-1][ww])
            continue;
        else{
            cout<<i<<" ";
            ww=ww-w[i];
            res=a[i][ww];

        }
    }




return 0;
}
