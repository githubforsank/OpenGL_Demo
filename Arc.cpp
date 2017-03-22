#include <iostream>
#include <math.h>
#include <GL/freeglut.h>
#define PI 3.14
using namespace std;
/*

*/
int return_quad(float alpha)
{
	return alpha/45;
}
void draw(float alpha,float beta);
void circle() {
	float alpha=0;
	float beta=0;
	cout<<"Enter alpha";
	cout<<"Enter Beta in degrees";
	cin>>alpha>>beta;
	//alpha= PI/180*alpha;
	//beta=PI/180*beta;
	
	cout<<"alpha in radians : "<<alpha;
	cout<<"Beta in radians : "<<beta;
 glColor3f(1,1,1);
 glPointSize(2.0);
// float r = 100;
 //float x = 0, y = r;
// float p = 1 - r;
 glBegin(GL_POINTS);
 glVertex2i(0,0);
 float angle;
 for(int i=0;i<100;i++)
 {
	 glVertex2i(0, i);
	 glVertex2i(i, 0);
	  glVertex2i(0, -i);
	 glVertex2i(-i, 0);
 }
 glEnd();

 if(alpha+beta>=360)
	{
		draw(alpha,360);
		draw(0,beta-(360-alpha));
 }
 else
 {
	 beta=beta+alpha;
	 draw(alpha,beta);
 }

}
void drawLine(int x,int y)
{
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2i(0,0);
	glVertex2i(y, x);
	glEnd();


}
void draw(float alpha,float beta)
{
	 glBegin(GL_LINES);
	 glColor3f(1,0,0);
	float r=100;
	float x=0;
	float y=r;
	float angle;
	float p=1-r;
	 while ( x <= y ) 
	{
  
  if (p < 0) {
   p += 2*x + 3;
   x++;
  }
  else {
  
   p += 2*x + 5 - 2*y;
   x++;
   y--;
  }
	
 
	angle=atan(y/x);
	angle=angle*180/PI;
	
	if((90-angle) >= alpha  && (90-angle) <=beta)
	{
		glVertex2i(0,0);
	
		glVertex2i(y, x);
	
		
		
	}
	//1
	if(angle >=alpha && angle <= beta)
	{
		glVertex2i(0,0);
		glVertex2i(x,y);
	}
	//2
	if(180-angle>=alpha && 180-angle<=beta)
	{
		glVertex2i(0,0);
		glVertex2i(-x, y);
	}
	//3
	if(angle+90>=alpha  && angle+90<=beta)
	{
		glVertex2i(0,0);
		glVertex2i(-y,x);
	}
	//4
	if(270-angle>=alpha  && 270-angle<=beta)
	{
		glVertex2i(-y, -x);
	}
	//5
	if(angle+180>=alpha  && angle+180<=beta)
	{
		glVertex2i(0,0);
		glVertex2i(-x,-y);
	}
	//6
	if(360-angle>=alpha  && 360-angle<=beta)
	{
		glVertex2i(0,0);
		glVertex2i(x, -y);
	}
	//7
	if(angle+270>=alpha  && angle+270<=beta)
    {
		glVertex2i(0,0);
		glVertex2i(y,-x);
	}
	;
	;
	//8
	

  
 }
}

void call_back()
 {
	circle();
	glEnd();
	glFlush();
 }
int main(int argc, char ** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Line Draw OpenGL");
 gluOrtho2D(-250,250,-250,250);
 glClearColor(0,0,0,0);
 glClear(GL_COLOR_BUFFER_BIT);


 
 glutDisplayFunc(call_back);
 glutMainLoop();
 return 0;
}