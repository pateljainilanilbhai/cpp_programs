#include <stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int count=0;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    count++;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        count++;
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
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


    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    cout<<"\ncount is :"<<count;
    }
    return 0;
}





