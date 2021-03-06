#include <windows.h>
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(9);
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex2d(0,0);
    glColor3f(1,0,1);
    glVertex2d(0,5);
    glColor3f(0.1,1,1);
    glVertex2d(5,5);
    glEnd();

    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex2d(1,-2);
    glColor3f(1,0,1);
    glVertex2d(9,-11);
    glColor3f(0.1,1,1);
    glVertex2d(-11,-11);


    glEnd();

    glFlush();
}

void Init()
{
    //glOrtho(-2, 2, -2,2, -2,2);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello OpenGL Nowshad");
    glClearColor(0.0f, 0.3f, 0.2f, 1.0f);
    glOrtho(-20,20,-20,20,-20,20);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}




