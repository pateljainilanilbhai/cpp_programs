#include <iostream>
#include<stdlib.h>
#include <stdio.h>
#include "string"
using namespace std;






bool CheckSubstring(std::string firstString, std::string secondString){
    if(secondString.size() > firstString.size())
        return false;

    for (int i = 0; i < firstString.size(); i++){
        int j = 0;
        // If the first characters match
        if(firstString[i] == secondString[j]){
            int k = i;
            while (firstString[i] == secondString[j] && j < secondString.size()){
                j++;
                i++;
            }
            if (j == secondString.size())
                return true;
            else // Re-initialize i to its original value
                i = k;
        }
    }
    return false;
}








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
    string cipher;
    cout<<"enter cipher text\n";
	getline(cin, cipher);
	fflush(stdin);

	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";

int a[26]={};
	string intellegentdecision;
	for(int i=25;i>=0;i--)
    {
        string guess=encrypt(cipher, i);
        cout<<"key"<<25-i<<"   :"<<guess<<"\n\n\n";
        if(CheckSubstring(guess," or ")||CheckSubstring(guess," the ")||CheckSubstring(guess," in ")||CheckSubstring(guess," is ")||CheckSubstring(guess," of ")||CheckSubstring(guess," on ")||CheckSubstring(guess," am ")||CheckSubstring(guess," was ")||CheckSubstring(guess," were ")||CheckSubstring(guess," under "))
        {
           a[i]++;
        }
        int max=0;
        for(int j=0;j<26;j++)
        {
            if(a[j]>max)
            {
                max=a[j];
            }

        }
        if(a[i]==max)
        {
            intellegentdecision=guess;
        }
    }




	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";



	cout<<"INTELLEGENT DESISION:"<<intellegentdecision;
    return 0;

}

