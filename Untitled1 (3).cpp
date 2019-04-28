#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
void sound()
{
 sound(2000);
 delay(100);
 nosound();
}
int main()
{
 sound();
}


