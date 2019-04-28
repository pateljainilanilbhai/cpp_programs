#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    float g[5];
    for(int i=0;i<5;i++)
    {
        cout<<"enter "<<i+1<<" "<<"height";
        cin>>g[i];
    }
    ofstream f("123.txt");
    f.write((char *)&g,sizeof(g));
    f.close();
    ifstream a("123.txt");
    float s[10]={0,0,0,0,0,0,0,0,0,0};
    a.read((char *)&s,sizeof(s));
    a.close();
    for(int i=0;i<10;i++)
    {
       cout<<s[i]<<" ";
    }
}
