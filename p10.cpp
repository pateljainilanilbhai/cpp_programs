#include<iostream>
using namespace std;
struct node
{
    	char value;
    	int as=0,rr=0;
    	node *left, *right;
};
int fndmax[50],k=0;
int isOperator(char c)
{
    	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    	{
        		return 1;
    	}
    	return 0;
}
void display(node *t)
{
    	if(t)
    	{
        		display(t->left);
                	cout<<t->value<<"\t";
        		cout<<t->rr<<"\t";
        		cout<<t->as<<"\t";
                	cout<<endl;
        		display(t->right);
    	}
}
void assignrr(node *t){
    	if(t)
    	{
        		assignrr(t->left);
        		assignrr(t->right);
        		if(!isalpha(t->value))
        		{
            		if(t->left->as!=1 && isalpha(t->left->value))
            		{
                			t->left->rr=1;
                			t->left->as=1;
                            	}
            		if(t->right->as!=1 && isalpha(t->right->value))
            		{
                			t->right->as=1;
                			t->right->rr=0;
                            	}
                        	int v1,v2;
            		v1=t->left->rr;
            		v2=t->right->rr;
            		if(v1==v2)
            		{
                			t->rr=v1+1;
            		}
            		else if(v1>v2)
            		{
                			t->rr=v1;
            		}
            		else
            		{
                			t->rr=v2;
            		}
            		fndmax[k]=t->rr;
            		k++;
        		}
    	}
}
node* create(int v)
{
    	node *temp = new node;
    	temp->left = temp->right = NULL;
    	temp->value = v;
    	return temp;
};
node *stack[100];
int top=0;
void push(node *t)
{
    	stack[top]=t;
    	top++;
}
node *pop()
{
    	top--;
    	return stack[top];
}

node *cre_tree(string s)
{
    	node *t, *t1, *t2;
    	for (int i=0; i<s.length(); i++)
    	{
        		if (!isOperator(s[i]))
        		{
            		t = create(s[i]);
            		push(t);
        		}
        		else
        		{
            		t = create(s[i]);
            		t1 = pop();
            		t2 = pop();
            		t->right = t1;
            		t->left = t2;
            		push(t);
        		}
    	}
    	t = pop();
    	return t;
}
int main()
{
    	string s ;
    	cout<<"Enter String in Postfix Order: ";
    	cin>>s;
    	node *r = cre_tree(s);
    	assignrr(r);
        	int i,temp=fndmax[0];
    	for(i=1; i<s.length(); i++)
    	{
        		if(temp<fndmax[i])
        		{
            		temp = fndmax[i];
        		}
    	}
    	cout<<"Maximum Register Required is "<<temp;
    	return 0;
}
