# include <stdio.h>
# include <conio.h>
# include <graphics.h>
# include <math.h>

void  hilbertCurve(int x, int y, int xi, int xj, int yi, int yj, int level){

    if(level <= 0){
        line(x, y, x + (xi + yi)/2, y + (xj + yj)/2);
        return;
    }

    hilbertCurve(x, y, xi/2, xj/2, yi/2, yj/2, level - 1);
    hilbertCurve(x + xi/2, y + xj/2, xi/2, xj/2, yi/2, yj/2, level - 1);
    hilbertCurve(x + xi/2 + yi/2, y + xj/2 + yj/2, xi/2, xj/2, yi/2, yj/2, level - 1);
   hilbertCurve(x + xi/2 + yi, y + xj/2 + yj, -xi/2, -xj/2, -yi/2, -yj/2, level - 1);
}

int main(){

    int x = 100;
    int y = 100;
    int xi = 200;
    int xj = 0;
    int yi = 0;
    int yj = 200;
    int level = 0;

    int gd = DETECT, gm;

    initgraph(&gd, &gm, (char*)"");

    printf("Enter the number of levels:-");
    scanf("%d", &level);

    hilbertCurve(x, y, xi, xj, yi, yj, level);

    getch();
    closegraph();
    return 0;
}
