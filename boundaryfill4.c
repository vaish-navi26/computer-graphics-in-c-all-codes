#include<stdio.h>
#include<conio.h>
#include<graphics.h>


void poly(){
    rectangle(100,100,140,140);
}

void boundfill(int x,int y,int fc,int bc){
if(getpixel(x,y)!=fc && getpixel(x,y)!=bc){
   putpixel(x,y,fc);
   bf(x+1,y,fc,bc);
   bf(x-1,y,fc,bc);
   bf(x,y+1,fc,bc);
   bf(x,y-1,fc,bc);
}
}
int main(){
int gd=DETECT,gm;

initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

        poly();
        boundfill(105,105,13,15);
        getch();
       closegraph();

return 0;
}

