#include <windows.h>
#include <GL/glut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glPointSize(9);
   glColor3f(1,1,1);
   glBegin(GL_POINTS);
   glVertex2d(0,0);
   glVertex2d(0,0.1);
   glVertex2d(0,0.2);
   glVertex2d(0,0.3);
   glVertex2d(0,0.4);
   glVertex2d(0,0.5);
   glVertex2d(0,0.6);
   glVertex2d(0,0.7);
   glVertex2d(0,0.8);
   glVertex2d(0,0.9);
   glEnd();

   glFlush();
}

void Init()
{
    //glOrtho(-2, 2, -2,2, -2,2);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(400, 400);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Hello OpenGL Nowshad");
   glClearColor(0.0f, 0.3f, 0.2f, 1.0f);
   glOrtho(-2,2,-2,2,-2,2);
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}

