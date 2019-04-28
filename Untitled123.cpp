#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int start[n];
    int endd[n];
    for(int i=0;i<n;i++)
    {
        cin>>start[i];
        cin>>endd[i];
    }
    for(int i =0;i<n;i++)
    {

        int factorcount=0;
        int number=start[i];
        int temp=1;
        while (temp <= number)
    {
        if (not(number % temp))
            factorcount++;

        temp++;
    }

        if(factorcount==2){
        int mat[start[i]][start[i]];
        for(int j=0;j<start[i];j++)
        {
            for(int k=0;k<start[i];k++)
            {
                mat[j][k]=(j*k)%start[i];
            }
        }

        int count=0;
        for(int j=0;j<start[i];j++)
        {
            for(int k=0;k<start[i];k++)
            {
                if(mat[j][k]==endd[i])
                {
                    count++;
                }
            }
        }
        cout<<count<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }


}
