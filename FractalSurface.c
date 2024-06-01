#include <graphics.h>
#include <stdlib.h>
#include <math.h>

// Function to draw the fractal mountain using Midpoint Displacement Algorithm
void drawFractalMountain(int x1, int y1, int x2, int y2, int depth, float roughness) {
    if (depth == 0) {
        line(x1, y1, x2, y2);
        return;
    }

    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;

    // Calculate displacement with roughness factor
    int displacement = (rand() % 20 - 10) * roughness;
    midY += displacement;

    // Recursively draw the two halves
    drawFractalMountain(x1, y1, midX, midY, depth - 1, roughness * 0.6); // Reduce roughness
    drawFractalMountain(midX, midY, x2, y2, depth - 1, roughness * 0.7); // Reduce roughness
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x1 = 50, y1 = 300;
    int x2 = 590, y2 = 300;
    int depth = 7;  // Adjust depth for more or fewer iterations
    float roughness = 20.0;  // Initial roughness

    // Seed the random number generator
    srand(time(0));

    // Draw the fractal mountain
    drawFractalMountain(x1, y1, x2, y2, depth, roughness);

    getch();
    closegraph();
    return 0;
}

