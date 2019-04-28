#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    float start[n];
    float endd[n];
    for(int i=0;i<n;i++)
    {
        cin>>start[i];
        cin>>endd[i];
    }
    for(int i =0;i<n;i++)
    {
        if(endd[i]>=180){
            cout<<-1<<endl;
        }
        else{
        if(start[i]==1)
        {
            float a=endd[i];
            float anglefound=180-a;
            float k=anglefound/2.0;
            cout<<k<<" "<<k<<endl;
        }
        if(start[i]==2)
        {
            float a=endd[i];
            if(a>=90)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<a<<" "<<180-a-a<<endl;
            }
        }
        if(start[i]==3)
        {
            float a=endd[i];
            if(a>=90)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<180-a-a<<" "<<a<<endl;
            }
        }



        if(start[i]==4)
        {
            float a=endd[i];
            if(a>=90)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<180-a-a<<" "<<a<<endl;
            }
        }

        if(start[i]==5)
        {
            float a=endd[i];
            float anglefound=180-a;
            float k=anglefound/2.0;
            cout<<k<<" "<<k<<endl;
        }

         if(start[i]==6)
        {
            float a=endd[i];
            if(a>=90)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<a<<" "<<180-a-a<<endl;
            }
        }


         if(start[i]==7)
        {
            float a=endd[i];
            if(a>=90)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<a<<" "<<180-a-a<<endl;
            }
        }


         if(start[i]==8)
        {
            float a=endd[i];
            if(a>=90)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<180-a-a<<" "<<a<<endl;
            }
        }

         if(start[i]==9)
        {
            float a=endd[i];
            float anglefound=180-a;
            float k=anglefound/2.0;
            cout<<k<<" "<<k<<endl;
        }




        }









    }
}
