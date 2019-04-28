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
    rfile.open("D:\input1.txt");
    rfile >> aa;
    string k;
    string kk;
    for(int j=0;j<8;j++){
     for(int i=j;i<aa.size();i=i+8)
    {
        k=aa.substr(i,1);
        kk=k+kk;
    }
    vrc=vrc+vrccheck(kk);
    kk="";
    }
    cout<<aa+vrc;
     ofstream myfile;
  myfile.open ("d:\output1.txt");
  myfile << aa+vrc;
  myfile.close();
}
