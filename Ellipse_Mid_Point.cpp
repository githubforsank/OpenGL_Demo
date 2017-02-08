#include <gl/freeglut.h>
#include <Windows.h>
#include <iostream>
#include <math.h>
#define PI 3.14
using namespace std;
/*

*/
void ellipse()
{
		cout<<"Enter Center coordinates of the ellipse \n";
        float xc=0, yc=0;
		cin>>xc>>yc;
		cout<<"enter x radius and y radius respectively \n";
		float rx=140, ry=100;
		cin>>rx>>ry;
		cout<<"Drawing the ellipse at center ("<<xc<<","<<yc<<") and x radius: "<<rx<<" and y radius: "<<ry<<endl;
        float rxSq = rx * rx;
        float rySq = ry * ry;
        float x = 0, y = ry, p;
        float px = 0, py = 2 * rxSq * y;
        glClear(GL_COLOR_BUFFER_BIT);
		glColor3f( 1 ,0, 0);
        glBegin(GL_POINTS);

         
          glVertex2d(xc+x,yc-y);
          glVertex2d(xc-x,yc-y);
          glVertex2d(xc-x,yc+y);
         glEnd();

        p = rySq - (rxSq * ry) + (0.25 * rxSq);
        while (px < py)
        {
                        x++;
                        px = px + 2 * rySq;
                        if (p < 0)
                        p = p + rySq + px;
                        else
                        {
                        y--;
                        py = py - 2 * rxSq;
                        p = p + rySq + px - py;
                        }
                         glBegin(GL_POINTS);

                          glVertex2d(xc+x,yc+y);
                          glVertex2d(xc+x,yc-y);
                          glVertex2d(xc-x,yc-y);
                          glVertex2d(xc-x,yc+y);
                         glEnd();

        }

        p = rySq*(x+0.5)*(x+0.5) + rxSq*(y-1)*(y-1) - rxSq*rySq;
        while (y > 0)
        {
                y--;
                py = py - 2 * rxSq;
                if (p > 0)
                p = p + rxSq - py;
                else
                {
                x++;
                px = px + 2 * rySq;
                p = p + rxSq - py + px;
                }
               glBegin(GL_POINTS);

          glVertex2d(xc+x,yc+y);
          glVertex2d(xc+x,yc-y);
          glVertex2d(xc-x,yc-y);
          glVertex2d(xc-x,yc+y);
        
              
        }
        }

void call_back()
 {
	ellipse();
	glEnd();
	glFlush();
 }
int main(int argc, char ** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Line Draw OpenGL");
 
 glClearColor(1.0, 1.0, 1.0, 1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 gluOrtho2D(-250, 250, -250, 250);
 //glMatrixMode(GL_PROJECTION);
 glViewport(0, 0, 500, 500);
 
 glutDisplayFunc(call_back);
 glutMainLoop();
 return 0;
}
