#include<iostream>

using namespace std;
int main()
{
    int a,b;
    char c;
    cin>>a;
    cin>>c;
    cin>>b;
    int count=0;
    int j;
	for(j=a;j>=1&&count<b;j--)
	{
	if((a%j)==0)
	{
	count++;
	}
	}
cout<<(j+1);
}


