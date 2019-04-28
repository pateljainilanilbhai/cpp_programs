#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char a[1000];
    cout<<"source file opened :";
    ofstream sour("abc.txt");
    cout<<"\n"<<"enter data in file"<<"\n";

    char ch='a';
    while(ch!=EOF)
    {
        ch=getchar();
        sour.put(ch);
    }
    sour.close();
    ifstream sour1("abc.txt");
    ofstream dest1("xyz.txt");
    cout<<"copying starts to destination file \n";
    ch='a';
    int i=0;
        while(sour1)
    {
        sour1.seekg(i,ios::beg);
        sour1.get(ch);
        dest1<<ch;
        i++;
    }
    sour1.close();
    dest1.close();
    cout<<" \n printing copied data \n";
    ifstream dest2("xyz.txt");
    ch='a';
    i=0;
        while(!dest2.eof())
    {

        dest2.seekg(i,ios::beg);
        dest2.get(ch);
        cout<<ch;
        i++;
    }
    cout<<"\n ending program type a character";
    cin>>ch;

}
