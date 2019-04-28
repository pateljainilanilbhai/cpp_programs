#include <iostream>
using namespace std;
int main()

{
    int var1 = 35,var2 = 20;
    int *const ptr = &var1;
    cout<<"var1= "<<*ptr;
    return 0;
}
