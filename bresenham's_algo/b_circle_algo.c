#include<stdio.h>
#include<dos.h>
#include<graphics.h>

void main(){
	int gd=DETECT,gm=0;
	initgraph(&gd,gm,"C:\\turboc3\\bgi");


	int xa,ya,x,y;
	int radius;
	//decision variable
	int p;
	printf("\nEnter the coordinates >> ");
	scanf("%d%d",&xa,&ya);
	printf("Enter the radius >> ");
	scanf("%d",&radius);
	p=1-radius;
	x=0;
	y=radius;

	for(int i=0;x<y;i++){
		if(p<0){
			p= p + (2*x) + 3;
		}
		else{
			p = p + 2 * (x - y) + 5;
			y--;
		}
		x++;	

		putpixel(xa+x,ya+y,RED);
		putpixel(xa-x,ya+y,RED);
		putpixel(xa+x,ya-y,RED);
		putpixel(xa-x,ya-y,RED);
		putpixel(xa+y,ya+x,RED);
		putpixel(xa-y,ya+x,RED);
		putpixel(xa+y,ya-x,RED);
		putpixel(xa-y,ya-x,RED);
		delay(50);
		
	}



}
