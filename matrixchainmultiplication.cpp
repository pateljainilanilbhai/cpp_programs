
#include<stdio.h>
#include<limits.h>
#include<iostream>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n

int MatrixChainOrder(int p[], int n)
{
    int m[n][n];
    int s[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            m[i][j]=0;
        }
    }

    int i, j, k, L, q;

    for (i=1; i<n; i++)
        m[i][i] = 0;

    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = q;
                    }
            }
        }
    }

    for(int count=0;count<n;count++)
    {
        for(int jj=0;jj<n;jj++){
        cout<<m[count][jj]<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n\n\n";



    return m[1][n-1];
}

int main()
{
    int n;
    cout<<"Enter number of matrixes";
    cin>>n;
    int arr[n+1];
    cout<<"Enter all values\n";
    for(int i=0;i<n+1;i++)
    {
        cin>>arr[i];
    }


    printf("Minimum number of multiplications is %d ",
                       MatrixChainOrder(arr, n+1));


    return 0;
}
