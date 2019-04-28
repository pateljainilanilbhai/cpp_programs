#include <stdio.h>
int func(int, int);
#define func(x,y) x/y+x  // Complete the Macro definition
int main() {
    int i,j;

    scanf("%d", &i);
    scanf("%d", &j);
    printf("%d ",func(i + j, 3));
       // Fill the blank
    printf("%d\n",func(i + j, 3));
}
int func(int x, int y) {
    return x / y + x;
}
