#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char a='A';
    ofstream abc("abc.txt");
    for(int i=0;i<26;i++)
    {
        abc<<a;
        a++;
    }
    abc.close();
    ifstream file1("abc.txt");
    ofstream file2("cba.txt");
    char b[1];
    file1.seekg(0,ios::end);
    for(int i=0;i<26;i++)
    {

        char ch;
        file1.seekg(-1L,ios::cur);
        file.get(ch);
               file2<<ch;
    }
    file2.close();
    file1.close();
    ifstream file4("abc.txt");
    ifstream file3("cba.txt");
    char p[100];
    file3.getline(p,100);
    cout<<p;

}
