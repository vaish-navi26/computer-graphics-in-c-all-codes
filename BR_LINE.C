#include <stdio.h>
#include <graphics.h>

void bresenhams_line(int x1, int y1, int x2, int y2) {
     int i;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1, y = y1;
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;

    if (dx > dy) {
	int p = 2 * dy - dx;
	for (i = 0; i <= dx; i++) {
	    putpixel(x, y, WHITE);
	    if (p >= 0) {
		y += sy;
		p -= 2 * dx;
	    }
	    x += sx;
	    p += 2 * dy;
	}
    } else {
	int p = 2 * dx - dy;
	for (i = 0; i <= dy; i++) {
	    putpixel(x, y, WHITE);
	    if (p >= 0) {
		x += sx;
		p -= 2 * dy;
	    }
	    y += sy;
	    p += 2 * dx;
	}
    }
}

void triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    bresenhams_line(x1, y1, x2, y2);
    bresenhams_line(x2, y2, x3, y3);
    bresenhams_line(x3, y3, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"C://programs//TC//BGI");
    triangle(150, 150, 250, 150, 200, 350);
    triangle(150,300,250,300,200,100);
    getch();
    closegraph();
    return 0;
}