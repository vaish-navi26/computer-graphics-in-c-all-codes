#include <stdio.h>
#include <dos.h>
#include <graphics.h>

void drawCircle(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, GREEN);
	putpixel(xc-x, yc+y, GREEN);
	putpixel(xc+x, yc-y, GREEN);
	putpixel(xc-x, yc-y, GREEN);
	putpixel(xc+y, yc+x, GREEN);
	putpixel(xc-y, yc+x, GREEN);
	putpixel(xc+y, yc-x, GREEN);
	putpixel(xc-y, yc-x, GREEN);
}


void circleBres(int xc, int yc, int r)
{
	int x = 0, y = r;
	int d = 3 - 2 * r;
	drawCircle(xc, yc, x, y);
	while (y >= x)
	{

		x++;

		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawCircle(xc, yc, x, y);
	}
}


void main()
{
	int gd = DETECT, gm,x,y,r;
	initgraph(&gd, &gm, "C://TURBOC3//BGI");
	
	 printf("-------MIDPOINT CIRCLE ALGO--------\n");
printf("enter x,y,r:");
scanf("%d %d %d",&x,&y,&r);
circleBres(x,y,r);
	getch();
	closegraph();
}
