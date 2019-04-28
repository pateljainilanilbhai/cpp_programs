#include<iostream>
using namespace std;
int main()
{
    int comparision=0;
    int exchange=0;
    int arr[10]={34,54,12,10,67,45,55,88,10};
    int n=8;
    int i, key, j;
   for (i = 1; i < n; i++)
   {
       comparision++;
       key = arr[i];
       j = i-1;


       while (j >= 0 && arr[j] > key)
       {
           comparision++;
           comparision++;
           arr[j+1] = arr[j];
           j = j-1;
           exchange++;
       }
       arr[j+1] = key;
   }
    for(i=0;i<8;i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<"\ncomparision="<<comparision<<" exchange="<<exchange;

}
