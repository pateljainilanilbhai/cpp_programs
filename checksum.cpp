#include<iostream>
using namespace std;

int main()
{
    int a[5][8]= {{1,0,1,1,0,0,1,1},{1,0,1,0,1,0,1,1},{0,1,0,1,1,0,1,0},{1,1,0,1,0,1,0,1},{0,0,0,0,0,0,0,0} };
    int b[5][8],p[8]= {0,0,0,0,0,0,0,1},temp[8];
    int i,j,k,l,c=0,c1=0;
    for(i=0; i<4; i++)
    {
        for(j=0; j<8; j++)
            b[i][j]=a[i][j];
    }
    cout<<"At sender side :\n";
    for(i=0;i<4;i++)
    {
        cout<<"Enter no "<<i+1<<" code :\n";
        for(j=0;j<8;j++)
        {
            cin>>a[i][j];
        }}
    for(i=0; i<3; i++)
    {
        c=0;
        for(j=8; j>0; j--)
        {
            a[i+1][j]=a[i+1][j]+a[i][j]+c;
            if(a[i+1][0]==2)
            {
                c1=0;
                a[i+1][0]=0;
                for(k=8; k>0; k--)
                {
                    a[i+1][k]=a[i+1][k]+p[k];
                    if(a[i+1][k]==3)
                    {
                        c1=1;
                        a[i+1][k]=1;
                    }
                    else if(a[i+1][k]==2)
                    {
                        c1=1;
                        a[i+1][k]=0;
                    }
                    else
                        c1=0;
                }
            }
            else if(a[i+1][0]==3)
            {
                a[i+1][0]=1;
                c1=0;
                for(k=8; k>0; k--)
                {
                    a[i+1][k]=a[i+1][k]+p[k];
                    if(a[i+1][k]==3)
                    {
                        c1=1;
                        a[i+1][k]=1;
                    }
                    else if(a[i+1][k]==2)
                    {
                        c1=1;
                        a[i+1][k]=0;
                    }
                    else
                        c1=0;
                }
            }
            else if(a[i+1][j]==3)
            {
                c=1;
                a[i+1][j]=1;
            }
            else if(a[i+1][j]==2)
            {
                c=1;
                a[i+1][j]=0;
            }
            else
                c=0;
        }
    }
    for(i=0; i<8; i++)
    {
        a[4][i]=a[3][i];
        b[3][i]=a[3][i];
    }
    for(i=0,j=7; i<8,j>=0; i++,j--)
    {
        temp[i]=a[4][j];
    }
    cout<<"checksum :\n";
    for(i=0; i<8; i++)
    {
        if(temp[i]==1)
            b[4][i]=0;
        else
            b[4][i]=1;
        cout<<b[4][i]<<" ";
    }
    cout<<"\nAt receiver side :\n";
    c=0;
        for(j=8; j>0; j--)
        {
            b[4][j]=b[4][j]+b[3][j]+c;
            if(b[4][0]==2)
            {
                c1=0;
                b[4][0]=0;
                for(k=8; k>0; k--)
                {
                    b[4][k]=b[4][k]+p[k];
                    if(b[4][k]==3)
                    {
                        c1=1;
                        b[4][k]=1;
                    }
                    else if(b[4][k]==2)
                    {
                        c1=1;
                        b[4][k]=0;
                    }
                    else
                        c1=0;
                }
            }
            else if(b[4][0]==3)
            {
                b[4][0]=1;
                c1=0;
                for(k=8; k>0; k--)
                {
                    b[4][k]=b[4][k]+p[k];
                    if(b[4][k]==3)
                    {
                        c1=1;
                        b[4][k]=1;
                    }
                    else if(b[4][k]==2)
                    {
                        c1=1;
                        b[4][k]=0;
                    }
                    else
                        c1=0;
                }
            }
            else if(b[4][j]==3)
            {
                c=1;
                b[4][j]=1;
            }
            else if(b[4][j]==2)
            {
                c=1;
                b[4][j]=0;
            }
            else
            {
                c=0;
            }
        }
    cout<<"checksum :\n";
    for(i=0; i<8; i++)
    {
        if(b[4][i]==1)
            b[4][i]=0;
        else
            b[4][i]=1;
        cout<<b[4][i]<<" ";
    }
    return 0;
}
