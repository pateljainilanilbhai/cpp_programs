#include<iostream>
#include<stdio.h>
#include<stack>
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
    int topp=-1;
    void push(char a)
    {
        if (topp==n-1)
        {
            cout<<"overflow occured";
        }
        else
        {
            topp++;
            data[topp]=a;
        }
    }
    char pop()
    {
        if(topp==-1)
        {
            cout<<"underflow occured";
            return -1;

        }
        else
        {

            topp--;
            return data[topp+1];

        }
    }
    char top()
    {
        return(data[topp]);
    }


};




int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

void infixToPostfix(string s)
{
    stackk st;
    st.push('#');
    int l = s.length();
    string ns;
    for(int i = 0; i < l; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
        ns+=s[i];
        else if(s[i] == '(')
        st.push('(');
        else if(s[i] == ')')
        {
            while(st.top() != '#' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
               ns += c;
            }
            if(st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }
        else{
            while(st.top() != '#' && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }

    }
    while(st.top() != '#')
    {
        char c = st.top();
        st.pop();
        ns += c;
    }
    cout << ns << endl;
}
int main()
{
     string exp;
    cout<<"enter infix expression \n";
   cin>>exp;
    infixToPostfix(exp);
    return 0;
}

