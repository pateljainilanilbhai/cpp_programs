
#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

void printParenthesis(int i, int j, int n,
                      int *bracket, char &name)
{

    if (i == j)
    {
        cout << name++;
        return;
    }

    cout << "(";

    printParenthesis(i, *((bracket+i*n)+j), n,
                     bracket, name);

    printParenthesis(*((bracket+i*n)+j) + 1, j,
                     n, bracket, name);
    cout << ")";
}


void matrixChainOrder(int p[], int n)
{

    int m[n][n];


    int bracket[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            bracket[i][j]=0;
            m[i][j]=0;
        }
    }


    for (int i=1; i<n; i++)
        m[i][i] = 0;

    // L is chain length.
    for (int L=2; L<n; L++)
    {
        for (int i=1; i<n-L+1; i++)
        {
            int j = i+L-1;
            m[i][j] = INT_MAX;
            for (int k=i; k<=j-1; k++)
            {

                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;


                    bracket[i][j] = k;
                }
            }
        }
    }


    char name = 'A';

    cout<<"S matrix is"<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<bracket[i][j]<<" ";
        }
        cout<<"\n";
    }


     cout<<"\nM matrix is"<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }



    cout << "Optimal Parenthesization is : ";
    printParenthesis(1, n-1, n, (int *)bracket, name);
    cout << "nOptimal Cost is : " << m[1][n-1];
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int k = sizeof(arr)/sizeof(arr[0]);
    matrixChainOrder(arr, k);
    getch();
    return 0;
}
