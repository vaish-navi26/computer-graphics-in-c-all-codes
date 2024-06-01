#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define r 4

float T[3][3] = {{1,0,0},
		 {0,1,0},
		 {0,0,1}};

float S[3][3] = {{1,0,0},
		 {0,1,0},
		 {0,0,1}};

float SH[3][3] = {{1,0,0},
		  {0,1,0},
		  {0,0,1}};

float R[3][3] =  {{1,0,0},
		  {0,1,0},
		  {0,0,1}};


float A[r][3] = {{20,20,1},
	       {100,20,1},
	       {100,100,1},
	       {20,100,1}};
float mul[r][3];

/* void reflection(float rx, float ry)
{
 int i,j,k;
 R[0][0] = rx;
 R[1][1] = ry;

 for (i=0;i<r;i++)
 {
  for (j=0;j<3;j++)
  {
   mul[i][j]=0;
   for (k=0;k<3;k++)
   {
    mul[i][j] += A[i][k] * R[k][j];
   }
  }
 }
}
*/
void shear(float shx, float shy)
{
 int i,j,k;
 SH[0][1] = shx;
 SH[1][0] = shy;

 for (i=0;i<r;i++)
 {
  for (j=0;j<3;j++)
  {
   mul[i][j]=0;
   for (k=0;k<3;k++)
   {
    mul[i][j] += A[i][k] * SH[k][j];
   }
  }
 }
}

void scale(float sx, float sy)
{
 int i,j,k;
 S[0][0] = sx;
 S[1][1] = sy;

 for (i=0;i<r;i++)
 {
  for (j=0;j<3;j++)
  {
   mul[i][j]=0;
   for (k=0;k<3;k++)
   {
    mul[i][j] += A[i][k] * S[k][j];
   }
  }
 }
}

void translate(float tx, float ty)
{
 int i,j,k;
 T[2][0] = tx;
 T[2][1] = ty;

 for (i=0;i<r;i++)
 {
  for (j=0;j<3;j++)
  {
   mul[i][j]=0;
   for (k=0;k<3;k++)
   {
    mul[i][j] += A[i][k] * T[k][j];
   }
  }
 }

}




void main()
{
 int gd = DETECT,gm,i,j;
 float tx = 50,ty = 50;
 float sx = 0.5,sy = 0.5;
 float shx = 1,shy = 1;
 int choi;

 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 printf("\n1). Translation \n2). Scaling \n3). Reflection on y-axis \n4). Reflection on x-axis \n5). Reflection about origin \n6). Shear-x \n7). Shear-y");
 printf("\nEnter choi: ");
 scanf("%d",&choi);
 cleardevice();

 line(A[0][0],A[0][1],A[1][0],A[1][1]);
 line(A[1][0],A[1][1],A[2][0],A[2][1]);
 line(A[2][0],A[2][1],A[3][0],A[3][1]);
 line(A[3][0],A[3][1],A[0][0],A[0][1]);
 getch();
 cleardevice();

 switch(choi)
 {
  case 1:
    translate(tx,ty);
    break;

  case 2:
    scale(sx,sy);
    break;
/*
  case 3:
    reflection(-1,1);
    break;

  case 4:
    reflection(1,-1);
    break;

  case 5:
    reflection(-1,-1);
    break;
*/
  case 6:
    shear(shx,0);
    break;

  case 7:
    shear(0,shy);
    break;

  default:
    printf("\nInavalid Input!!");
 }

 line(mul[0][0],mul[0][1],mul[1][0],mul[1][1]);
 line(mul[1][0],mul[1][1],mul[2][0],mul[2][1]);
 line(mul[2][0],mul[2][1],mul[3][0],mul[3][1]);
 line(mul[3][0],mul[3][1],mul[0][0],mul[0][1]);
 getch();
 closegraph();
}
