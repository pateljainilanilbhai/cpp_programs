#include<iostream>
using namespace std;
int main()
{
    int n1[14]= {1,1,0,1,0,1,1,0,1,1,0,0,0,0};
    int n2[5]= {1,0,0,1,1};
    int n3[14];
    int n4[5];
    int i,j,k,l,d=14;

    cout<<"enter data (10 bits): ";
    for(i=0;i<10;i++)
    {
        cin>>n1[i];
    }
    for(i=10;i<14;i++)
    {
        n1[i]=0;
    }
    cout<<endl<<"enter generator (5 bits): ";
    for(i=0;i<5;i++)
    {
        cin>>n2[i];
    }

    for(i=0; i< 10; i++)
        n3[i]= n1[i];

        for(i=0; i< 10; ++i)
    {
        if(n1[i]==0)
        {
            for(j=i; j< i+4; ++j)
                n1[j] = n1[j]^0;
        }
        else
        {

            n1[i] = n1[i]^n2[0];
            n1[i+1]=n1[i+1]^n2[1];
            n1[i+2]=n1[i+2]^n2[2];
            n1[i+3]=n1[i+3]^n2[3];
            n1[i+4]=n1[i+4]^n2[4];
        }
    }

    for(i=10;i<14;i++){
        n3[i]=n1[i];
    }
    cout<<"sended code is ";
    for(i=0; i<14; i++)
    {
        cout<<n3[i]<<" ";
    }
    return 0;
}
