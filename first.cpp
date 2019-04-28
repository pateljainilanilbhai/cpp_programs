#include<iostream>
void firstfit(int memoryspace[],int processsize[])
{
    int remaining[5];
    for(int i=0;i<5;i++)
    {
        remaining[i]=memoryspace[i];
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++){
        if(remaining[j]<=processsize[i])
        {

            cout<<process[i]<<"in "<<memoryspace[j];
            remaining[i]=remaining[i]-processsize[i];
            break;
        }
        }
    }

}
int main()
{
    memory
}
