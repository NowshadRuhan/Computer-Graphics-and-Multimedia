#include <windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
double X11,X22,Y11,Y22,X,Y,m,b;

void display()
{
    m = (Y22-Y11)/(X22-X11);
    //printf("%lf\n",m);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    if(fabs(m)<1){
        if(X11>X22){
            swap(X11,X22);
            swap(Y11,Y22);
        }
        glVertex2d(X11,Y11);
        X=X11;
        Y=Y11;
        while(X<X22){
            X++;
            Y= Y+m;
            glVertex2d(X,round(Y));
            printf("%lf  %lf\n",X,Y);
        }
    }
    else{
        if(Y11>Y22){
            swap(X11,X22);
            swap(Y11,Y22);
        }
        glVertex2d(X11,Y11);
        X=X11;
        Y=Y11;
        m= 1/m;
        while(Y<Y22){
            Y++;
            X= X+m;
            glVertex2d(round(X),Y);
            printf("%lf  %lf\n",X,Y);
        }
    }
    glEnd();
    glColor3f(1,1,0);
    glBegin(GL_LINES);
    glVertex2d(0,200);
    glVertex2d(0,-200);
    glVertex2d(-200,0);
    glVertex2d(200,0);
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    cin >> X11 >> Y11 >> X22 >> Y22;
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Hello OpenGL");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-200,200,-200,200,-9,9);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
// 10 22 135 140

