#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

// Function prototypes
void output(GLfloat x, GLfloat y, char *text);
void display(void);
void idle(void);
void visible(int vis);

/*
light0_ambient, light0_diffuse, light1_diffuse, light1_position, light2_diffuse,
light2_position are arrays representing different properties of lights.
These properties include ambient and diffuse components, 
as well as the position of lights in 3D space.
*/

// Global variables
GLfloat light0_ambient[] = {0.2, 0.2, 0.2, 1.0};
GLfloat light0_diffuse[] = {0.0, 0.0, 0.0, 1.0};
GLfloat light1_diffuse[] = {1.0, 0.0, 0.0, 1.0};
GLfloat light1_position[] = {1.0, 1.0, 1.0, 0.0};
GLfloat light2_diffuse[] = {0.0, 1.0, 0.0, 1.0};
GLfloat light2_position[] = {-1.0, -1.0, 1.0, 0.0};
GLfloat angle1 = 0.0, angle2 = 0.0; //angle1 and angle2 are variables used to control the rotation angles of some objects in the scene. 
float s = 0.0;

int main(int argc, char **argv)
{                                                               
    // Initialize GLUT (Graphics Library Utility Toolkit)
    glutInit(&argc, argv);// It takes command-line arguments (argc and argv) which are typically passed to the program when it is executed
    
    // (GLUT_DOUBLE), which helps prevent flickering in animations.
    // it also specifies that the color mode is RGB (GLUT_RGB),
    // it enables depth buffering (GLUT_DEPTH) which is essential for handling 3D scenes properly.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // This function creates a window with the specified title, in this case, "Blender
    glutCreateWindow("Blender");
    
    // Set callback functions
    glutDisplayFunc(display);
    glutVisibilityFunc(visible);

    // Initialize OpenGL settings   
    glEnable(GL_DEPTH_TEST); 
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(2.0);
    
    // Set up projection and modelview matrices
    glMatrixMode(GL_PROJECTION);
    gluPerspective(40.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0, 0.0, 5.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.6, -1.0);

    // Enable lighting and set light properties
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
    glLightfv(GL_LIGHT2, GL_POSITION, light2_position);

    // Create display list for icosahedron
    glNewList(1, GL_COMPILE);
    glutSolidIcosahedron();
    glEndList();

    glutMainLoop();
    return 0;
}

void output(GLfloat x, GLfloat y, char *text)
{
    char *p;
    glPushMatrix();
    glTranslatef(x, y, 0);
    for (p = text; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}

void display(void)
{
    static GLfloat amb[] = {0.4, 0.4, 0.4, 0.0};
    static GLfloat dif[] = {1.0, 1.0, 1.0, 0.0};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set material properties and draw the first icosahedron
    glEnable(GL_LIGHT1);
    glDisable(GL_LIGHT2);

    amb[3] = dif[3] = cos(s) / 2.0 + 0.5;
    glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);

    glPushMatrix();
    glTranslatef(-0.3, -0.3, 0.0);
    glRotatef(angle1, 1.0, 5.0, 0.0);
    glCallList(1); // Render ico display list
    glPopMatrix();

    glClear(GL_DEPTH_BUFFER_BIT);

    // Set material properties and draw the second icosahedron
    glEnable(GL_LIGHT2);
    glDisable(GL_LIGHT1);

    amb[3] = dif[3] = 0.5 - cos(s * 0.95) / 2.0;
    glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);

    glPushMatrix();
    glTranslatef(0.3, 0.3, 0.0);
    glRotatef(angle2, 1.0, 0.0, 5.0);
    glCallList(1); // Render ico display list
    glPopMatrix();

    // Render 2D text
    glPushAttrib(GL_ENABLE_BIT);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 1500, 0, 1500);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    // Rotate text slightly to help show jaggies
    glRotatef(4, 0.0, 0.0, 1.0);
    output(200, 225, "This is antialiased.");
    glDisable(GL_LINE_SMOOTH);
    glDisable(GL_BLEND);
    output(160, 100, "This text is not.");
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glPopAttrib();
    glMatrixMode(GL_MODELVIEW);

    glutSwapBuffers();
}

void idle(void)
{
    angle1 = fmod(angle1 + 0.8, 360.0);
    angle2 = fmod(angle2 + 1.1, 360.0);
    s += 0.05;
    glutPostRedisplay();
}

void visible(int vis)
{
    if (vis == GLUT_VISIBLE)
        glutIdleFunc(idle);
    else
        glutIdleFunc(NULL);
}