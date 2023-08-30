#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int x, y, az, w, xa, ya, ra, a[10], b[10], width, height;
float shiftx, shifty, theta, scalex, scaley, xshear, yshear, a1[10], b1[10];

// (x, y) as the upper-left corner and (az, w) as the lower-right corner.
// The arrays a and b seem to store the coordinates of the four corners of the rectangle.

void drawRectangle() {
    rectangle(x, y, az, w);
}

void translate() {
    x += shiftx;
    y += shifty;
    az += shiftx;
    w += shifty;
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
    x *= scalex;
    y *= scaley;
    az *= scalex;
    w *= scaley;
    drawRectangle();
}

void reflectXAxis() {
    printf("Enter the fixed point\n"); 
    scanf("%d%d",&xa,&ya); 
    theta=(float)(90*(3.14/180)); 
    for(i=0;i<4;i++)
    {
        a1[i]=(xa+((a[i]-xa)*cos(theta)-(-b[i]-ya)*sin(theta)));
        b1[i]=(ya+((a[i]-xa)*sin(theta)+(-b[i]-ya)*cos(theta)));
    }
    for(i=0;i<4;i++)
    {
        if(i!=3) 
          line(a1[i],b1[i],a1[i+1],b1[i+1]); 
        else 
            line(a1[i],b1[i],a1[0],b1[0]);
    }
}

void reflectYAxis() {
    printf("Enter the fixed point\n"); 
    scanf("%d%d",&xa,&ya); 
    theta=(float)(270*(3.14/180)); 
    for(i=0;i<4;i++)
    {
        a1[i]=(xa+((-a[i]-xa)*cos(theta)-(b[i]-ya)*sin(theta)));
        b1[i]=(ya+((-a[i]-xa)*sin(theta)+(b[i]-ya)*cos(theta)));
    }
    for(i=0;i<4;i++)
    {
        if(i!=3) 
            line(a1[i],b1[i],a1[i+1],b1[i+1]); 
        else 
            line(a1[i],b1[i],a1[0],b1[0]);
    }
}

void reflectBothAxis() {
    printf("Enter the fixed point\n"); 
    scanf("%d%d",&xa,&ya); 
    theta=(float)(180*(3.14/180)); 
    for(i=0;i<4;i++)
    {
        a1[i]=(xa+((-a[i]-xa)*cos(theta)-(-b[i]-ya)*sin(theta)));
        b1[i]=(ya+((-a[i]-xa)*sin(theta)+(-b[i]-ya)*cos(theta)));
    }
    for(i=0;i<4;i++)
    {
        if(i!=3) 
            line(a1[i],b1[i],a1[i+1],b1[i+1]); 
        else 
            line(a1[i],b1[i],a1[0],b1[0]);
    }
}

void shearXDirection() {
    x += y * xshear;
    y = y;
    az += w * xshear;
    w = w;
    drawRectangle();
}

void shearYDirection() {
    x = x;
    y += x * yshear;
    az = az;
    w += az * yshear;
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
    width = az - x; //width
    height = w - y; //height
    a[0] = x;
    b[0] = y;
    a[1] = x + width;
    b[1] = y;
    a[2] = x + width;
    b[2] = y + height;
    a[3] = x;
    b[3] = y + height;

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
                scanf("%f%f", &shiftx, &shifty);
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
                scanf("%f%f", &scalex, &scaley);
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
                        scanf("%f", &xshear);
                        shearXDirection();
                        break;

                    case 2:
                        printf("Enter the value of shear:\n");
                        scanf("%f", &yshear);
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
