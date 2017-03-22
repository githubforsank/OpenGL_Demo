#include <GL\freeglut.h>
#include <ctime>
#include <iostream>
using namespace std;
GLfloat xRotated, yRotated, zRotated;
// Torus
GLdouble innerRaidus=0.5;
GLdouble outterRaidus=1;
GLint sides =50;
GLint rings =50;




void reshapeTorus(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0
     
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
 
    glViewport(0,0,x,y);  //Use the whole window for rendering
	
}
clock_t start=clock();
float x=0,y=0,z=-4.5;
void displayTorus(void)
{
	int duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	cout<<"Display funct duration"<<duration<<endl;
    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	
    glTranslatef(x,y,z);
	if(duration>10 && duration<12)
	{
		x+=0.001;
		glTranslatef(x,y,z);
	}
	else if(duration >12 && duration < 14)
	{
		x=0;
		y+=0.001;
		glTranslatef(x,y,z);
	}
	else if(duration >14 && duration < 16)
	{
		x=0;
		y=0;
		z+=0.001;
		glTranslatef(x,y,z);
	}
    // Red color used to draw.
    glColor3f(0.8, 0.2, 0.1); 
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation 
    glScalef(1.0,1.0,1.0);
    // built-in (glut library) function , draw you a Torus.
 

    glutSolidTorus(innerRaidus,outterRaidus,sides,rings);
    // Flush buffers to screen
     
    glFlush();        
    // sawp buffers called because we are using double buffering 
   // glutSwapBuffers();
}

void idleTorus(void)
{
	float x=1,y=1,z=1;
	int duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	cout<<"idle torus duration "<<duration<<endl;
	if(duration<3)
	{	
		xRotated += 0.3;
		cout<<"\nRotating in x axis";
	}
	else if(duration < 6)
	{
		yRotated +=0.3;
		cout<<"\nRotating in y axis";
	}
	else if(duration <9)
	{
		zRotated +=0.5;
		cout<<"\n Rotating in z axis";
	}
	else if(duration < 10)
	{
		xRotated=0;
		yRotated=0;
		zRotated=0;
		
			
	}
	
	 
     
    displayTorus();
}


int main (int argc, char **argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    //double buffering used to avoid flickering problem in animation
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    // window size
    glutInitWindowSize(400,350);
    // create the window 
    glutCreateWindow("Torus Rotating Animation");
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    xRotated = yRotated = zRotated = 30.0;
     xRotated=33;
     yRotated=40;
    glClearColor(0.0,0.0,0.0,0.0);
    //Assign  the function used in events
    glutDisplayFunc(displayTorus);
   glutReshapeFunc(reshapeTorus);
    glutIdleFunc(idleTorus);
    //Let start glut loop
    glutMainLoop();
    return 0;
}
