//2.1 Mark purchased Books from books store of standard 1 to 7. He purchased 4 books for each standard(for std.1 books are 1.1,1.2,1.3,1.4 and for std. 2 books are 2.1,2.2,2.3,2.4 and so on..). When he reached home, he opens the bag and sees that all the books got mixed. So, how he will sort all the books, according to the standards and their preference in that particular standard. (ex. : preference in std. 1 is 1.1<1.2<1.3)


#include<iostream>
using namespace std;
int main()
{

    float arr[28]={1.1,1.3,1.2,1.4,2.1,2.2,2.3,2.4,3.2,3.1,3.3,3.4,4.3,4.2,4.1,4.4,5.2,5.1,5.3,5.4,6.1,6.3,6.1,6.2,7.1,7.3,7.4,7.2};
    int n=28;
    float  temp;
    int j,i,min;
    for (i = 0; i < n-1; i++)
    {

        min = i;
        for (j = i+1; j < n; j++)
          {

              if (arr[j] < arr[min])
            {min = j; }}

        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;

    }

     for(i=0;i<n;i++)
    {
        cout<<arr[i]<<",";
    }

}


