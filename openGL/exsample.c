#include <GL/glut.h>
GLfloat angleX = 0;
GLfloat angleY = 0;


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -5);
    glRotatef(angleX, 1, 0, 0);
    glRotatef(angleY, 0, 1, 0);

    glBegin(GL_QUADS);
        // Front face
        glColor3f(1, 0, 0);  // Red
        glVertex3f(-1, -1, 1);
        glVertex3f( 1, -1, 1);
        glVertex3f( 1,  1, 1);
        glVertex3f(-1,  1, 1);

        // Back face
        glColor3f(0, 1, 0);  // Green
        glVertex3f(-1, -1, -1);
        glVertex3f( 1, -1, -1);
        glVertex3f( 1,  1, -1);
        glVertex3f(-1,  1, -1);

        // Top face
        // glColor3f(0, 0, 1);  // Blue
        // glVertex3f(-1, 1, -1);
        // glVertex3f( 1, 1, -1);
        // glVertex3f( 1, 1, 1);
        // glVertex3f(-1, 1, 1);

        // Bottom face
        // glColor3f(1, 1, 0);  // Yellow
        // glVertex3f(-1, -1, -1);
        // glVertex3f( 1, -1, -1);
        // glVertex3f( 1, -1, 1);
        // glVertex3f(-1, -1, 1);

        // Right face
        glColor3f(1, 0, 1);  // Magenta
        glVertex3f(1, -1, -1);
        glVertex3f(1,  1, -1);
        glVertex3f(1,  1, 1);
        glVertex3f(1, -1, 1);

        // Left face
        glColor3f(0, 1, 1);  // Cyan
        glVertex3f(-1, -1, -1);
        glVertex3f(-1,  1, -1);
        glVertex3f(-1,  1, 1);
        glVertex3f(-1, -1, 1);
    glEnd();

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            angleX += 5;
            break;
        case GLUT_KEY_DOWN:
            angleX -= 5;
            break;
        case GLUT_KEY_LEFT:
            angleY += 5;
            break;
        case GLUT_KEY_RIGHT:
            angleY -= 5;
            break;
    }

    glutPostRedisplay();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 1.5, 20);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL 3D Cube");

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    init();

    glutMainLoop();
    return 0;
}
