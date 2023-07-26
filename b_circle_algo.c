#include<stdio.h>
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
			p=p+(2*x)+3;
			x++;
		}
		else{
			p=p+(2*x)+3-(2*y)+2;
			x++;
			y--;
		}

		putpixel(xa+x,ya+y,1);
		putpixel(xa-x,ya+y,2);
		putpixel(xa+x,ya-y,3);
		putpixel(xa-x,ya-y,4);
		putpixel(xa+y,ya+x,5);
		putpixel(xa-y,ya+x,6);
		putpixel(xa+y,ya-x,7);
		putpixel(xa-y,ya-x,8);

		
	}



}
