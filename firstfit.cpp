#include<iostream>
using namespace std;
void firstfit(int sizeofmem,int sizeofpro,int mem[],int pro[])
{
    int noofmemoryspace=sizeofmem;
    int noofprocess= sizeofpro;

    for(int i=0;i<noofprocess;i++)
    {

        int flag=0;
        for(int j=0;j<noofmemoryspace;j++)
        {
            if(pro[i]<=mem[j])
            {
                cout<<"process "<<i<<" of size "<<pro[i]<<"in memory location "<<j<<"\n";
                mem[j]=mem[j]-pro[i];
                flag=1;
                goto aa;
            }
        }
        if(flag==0)
        {
            cout<<"no space found for "<<"process "<<i<<" of size "<<pro[i]<<"\n";
        }
        aa:
            ;
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
    firstfit(m,p,memory,process);

}
