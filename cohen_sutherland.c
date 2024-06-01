#include <graphics.h>
#include <conio.h>
#include <stdio.h>
 
// Define region codes
#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8
 
// Define screen boundaries
#define X_MIN 100
#define Y_MIN 100
#define X_MAX 500
#define Y_MAX 300
 
// Function to draw a line
void drawLine(int x1, int y1, int x2, int y2) {
   line(x1, y1, x2, y2);
}
 
// Function to compute region code for a point
int computeRegionCode(int x, int y) {
   int code = INSIDE; // Initialized as inside
 
   if (x < X_MIN)
       code |= LEFT;
   else if (x > X_MAX)
       code |= RIGHT;
 
   if (y < Y_MIN)
       code |= BOTTOM;
   else if (y > Y_MAX)
       code |= TOP;
 
   return code;
}
 
// Function to clip a line segment using Cohen-Sutherland algorithm
void cohenSutherland(int x1, int y1, int x2, int y2) {
   int code1 = computeRegionCode(x1, y1);
   int code2 = computeRegionCode(x2, y2);
   int accept = 0;
 
   while (1) {
       if ((code1 == 0) && (code2 == 0)) {
           // Both endpoints are inside, accept the line
           accept = 1;
           break;
       } else if (code1 & code2) {
           // Both endpoints are outside the same region, reject the line
           break;
       } else {
           // Clipping required, find intersection point
           int codeOut = code1 ? code1 : code2;
           int x, y;
 
           if (codeOut & TOP) {
               x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
               y = Y_MAX;
           } else if (codeOut & BOTTOM) {
               x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
               y = Y_MIN;
           } else if (codeOut & RIGHT) {
               y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
               x = X_MAX;
           } else if (codeOut & LEFT) {
               y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
               x = X_MIN;
           }
 
           if (codeOut == code1) {
               x1 = x;
               y1 = y;
               code1 = computeRegionCode(x1, y1);
           } else {
               x2 = x;
               y2 = y;
               code2 = computeRegionCode(x2, y2);
           }
       }
   }
 
   if (accept) {
       // Draw the clipped line segment
       drawLine(x1, y1, x2, y2);
   }
}
 
int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
 
   // Set the viewport
   setviewport(0, 0, 640, 480, 1);
 
   // Draw the window boundaries
   rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
 
   // Define line endpoints
   int x1 = 50, y1 = 50, x2 = 600, y2 = 400;
 
   // Draw the original line
   setcolor(WHITE);
   drawLine(x1, y1, x2, y2);
 
   // Clip the line using Cohen-Sutherland algorithm
   setcolor(YELLOW);
   cohenSutherland(x1, y1, x2, y2);
 
   getch();
   closegraph();
   return 0;
}
