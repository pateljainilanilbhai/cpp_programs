#include <iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

string encrypt(string text, int s)
{
	string result = "";
	for (int i=0;i<text.length();i++)
	{
		if (isupper(text[i]))
			result += char(int(text[i]+s-65)%26 +65);
    else if(text[i]==' ')
        result+=' ';
    else if(text[i]=='.')
        result+='.';
    else if(text[i]==':')
        result+=':';
    else if(text[i]=='"')
        result+='"';
    else if(text[i]=='-')
        result+='-';
	else
		result += char(int(text[i]+s-97)%26 +97);
	}


	return result;
}

int main()
{

    int s;
    string text;
    cout<<"enter text\n";
	getline(cin, text);
	fflush(stdin);
	cout<<"enter key:";
	cin>>s;
    string cipher=encrypt(text, s);
	cout << "\nHAVE Cipher: " << cipher;

	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";


	//for(int i=25;i>=0;i--)
    //{
    //    string guess=encrypt(cipher, i);
    //   cout<<"key"<<25-i<<"   :"<<guess<<"\n\n\n";
    //}

	//cout<<"\n";
	//cout<<"\n";
	//cout<<"\n";
	//cout<<"\n";6




    return 0;

}
