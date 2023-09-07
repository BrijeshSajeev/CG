#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <graphics.h>

int computeRegionCode(int, int);
int isLineVisible(int, int, int);
void drawRectangle(int, int, int, int);
void drawDDALine(int, int, int, int);

void main() {
    int gd = DETECT, gm, n, i, m = 0, regionCode1, regionCode2, currentRegion, isVisible, edge, previousVertex;
    int newX[20], newY[20], currentRegionCode, x1, x2, y1, y2, verticesX[20], verticesY[20];
    int windowLeft = 100, windowBottom = 200, windowRight = 400, windowTop = 400, xIntercept, yIntercept;

    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "e:\\tcplus\\bgi");

    printf("\nEnter the number of vertices:");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter polygon co-ordinates:");
        scanf("%d%d", &verticesX[i], &verticesY[i]);
    }
    n++;
    verticesX[n] = verticesX[1];
    verticesY[n] = verticesY[1];

    printf("\nEnter window coordinates:");
    scanf("%d%d%d%d", &windowLeft, &windowBottom, &windowRight, &windowTop);

    cleardevice();
    drawRectangle(windowLeft, windowBottom, windowRight, windowTop);

    moveto(verticesX[1], verticesY[1]);
    for (i = 2; i <= n; i++)
        lineto(verticesX[i], verticesY[i]);

    getch();
    cleardevice();

    do {
        m = 0;
        for (i = 1; i <= n; i++) {
            if ((i == 1) && (currentRegion == 0))
                goto process;
            else {
                regionCode2 = computeRegionCode(verticesX[i], verticesY[i]);
                currentRegionCode = (int)pow((float)2, (float)currentRegion);

                if (((currentRegionCode & regionCode1) || (currentRegionCode & regionCode2)) != 0) {
                    x1 = verticesX[previousVertex];
                    x2 = verticesX[i];
                    y1 = verticesY[previousVertex];
                    y2 = verticesY[i];
                    edge = currentRegion;

                    if (edge == 0) {
                        xIntercept = windowLeft;
                        yIntercept = y2 - (float)(y2 - y1) / (x2 - x1) * (x2 - windowLeft);
                    }
                    if (edge == 1) {
                        xIntercept = windowRight;
                        yIntercept = y2 - (float)(y2 - y1) / (x2 - x1) * (x2 - windowRight);
                    }
                    if (edge == 2) {
                        yIntercept = windowTop;
                        xIntercept = x2 - (float)(x2 - x1) / (y2 - y1) * (y2 - windowTop);
                    }
                    if (edge == 3) {
                        yIntercept = windowBottom;
                        xIntercept = x2 - (float)(x2 - x1) / (y2 - y1) * (y2 - windowBottom);
                    }
                    m++;
                    newX[m] = xIntercept;
                    newY[m] = yIntercept;
                }
            }
        process:
            previousVertex = i;
            regionCode1 = computeRegionCode(verticesX[i], verticesY[i]);
            isVisible = isLineVisible(verticesX[i], verticesY[i], currentRegion);

            if (isVisible == 1) {
                m++;
                newX[m] = verticesX[i];
                newY[m] = verticesY[i];
            }
        }
        currentRegion++;
        n = m;
        for (i = 1; i <= n; i++) {
            verticesX[i] = newX[i];
            verticesY[i] = newY[i];
        }
    } while (currentRegion < 4);

    i = 1;
    moveto(verticesX[i], verticesY[i]);

    for (i = 2; i <= n; i++)
        lineto(verticesX[i], verticesY[i]);

    lineto(verticesX[1], verticesY[1]);
    drawRectangle(windowLeft, windowBottom, windowRight, windowTop);

    getch();
    closegraph();
}

int computeRegionCode(int x, int y) {
    int code = 0;
    if (x < windowLeft) code += 1;
    if (x > windowRight) code += 2;
    if (y < windowBottom) code += 8;
    if (y > windowTop) code += 4;
    return code;
}

int isLineVisible(int x, int y, int region) {
    int computeRegionCode(int, int);
    int code = computeRegionCode(x, y);
    int regionCode = (int)pow((float)2, (float)region);
    if ((code & regionCode) == 0)
        return 1;
    else
        return 0;
}

void drawRectangle(int left, int bottom, int right, int top) {
    drawDDALine(left, bottom, right, bottom);
    drawDDALine(right, bottom, right, top);
    drawDDALine(right, top, left, top);
    drawDDALine(left, top, left, bottom);
}

void drawDDALine(int x1, int y1, int x2, int y2) {
    float x, y, dy, dx, len;
    int i;

    if (abs(y2 - y1) >= abs(x2 - x1))
        len = abs(y2 - y1);
    else
        len = abs(x2 - x1);

    dx = (x2 - x1) / len;
    dy = (y2 - y1) / len;
    x = x1 + 0.5 * dx;
    y = y1 + 0.5 * dy;

    for (i = 1; i <= len; i++) {
        putpixel(x, y, getmaxcolor());
        x += dx;
        y += dy;
    }
}
