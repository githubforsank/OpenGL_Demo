#include <GL/freeglut.h>
#include <Windows.h>
void display_triangle()
{
		glClearColor(1.0f,0.654f,0.260f,1.0f);
		//Set background alpha and color to black
		glClear(GL_COLOR_BUFFER_BIT);
		//clear the color buffer
		glBegin(GL_POLYGON);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex2f(0.5f,0.0f);
		glVertex2f(0.0f,0.5f);
		glVertex2f(-0.5f,0.0f);
		//glVertex2f(0.8f,0.0f);
		glEnd();
		glFlush();//Render the thing
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);//Initialize glut
	glutInitDisplayMode(GLUT_SINGLE);
//	glutSwapBuffer();
	glutCreateWindow("Triangle");
	glutInitWindowSize(500,500);
	glutInitWindowPosition(60,50);
	glutDisplayFunc(display_triangle);//Register display call bach handler for window
	glutMainLoop();
	return 0;
}
