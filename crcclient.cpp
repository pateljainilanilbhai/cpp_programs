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
int lrcclient()
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
            return i/9;
        }
    }
    return 0;


}
int main()
{

    string vrc;
    int level=0;
    string aa;
    ifstream rfile;
    rfile.open("D:\output1.txt");
    rfile >> aa;
    string k;
    string kk;
    for(int j=0;j<9;j++){
     for(int i=j;i<aa.size()-9;i=i+9)
    {
        k=aa.substr(i,1);
        kk=k+kk;
    }
    vrc=vrc+vrccheck(kk);
        if(aa.substr(aa.length()-9+j,1)!=vrccheck(kk))
        {
            cout<<aa.substr(aa.length()-9+j,1)<<"       "<<vrccheck(kk);
            level=j;
            goto x;
        }
         kk="";
    }
    x:
        cout<<"error found at"<<(((lrcclient())*8)+(level+1));

}

