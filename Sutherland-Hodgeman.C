#include <graphics.h>
#include <conio.h>
 
#define MAX_POINTS 20
 
typedef struct {
   int x, y;
} Point;
 
int inside(Point p, int x1, int y1, int x2, int y2, int edge);
Point intersect(Point p1, Point p2, int x1, int y1, int x2, int y2, int edge);
void clipPolygon(Point* poly, int* len, int x1, int y1, int x2, int y2, int edge);
void drawPolygon(Point* poly, int len);
 
int main() {
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
 
   Point poly[MAX_POINTS] = {{150, 150}, {300, 100}, {350, 200}, {250, 250}, {200, 200}};
   int len = 5;
   int x1 = 100, y1 = 100, x2 = 300, y2 = 200;
 
   setcolor(WHITE);
   drawPolygon(poly, len);
 
   setcolor(RED);
   rectangle(x1, y1, x2, y2);
 
   for (int edge = 0; edge < 4; edge++) {
       clipPolygon(poly, &len, x1, y1, x2, y2, edge);
   }
 
   setcolor(GREEN);
   drawPolygon(poly, len);
 
   getch();
   closegraph();
   return 0;
}
 
int inside(Point p, int x1, int y1, int x2, int y2, int edge) {
   switch (edge) {
       case 0: return p.x >= x1; // Left
       case 1: return p.x <= x2; // Right
       case 2: return p.y <= y2; // Bottom
       case 3: return p.y >= y1; // Top
   }
   return 0;
}
 
Point intersect(Point p1, Point p2, int x1, int y1, int x2, int y2, int edge) {
   Point p;
   if (edge == 0 || edge == 1) { // Left or Right
       p.x = (edge == 0) ? x1 : x2;
       p.y = p1.y + (p.x - p1.x) * (p2.y - p1.y) / (p2.x - p1.x);
   } else { // Bottom or Top
       p.y = (edge == 2) ? y2 : y1;
       p.x = p1.x + (p.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
   }
   return p;
}
 
void clipPolygon(Point* poly, int* len, int x1, int y1, int x2, int y2, int edge) {
   Point newPoly[MAX_POINTS];
   int newLen = 0;
 
   for (int i = 0; i < *len; i++) {
       Point curr = poly[i];
       Point prev = poly[(i + *len - 1) % *len];
 
       if (inside(curr, x1, y1, x2, y2, edge)) {
           if (!inside(prev, x1, y1, x2, y2, edge)) {
               newPoly[newLen++] = intersect(prev, curr, x1, y1, x2, y2, edge);
           }
           newPoly[newLen++] = curr;
       } else if (inside(prev, x1, y1, x2, y2, edge)) {
           newPoly[newLen++] = intersect(prev, curr, x1, y1, x2, y2, edge);
       }
   }
 
   *len = newLen;
   for ( i = 0; i < newLen; i++) {
       poly[i] = newPoly[i];
   }
}
 
void drawPolygon(Point* poly, int len) {
   for (int i = 0; i < len; i++) {
       int next = (i + 1) % len;
       line(poly[i].x, poly[i].y, poly[next].x, poly[next].y);
   }
}
