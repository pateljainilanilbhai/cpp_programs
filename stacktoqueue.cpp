#include<iostream>
#include <sstream>
#include<string>
#include<math.h>
#include<stdio.h>
#include<stack>
using namespace std;
class cirqularqueue
{
    public:
    int f=-1;
    int r=-1;
    int a[5];

    void anque(int x)
    {
        if((f==0&&r==4)||f==(r+1))
        {
             cout<<"overflow occured \n";
        }
        else if(f==-1)
        {
            f++;
            r++;
            a[r]=x;

        }
        else if(r==4&&f!=0)
        {
            r=0;
            a[r]=x;
        }

        else{
        r++;
        a[r]=x;}


    }
    int dequee()
    {
        if((f>r)&&f==4)
        {
            f=0;
        }
        if(f==r)
        {
            int p=f;
            f=-1;
            r=-1;
            return(a[p]);

        }
        else
        {
            f++;
            return a[f-1];

        }
        if(f==-1&&r==-1)
        {

            cout<<"underflow occured \n";
            return(0);
        }
    }

    void display()
{
    int i;
    printf("\n");
    if (f> r)
    {
        for (i = f; i < 5; i++)
        {
            printf("%d ", a[i]);
        }
        for (i = 0; i <= r; i++)
            printf("%d ", a[i]);
    }
    else
    {
        for (i = f; i <= r; i++)
            printf("%d ", a[i]);
    }
    cout<<"front is at "<<f<<" and rear is at "<<r<<"\n";
}

}qq;
int main()
{
    stack<int> s;
    for(int i=0;i<5;i++)
    s.push(i);
    while(!s.empty())
    {
        qq.anque(s.top());
        s.pop();
    }
    qq.display();
}

