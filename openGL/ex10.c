#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

int colorToggle = 0;  // Renamed 'c' to 'colorToggle' for clarity

void init() {
    glClearColor(0, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0, 600);
}

void drawSquare(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4) {
    if (colorToggle == 0) {
        glColor3f(1, 1, 1);
        colorToggle = 1;
    }
    else {
        glColor3f(0, 0, 0);
        colorToggle = 0;
    }

    glBegin(GL_POLYGON);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x4, y4);
    glEnd();
}

void drawChessboard() {  // Renamed 'chessboard' to 'drawChessboard' for clarity
    glClear(GL_COLOR_BUFFER_BIT);
    GLint x,y;
    for ( x = 0; x <= 800; x += 100) {
        for ( y = 0; y <= 600; y += 75) {
            drawSquare(x, y + 75, x + 100, y + 75, x + 100, y, x, y);
        }
    }

    glFlush();
}

int main(int argc, char** argv) {  // Made small adjustments to main function signature
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Chess Board using OpenGL in C++");
    init();
    glutDisplayFunc(drawChessboard);  // Changed function name to match
    glutMainLoop();
    return 0;
}
