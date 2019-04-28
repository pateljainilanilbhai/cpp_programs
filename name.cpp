#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include<dos.h>
#include<string.h>
#include<iostream>
#include<ctime>
using namespace std;
int main( void)
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
setfillstyle(SOLID_FILL,GREEN);
setcolor(GREEN);
rectangle(50,50,50+400,50+300);
floodfill(51,51,GREEN);
setfillstyle(SOLID_FILL,RED);
setcolor(RED);
circle(250,200,100);
floodfill(250,200,RED);
getch();
closegraph();
return 0;
}
