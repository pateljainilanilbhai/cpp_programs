#include<iostream>
#include<cstring>
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
    int data[500];
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
            cout<<"not found";
        }
        return(data[top]-i+1);
    }


};
int main()
{
    stackk a(50);
    int choice;
    int x;
    while(1){
    cout<<"1.push \n";
    cout<<"2.pop \n";
    cin>>choice;
    if(choice==1)
    {
        cout<<"enter data:";
        cin>>x;
        a.push(x);
    }
    if(choice==2)
    {
        cout<<a.pop()<<"\n";
    }}



}
