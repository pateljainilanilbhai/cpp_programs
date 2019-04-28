#include<iostream>
#include <sstream>
#include<string>
using namespace std;

class stackk
{
public:
    int n=500;
     stackk()
    {
        n=500;
    }
     stackk(int a)
    {
        n=a;
    }
    char data[500];
    int top=-1;
    void push(char a)
    {
        if (top==n-1)
        {
            cout<<"overflow occured";
        }
        else
        {
            top++;
            data[top]=a;
        }
    }
    char pop()
    {
        if(top==-1)
        {
            cout<<"underflow occured";
            return -1;

        }
        else
        {

            top--;
            return data[top+1];

        }
    }
    char peek(int i)
    {
        if((top-i+1)<=-1)
        {
            return '&';
        }
        return(data[top]-i+1);
    }


}s;

string p="(";
stringstream ss;


int precedence(char a)
{
    if(a=='+'||a=='-')
    {
        return 1;
    }
    if(a=='*'||a=='/')
    {
        return 2;
    }
    if(a=='^')
    {
        return 3;
    }
    if(a=='&')
    {
        return 4;
    }
}

string infixtopostfix(string q)
{
    int length=q.length();
    for(int i=0;i<length;i++)
    {
        char c=q[i];
        if(!(c=='+'||c=='*'||c=='/'||c=='-'||c=='^'))
        {
            ss<<c;
            ss>>p;
            cout<<p<<"     ";
        }
        if(c=='(')
        {
            s.push(c);
        }
        if((c=='+'||c=='*'||c=='/'||c=='-'||c=='^'))
        {
            while(precedence(c)<=precedence(s.peek(1)))
            {
                 ss<<s.pop();
                 ss>>p;
                  cout<<p<<"     ";
            }
            s.push(c);
        }
        if((c==')'))
        {
            while(s.peek(1)!='(')
            {
                ss<<s.pop();
                ss>>p;
                 cout<<p<<"     ";
            }
            s.pop();
        }
    }
}

int main()
{
  //  string q="+*)";
    //cout<<infixtopostfix(q);
    ss<<'d';
    string q;
    ss>>q;
    cout<<q<<" ";
     ss<<'qqqqqq';
      ss>>q;
       cout<<q<<" ";


}
