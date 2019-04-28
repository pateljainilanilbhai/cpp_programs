#include <cstdlib>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<conio.h>
using namespace std;
int main()
{

    start:
   int choice;
   cout<<"\n1. create a file"<<endl;
   cout<<"2. display content of file"<<endl;
   cout<<"3. write content in a file"<<endl;
   cout<<"4. update the content of file"<<endl;
   cout<<"5. copy file content"<<endl;
   cout<<"6. delete file permanently from storage"<<endl;
   cout<<"7. to count number of cbaracters in file"<<endl;
   cout<<"8. to write array of double in binary file"<<endl;
   cout<<"9. to read array of double from binary file"<<endl;
   cout<<"0. to end the program"<<endl;
   cout<<"11. shut down all programs running now"<<endl;
   cout<<"12. Restart the computer"<<endl;
   cout<<"13. Shutdown the computer"<<endl;
   cout<<"ENTER YOUR CHOICE:";

   cin>>choice;
   switch (choice)
   {
   case 1:
    {
        char c[500];
        cout<<"enter name of file to be created:";
        cin>>c;
        ofstream file(c);
        cout<<"file "<<c<<" is created now\n";
        file.close();
        break;
    }
    case 2:
    {
        char c[500];
        cout<<"enter name of file to be readed and displayed:";
        cin>>c;
        ifstream dest2(c);
        char ch;
        int i=0;
        while(!dest2.eof())
    {

        dest2.seekg(i,ios::beg);
        dest2.get(ch);
        cout<<ch;
        i++;
    }
    dest2.close();

        break;
    }
    case 3:
        {
            char c[500];
        cout<<"enter name of file to be writted from beginning :";
        cin>>c;
        ofstream sour(c);
    cout<<"\n"<<"enter data in file "<<c<<"\n";

    char ch='a';
    while(ch!=EOF)
    {
        ch=getchar();
        sour.put(ch);
    }
    sour.close();
    break;
        }
    case 4:
        {
            char c[500];
        cout<<"enter name of file to be readed and updated :";
        cin>>c;
        ifstream dest2(c);
        char ch;
        int i=0;
        while(!dest2.eof())
    {

        dest2.seekg(i,ios::beg);
        dest2.get(ch);
        cout<<ch;
        i++;

    }
    fstream sour(c);
    sour.seekg(0,ios::end);
     ch='a';
    while(ch!=EOF)
    {
        ch=getchar();
        sour.put(ch);
    }
    sour.close();

    break;
        }

    case 5:
        {
        char c1[500];
        cout<<"enter source file name :";
        cin>>c1;
        char c2[500];
        cout<<"enter destination file name :";
        cin>>c2;
        ifstream sour1(c1);
        ofstream dest1(c2);
        char ch;
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
        cout<<"data copied from "<<c1<<" to "<<c2;
        break;

        }
    case 6:
        {
           char c1[500];
        cout<<"enter file to be deleted or enter path of file to be deleted: ";
        cin>>c1;
        remove(c1);
        //use of remove command in cstdio is done here to delete a file.
        break;

        }
    case 7:
        {
            char c1[500];
            cout<<"enter file so that characters are count: ";
            cin>>c1;
            ifstream dest2(c1);

        char ch;
        int i=0;
        while(!dest2.eof())
    {

        dest2.seekg(i,ios::beg);
        dest2.get(ch);
        i++;

    }
             int n=dest2.tellg();
            cout<<"the number of characters in file are:"<<i-1<<endl;
            break;

        }
    case 8:
        {
            char c1[500];
            cout<<"enter binary file name to write it: "<<endl;
            cin>>c1;
            int qq;
            cout<<"enter no of terms you like to write in double binary file:"<<endl;
            cin>>qq;
                float g[qq];
    for(int i=0;i<qq;i++)
    {
        cout<<"enter "<<i+1<<" "<<" item :";
        cin>>g[i];
    }
    ofstream f(c1);
    f.write((char *)&g,sizeof(g));
    f.close();
    break;
        }
    case 9:
        {char c1[500];
            cout<<"enter binary file name to read it: "<<endl;
            cin>>c1;
            int qq;
            cout<<"enter no of terms you like to read from double binary file:"<<endl;
            cin>>qq;
    ifstream a(c1);
    float s[qq];
    a.read((char *)&s,sizeof(s));
    a.close();
    for(int i=0;i<qq;i++)
    {
       cout<<s[i]<<" ";

        }
        break;
        }
    case 11:
        { system("shutdown -f"); break;}
    case 12:
        { system("shutdown -r");     break; }
    case 13:
    { system("shutdown -s");     break;}
}
getch();
system("cls");
if(choice!=10)
goto start;
}
