#include<iostream>
#include<iomanip>
using namespace std;



// Constants
const int N = 20;
const int lef = -1, righ = 1, dow = N, u = -N;
int grid[N * N];

// Get next clockwise direction
int next(int dir)
{

    if(dir==lef)
    {
        return u;
    }
    else if(dir==u)
    {
        return righ;
    }
   else if(dir==righ)
    {
        return dow;
    }
    else if(dir==dow)
    {
        return lef;
    }


}


// Assumes default is all zero
void fill(int grid[])
{
  int pos = 0, dir = u;

  for (int i = 1; i <= N*N; i++)
  {

    // Fill the block
    grid[pos] = i;

    if (pos == 0 || pos == N - 1 || pos == N*(N - 1) || pos == N*N - 1
      || grid[pos + dir] != 0)
    {

      // if corner point reached or block already filled, change direction
      dir = next(dir);
    }

    // Move to next position
    pos += dir;
  }
}
int main()
{
    int a[N*N]={};
    fill(a);
    for(int i=0;i<=(N*N)-1;i++)
    {
        if(i%N==0)
        {
            cout<<"\n";
        }
        cout<<setw(4)<<a[i]<<" " ;

    }
}
