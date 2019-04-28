#include<iostream>
using namespace std;
int main()
{
    	int l,i;
    	cout<<"Enter total line in Grammar: ";
    	cin>>l;
    	string gs[l],ts,fs,fs2;
        for(i=0; i<l; i++)
        	cin>>gs[i];
    	cout<<"After removing left recursion: "<<endl;
		for(i=0; i<l; i++)
    	{
        		ts=gs[i];
        		int j=3;
        		char ch;
        		if(ts[0]==ts[2])
        		{
            		fs = ts[0];
            		fs += "=";
            		fs += ts[ts.length()-1];
            		fs += ts[0];
            		fs += "'";
               		cout<<fs<<endl;
            		fs2 = fs[fs.length()-2];
            		fs2 += fs[fs.length()-1];
            		fs2 += "=";
            		while(ts[j]!='|')
            		{
                			fs2 += ts[j];
                			j++;
            		}
            		fs2 += fs[fs.length()-2];
            		fs2 += fs[fs.length()-1];
            		fs2 += "|#";
                 		cout<<fs2<<endl;
        		}
        		else
            		cout<<ts<<endl;
    	}
    	return 0;
}
