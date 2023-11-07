#include <stdio.h>
#include <conio.h>
#include <graphics.h>

// Working..

float x1, y1, x2, y2, xmin, ymin, xmax, ymax, m;

void drawLine(float x1, float y1, float x2, float y2) {
    line(x1, y1, x2, y2);
}

void clipLine() {
    int i;
    float a[4] = {0}, b[4] = {0}, c[4] = {0};
    
    if (x1 < xmin) a[3] = 1;
    if (x1 > xmax) a[2] = 1;
    if (y1 < ymin) a[1] = 1;
    if (y1 > ymax) a[0] = 1;

    if (x2 < xmin) b[3] = 1;
    if (x2 > xmax) b[2] = 1;
    if (y2 < ymin) b[1] = 1;
    if (y2 > ymax) b[0] = 1;
    
    for ( i = 0; i < 4; i++) {
        c[i] = a[i] && b[i];
    }
    
    if ((c[0] == 0) && (c[1] == 0) && (c[2] == 0) && (c[3] == 0)) {
        
        if ((a[0] == 0) && (a[1] == 0) && (a[2] == 0) && (a[3] == 0) &&
            (b[0] == 0) && (b[1] == 0) && (b[2] == 0) && (b[3] == 0)) {
            clrscr();
            clearviewport();
            printf("\n The line is totally visible\n and not a clipping candidate");
            rectangle(xmin, ymin, xmax, ymax);
            drawLine(x1, y1, x2, y2);
            getch();
        } else {
            clrscr();
            clearviewport();
            printf("\n Line is partially visible");
            rectangle(xmin, ymin, xmax, ymax);
            drawLine(x1, y1, x2, y2);
            getch();
            
            if ((a[0] == 0) && (a[1] == 1)) {
                x1 = x1 + (ymin - y1) / m;
                y1 = ymin;
            } else if ((b[0] == 0) && (b[1] == 1)) {
                x2 = x2 + (ymin - y2) / m;
                y2 = ymin;
            }
            
            if ((a[0] == 1) && (a[1] == 0)) {
                x1 = x1 + (ymax - y1) / m;
                y1 = ymax;
            } else if ((b[0] == 1) && (b[1] == 0)) {
                x2 = x2 + (ymax - y2) / m;
                y2 = ymax;
            }
            
            if ((a[2] == 0) && (a[3] == 1)) {
                y1 = y1 + m * (xmin - x1);
                x1 = xmin;
            } else if ((b[2] == 0) && (b[3] == 1)) {
                y2 = y2 + m * (xmin - x2);
                x2 = xmin;
            }
            
            if ((a[2] == 1) && (a[3] == 0)) {
                y1 = y1 + m * (xmax - x1);
                x1 = xmax;
            } else if ((b[2] == 1) && (b[3] == 0)) {
                y2 = y2 + m * (xmax - x2);
                x2 = xmax;
            }
            
            clrscr();
            clearviewport();
            printf("\n After clipping:");
            rectangle(xmin, ymin, xmax, ymax);
            drawLine(x1, y1, x2, y2);
            getch();
        }
    }
}

int main() {
    int gd = DETECT, gm;
    
    clrscr();
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    
    printf("\nEnter the 1st co-ordinate of line: ");
    scanf("%f %f", &x1, &y1);
    printf("\nEnter the 2nd co-ordinate of line: ");
    scanf("%f %f", &x2, &y2);
    printf("\nEnter the co-ordinates of clipping window: ");
    scanf("%f %f %f %f", &xmin, &ymin, &xmax, &ymax);
    
    rectangle(xmin, ymin, xmax, ymax);
    drawLine(x1, y1, x2, y2);
    
    m = (y2 - y1) / (x2 - x1);
    clipLine();
    
    getch();
    closegraph();
    return 0;
}
/*
Enter the 1st co-ordinate of line: 150 300
Enter the 2nd co-ordinate of line: 450 300
Enter the co-ordinates of clipping window: 200 200 400 400
*/