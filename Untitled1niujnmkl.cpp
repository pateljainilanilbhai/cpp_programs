#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
int main() {
 char str[19]= "Programming";
 stack<char> s;
 for(int i = 0; i < strlen(str); i++)
 s.push(str[i]);
 for(int i = 0; i < strlen(str) - 1; i++) {
cout << s.top();
s.pop();
}
return 0;
}
