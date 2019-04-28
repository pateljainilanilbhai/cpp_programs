
#include<iostream>
using namespace std;
char st[100];
int sp=0,ss=0;
void push(char c)
{
    	st[sp]=c;
    	sp++;
}
char pop()
{
    	char ch;
    	sp--;
    	ch=st[sp];
    	return ch;
}
int main()
{
    	string s;
    	char cg,table[10][4],a;
    	int i,ii=0,jj=0,al=65;
    	cout<<"Enter the String: ";
    	cin>>s;
    	for(i=0; i<s.length(); i++)
    	{
        		if(isalpha(s[i])||isdigit(s[i]))
            		push(s[i]);
        		else
        		{
            		int k=0,cc=0;
            		while(k!=1)
            		{
                			if(cc!=2)
                			{
                    				table[ii][jj]=pop();
                    				jj++;
                    				cc++;
                			}
                			else
                    				k=1;
            		}
            		table[ii][jj]=s[i];
            		jj++;
            		a=al;
            		table[ii][jj]=a;
           		push(al);	// Calling push() method
            		al++;
            		a=al;
            		ii++;
        		}
        		jj=0;
    	}
    	cout<<endl;
    	for(i=0; i<ii; i++)
    	{
        		for(int j=0; j<4; j++)
        		{
            		cout<<" "<<table[i][j]<<" | ";
        		}
        		cout<<endl;
    	}
    	return 0;
}
