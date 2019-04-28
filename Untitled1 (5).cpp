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
    rfile.open("D:\input1.txt");
    rfile >> aa;
    int size=aa.size();
    string k;
    string neww;
    for(int i=0;i<aa.size();i=i+8)
    {
        k=aa.substr(i,8);
        neww=neww+lrc(k);

    }
    cout<<neww;
    ofstream myfile;
  myfile.open ("d:\output1.txt");
  myfile << neww;
  myfile.close();
}
