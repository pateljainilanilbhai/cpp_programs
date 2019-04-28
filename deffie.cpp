#include<iostream>
#include<cmath>
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









int alicewillsend(int prime,int base,int secret)
{
    stringstream ss;
    ss << base;
    string str = ss.str();
    return(ApowBmodM(str,secret,prime));
    //return(pow(str,secret)%prime);
}

int bobwillsend(int prime,int base,int secret)
{
    stringstream ss;
    ss << base;
    string str = ss.str();
    return(ApowBmodM(str,secret,prime));
    //return(pow(base,secret)%prime);
}

int alicewilldecrypt(int prime,int received,int alicesecret)
{
    stringstream ss;
    ss << received;
    string str = ss.str();
    return(ApowBmodM(str,alicesecret,prime));
    //return(pow(received,alicesecret)%prime);
}


int bobwilldecrypt(int prime,int received,int bobsecret)
{
    stringstream ss;
    ss << received;
    string str = ss.str();
    return(ApowBmodM(str,bobsecret,prime));
    //return(pow(received,bobsecret)%prime);
}





int main()
{
    int prime=71;
    int base=5;
    int bobsecret=15;
    int alicesecret=6;
    cout<<"alice secret key:"<<bobwilldecrypt(prime,alicewillsend(prime,base,alicesecret),bobsecret);
    cout<<endl;
     cout<<"bob secret key:"<<alicewilldecrypt(prime,bobwillsend(prime,base,bobsecret),alicesecret);
    cout<<endl;

}
