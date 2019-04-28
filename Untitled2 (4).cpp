#include<iostream>
#include<fstream>
using namespace std;
string lrc(string a)
{
         int count=0;
        string parity="0";


        for(int i=0;i<8;i++)
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
        a=parity+a;
        return a;
}
int main()
{
string aa;
    //fstream file=new fstream(Input1.txt);
    ifstream rfile;
    rfile.open("D:\input1.txt");
    rfile >> aa;
    int size=aa.size();
    string k;
   for(int i=0;i<size;i=i+8)
   {
       k=aa.substr(i,i+8);
       cout<<k<<endl;
   }




}
