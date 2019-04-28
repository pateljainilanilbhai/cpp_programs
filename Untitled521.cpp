#include<iostream>
#include<queue>

using namespace std;
int main()
{
    queue<long> q;
    for(long i=0;i<1000000;i++)
    {
        q.push(i);
    }
    for(long i=0;i<1000000;i++){
    cout<<q.front()<<" ";
    q.pop();}
}
