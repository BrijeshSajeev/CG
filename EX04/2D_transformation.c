#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int x, y, az, w, xa, ya, ra, a[10], b[10], da, db;
float dx, dy, theta, sx, sy, x1s, y1s, a1[10], b1[10];

void drawRectangle() {
    rectangle(x, y, az, w);
}

void translate() {
    x += dx;
    y += dy;
    az += dx;
    w += dy;
    drawRectangle();
}

void rotate() {
    theta = ra * (3.14 / 180);
    for (int i = 0; i < 4; i++) {
        a1[i] = xa + ((a[i] - xa) * cos(theta) - (b[i] - ya) * sin(theta));
        b1[i] = ya + ((a[i] - xa) * sin(theta) + (b[i] - ya) * cos(theta));
    }
    for (int i = 0; i < 4; i++) {
        if (i != 3)
            line(a1[i], b1[i], a1[i + 1], b1[i + 1]);
        else
            line(a1[i], b1[i], a1[0], b1[0]);
    }
}

void scale() {
    x *= sx;
    y *= sy;
    az *= sx;
    w *= sy;
    drawRectangle();
}

void reflectXAxis() {
    for (int i = 0; i < 4; i++) {
        a1[i] = a[i];
        b1[i] = -b[i];
    }
    drawRectangle();
}

void reflectYAxis() {
    for (int i = 0; i < 4; i++) {
        a1[i] = -a[i];
        b1[i] = b[i];
    }
    drawRectangle();
}

void reflectBothAxis() {
    for (int i = 0; i < 4; i++) {
        a1[i] = -a[i];
        b1[i] = -b[i];
    }
    drawRectangle();
}

void shearXDirection() {
    x += y * x1s;
    y = y;
    az += w * x1s;
    w = w;
    drawRectangle();
}

void shearYDirection() {
    x = x;
    y += x * y1s;
    az = az;
    w += az * y1s;
    drawRectangle();
}

int main() {
    int gm, gr, ch, ch1, ch2;

    clrscr();
    detectgraph(&gm, &gr);
    initgraph(&gm, &gr, "d:\\tc\\BGI");

    printf("Enter the upper left corner of the rectangle:\n");
    scanf("%d%d", &x, &y);
    printf("Enter the lower right corner of the rectangle:\n");
    scanf("%d%d", &az, &w);

    rectangle(x, y, az, w);
    da = az - x;
    db = w - y;
    a[0] = x;
    b[0] = y;
    a[1] = x + da;
    b[1] = y;
    a[2] = x + da;
    b[2] = y + db;
    a[3] = x;
    b[3] = y;

    while (1) {
        printf("******2D Transformations*******\n");
        printf("1. Translation\n2. Rotation\n3. Scaling\n4. Reflection\n5. Shearing\n6. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, "d:\\tc\\BGI");
                drawRectangle();
                printf("*******Translation*******\n\n");
                printf("Enter the value of shift vector:\n");
                scanf("%f%f", &dx, &dy);
                translate();
                break;

            case 2:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, "d:\\tc\\BGI");
                drawRectangle();
                printf("*******Rotation*******\n\n");
                printf("Enter the value of fixed point and angle of rotation:\n");
                scanf("%d%d%d", &xa, &ya, &ra);
                rotate();
                break;

            case 3:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, "d:\\tc\\BGI");
                drawRectangle();
                printf("*******Scaling*******\n\n");
                printf("Enter the value of scaling factor:\n");
                scanf("%f%f", &sx, &sy);
                scale();
                break;

            case 4:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, "d:\\tc\\BGI");
                drawRectangle();
                printf("*******Reflection*********\n");
                printf("1. About x-axis\n2. About y-axis\n3. About both axes\nEnter your choice:\n");
                scanf("%d", &ch1);

                switch (ch1) {
                    case 1:
                        reflectXAxis();
                        break;

                    case 2:
                        reflectYAxis();
                        break;

                    case 3:
                        reflectBothAxis();
                        break;
                }
                break;

            case 5:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, "d:\\tc\\BGI");
                drawRectangle();
                printf("*******Shearing******\n\n");
                printf("1. x-direction shear\n2. y-direction shear\nEnter your choice:\n");
                scanf("%d", &ch2);

                switch (ch2) {
                    case 1:
                        printf("Enter the value of shear:\n");
                        scanf("%f", &x1s);
                        shearXDirection();
                        break;

                    case 2:
                        printf("Enter the value of shear:\n");
                        scanf("%f", &y1s);
                        shearYDirection();
                        break;
                }
                break;

            case 6:
                exit(0);
        }
    }

    getch();
    closegraph();
    return 0;
}
