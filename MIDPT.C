#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void MD(int x0, int y0, int r)
{


 int x = 0;
 int y = r;
 int pk = 1-r;

 while (x <= y)
 {
  putpixel(x0 + x, y0 + y, WHITE);
  putpixel(x0 - x, y0 + y, WHITE);
  putpixel(x0 + x, y0 - y, WHITE);
  putpixel(x0 - x, y0 - y, WHITE);
  putpixel(x0 + y, y0 + x, WHITE);
  putpixel(x0 - y, y0 + x, WHITE);
  putpixel(x0 + y, y0 - x, WHITE);
  putpixel(x0 - y, y0 - x, WHITE);

  if (pk < 0)
  {
   x++;
   pk = pk + 2*x +1;
  }
  if (pk >= 0)
  {
   x++;
   y--;
   pk = pk - 2*y + 2*x + 1;
  }
 }


}

void main()
{
 int gd = DETECT, gm;
 int x,y,r;
 clrscr();
 initgraph(&gd,&gm,"C:\\programs\\TC\\BGI");
 MD(200,200,50);
 MD(150,200,50);
 MD(250,200,50);
 MD(200,150,50);
 MD(200,250,50);
 getch();
 closegraph();
}