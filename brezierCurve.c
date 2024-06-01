# include <stdio.h>
# include <conio.h>
# include <graphics.h>
# include <math.h>

double ncr(int n, int r) {
    double result = 1;
    int i;
    for ( i = 1; i <= r; i++) { 
        result *= (double)(n - i + 1) / i;
    }
    return result;
}

int main(){

    int points;
    int x[points],y[points],i = 0,j;
    double puty = 0,putx = 0,t;
    int gd=DETECT,gm;
    printf("Enter the number of points for Curve: ");
    scanf("%d", &points);

    initgraph(&gd,&gm,(char*)"");
    for ( i = 0; i < points; i++)
    {
        printf("Enter x and y coordinated of point %d: ",i+1);
        scanf("%d%d",&x[i],&y[i]);
        
    }

    for( i = 0; i < points - 1; i++){
        line(x[i],y[i],x[i + 1], y[i + 1]);
    }

    for(t = 0.0; t <= 1.0; t += 0.001){

    putx = 0;
    puty = 0;
    for( j = 0; j < points; j++){
        
        putx += ncr(points - 1, j) * pow(1 - t, points - 1 - j) * pow(t, j) * x[j];
        puty += ncr(points - 1, j) * pow(1 - t, points - 1 - j) * pow(t, j) * y[j];
    }
    putpixel((int)putx, (int)puty, WHITE); 
}


    getch();
    closegraph();
    return 0;
}
