#include<GL/freeglut.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
float round(float x) 
{
        return int(x+0.5);
}
int xa,xb,ya,yb,pk,p0;


void display (void) {
        int temp;


        if(ya>yb)
        {
                temp=ya;
                ya=yb;
                yb=temp;

                temp=xa;
                xa=xb;
                xb=temp;


        }
int dx=xb-xa,dy=yb-ya,steps,k;
 glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);

        p0=2*dy-dx;
        pk=p0;

   glBegin(GL_POINTS);
        glVertex2s(xa,ya);
         for(k=0;k<dx;k++)
         {
			  xa=xa+1;
        if(pk<0)
                {
                 pk=pk+2*dy;
                 cout<<xa<<" "<<ya<<endl;
                 glVertex2s(xa,ya);
        }
        else
                {   ya=ya+1;
                        pk=pk+2*dy-2*dx;
                          cout<<xa<<" "<<ya<<endl;
             glVertex2s(xa,ya);
        }
        
         }
    
     glEnd();
    glFlush();
}
void init(void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
   glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

int main(int argc, char** argv){
    printf("Enter two end points of a line\n");
    scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Bresenham");
    init ();
    glutDisplayFunc(display);        
    glutMainLoop();
    return 0;
}
