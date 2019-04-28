#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    string name;
    ofstream file1("name.txt");
    cout<<"enter name:";
    cin>>name;
    file1<<name;
    file1.close();

    ifstream file3("name.txt");
    ofstream file2("duplicate.txt");
    char l[30];
    {
    file3.getline(l,30);
    file2<<l;
    }
    file2.close();
    ifstream file4("duplicate.txt");
    char k[30];
    file4.getline(k,30);

    cout<<k;
    cout<<"\n\n";

    cout<<file4.eof();
    cout<<file4.fail();
    cout<<file4.bad();
    cout<<file4.good();
}

