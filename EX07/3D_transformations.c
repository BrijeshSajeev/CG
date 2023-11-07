#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void drawcube(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){

      rectangle(x1,y1,x2,y2);

      rectangle(x3,y3,x4,y4);

      line(x1,y1,x3,y3) ;
      line(x2,y2,x4,y4);
      line(y1,y2,x3,y4);
      line(x2,y1,x4,y3);


}

void translate(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
  int tx=200,ty=200;
  drawcube(x1+tx,y1+ty,x2+tx,y2+ty,x3+tx,y3+ty,x4+tx,y4+ty);
}
void scale(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
  int tx=1,ty=2;
  drawcube(x1*tx,y1*ty,x2*tx,y2*ty,x3*tx,y3*ty,x4*tx,y4*ty);
}

void rotate(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
  int xa=60;

  float radX = xa *(3.14/180);

  int x1n,x2n,x3n,x4n,y1n,y2n,y3n,y4n;

   x1n = x1* cos(radX)- y1*sin(radX);
   y1n = x1* sin(radX)+ y1*cos(radX);
   x2n = x2* cos(radX)- y2*sin(radX);
   y2n = x2* sin(radX)+ y2*cos(radX);
   x3n = x1+50*cos(radX);
   y3n= y1-50*sin(radX);
   x4n= x2+50*cos(radX);
   y4n = y2 - 50 *sin(radX);
   printf("Hello");
   drawcube(x1n,y1n,x2n,y2n,x3n,y3n,x4n,y4n);
}
int main(){
      int gd=DETECT,gm;
      int x1=100,x2=200,y1=100,y2=200;
      int x3,y3,x4,y4,depth=50;
      initgraph(&gd,&gm,"c:\\turboc3\\BGI");

      //front face
      x3=x1+depth;
      y3=y1-depth;
      x4=x2+depth;
      y4=y2-depth;
      drawcube(x1,y1,x2,y2,x3,y3,x4,y4);
      getch();
     // translate(x1,y1,x2,y2,x3,y3,x4,y4);
    //  scale(x1,y1,x2,y2,x3,y3,x4,y4) ;
      rotate(x1,y1,x2,y2,x3,y3,x4,y4) ;
      delay(5);
      getch();
      closegraph();
      return 0;
}