#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include <sstream>
using namespace std;



int mod(string num, int a)
{
    // Initialize result
    int res = 0;

    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') %a;

    return res;
}



int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a%h;
        if (temp == 0)
          return h;
        a = h;
        h = temp;
    }
}



unsigned int aModM(string s, unsigned int mod)
{
    unsigned int number = 0;
    for (unsigned int i = 0; i < s.length(); i++)
    {
        // (s[i]-'0') gives the digit value and form
        // the number
        number = (number*10 + (s[i] - '0'));
        number %= mod;
    }
    return number;
}

// Returns find (a^b) % m
unsigned int ApowBmodM(string &a, unsigned int b,
                                  unsigned int m)
{
    // Find a%m
    unsigned int ans = aModM(a, m);
    unsigned int mul = ans;

    // now multiply ans by b-1 times and take
    // mod with m
    for (unsigned int i=1; i<b; i++)
        ans = (ans*mul) % m;

    return ans;
}






string encrypt(long n,string message,long e)
{
    string encrypted="";
    for(int i=0;i<message.length();i++)
    {
        string mystring;
        stringstream mystream;
    mystream << (long)pow(message[i],e)%n;
    mystring = mystream.str();
        encrypted=encrypted+mystring+",";
    }
    return encrypted;
}


string decrypt(long p,long q,int n,int e,string message)
{
     long phi = (p-1)*(q-1);
    long d=0;
     while(true)
    {
       if((((long)(d*e))%phi)==1)
       {
           break;
       }
       d++;
    }

    string decryptedtext="";






    std::string s = message;
std::string delimiter = ",";

size_t pos = 0;
std::string token;
while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    string mystring;
        stringstream mystream;
    mystream << ApowBmodM(token, d, n);
    mystring = mystream.str();
   decryptedtext=decryptedtext+mystring+",";
    s.erase(0, pos + delimiter.length());
}
std::cout << s << std::endl;
    return decryptedtext;
}





int main()
{

    long p = 53;
    long q = 59;
    long n = p*q;

    long e = 2;
    long phi = (p-1)*(q-1);
    while (e < phi)
    {
        // e must be co-prime to phi and
        // smaller than phi.
        if (gcd(e, phi)==1)
            break;
        else
            e++;
    }




    string message;
    cout<<"enter your message:";
    cin>>message;
    cout<<encrypt(n,message,e)<<"\n";
    cout<<decrypt(p,q,n,e,encrypt(n,message,e));


}
