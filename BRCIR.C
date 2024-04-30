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
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C://TURBOC3//BGI");
	circleBres(200,200,50);
	circleBres(150,200,50);
	circleBres(250,200,50);
	circleBres(200,150,50);
	circleBres(200,250,50);
	getch();
	closegraph();
}