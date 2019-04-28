#include<iostream>
#include<fstream>
using namespace std;
string vrccheck(string a)
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
        return parity;
}
int main()
{
    string vrc;

    string aa;
    ifstream rfile;
    rfile.open("D:\output1.txt");
    rfile >> aa;
    string k;
    string kk;
    for(int j=0;j<8;j++){
     for(int i=j;i<aa.size()-8;i=i+8)
    {
        k=aa.substr(i,1);
        kk=k+kk;

    }
    vrc=vrc+vrccheck(kk);
        if(aa.substr(aa.length()-8+j,1)!=vrccheck(kk))
        {
            cout<<aa.substr(aa.length()-8+j,1)<<"     "<<vrccheck(kk);
            cout<<"error detected at level "<<j<<"\n";
        }
         kk="";
    }
    string check=aa.substr(aa.length()-8,8);
    if(vrc==check)
    {
        cout<<"file is perfect"<<"\n";
    }
    else
    {
        cout<<"error in file drop the whole file"<<"\n";
    }
}
