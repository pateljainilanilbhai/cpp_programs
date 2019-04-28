
#include<iostream>
#include <sstream>
#include<string>
#include<math.h>
using namespace std;
class q
{
    public:
    int f=-1;
    int r=-1;
    char a[50]={};

    void anque(int x)
    {
        if(r!=50){
        if(f==-1)
        {
            f=0;

        }
        r++;
        a[r]=x;
        }
        else
        {
            cout<<"overflow";
        }
    }
    int dequee()
    {
        if(f==r+1)
        {
            f=-1;
            r=-1;
            return '/';
            cout<<"underflow occured";
        }
        else
        {
            f++;
            return a[f-1];

        }
    }

    bool isempty()
    {
        if(f==-1&&r==-1)
        {
            return 1;
        }
        return 0;
    }




    bool iscontain(int k)
    {
        for(int i=f;i<=r;i++)
        {
            if(a[i]==k)
            {
                return 1;
            }
        }
        return 0;
    }



}qq;
    int mark[6];
    int adj[6][6]={{0,0,0,1,0,1},{0,0,1,0,0,1},{0,1,0,1,1,0},{1,0,1,0,1,0},{0,0,1,1,0,1},{1,1,0,0,1,0}};

void dfs(int v)
{
    mark[v]=1;
    cout<<v<<" ";
    for(int i=0;i<6;i++)
    {
        if(adj[v][i]==1&&mark[i]!=1)
        {
            dfs(i);
        }
    }
}
int main()
{
    int noofvertex=6;


    for(int i=0;i<noofvertex;i++)
    {
        mark[i]=0;
    }


    cout<<"PRNTING ADJACENCY MATIX YOU HAVE INSERTED";

     for(int i=0;i<noofvertex;i++)
    {
        for(int j=0;j<noofvertex;j++)
        {
            cout<<adj[i][j]<<"  ";
        }
        cout<<"\n";
    }
cout<<"DEPTH FIRST SEARCH IS:";
    dfs(0);

}

