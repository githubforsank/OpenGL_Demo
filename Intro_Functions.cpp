
#include <GL/freeglut.h>
void display()
{
		glClearColor(1.0f,1.0f,1.0f,1.0f);
		//Set background alpha and color to black
		glClear(GL_COLOR_BUFFER_BIT);
		//clear the color buffer
		glBegin(GL_QUADS);//Draw a red square
		glColor3f(0.0f,0.0f,1.0f);
		glVertex2f(0.0f,0.0f);
		glVertex2f(0.5f,0.5f);
		glVertex2f(0.5f,-0.5f);
		glEnd();
		glFlush();//Render the thing
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);//Initialize glut
	glutCreateWindow("Open GL Setup Test");
	glutInitWindowSize(500,500);
	glutInitWIndowPosition(60,50);
	glutDisplayFunc(display);//Register display call bach handler for window
	glutMainLoop();
	return 0;
}
