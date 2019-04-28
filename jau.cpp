#include<iostream>

using namespace std;
int main()
{
    int a[9];
    char b;
    for(int i=0;i<8;i++)
    {
        cin>>a[i];
        cin>>b;
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;

            }
        }
    }
    cout<<a[0]<<a[1]<<":"<<a[2]<<a[3]<<":"<<a[4]<<a[5];

}
