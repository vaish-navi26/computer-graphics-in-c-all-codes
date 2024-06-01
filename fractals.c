# include <stdio.h>
# include <conio.h>
# include <graphics.h>
# include <math.h>

void drawCoastline(int x1, int y1, int x2, int y2, int iterations){

     if (iterations == 0) {
        // Base case: draw a straight line
        line(x1, y1, x2, y2);
    }
    else {

        // calculating the mid points.

        int midX = (x1 + x2) / 2;
        int midY = (y1 + y2) / 2;

        // calculation the delta x and delta y

        int deltaX = rand() % (2 * iterations) - iterations;
        int deltaY = rand() % (2 * iterations) - iterations;

        midX += deltaX;
        midY += deltaY;

        // now recursion

        drawCoastline(x1, y1, midX, midY, iterations - 1);
        drawCoastline(midX, midY, x2, y2, iterations - 1);
    }
}

int main(){

    int gd = DETECT, gm;
    int iterations;

    // Initialize graphics mode
    initgraph(&gd, &gm, (char*)"");

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    srand(1);

     int x1 = 100, y1 = 200;
    int x2 = 500, y2 = 200;

    // Draw the coastline
    drawCoastline(x1, y1, x2, y2, iterations);

    getch();
    closegraph();
    return 0;
}
