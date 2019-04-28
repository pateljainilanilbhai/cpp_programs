#include <stdio.h>
void foo( int[ ] );
int main()
{int myarray[4] = {1, 2, 3, 0};
foo(myarray);
printf("%d ", myarray[0]);
}
void foo(int p[4]){
    int k = 34;
p = &k;
printf("%d ", p[0]);
	}
