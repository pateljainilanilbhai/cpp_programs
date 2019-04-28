#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

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
    stack<char> st;
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
    string exp = "(a+b*(c^d-e)^(f+g*h)-i)";
    infixToPostfix(exp);
    return 0;
}

