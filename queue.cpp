#include<iostream>
#include <sstream>
#include<string>
#include<math.h>
#include<queue>
using namespace std;

int main()
{
    queue <int> q;
    q.push(50);
    q.push(7);
    q.push(9);
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();


}
