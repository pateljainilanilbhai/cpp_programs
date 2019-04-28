#include<iostream>
class employee
{
public:
   void hello()
   {
       cout<<"Hi hello"<<endl;
   }
};
int main()
{
   // declaring pointer to member function hello
   void (employee ::*fp)() = &employee::hello;
   employee e;
   employee *optr = &e;
   (e->*fp)();
   (optr.*fp)();
   return 0;
}
