#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void drawRectangle(int left, int top, int right, int bottom) {
    rectangle(left, top, right, bottom);
}

void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}

void translateAndScale(int x1, int y1, int x2, int y2, int x3, int y3, int v1, int v2, int v3, int v4,int w1,int w2,int w3,int w4) {
    float sx = (float)(v3 - v1) / (w3 - w1);
    float sy = (float)(v4 - v2) / (w4 - w2);
    
    int translatedX1 = v1 + floor(((float)(x1 - w1) * sx) + 0.5);
    int translatedY1 = v2 + floor(((float)(y1 - w2) * sy) + 0.5);
    int translatedX2 = v1 + floor(((float)(x2 - w1) * sx) + 0.5);
    int translatedY2 = v2 + floor(((float)(y2 - w2) * sy) + 0.5);
    int translatedX3 = v1 + floor(((float)(x3 - w1) * sx) + 0.5);
    int translatedY3 = v2 + floor(((float)(y3 - w2) * sy) + 0.5);
    
    drawLine(translatedX1, translatedY1, translatedX2, translatedY2);
    drawLine(translatedX2, translatedY2, translatedX3, translatedY3);
}

int main() {
    int w1 = 5, w2 = 5, w3 = 635, w4 = 465;
    int x1, y1, x2, y2, x3, y3, v1 = 425, v2 = 75, v3 = 550, v4 = 250;
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "..//bgi");
    
    printf("Enter the Co-ordinates x1, y1, x2, y2, x3, y3\n");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    
    cleardevice();
    drawRectangle(w1, w2, w3, w4);
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    
    getch();
    
    cleardevice();
    drawRectangle(v1, v2, v3, v4);
    translateAndScale(x1, y1, x2, y2, x3, y3, v1, v2, v3, v4,w1,w2,w3,w4);
    
    getch();
    
    closegraph();
    return 0;
}
/*
Enter the Co-ordinates x1, y1, x2, y2, x3, y3 >> 
100
150
200
100
50
150
*/