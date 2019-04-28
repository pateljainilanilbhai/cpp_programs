#include<iostream>
#include<iomanip>
using namespace std;
int N;
int lef = -1, righ = 1, dow = N, u = -N;
int next(int dir)
{
    if(dir==lef)
    {return u;}
    else if(dir==u)
    {return righ;}
   else if(dir==righ)
    {return dow;}
    else if(dir==dow)
    {return lef;}
}

void fill(int grid[])
{
  int pos = 0, dir = u;
  for (int i = 1; i <= N*N; i++)
  {
    grid[pos] = i;
    if (pos == 0 || pos == N - 1 || pos == N*(N - 1) || pos == N*N - 1 || grid[pos + dir] != 0)
    {
      dir = next(dir);
    }
    pos += dir;
  }
}
int main()
{
    cin>>N;
    u=-N; dow=N;
    int a[N*N];
    for(int i=0;i<N*N;i++)
    {a[i]=0;}
    fill(a);
    for(int i=0;i<=(N*N)-1;i++)
    {
        if(i%N==0&&i!=0)
        {
            cout<<"\n";
        }
        cout<<setw(3)<<a[i]<<" " ;
    }
}
