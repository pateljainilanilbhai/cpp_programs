
/*Implement the function shift_element() which takes as input the index of an array element that has been determined to be out of order.
 The function shifts the element towards the front of the array, repeatedly swapping the preceding element until the out-of-order element is in the proper location.\
Print the updated list.*/
#include<iostream>
using namespace std;
int arr[10]={34,54,12,10,67,45,55,88,10};
void shiftelement(int j)
{
    int i=j+1;
    int key=arr[i];
     while (j >= 0 && arr[j] > key)
       {

           arr[j+1] = arr[j];
           j = j-1;

       }
       arr[j+1] = key;
}

int main()
{
    int n=8;
    int i, key, j;
   for (i = 2; i < n-1; i++)
   {
       shiftelement(i);
   }
    for(i=0;i<8;i++)
    {
        cout<<arr[i]<<",";
    }

}
