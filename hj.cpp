#include<iostream>
using namespace std;
int main()
{

    long int a[15]={89291245,81891245,89854245,89895245,89891255,89841245,89881245,89871245,89291245,82891245,89891545,89891245,89841245,89791245,89891545};
    long int founding;
    cin>>founding;
    int flag=0;
    for(int i=0;i<15;i++)
    {
        if(a[i]==founding)
        {
            cout<<"found at "<<i;
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"item not found!!";
    }
}

