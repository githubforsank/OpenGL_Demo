#include <GL/freeglut.h>
#include <Windows.h>
#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14
void display_triangle()
{
		glClearColor(1.0f,1.0f,1.00f,0.0f);
		//Set background alpha and color to black
		glClear(GL_COLOR_BUFFER_BIT);
		 gluOrtho2D(-50,50,-50, 50);
		//clear the color buffer
		glLineWidth(1.5); 
		
		float x1=0,y1=0,x2=20,y2=0,x3=20,y3=20;
		float x10=0,y10=0,x20=20,y20=0,x30=20,y30=20;
		cout<<"Enter the no of triangles to be drawn";
		int n;
		cin>>n;
		float theta=0;
		while(n>0)
		{
			x1=x10*cos(theta)-y10*sin(theta);
			y1=x10*sin(theta)+y10*cos(theta);
			x2=x20*cos(theta)-y20*sin(theta);
			y2=x20*sin(theta)+y20*cos(theta);
			x3=x30*cos(theta)-y30*sin(theta);
			y3=x30*sin(theta)+y30*cos(theta);
			cout<<theta<<" ";
			cout<<x1<<","<<y1<<" ";
			cout<<x2<<","<<y2<<" ";
			cout<<x3<<","<<y3<<endl;
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0f,0.0f,0.0f);
			glVertex2f(x1,y1);
			glVertex2f(x2,y2);
			glVertex2f(x3,y3);
			glEnd();
			theta=theta+PI/9;
			n--;
		}
		glFlush();//Render the thing
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);//Initialize glut
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Triangle");
	
	
	glutDisplayFunc(display_triangle);//Register display call bach handler for window
	glutMainLoop();
	return 0;
}