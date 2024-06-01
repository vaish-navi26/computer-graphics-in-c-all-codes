# include <stdio.h>
# include <conio.h>
# include <graphics.h>
# include <math.h>

void kochCurve(int x1, int y1, int x2, int y2, int iteration);

int main(){

    int gd = DETECT, gm;
    int x1 = 100, y1 = 300, x2 = 500, y2 = 300;
    int iteration = 0;

    printf("Enter How may iterations you want:-");
    scanf("%d", &iteration);

     initgraph(&gd, &gm, (char*)"");

    setcolor(WHITE);
    kochCurve(x1, y1, x2, y2, iteration);

    getch();
    closegraph();

    return 0;
}

void kochCurve(int x1, int y1, int x2, int y2, int iteration)
{
    if(iteration == 0){
        line(x1, y1, x2, y2);
        return;
    }

    // This is to find the 1/3rd value of the line.
    int dx = (x2 - x1)/3;
    int dy = (y2 - y1)/3;

    // This is the 1/3rd line of curve.
    int x3 = x1 + dx;
    int y3 = y1 + dy;

    // This is the 2/3rd line of curve.
    int x4 = x2 - dx;
    int y4 = y2 - dy;

    // Now the midpoint of the (x1,y1) and (x2,y2).
    int xMid = (x1 + x2)/2;
    int yMid = (y1 + y2)/2;

    // Now the point curve point.

    int x5 = xMid + (x3 - xMid) * cos(M_PI/3) - (y3 - yMid) * sin(M_PI/3);
    int y5 = yMid + (x3 - xMid) * sin(M_PI/3) + (y3 - yMid) * cos(M_PI/3);

    kochCurve(x1, y1, x3, y3, iteration - 1);
    kochCurve(x3, y3, x5, y5, iteration - 1);
    kochCurve(x5, y5, x4, y4, iteration - 1);
    kochCurve(x4, y4, x2, y2, iteration - 1);
}
