#include<iostream>
#include<cstdio>
using namespace std;
class celsius
{
    float temp;
    public:
    celsius ()
    {

    }
    celsius(float x)
    {
        temp=x;
    }
    operator float()
    {
        return temp;
    }
};
int main()
{
    celsius t;
    float temperature;
    t=75;
    temperature=t;
    cout<<temperature;
}
