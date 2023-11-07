#include<stdio.h>
#include<graphics.h>



void draw_line(x1,y1,x2,y2){
	
	int x=x1;
	int y=y1;
	int dx = x2-x1;
	int dy = y2-y1;
	p= 2*dy - dx;
	
	while(x<=x2){
		putpixel(x,y);
		x++;
		
		if(p<0)
		{
			p=p+2*dy;
		}
		else{
			p=p+2*dy-2*dx;
			y++;
		}

	}
	
	
}


void main(){
	int x1,x2,y2,y1;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,'c:\\turboc3\\BGI');

	printf("Enter x1 and y1 >> ");
	scanf("%d%d",&x1,&y1);

	printf("Enter x2 and y2 >> ");
	scanf("%d%d",&x2,&y2);
	draw_line(x1,x2,y1,y2);
}
