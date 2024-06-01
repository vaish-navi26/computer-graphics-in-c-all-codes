#include <graphics.h>
#include <stdio.h>
#include <dos.h> // For delay function

// Function to compute region code for a point (x, y)
int computeCode(int x, int y, int xmin, int ymin, int xmax, int ymax) {
int code = 0;
if (x < xmin)
code |= 1;
if (x > xmax)
code |= 2;
if (y < ymin)
code |= 4;
if (y > ymax)
code |= 8;
return code;
}

// Function to clip a line from (x1, y1) to (x2, y2) using Mid-point Subdivision algorithm
void clipLine(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
int outcode1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
int outcode2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
int accept = 0;

while (1) {
if (!(outcode1 | outcode2)) { // Both endpoints lie inside the window
accept = 1;
break;
} else if (outcode1 & outcode2) { // Both endpoints lie in one region

Computer Graphics And Gaming Laboratory

break;
} else { // Some part of the line lies inside the window
int x, y;
int outcode = outcode1 ? outcode1 : outcode2;

// Find intersection point
if (outcode & 8) { // Point is above the clip window
x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
y = ymax;
} else if (outcode & 4) { // Point is below the clip window
x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
y = ymin;
} else if (outcode & 2) { // Point is to the right of the clip window
y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
x = xmax;
} else if (outcode & 1) { // Point is to the left of the clip window
y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
x = xmin;
}

// Replace outside point with intersection point
if (outcode == outcode1) {
x1 = x;
y1 = y;
outcode1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
} else {
x2 = x;
y2 = y;
outcode2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
}
}
}

Computer Graphics And Gaming Laboratory

// If line segment is accepted
if (accept) {
setcolor(GREEN);
line(x1, y1, x2, y2);
}

}

int main() {
int gd = DETECT, gm;
int xmin, ymin, xmax, ymax;
int x1, y1, x2, y2;
int outcode1, outcode2;
initgraph(&gd, &gm, "C:/TURBOC3/BGI");

printf("Enter coordinates of rectangular window (xmin ymin xmax ymax): ");
scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);

// Draw the window
setcolor(RED);
rectangle(xmin, ymin, xmax, ymax);

printf("Enter coordinates of line (x1 y1 x2 y2): ");
scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

// Draw the line before clipping
setcolor(BLUE);
line(x1, y1, x2, y2);

// Calculate and print bitcodes
outcode1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
outcode2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);

Computer Graphics And Gaming Laboratory

printf("Bitcode of Point 1: %d%d%d%d\n", (outcode1 & 8) ? 1 : 0, (outcode1 & 4) ? 1 : 0, (outcode1 & 2)
? 1 : 0, (outcode1 & 1) ? 1 : 0);
printf("Bitcode of Point 2: %d%d%d%d\n", (outcode2 & 8) ? 1 : 0, (outcode2 & 4) ? 1 : 0, (outcode2 & 2)
? 1 : 0, (outcode2 & 1) ? 1 : 0);

delay(2000); // Delay for 2 seconds
// Draw the window and clipped line
clipLine(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

getch();
closegraph();
return 0;
}
