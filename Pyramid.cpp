#include <GL\glut.h>

GLfloat xRotated, yRotated, zRotated;
// Torus
GLdouble innerRaidus=0.5;
GLdouble outterRaidus=1;
GLint sides =50;
GLint rings =50;
int k = 0;



void displayTorus(void)
{

    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
	glLineWidth(2);
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(0.0,0.0,-4.5);
    // Red color used to draw.
    glColor3f(0, 1.0, 0.0); 
    // changing in transformation matrix.
    // rotation about X axis
    if(k==0)
        {
                glRotatef(xRotated,1.0,0.0,0.0);
        }
    // rotation about Y axis
        else if(k==1)
        {
                glRotatef(yRotated,0.0,1.0,0.0);
        }
    // rotation about Z axis
        else if(k==2)
        {
                glRotatef(zRotated,0.0,0.0,1.0);
        }
    // scaling transfomation 
    glScalef(1.0,1.0,1.0);
    // built-in (glut library) function , draw you a Torus.
 

    glBegin(GL_LINE_LOOP);


                glVertex3f(0.5,-0.5,0.0);
                glVertex3f(0.5,0.5,0.0);
                glVertex3f(-0.5,0.5,0.0);
                glVertex3f(-0.5,-0.5,0.0);
                glEnd();
                //draw the nose
                glBegin(GL_LINES);

                glVertex3f(0.5,-0.5,0.0);
                //glColor3f(1.0,0.0,0.0);
                glVertex3f(0.0,0.0,1);

                //glColor3f(1.0,1.0,1.0);
                glVertex3f(0.5,0.5,0.0);
                //glColor3f(1.0,0.0,0.0);
                glVertex3f(0.0,0.0,1);

                //glColor3f(1.0,1.0,1.0);
                glVertex3f(-0.5,0.5,0.0);
                //glColor3f(1.0,0.0,0.0);
                glVertex3f(0.0,0.0,1);

                //glColor3f(1.0,1.0,1.0);
                glVertex3f(-0.5,-0.5,0.0);
                //        glColor3f(1.0,0.0,0.0);
                glVertex3f(0.0,0.0,1);
                glEnd();
     
    glFlush();        
    // sawp buffers called because we are using double buffering 
   // glutSwapBuffers();
}

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

void idleTorus(void)
{
 
     yRotated += 0.01;
     xRotated += 0.01;
     zRotated += 0.01;
    displayTorus();
}

int onMouse;
void mouseClicks(int button, int state, int x, int y)
{
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
                k = 0;
                glutDisplayFunc(displayTorus);
        }
		else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {
                k = 1;
                glutDisplayFunc(displayTorus);
        }

else if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
        {
                k = 2;
                glutDisplayFunc(displayTorus);
        }
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
        glutMouseFunc(mouseClicks);
    glutDisplayFunc(displayTorus);
    glutReshapeFunc(reshapeTorus);
    glutIdleFunc(idleTorus);
    //Let start glut loop
    glutMainLoop();
    return 0;
}
