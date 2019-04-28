
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
    string neww;
        neww=neww+lrc(aa);
    cout<<neww;
    ofstream myfile;
  myfile.open ("d:\output1.txt");
  myfile << neww;
  myfile.close();
}
