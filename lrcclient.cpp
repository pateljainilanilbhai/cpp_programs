#include<iostream>
#include<fstream>
using namespace std;
string lrc(string a)
{
         int count=0;
        string parity="0";


        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='1')
            {
                count++;
            }
        }
        if(count%2!=0)
        {
            parity="1";
        }
        else{
            parity="0";
        }
        a=a+parity;
        return a;
}
int main()
{
    string aa;
    ifstream rfile;
    rfile.open("D:\output1.txt");
    rfile >> aa;
    string k;
    string kk;
    int flag=0;
    for(int i=0;i<aa.size()-9;i=i+9)
    {
        k=aa.substr(i,8);
        kk=aa.substr(i,9);
        if((kk)!=lrc(k))
        {
            cout<<"error detected at"<<(i/9)<<" th byte \n";
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"no error detected \n";
    }



}
