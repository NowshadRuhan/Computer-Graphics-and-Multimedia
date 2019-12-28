#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include <GL/glut.h>
using namespace std;


double v1,v2 ,Z, X , Y;

double arr_x[100], arr_y[100];

double ans_x[100], ans_y[100];
int m;
double pi = 3.14159265;

void translation()
{
    cout<<"Welcome to Translation :"<<endl;
    cout<<"Please input all point"<<endl;

    for(int i =0; i<m; i++)
    {
        cin>>arr_x[i]>>arr_y[i];
    }

    cout<<"Please input Vactor"<<endl;

    cin>>v1>>v2;


    for(int i =0; i<m; i++)
    {
        ans_x[i] = arr_x[i]+v1;
        ans_y[i] = arr_y[i]+v2;
    }

}

void rotation(){

    cout<<"Welcome to Rotation :"<<endl;
    cout<<"Please input all point"<<endl;

    for(int i =0; i<m; i++)
    {
        cin>>arr_x[i]>>arr_y[i];
    }

    cout<<"Please input Rotation Value :"<<endl;

    cin>>Z;

    Z = ((Z*pi)/180);

    for(int i =0; i<m; i++)
    {
        X = arr_x[i];
        Y = arr_y[i];
        ans_x[i] = ((X*(cos(Z))) - ((Y)*(sin(Z))));

        ans_y[i] = ((X*(sin(Z))) + ((Y)*(cos(Z))));
    }

}

void scaling()
{
    cout<<"Welcome to Scaling :"<<endl;
    cout<<"Please input all point"<<endl;

    for(int i =0; i<m; i++)
    {
        cin>>arr_x[i]>>arr_y[i];
    }

    cout<<"Please Input Scaling Value :"<<endl;
    cin>>v1>>v2;

    for(int i =0; i<m; i++)
    {
        ans_x[i] = (arr_x[i]*v1);
        ans_y[i] = (arr_y[i]*v2);
    }
}
void mirror(){

    cout<<"Welcome to Mirror :"<<endl;
    cout<<"Please input all point"<<endl;

    for(int i =0; i<m; i++)
    {
        cin>>arr_x[i]>>arr_y[i];
    }

    cout<<"Please Enter 1 for Respect to X-axis Or 2 for Respect to Y-axis :"<<endl;
    cin>>v1;

    if(v1 == 1){
        for(int i =0; i<m; i++)
        {
            ans_x[i] = (arr_x[i]);
            ans_y[i] = (-1*arr_y[i]);
        }
    }else if(v1 == 2){
        for(int i =0; i<m; i++)
        {
            ans_x[i] = (-1*arr_x[i]);
            ans_y[i] = (arr_y[i]);

        }
    }

}

void algo(){

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0 ,1);
    glBegin(GL_LINES);
    glVertex2d (0, 200);
    glVertex2d (0, -200);
    glVertex2d (200, 0);
    glVertex2d (-200, 0);
    glEnd();

    glColor3f(1, 0 ,1);
    glBegin(GL_LINE_LOOP);

    for(int i =0; i<m; i++)
    {
        glVertex2d (arr_x[i], arr_y[i]);
    }


    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0 ,1);
    for(int i =0; i<m; i++)
    {
        glVertex2d (ans_x[i], ans_y[i]);
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
        cout<<"Enter How many Point you want :"<<endl;
        cin>>m;
        rotation();
    }
    else if( n == 3){
        cout<<"Enter How many Point you want :"<<endl;
        cin>>m;
        scaling();
    }
    else if( n == 4){
        cout<<"Enter How many Point you want :"<<endl;
        cin>>m;
        mirror();
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


//20 20 50



