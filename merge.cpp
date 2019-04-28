#include<iostream>
#include<cmath>
using namespace std;

int simplemerge(int *k,int first,int second,int third)
{
    int i=first;
    int j=second+1;
    int l=first;
    int temp[5000];
    while((i<=second)&&j<=third)
    {
        if(k[i]<k[j])
        {
            temp[l]=k[i];
            l=l++;
            i=i++;
        }
        else
        {
            temp[l]=k[j];
            l=l++;
            j=j++;
        }
    }

    while(i<=second)
        {
            temp[l]=k[i];
            l=l++;
            i=i++;
        }
     while(j<=third)
        {
            temp[l]=k[j];
            l=l++;
            j=j++;
        }
    for(i=first;i<l;i++)
    {
        k[i]=temp[i];
    }


    return 0;
}


int twowaymerge(int *k,int start,int finish)
{
    int middle;
    if(start<finish)
        {
    middle=(start+finish)/2;
    twowaymerge(k,start,middle);
    twowaymerge(k,middle+1,finish);
    simplemerge(k,start,middle,finish);
        }
    return 0;
}
int main()
{
    int a[10]={5,2,4,9,8,7,3,1,6,10};
    twowaymerge(a,0,9);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<"  ";
    }

}
