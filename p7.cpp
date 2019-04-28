#include<iostream>
#include<string.h>
using namespace std;
char next;
int k=0;
string a;
char getchar(){
    	next=a[k];
    	k++;
    	return next;
}
int A(){
    	next=getchar();
    	cout<<next;
    	if(next=='c'){
        		next=getchar();
        		cout<<next;
        		if(next=='d')
            		return 1;
        		else
                    		return 0;
       	}
    	else if(next=='a'){
        		next=getchar();
        		cout<<next;
        		if(next=='c')
                    		return 1;
                	else
                    		return 0;
 	}
    	else
            	return 0;
}
int S(){
    	if(next=='b'){
        		int q;
        		q=A();
        		if(q==1)
            		return 1;
        		else
            		return 0;
    	}
}
int main(){
    	int j=0,w;
        	cout<<"Enter the string: ";
    	cin>>a;
    	next=getchar();
    	cout<<next;
    	w=S();
    	if(w==1){
        		next=getchar();
        		if(next=='#')
        			cout<<"\nString valid.\n";
        		else
                    		cout<<"\nString valid.\n";
          	}
    	else if(w==0){
        		cout<<"\nString invalid.\n";
    	}
    	return 0;
}
