#include <GL/freeglut.h>
#include <Windows.h>
#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14159
int calculate_pixels(float x1,float y1,float x2,float y2,float x3,float y3)
{
		float sum1,sum2,sum3;
		//Line 1
		//Between x1 y1 and x2 y2
		if(abs(x1-x2)>abs(y1-y2))
		{
			sum1=abs(x1-x2)+1;
		}
		else
			sum1=abs(y1-y2)+1;
		//For line 2
			if(abs(x2-x3)>abs(y2-y3))
		{
			sum2=abs(x2-x3)+1;
		}
		else
			sum2=abs(y2-y3)+1;
		//For line 3
				if(abs(x3-x1)>abs(y3-y1))
		{
			sum3=abs(x3-x1)+1;
		}
		else
			sum3=abs(y1-y2)+1;
				return sum1+sum2+sum3;

}
void display_triangle()
{
		glClearColor(1.0f,1.0f,1.00f,0.0f);
		//Set background alpha and color to black
		glClear(GL_COLOR_BUFFER_BIT);
		 gluOrtho2D(-50,50,-50, 50);
		//clear the color buffer
		glLineWidth(1.5); 
		
		float x1,y1,x2,y2,x3,y3;
		float x10,y10,x20,y20,x30,y30;
		cout<<"Enter three points of traingle";
		cin>>x10>>y10>>x20>>y20>>x30>>y30;
		cout<<"\n Enter the angle of rotation in degrees.";
		float angle=0;
		cin>>angle;
		angle=-angle;
		angle=PI/180*angle; //angle in radian
		cout<<"Enter the no of triangles to be drawn";
		int n;
		cin>>n;
		int no=n;
		float theta=0;
		//float 0.0;
		float step=0.3;
		cout<<"Enter choice of rotation \n";
		int a;
		cin>>a;
		while(n>0)
		{
			switch(a)
			{
			case 1:
				x1=x10;
				y1=y10;
				x2=(x20-x10)*cos(theta)-(y20-y10)*sin(theta)+x10;
				y2=(x20-x10)*sin(theta)+(y20-y10)*cos(theta)+y10;
				x3=(x30-x10)*cos(theta)-(y30-y10)*sin(theta)+x10;
				y3=(x30-x10)*sin(theta)+(y30-y10)*cos(theta)+y10;
				
				break;
			case 2:
				x1=(x10-x20)*cos(theta)-(y10-y20)*sin(theta)+x20;
				y1=(y10-y20)*cos(theta)+(x10-x20)*sin(theta)+y20;
				x2=x20;
				y2=y20;
				x3=(x30-x20)*cos(theta)-(y30-y20)*sin(theta)+x20;
				y3=(x30-x20)*sin(theta)+(y30-y20)*cos(theta)+y20;
				break;
			case 3:
				x1=(x10-x30)*cos(theta)-(y10-y30)*sin(theta)+x30;
				y1=(y10-y30)*cos(theta)+(x10-x30)*sin(theta)+y30;
				x2=(x20-x30)*cos(theta)-(y20-y30)*sin(theta)+x30;
				y2=(x20-x30)*sin(theta)+(y20-y30)*cos(theta)+y30;
				x3=x30;
				y3=y30;
				break;
			default:
				cout<<"Enter proper choice exiting program .....";
				exit(0);
			}
			
		
			cout<<"========================= Triangle No "<<no-(n-1)<<" Information ==========================\n";
			cout<<theta<<" ";
			cout<<'('<<x1<<","<<y1<<")";
			cout<<"("<<x2<<","<<y2<<")";
			cout<<"("<<x3<<","<<y3<<")"<<endl;
			cout<<"Pixel value of triangle "<<calculate_pixels(x1,y1,x2,y2,x3,y3)<<endl;
			cout<<"===========================================================================================\n";
			glColor3f(0,0,0);
			glBegin(GL_LINES);
			
				
					glVertex2f(x1,y1);
					glVertex2f(x2,y2);
					glVertex2f(x2,y2);
					glVertex2f(x3,y3);
					glVertex2f(x3,y3);
					glVertex2f(x1,y1);

					
			glEnd();
			step+=step;
			theta=theta+angle;
		
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