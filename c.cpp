#include<iostream>
using namespace std;
const int n=5;
const int lef = -1, righ = 1, dow =n, u = -n;
int next(int dir)
{
  switch (dir)
  {
    case lef: return u;
    case u: return righ;
    case righ: return dow;
    case dow: return lef;
  }
}
void fill(int a[n][n])
{
    int pos = n-1, dir = righ;


        int *k=&a[0][0];
        for(int i=0;i<n*n;i++)
        {
            *k=i;


         if (pos == 0 || pos == n - 1 || pos == n*(n - 1) || pos == n*n - 1
      || a[pos + dir] != 0)
    {

      // if corner point reached or block already filled, change direction
      dir = next(dir);
    }
    k+=dir;
        }

}
int main()
{


    int a[n][n];
    fill(a);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
    {
        cout<<a[i][j]<<" ";
    }
    cout<<"\n";
    }

}
