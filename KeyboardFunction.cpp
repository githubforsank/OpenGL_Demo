
#include<GL/freeglut.h>
#include "math.h"
#include "stdio.h"
#include "stdlib.h"

void display()
{
         glClearColor(0.0f,5.0f,0.0f,1.0f);
         glClear(GL_COLOR_BUFFER_BIT);

         glBegin(GL_POLYGON);  //Triangle
         glColor3f(0.0f,0.0f,1.0f);
        
         glVertex2f(0.0f,0.0f);
       //  glColor3f(0.1f,0.0f,0.0f);
         glVertex2f(0.125f,0.25f);
          glVertex2f(0.25,0.0f);
        
         glEnd();

    
         glBegin(GL_POLYGON);   //Trapezoid
         glColor3f(1.0f,0.0f,1.0f);
         glVertex2f(0.30f,0.0f);
       //  glColor3f(0.0f,0.0f,1.0f);
         glVertex2f(0.40f,0.25f);
     //    glColor3f(1.0f,1.0f,0.0f);
         glVertex2f(0.5f,0.25f);
         //glColor3f(1.0f,0.0f,0.0f);
         glVertex2f(0.60,0.0f);
        
         glEnd();

        
         glBegin(GL_POLYGON);  //Pentagon
         glColor3f(1.0f,0.0f,0.0f);
         glVertex2f(-0.5f,0.0f);
         glVertex2f(-0.6f,0.25f);
         glVertex2f(-0.4f,0.5f);
         glVertex2f(-0.2,0.25f);
         glVertex2f(-0.3f,0.0f);
         glEnd();
        
         glutSwapBuffers();
}
int myrandom(int x)
{
		return rand()%x;
}
 
void keyboard (unsigned char key, int x, int y)
{
    // we'll switch between red and blue when the user presses a key:


    switch (key) {
    case 27: 
        exit(0);
	case 'a':
       
        glClearColor(5.0f,0.0f,0.0f, 1.0f);
        glutPostRedisplay();
		break;
		 
    }
}


int main(int argc, char** argv)
{
        glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE);
        //glutInitDisplayMode(GLUT_DOUBLE);
        glutInitWindowSize(1000, 1000);
        glutCreateWindow("Shapes");
        glutInitWindowPosition(0,0);
        
        glutDisplayFunc(display);
        //glutDisplayFunc(display1);
		glutKeyboardFunc(keyboard);
        glutMainLoop();
        return 0;
}
