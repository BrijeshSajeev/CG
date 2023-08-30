#include<stdio.h>
#include<graphics.h>

void ellipse(int a,int b);

void main(){
	int a,b;
	int gd=DETECT,gm=0;

	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	
	printf("\nEnter the X-radius and Y-radius >> ");
	scanf("%d%d",&a,&b);

	ellipse(a,b);

}

void ellipse(int a,int b){
	int x,y;
	float d;

	for(x=0;x<=a;x++){
		y = b * sqrt(1-(x*x))/(float)(a*a);
		putpixel(200+x,200+y,7);
	
		putpixel(200-x,200+y,7);
	
		putpixel(200+x,200-y,7);
	
		putpixel(200-x,200-y,7);
	
	}

	for(y=0;y<=b;y++){
		x=a* sqrt(1-(y*y))/(float)(b*b);

		putpixel(200+x,200+y,7);

		putpixel(200-x,200+y,7);
	
		putpixel(200+x,200-y,7);
	
		putpixel(200-x,200-y,7);
	

	}



}


