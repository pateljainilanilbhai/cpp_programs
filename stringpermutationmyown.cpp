#include<iostream>
using namespace std;
int main()
{
    string s;
    cout<<"enter string";
    cin>>s;
    int q=s.length();
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<q;j++)
        {
            for(int k=0;k<q;k++)
            {
                for(int l=0;l<q;l++)
                {
                    if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l)
                    {
                        cout<<s[i]<<s[j]<<s[k]<<s[l]<<"\n";
                    }
                }
            }
        }
    }
}
