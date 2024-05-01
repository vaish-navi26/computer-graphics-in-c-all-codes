#include<stdio.h>
#include<conio.h>
#include<graphics.h>


void poly(){
    rectangle(100,100,140,140);
}
void ffill(int x,int y,int nc){
int current= getpixel(x, y);
int newcolor=nc;
 if (current!= newcolor){
    putpixel (x, y, newcolor);
    ffill (x-1, y,newcolor);
    ffill (x+1,y, newcolor);
    ffill(x,y-1, newcolor);
    ffill (x, y+1, newcolor);
 }
}


int main(){
int gd=DETECT,gm;

initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    
	   poly();
	   ffill(105,105,10);
	   getch();
     
closegraph();

return 0;
}

