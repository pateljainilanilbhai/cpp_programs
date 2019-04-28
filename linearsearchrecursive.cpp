/* Recursive function to search x in arr[l..r] */
#include<iostream>
#include<stdio.h>
using namespace std;
int count;
int recSearch(int arr[], int l, int r, int x)
{
     if (r < l)
     {
         count++;
        return -1;
     }
     if (arr[l] == x)
     {
         count++;
        return l;
     }
        count++;
     return recSearch(arr, l+1, r, x);
}

int main()
{
    int no;
    cout<<"ENTER SIZE OF ELEMENTS "<<endl;
    cin>>no;
    int arr[no], i;
    cout<<"ENTER ELEMENTS"<<endl;
    for(int i=0;i<no;i++)
    {
        cin>>arr[i];
    }

    int n = sizeof(arr)/sizeof(arr[0]);
    int x ;
    cout<<"ENTER NUMBER TO SEARCH"<<endl;
    cin>>x;
    int index = recSearch(arr, 0, n-1, x);
    if (index != -1)
       printf("Element %d is present at index %d", x, index);
    else
        printf("Element %d is not present", x);



    return 0;
}
