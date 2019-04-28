#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char * argv[])
{
    char a[1000];
    cout<<"source file opened :"<<argv[1];
    ofstream sour(argv[1]);
    cout<<"\n"<<"enter data in file"<<"\n";

    char ch='a';
    while(ch!=EOF)
    {
        ch=getchar();
        sour.put(ch);
    }
    sour.close();
    ifstream sour1(argv[1]);
    ofstream dest1(argv[2]);
    cout<<"copying starts to destination file \n";
    ch='a';
        while(sour1)
    {
        sour1.seekg(1L,ios::cur);
        sour1.get(ch);
        dest1<<ch;
    }
    sour1.close();
    dest1.close();
    cout<<" \n printing copied data \n";
    ifstream dest2(argv[2]);
    ch='a';
        while(dest2)
    {

        dest2.seekg(1L,ios::cur);
        dest2.get(ch);
        cout<<ch;
    }
    cout<<"\n ending program type a character";
    cin>>ch;

}
