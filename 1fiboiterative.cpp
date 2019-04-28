#include<iostream>
using namespace std;

int main(){
  int x = 0, y = 1, z, i, n, count = 0;
  cout<<"Enter the number of terms you want :";
  cin>>n;
  cout<<"\nFibonacci series : ";
  for(i=0;i<n;i++){
    count++;
    if(i == 0)
      cout<<0<<"\t";
    else if(i == 1)
      cout<<1<<"\t";
    else{
      z = x + y;
      x = y;
      y = z;
      cout<<z<<"\t";
    }
  }
  cout<<"\nTotal steps :"<<count;
}

