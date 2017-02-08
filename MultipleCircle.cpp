#include <gl/freeglut.h>
#include <Windows.h>
#include <iostream>
#include <math.h>
#define PI 3.14
using namespace std;
/*

*/
void circle() {
 glColor3f(1.0, 0.0, 0.0);
 glPointSize(2.0);
 float r = 100;
 float x = 0, y = r;
 float p = 1 - r;
 glBegin(GL_POINTS);
 glVertex2i(0,0);
 while ( x < (r*sin(PI/4)) && x!=y ) 
 {
  x++;
  if (p < 0) {
   p += 2 * (x + 1) + 1;
  }
  else {
   y--;
   p += 2 * (x + 1) + 1 - 2 * (y - 1);
  }
	glVertex2i(x, y);
	glVertex2i(y,x);
    glVertex2i(x, -y);
	glVertex2i(-x, y);
	glVertex2i(-x,- y);
	glVertex2i(-y,x);
	glVertex2i(y, -x);
    glVertex2i(-y, -x);

 
 }

}
void circle1() {
 glColor3f(1.0, 0.0, 0.0);
 glPointSize(2.0);
 float r = 100;
 float x = 0, y = r;
 float p = 1 - r;
 glBegin(GL_POINTS);
 glVertex2i(0,0);
 while ( x < (r*sin(PI/4)) && x!=y ) 
 {
  x++;
  if (p < 0) {
   p += 2 * (x + 1) + 1;
  }
  else {
   y--;
   p += 2 * (x + 1) + 1 - 2 * (y - 1);
  }
	glVertex2i(x+r, y);
	glVertex2i(y+r,x);
    glVertex2i(x+r, -y);
	glVertex2i(-x+r, y);
	glVertex2i(-x+r,- y);
	glVertex2i(-y+r,x);
	glVertex2i(y+r, -x);
    glVertex2i(-y+r, -x);

 
 }
 
}
void circle2() {
 glColor3f(1.0, 0.0, 0.0);
 glPointSize(2.0);
 float r = 100;
 float x = 0, y = r;
 float p = 1 - r;
 glBegin(GL_POINTS);
 glVertex2i(0,0);
 while ( x < (r*sin(PI/4)) && x!=y ) 
 {
  x++;
  if (p < 0) {
   p += 2 * (x + 1) + 1;
  }
  else {
   y--;
   p += 2 * (x + 1) + 1 - 2 * (y - 1);
  }
	glVertex2i(x+r*cos(PI/4), y+r*sin(PI/4));
	glVertex2i(y+r*cos(PI/4),x+r*sin(PI/4));
    glVertex2i(x+r*cos(PI/4), -y+r*sin(PI/4));
	glVertex2i(-x+r*cos(PI/4), y+r*sin(PI/4));
	glVertex2i(-x+r*cos(PI/4),- y+r*sin(PI/4));
	glVertex2i(-y+r*cos(PI/4),x+r*sin(PI/4));
	glVertex2i(y+r*cos(PI/4), -x+r*sin(PI/4));
    glVertex2i(-y+r*cos(PI/4), -x+r*sin(PI/4));

 
 }
 
}
void circle3() {
 glColor3f(1.0, 0.0, 0.0);
 glPointSize(2.0);
 float r = 100;
 float x = 0, y = r;
 float p = 1 - r;
 glBegin(GL_POINTS);
 glVertex2i(0,0);
 while ( x < (r*sin(PI/4)) && x!=y ) 
 {
  x++;
  if (p < 0) {
   p += 2 * (x + 1) + 1;
  }
  else {
   y--;
   p += 2 * (x + 1) + 1 - 2 * (y - 1);
  }
	glVertex2i(x+r*cos(PI/4), y-r*sin(PI/4));
	glVertex2i(y+r*cos(PI/4),x-r*sin(PI/4));
    glVertex2i(x+r*cos(PI/4), -y-r*sin(PI/4));
	glVertex2i(-x+r*cos(PI/4), y-r*sin(PI/4));
	glVertex2i(-x+r*cos(PI/4),- y-r*sin(PI/4));
	glVertex2i(-y+r*cos(PI/4),x-r*sin(PI/4));
	glVertex2i(y+r*cos(PI/4), -x-r*sin(PI/4));
    glVertex2i(-y+r*cos(PI/4), -x-r*sin(PI/4));

 
 }
 
}
void call_back()
 {
	circle();
	circle1();
	circle2();
	circle3();
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
