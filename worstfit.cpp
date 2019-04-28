#include<iostream>
using namespace std;

void worstfit(int sizeofmem,int sizeofpro,int mem[],int pro[])
{

    int noofmemoryspace=sizeofmem;
    int noofprocess= sizeofpro;

    for(int i=0;i<noofprocess;i++)
    {

        int flag=0;
        int bestindexfound=0;
        for(int j=0;j<noofmemoryspace;j++)
        {
            if((mem[j]-pro[i])>=(mem[bestindexfound]-pro[i])&&((mem[j]-pro[i])>=0))
            {
                bestindexfound=j;
            }
        }
        if(mem[bestindexfound]>=pro[i])
        {
            cout<<"process "<<i<<" of size "<<pro[i]<<"in memory location "<<bestindexfound<<"\n";
            mem[bestindexfound]=mem[bestindexfound]-pro[i];
        }
        else
        {
            cout<<"no space found for "<<"process "<<i<<" of size "<<pro[i]<<"\n";
        }
    }
}
int main()
{
    int p,m;
    cout<<"enter no of processes:";
    cin>>p;
    int process[p];
    cout<<"enter processes size separated by space:";
    for(int i=0;i<p;i++)
    {
         cin>>process[i];
    }
     cout<<"enter no of memory locations:";
    cin>>m;
    int memory[m];
    cout<<"enter memory locations available:";
     for(int i=0;i<p;i++)
    {
         cin>>memory[i];
    }
    worstfit(m,p,memory,process);

}


