#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    while(true){
    int count=0;
    int n,i,j;
    cout<<"Enter number";
    cin>>n;
    bool swap=false;
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=n-i;
    }

    for (i = 0; i < n; i++){

       // Last i elements are already in place
       for (j = 0; j < n; j++)  {
           if (a[j] > a[j+1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
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

