#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void dda(int x,int y,int x1,int y1){
float m,n,f,steps,x2,y2,i;
m=(y1-y);
n=(x1-x);
if(n>=m){
steps =n;
}
else{
steps= m;
}
n=n/steps;
m=m/steps;
x2=x;
y2=y;
i=1;
while(i<=steps){
putpixel(x2,y2,WHITE);


x2+=n;
y2+=m;
i=i+1;
}
}

int main(){
int gd = DETECT, gm,x,y,x1,y1;
initgraph(&gd, &gm, "c:\\programs\\tc\\bgi");

printf("-----DDA ALGO------\n");
printf("enter x1,y1:");
scanf("%d %d",&x,&y);
printf("enter x2,y2:");
scanf("%d %d",&x1,&y1);
cleardevice();
dda(x,y,x1,y1);

getch();
closegraph();
return 0;

}