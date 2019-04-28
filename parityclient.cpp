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
        a=parity;
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
    if(lrc(aa)=="0")
    {
        cout<<"file is perfect";
    }
    else{
        cout<<"file is damaged and droped";
    }
}

