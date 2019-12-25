#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include <GL/glut.h>
using namespace std;


double x1, n, y11, r, X,Y;
void algo()
{


    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0 ,1);
    glBegin(GL_POINTS);

    glVertex2d (x1, y11);
    n=0;
    double d=0.05;
    while( n<=(r/4))
    {
         Y = (r*(sin(n)));
         X = (r*(cos(n)));


        glVertex2d (X+x1, Y+y11);
        glVertex2d ((-X+x1), Y+y11);
        glVertex2d (X+x1, (-Y+y11));
        glVertex2d ((-X+x1),(-Y+y11));
        glVertex2d (Y+y11, X+x1);
        glVertex2d ((-Y+y11), X+x1);
        glVertex2d ((Y+y11), (-X+x1));
        glVertex2d ((-Y+y11), (-X+x1));

        n=(n+d);
    }

    glEnd();
    glColor3f(0, 0 ,1);
    glBegin(GL_LINES);
    glVertex2d (0, 200);
    glVertex2d (0, -200);
    glVertex2d (200, 0);
    glVertex2d (-200, 0);
    glEnd();
    glFlush();

}




void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glFlush();
}
int main(int argc, char** argv) {
   glutInit(&argc, argv);

   cin>>x1>>y11;
   cin>>r;

   glutInitWindowSize(400, 400);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Hello OpenGL");
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glOrtho(-200, 200, -200,200, -9,9);
   glutDisplayFunc(algo);
   glutMainLoop();
   return 0;
}


//20 20 50


