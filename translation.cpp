#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include <GL/glut.h>
using namespace std;


int v1,v2 ;

int arr_x[100], arr_y[100];
int m;
void translation()
{
    cout<<"Please input all point"<<endl;

    for(int i =0; i<m; i++)
    {
        cin>>arr_x[i]>>arr_y[i];
    }

    cout<<"Please input Vactor"<<endl;

    cin>>v1>>v2;


    for(int i =0; i<m; i++)
    {
        arr_x[i] = arr_x[i]+v1;
        arr_y[i] = arr_y[i]+v2;
    }

}


void algo(){

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0 ,1);
    glBegin(GL_LINES);
    glVertex2d (0, 0);
    glVertex2d (0, 200);
    glVertex2d (0, 0);
    glVertex2d (0, -200);
    glVertex2d (0, 0);
    glVertex2d (200, 0);
    glVertex2d (0, 0);
    glVertex2d (-200, 0);
    glEnd();

    glColor3f(1, 0 ,1);
    glBegin(GL_POLYGON);

    for(int i =0; i<m; i++)
    {
        glVertex2d (arr_x[i], arr_y[i]);
    }


    glEnd();
    glFlush();
}
int main(int argc, char** argv) {
   glutInit(&argc, argv);

   cout<<"Please Choice Algorithm :"<<endl;
   cout<<"If 1 its Translation"<<endl;
   cout<<"If 2 its Rotation"<<endl;
   cout<<"If 3 its Scaling"<<endl;
   cout<<"If 4 its Mirror"<<endl;

    int n;

    cin>>n;
    if(n == 1){
        cout<<"Enter How many Point you want :"<<endl;
        cin>>m;
        translation();
    }else if( n == 2){

    }
    else if( n == 3){

    }
    else if( n == 4){

    }

   glutInitWindowSize(400, 400);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Hello OpenGL");
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glOrtho(-200, 200, -200,200, -9,9);
   glutDisplayFunc(algo);
   glutMainLoop();
   return 0;
}


//1
//4
//10 10
//100 10
//100 100
//10 100
//2 2




