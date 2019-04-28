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
   string vrc;

    string vk;
    string vkk;
    for(int j=0;j<9;j++){
     for(int i=j;i<neww.size();i=i+9)
    {
        vk=neww.substr(i,1);
        vkk=vk+vkk;
    }
    vrc=vrc+vrccheck(vkk);
    vkk="";
    }
    cout<<neww+vrc;
     ofstream myfile;
  myfile.open ("d:\output1.txt");
  myfile << neww+vrc;
  myfile.close();
}
