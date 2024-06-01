#include <stdio.h>
#include <graphics.h>
#include <math.h>


void drawBezierCurve(int x[], int y[]) {
    float t;
    setcolor(BLUE);

  
    for (t = 0.0; t <= 1.0; t += 0.001) {
        float xt, yt;
        xt = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];
        yt = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];
        putpixel(xt, yt, RED);
    }
}

int main() {
    int gd = DETECT, gm;
    int choice;
    int bezierX[] = {100, 200, 300, 400};
    int bezierY[] = {100, 300, 200, 100};

    initgraph(&gd, &gm, "C://TURBOC3//BGI");

    drawBezierCurve(bezierX, bezierY);

closegraph();
return 0;
}


