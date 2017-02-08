#include <GL/freeglut.h>
#include <Windows.h>
#include <math.h>
void display()
{
		glClearColor(0.2f,0.2f,0.2f,1.0f);
		//Set background alpha and color to black
		glClear(GL_COLOR_BUFFER_BIT);
		//clear the color buffer
		
	float angleIncrement = 360.0f / 5;  // n is 5 in your case
	angleIncrement *= (3.14 / 180.0); // convert degrees to radians
	int radius=1.0f;
	glBegin(GL_POLYGON);
	float angle = 1.5f;
	for (int k = 0; k < 5; ++k) {
		 glVertex3f(radius * cos(angle), radius * sin(angle), 1.0f);
		  angle += angleIncrement;
		}
		glEnd();
		glutSwapBuffers();//Render the thing
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);//Initialize glut
	glutInitDisplayMode(GLUT_DOUBLE);
	glutCreateWindow("Pentagon");
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(60,50);
	glutDisplayFunc(display);//Register display call bach handler for window
	glutMainLoop();
	return 0;
}
