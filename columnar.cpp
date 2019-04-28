#include<iostream>
#include<cmath>
using namespace std;
string encryptColumnar(string s,int col)
{
    string cipher="";
    int r=ceil(s.length()/float(col));
    char enc[r][col];
    int k=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<col;j++)
        {

            enc[i][j]=s[k];
            if(!isalpha(s[k]))
            {
                enc[i][j]=' ';
            }
            k++;

            cout<<enc[i][j];

        }
        cout<<endl;
    }
    cout<<endl<<endl;

    for(int j=0;j<col;j++)
    {
        for(int i=0;i<r;i++)
        {
                cout<<enc[i][j];
                cipher+=enc[i][j];
        }
    }
    return cipher;
}
string decryptColumnar(string s,int col)
{
    string plain;
    int r=floor(s.length()/float(col));
    char enc[r][col]={};
    int k=0;

    cout<<endl;


    for(int j=0;j<col;j++)
        {
            for(int i=0;i<r;i++)
            {
                enc[i][j]=s[k];
                k++;
                cout<<enc[i][j];
            }
            cout<<endl;

        }




    cout<<endl<<endl;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<col;j++)
        {
                cout<<enc[i][j];
                plain+=enc[i][j];
        }
    }
    return plain;
}
int main()
{
    string s;
    int col;
    cout<<"Enter the string:"<<endl;
    getline(cin,s);
    cout<<"Enter the number of columns:"<<endl;
    cin>>col;
    string cipher=encryptColumnar(s,col);
    decryptColumnar(cipher,col);
}
