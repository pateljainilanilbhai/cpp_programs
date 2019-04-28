
#include<iostream>
using namespace std;
int main()
{	int nl;
    	cout<<"Enter no. of lines: ";
    	cin>>nl;
    	string input[nl],ts,arr,arr2;
    	cout<<"Enter the Grammar:\n";
    	for(int i=0;i<nl;i++)
        		cin>>input[i];
    	cout<<"\nAfter removing left factoring:\n";
    	for(int i=0;i<nl;i++)
    	{
        		ts=input[i];
        		if(ts[2] == ts[6])
        		{
                       	arr = ts[0];
            		arr += "=";
            		arr += ts[2];
arr += ts[0];
            		arr += "'";
            		cout<<arr<<endl;
            		arr2 = arr[arr.length()-2];
            		arr2 += arr[arr.length()-1];
            		arr2 += "=";
            		arr2 += ts[3];
            		arr2 += ts[4];
            		arr2 += "|#";
            		cout<<arr2<<endl;
        		}
        		else
            		cout<<ts<<endl;
    	}
}
