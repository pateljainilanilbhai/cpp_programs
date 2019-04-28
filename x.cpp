#include<iostream>
using namespace std;
int main()
{
    int n1,n2;

    cout<<"Enter length of first character";
    cin>>n1;

    cout<<"Enter length of second character";
    cin>>n2;

    char string1[n1],string2[n2];

    for(int i=0;i<n1;i++)
    {
        cin>>string1[i];
    }

    for(int i=0;i<n2;i++)
    {
        cin>>string2[i];
    }


    int matrix[n2+1][n1+1];
    char display[n2+1][n1+1];

    for(int i=0;i<n2+1;i++)
    {
        for(int j=0;j<n1+1;j++)
        {
            if(i==0)
            {
                matrix[i][j]=0;
            }
            if(j==0)
            {
                matrix[i][j]=0;
            }
        }
    }

    for(int i=1;i<n1+1;i++)
    {
        matrix[1][i]=1;
    }


    for(int i=2;i<n2+1;i++)
    {
        for(int j=1;j<n1+1;j++)
        {
            if(string2[i-1]!=string1[j-1])
            {
                int a=matrix[i-1][j];
                int b=matrix[i][j-1];
                if(a>=b){
                    matrix[i][j]=a;
                }
                else{
                    matrix[i][j]=b;
                }
            }

            else{
                matrix[i][j]=matrix[i-1][j-1]+1;
            }
        }
    }



    for(int i=0;i<n2+1;i++)
    {
        for(int j=0;j<n1+1;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    char a[100];
    int x=0;

    for(int i=n2;i>=0;i--)
    {
        for(int j=n1;j>=0;j--)
        {
            if(string2[i-1]==string1[j-1])
            {
                a[x]=string2[i-1];
                x++;
                i=i-1;
            }
            else{
                int a=matrix[i][j-1];
                int b=matrix[i-1][j];
                if(b>=a){
                    i=i-1;
                    j=j+1;
                }

            }
        }
    }

    cout<<endl<<endl;
    for(int i=x-1;i>=0;i--)
    {
        cout<<a[i];
    }


}


