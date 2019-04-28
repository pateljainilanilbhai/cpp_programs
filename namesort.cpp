#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int no;
    char temp[50];
    cout<<"enter number of names you want to arrange:"<<endl;
    cin>>no;
    char name[no][50];
    for(int i=0;i<no;i++)
    {
        cout<<"enter "<<i<<" th name:";
        cin>>name[i];
        cout<<endl;
    }
    for(int i=0;i<no;i++)
        for(int j=0;j<no;j++)
    {
        if(strcmp(name[i],name[j])<0)
        {
            strcpy(temp,name[i]);
            strcpy(name[i],name[j]);
            strcpy(name[j],temp);
        }
    }
    cout<<"sorted list is"<<endl;
    for(int i=0;i<no;i++)
        cout<<name[i]<<endl;
    return 0;

}
