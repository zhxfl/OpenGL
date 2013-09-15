#include <GL/glut.h>
#include "Test_4.h"

Test_4* Test_4::theTest = 0;


void Test_4::init(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glShadeModel(GL_FLAT);
}

void Test_4::display(void)
{
	/* 
		GL_LINE
		�������������ʾ
	*/
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_TRIANGLES);
	{
		glEdgeFlag(GL_TRUE);
		glVertex3f(-1.0, -1.0, 0.0);

		glEdgeFlag(GL_FALSE);
		glVertex3f(1.0, 0.0, 0.0);

		glEdgeFlag(GL_TRUE);
		glVertex3f(0.0, 1.0, 0.0);
	}
	glEnd();
	glFlush();
}

void Test_4::reshape(int w, int h)
{
	glClear(GL_COLOR_BUFFER_BIT);
}
