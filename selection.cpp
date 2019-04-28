#include<iostream>
using namespace std;
int main()
{
    int comparision=0;
    int exchange=0;
    int arr[10]={34,54,12,10,67,45,55,88,10};
    int n=8;
    int i, j, min,temp;

    for (i = 0; i < n-1; i++)
    {
        comparision++;
        min = i;
        for (j = i+1; j < n; j++)
          {
              comparision++;
              if (arr[j] < arr[min])
            {min = j; comparision++;}}

        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        exchange++;
    }

     for(i=0;i<8;i++)
    {
        cout<<arr[i]<<",";
    }
     cout<<"\ncomparision="<<comparision<<" exchange="<<exchange;

}

