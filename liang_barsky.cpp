#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <windows.h>
#include <GL/glut.h>
using namespace std;


double v1,v2 ,n, Xmin , Xmax,  Ymin, Ymax;

double a_x1[100], a_y1[100], a_x2[100], a_y2[100];

double ans_x1[100], ans_y1[100], ans_x2[100], ans_y2[100];

double U1=1000,U2=0;

void liang_barsky(double x11,double y11,double x22,double y22)
{
    double p1, p2, p3, p4, q1, q2, q3, q4, r1, r2, r3, r4, del_x , del_y;
    vector<double>u1;
    vector<double>u2;

    //cout<<"hello"<<endl;


    u1.push_back(0);
    u2.push_back(1);

    del_x = (x22 - x11);
    del_y = (y22 - y11);
    p1 = (-1*del_x);
    p2 = del_x;
    p3 = (-1*del_y);
    p4 = del_y;

    q1 = (x11 - Xmin);
    q2 = (Xmax - x11);
    q3 = (y11 - Ymin);
    q4 = (Ymax - y11);

    if((p1!=0 || q1>0) && (p2!=0 || q2>0) && (p3!=0 || q3>0) && (p4!=0 || q4>0)){

        if(p1 > 0 || p1<0){
            r1 = (q1/p1);
            //cout<<r1<<endl;
            if(p1<0){
                u1.push_back(r1);
            }else{
                u2.push_back(r1);
            }
        }



        if(p2 > 0 || p2<0){
            r2 = (q2/p2);
            //cout<<r2<<endl;
            if(p2<0){
                u1.push_back(r2);
            }else{
                u2.push_back(r2);
            }
        }



        if(p3 > 0 || p3<0){
            r3 = (q3/p3);
            //cout<<r3<<endl;
            if(p3<0){
                u1.push_back(r3);
            }else{
                u2.push_back(r3);
            }
        }



        if(p4 > 0 || p4<0){
            r4 = (q4/p4);
            //cout<<r4<<endl;
            if(p4<0){
                u1.push_back(r4);
            }else{
                u2.push_back(r4);
            }
        }

        U1 = *max_element(u1.begin(), u1.end());
        U2 = *min_element(u2.begin(), u2.end());

        cout<<U1<<endl;
        cout<<U2<<endl;
    }


}



void algo(){

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1 ,1);
    glBegin(GL_LINES);
    glVertex2d (0, 800);
    glVertex2d (0, -800);
    glVertex2d (800, 0);
    glVertex2d (-800, 0);
    glEnd();

    glColor3f(1, 0 ,1);
    glBegin(GL_LINE_LOOP);
    glVertex2d (Xmin, Ymax);
    glVertex2d (Xmin, Ymin);
    glVertex2d (Xmax, Ymin);
    glVertex2d (Xmax, Ymax);
    glEnd();

    glColor3f(1, 0 ,0);
    glBegin(GL_LINES);
    for(int i =0; i<n; i++)
    {
        glVertex2d(a_x1[i], a_y1[i]);
        glVertex2d(a_x2[i], a_y2[i]);

    }
    glEnd();


    glColor3f(0, 1 ,0);
    glBegin(GL_LINES);
    for(int i =0; i<n; i++)
    {
        glVertex2d(ans_x1[i], ans_y1[i]);
        glVertex2d(ans_x2[i], ans_y2[i]);

    }
    glEnd();

    glEnd();
    glFlush();
}
void inputfuntion()
{
   cout<<"Please Enter View Window :"<<endl;
   cin>>Xmin>>Ymin>>Xmax>>Ymax;

   cout<<"Please Enter How many line :"<<endl;
   cin>>n;
   for(int i=0; i<n; i++){

        double x11, x22, y11, y22;
        cout<<"Please enter line start point then end point :"<<endl;

        cin>>x11>>y11>>x22>>y22;
        liang_barsky( x11, y11, x22, y22);

        a_x1[i]= x11;
        a_y1[i]= y11;

        a_x2[i]= x22;
        a_y2[i]= y22;

        if(U1<=U2){
            double del_x1 = (x22 - x11);
            double del_y1 = (y22 - y11);

            double X1 = (x11 + (del_x1*U1));
            double Y1 = (y11 + (del_y1*U1));

            double X2 = (x11 + (del_x1*U2));
            double Y2 = (y11 + (del_y1*U2));


            ans_x1[i] = X1;
            ans_y1[i] = Y1;

            ans_x2[i] = X2;
            ans_y2[i] = Y2;



            cout<<"Line Point 1st : ( "<<ans_x1[i]<<" , "<<ans_y1[i]<<" ) "<<endl;
            cout<<"Line Point 2nd : ( "<<ans_x2[i]<<" , "<<ans_y2[i]<<" ) "<<endl;
        }

   }

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    inputfuntion();
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(" Liang Barsky Algorithm ");
    glClearColor(1, 1, 1 , 1);
    glOrtho(-800, 800, -800,800, -9,9);
    glutDisplayFunc(algo);
    glutMainLoop();
    return 0;

}


/*
20 20 200 200
2
10 10 150 250
30 30 150 150
*/



