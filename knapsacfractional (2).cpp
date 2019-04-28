#include<iostream>
using namespace std;

class question
{
    public:
    int questionno;
    int marks;
    int timing;
    float ratio;
};
int main()
{
    float marksobtaining=0;
    int timeremaining;
    question q[5];
    for(int i=0;i<5;i++)
    {
        cout<<"Enter marks for question "<<i<<":";
        q[i].questionno=i;
        cin>>q[i].marks;
        cout<<"Enter number of minutes for answering :";
        cin>>q[i].timing;
        q[i].ratio=(float)q[i].marks/q[i].timing;
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(q[i].ratio>q[j].ratio)
            {
                question temp;
                temp=q[i];
                q[i]=q[j];
                q[j]=temp;
            }
        }
    }
    cout<<"Enter time remaining";
    cin>>timeremaining;
    for(int i=0;i<5;i++)
    {
        if(q[i].timing<=timeremaining)
        {
            cout<<"\nCOMPLETE QUESTION "<<q[i].questionno;
            timeremaining-=q[i].timing;
            marksobtaining+=q[i].marks;
        }
        else
        {
            if(timeremaining>0)
            {
                cout<<"\nCOMPLETE PARTIALLY QUESTION "<<q[i].questionno;
                float fractiontocomplete=(float)timeremaining/q[i].timing;
                cout<<" IN FRACTION "<<fractiontocomplete<<" TIME REMAINING IS"<<timeremaining;
                marksobtaining+=fractiontocomplete*q[i].marks;
                timeremaining-=fractiontocomplete*q[i].timing;
            }
        }
    }
    cout<<"\nWASTE TIME"<<timeremaining;
    cout<<"\nMARKS OBTAININED"<<marksobtaining;
}
