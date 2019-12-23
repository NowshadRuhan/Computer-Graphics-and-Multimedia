#include<bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
using namespace std;


double x1, x2, y11, y22, dx ,dy ,ds, dt, X , Y, d;
void algo()
{
    dx = abs(x2 - x1);
    dy = abs(y22 - y11);

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0 ,1);


    if(dy< dx){

        ds = (2 * dy);
        dt = ((2* dy) - (2 * dx));

        if(x1 > x2)
        {
            swap(x1, x2);
            swap(y11, y22);
        }
        d = (2 * dy -dx);
        X = x1, Y = y11;
        glBegin(GL_POINTS);
        glVertex2d (x1, y11);
        while(X < x2){

            X++;
            if(d>=0){
                d = d + dt;
                if(y11>y22){
                    Y--;
                }else{
                    Y++;
                }

            }else{
                d = d + ds;
            }
            glVertex2d (X, Y);
        }

    }
    else{

        ds = (2 * dx);
        dt = ((2* dx) - (2 * dy));

        if(y11 > y22)
        {
            swap(x1, x2);
            swap(y11, y22);
        }
        d = (2 * dx -dy);
        X = x1, Y = y11;
        glBegin(GL_POINTS);
        glVertex2d (x1, y11);
        while(Y < y22){

            Y++;
            if(d>=0){
                d = d + dt;
                if(x1>x2){
                    X--;
                }else{
                    X++;
                }
            }else{
                d = d + ds;
            }
            glVertex2d (X, Y);
        }

    }
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
   cin>>x2>>y22;

   glutInitWindowSize(400, 400);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Hello OpenGL");
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glOrtho(-400, 400, -400,400, -9,9);
   glutDisplayFunc(algo);
   glutMainLoop();
   return 0;
}


//10 100 100 10
//10 10 100 100
