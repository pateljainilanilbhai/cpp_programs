#include<iostream>
using namespace std;


class activity
{
    public:
    int index;
    int start;
    int endd;
};



int main()
{
    int n;
    cout<<"HOW MANY TOTAL ACTIVITIES ARE THERE";
    cin>>n;
    activity a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"FOR ACTIVITY "<<i<<endl;
        cout<<"Start time"<<endl;
        cin>>a[i].start;
        cout<<"End time"<<endl;
        cin>>a[i].endd;
        a[i].index=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i].endd>a[j].endd)
            {
                activity temp;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    int currenttime=0;
    cout<<"Completed Processes";
    for(int i=0;i<n;i++)
    {
        if(a[i].start>=currenttime)
        {
            currenttime+=a[i].endd;
            cout<<endl<<"a"<<a[i].index<<endl<<" start "<<a[i].start<<endl<<" end "<<a[i].endd;
        }
    }



}
