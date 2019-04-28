#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int b[200][200]={0},c[200][200]={0};

int lcs(string x,string y)
{
    int m=x.length();
    int n=y.length();

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=3;
            }
            else if(c[i-1][j]>c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=1;
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=2;
            }
        }
    }


    return c[m][n];

}



void print(string x,int i,int j)
{
    if(i<=0&&j<=0)
        return;
         if(b[i][j]==3) {
        print(x,i-1,j-1);
        cout<<x[i-1];
    }
    else if(b[i][j]==1) {
        print(x,i-1,j);
    }
    else {
        print(x,i,j-1);
    }
}



int main()
{
    string x;
    string y;
    //char x[200],y[200];
    cout<<"Enter the first string:"<<endl;
    cin>>x;
    cout<<"Enter the second string:"<<endl;
    cin>>y;
    cout<<"Longest subsequence length is "<<lcs(x,y)<<"\n";

    cout<<"\n\n";
    cout<<"    ";
    for(int i=0;i<y.length();i++)
    {
        cout<<y[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<=x.length();i++) {
        for(int j=0;j<=y.length();j++){
                if(j==0)
                {
                    cout<<x[i-1]<<" ";
                }
                {
                    cout<<c[i][j]<<" ";
                }
        }
        cout<<endl;
    }

    cout<<"\n\n";


     for(int i=0;i<=x.length();i++) {
        for(int j=0;j<=y.length();j++){
                if(b[i][j]==3)
                {
                     cout<<"\\"<<" ";
                }

                if(b[i][j]==1)
                {

                    char a='|';
                     cout<<a<<" ";
                }

                if(b[i][j]==2)
                {
                    char x='-';
                     cout<<x<<" ";
                }


        }
        cout<<endl;
    }
    print(x,x.length(),y.length());
}
