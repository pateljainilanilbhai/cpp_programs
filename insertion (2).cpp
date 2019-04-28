#include <stdio.h>
#include <math.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int count=0;
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       count++;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
           count++;
       }
       arr[j+1] = key;
   }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}



/* Driver program to test insertion sort */
int main()
{
     while(true){
    int n;
    cout<<"enter n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand();
    }

    insertionSort(arr, n);
    printArray(arr, n);
    cout<<"Count is:"<<count;

}
 return 0;
}




