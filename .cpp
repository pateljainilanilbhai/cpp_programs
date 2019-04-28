#include<iostream>
using namespace std;
int main()
{

    long int a[20];
    int lower=0;
    int upper=20;
    long int founding;
    int flag=0;
    int j=0;
   cin>>founding;
    for(long int i=89891235;i<=89891254;i++)
    {
        a[j]=i;
        j++;
    }


    while((lower<=upper)&&flag==0)
    {

        int middle=(lower+upper)/2;
        if(a[middle]==founding)
        {
            cout<<"found at "<<middle<<" index";
            flag=1;
        }
        else if((a[middle]-founding)<0)
        {

            lower=middle+1;
        }
        else{
            upper=middle-1;
        }
    }

    if(flag==0)
    {

        cout<<("item not found");
    }

}
