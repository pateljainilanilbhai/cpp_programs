






#include<iostream>
using namespace std;
class number
{

    public:
            int num;
    number()
    {
        num=0;
    }
    number(int n)
    {
        num=n;
    }
   void getdata()
    {
        cout<<"enter num"<<endl;
        cin>>num;
    }
   void putdata(int i)
   {
       cout<<i<<"::"<<num<<endl;
   }
  number operator ++(int x)
   {
       x=num++;
       return (number(x));
   }
   number operator ++()
   {
       int x;
       x=++num;
       return(number(x));
   }
   number operator -()
   {
       int x;
       x=-num;
       return (number(x));
   }
};
int main()
{
    number n1,n2,n3;
    n2.getdata();
    n1=n2++;
    cout<<"after n1=n2++"<<endl;
    n1.putdata(1);
    n2.putdata(2);
    n3=++n1;
    cout<<"after n3=++n1"<<endl;
    n1.putdata(1);
    n2.putdata(2);
    n3.putdata(3);
    n3=-n3;
    n3.putdata(3);
}
