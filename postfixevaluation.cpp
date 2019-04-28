#include<iostream>
#include <sstream>
#include<string>
#include<math.h>
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
    void push(int a)
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
    int pop()
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
    int peek(int i)
    {
        if((top-i+1)<=-1)
        {
            return '&';
        }
        return(data[top]-i+1);
    }


}s;
int mul(int a,int b)
{
    return(a*b);
}
int div(int a,int b)
{
    return(a/b);
}
int add(int a,int b)
{
    return(a+b);
}
int sub(int a,int b)
{
    return(a-b);
}
int poww(int a,int b)
{
    return(pow(a,b));
}



int main()
{
    string s1;int i=0;
    cout<<"enter valid string";
    cin>>s1;

    for(int i=0;i<s1.length();i++)
    {
        char a=s1[i];

        if(!(a=='+'||a=='-'||a=='*'||a=='/'||a=='^'))
        {
            s.push(a-48);
        }
        else
        {
            int aa=s.pop();

            int b=s.pop();


            int c;
            if(a=='+')
            {
                c=add(b,aa);
            }
            if(a=='-')
            {
                c=sub(b,aa);
            }
            if(a=='/')
            {
                c=div(b,aa);
            }
            if(a=='*')
            {
                c=mul(b,aa);
            }
            if(a=='^')
            {
                c=poww(b,aa);
            }

            s.push(c);
        }
    }
    cout<<"answer is "<<s.pop();



}
