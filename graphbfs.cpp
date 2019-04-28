
#include<iostream>
#include <sstream>
#include<string>
#include<math.h>
#include<queue>
using namespace std;
    int mark[6]={0,0,0,0,0,0};
    int adj[6][6]={{0,0,0,1,0,1},{0,0,1,0,0,1},{0,1,0,1,1,0},{1,0,1,0,1,0},{0,0,1,1,0,1},{1,1,0,0,1,0}};
queue<int> q;
void bfs(int v)
{
    mark[v]=true;
    q.push(v);
    while(!q.empty()){
    v=q.front();
    q.pop();
    cout<<v<<" ";
    for(int i=0;i<6;i++)
        if(adj[v][i]&&!mark[i])
            {
                mark[i]=1;
                q.push(i);
            }
        }
}



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
    cout<<"PRNTING ADJACENCY MATIX YOU HAVE INSERTED \n";

     for(int i=0;i<noofvertex;i++)
    {
        for(int j=0;j<noofvertex;j++)
        {
            cout<<adj[i][j]<<"  ";
        }
        cout<<"\n";
    }
    cout<<"\n dfs is\n";
    dfs(0);
    for(int i=0;i<6;i++){
    mark[i]=0;}
    cout<<"\n bfs is\n";
    bfs(0);

}
