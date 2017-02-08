#include<GL/freeglut.h>
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "iostream"
using namespace std;
void dda()
{
	int m=1, x0=0,y0=0, xn=1000,yn=1000;
	glClearColor(0.5,0.5,0.5,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	int no_of_points=xn-x0;
	int y=y0;
	glColor3f(1.0,0.0,0.0);
	for(int i=x0;i<=xn;i++)
	{
		
		glVertex2f(i,y);
		cout<<i<<" "<<y; 
		y=y+m;
	}
	glEnd();
	glFlush();
}
int main(int argc, char** argv)
{
        glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE);
		glutInitWindowSize(1000, 1000);
        glutCreateWindow("Shapes");
        glutInitWindowPosition(0,0);
        
        glutDisplayFunc(dda);
        glutMainLoop();
        return 0;
}
