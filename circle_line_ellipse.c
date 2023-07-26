#include<stdio.h>
#include<graphics.h>

void draw_line();
void draw_circle();
void draw_ellipse();

void main(){

	int gd=DETECT,gm;
	int ch;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");


	do{
		printf("\n1.Line\n2.Circle\n3.Ellipse\n");
		printf("\nEnter your choice >> ");
		scanf("%d",&ch);
		
		switch(ch){
		case 1:
			draw_line();
			break;
		case 2:
			draw_circle();
			break;
		case 3:
			draw_ellipse();
			break;
		case 4:
			exit(0);
		
		}
	
	}while(ch!=4);	

}

void draw_line(){
	int x1,y1,x2,y2;
	int line_style,line_color,line_thikness;

	printf("\nEnter the co-ordinates >> ");
	scanf("%d%d%d%D",&x1,&y1,&x2,&y2);
	printf("\nEnter the line style >> ");
	scanf("%d",&line_style);
	printf("\nEnter line thikness 1/2/3 >> ");
	scanf("%d",&line_thikness);
	printf("\nEnter the line color >> ");
	scanf("%d",&line_color);

	clrscr();
	cleardevice();

	setcolor(line_color);
	setlinestyle(line_style,1,line_thickness);
	line(x1,y1,x2,y2);

	getch();

}
void draw_circle(){
	int radius,x,y;
	int fill_style,color;

	printf("\nEnter the radius >> ");scanf("%d",&radius);
	printf("\nEnter the fill style >>);
	scanf("%d",&fill_style);
	printf("\nEnter the color >> ");scanf("%d",&color);

	clrscr();
	cleardevice();
	
	setcolor(color);
	setfillstyle(fill_style,color);
	
	circle(x,y,radius);
	floodfill(x,y,radius);


	getch();
}
void draw_elipse(){
	int x,y;
	int x_radius,y_radius;
	int color,fill_style;

	printf("\nEnter X radius >> ")scanf("%d",&x_radius);
	printf("\nEnter Y radius >> ")scanf("%d",&y_radius);

	printf("\nEnter the co-ordinates >> ");
	scanf("%d%d",&x,&y);
	
	printf("\nEnter the color >> ");
	scanf("%d",&color);

	printf("\nEnter fill style >> ");
	scanf("%d",&fill_style);

	clrscr();
	cleardevice();

	setcolor(color);
	setfillstyle(fill_style,color);
	
	ellipse(x,y,0,360,x_radius,y_radius);

	fillellipse(x,y,x_radius,y_radius);

	getch();


}

