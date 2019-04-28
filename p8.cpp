#include<iostream>
#include<string.h>
using namespace std;
char stk[50];
string table[10][10];
int TOP=0;
void push(char t)
{
    	TOP++;
    	stk[TOP] = t;
}
char pop()
{
    	char t = stk[TOP];
    	TOP--;
    	return t;
}
int findfrommat(char temp,int nt,int t)
{
    	int ro1,col1;
    	string str = "";
    	str += temp;
    	for(int i=0;i<nt;i++)
    	{
       	 	if(str == table[i][0])
        		{
            		return i;
        		}
    	}
    	for(int j=0;j<t;j++)
    	{
        		if(str == table[0][j])
        		{
            		return j;
        		}
    	}
}
void stackinput(string put)
{
    	char temp;
    	if(put != "#") {
    		for(int i=put.length()-1; i>=0; i--)
    		{
        			temp = put[i];
                		push(temp);
    		}
    	}
    	else
    	{
        		char t = pop();
    	}
}
int main()
{
    	int nt,t,c=1,ti1,ti2,choice=1;
    	cout<<"Enter the dimensions of Table: ";
    	cin>>nt>>t;
    	cout<<"Enter the table (#=null):\n";
    	for(int i=0; i<nt; i++)
    	{
        		for(int j=0; j<t; j++)
        		{
            		cin>>table[i][j];
        		}
    	}
        	string input;
    	do{
    		cout<<"Enter the String: ";
    		cin>>input;
    		input += "$";
    		push('$');
    		string str = table[1][0];
    		char temp1 = str[0];
    		push(temp1);
        		int len =0;
    		char temp2 = input[len];
    		for(int t1=0; t1<500; t1++)
    		{
        			if(temp1 == temp2)
        			{
            			if(TOP == 1)
            			{
                			cout<<endl<<"\nValid String.\n";
                			break;
            		}
            		else
            		{
                			char t = pop();
                                		temp1 = stk[TOP];
                			len++;
                			temp2 = input[len];
            		}
        		}
        		else
        		{
            		int temp3 = (int) temp1;
                        	if(temp3 >= 65 && temp3 <= 90)
            		{
                			int row = findfrommat(temp1,nt,t);
                                		int column = findfrommat(temp2,nt,t);
                                		string put = table[row][column];
                			stackinput(put);
                			temp1 = stk[TOP];
            		}
            		else if(temp3 >= 97 && temp3 <= 122)
            		{
                			cout<<endl<<"\nInvalid String.\n";
                			break;
            		}
            		else
            		{
                			cout<<endl<<"\nInvalid Symbol.\n";
                			break;
            		}
        		}
    	}
    	cout<<"Press 0 to exit. ";
    	cin>>choice;
    	}while(choice!=0);
    	return 0;
}
