#include <GL/glut.h>
#include "Test_3.h"

Test_3* Test_3::theTest = 0;
#define drawOneLine(x1, y1, x2, y2) \
	glBegin(GL_LINES);  \
	glVertex2f(x1, y1);\
	glVertex2f(x2, y2);\
	glEnd();

void Test_3::init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void Test_3::display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LINE_STIPPLE);

	/*���û�ֱ�ߵķ��*/
	glLineStipple(1, 0x0101);
	drawOneLine(50.0, 100.0, 150.0, 100.0);

	glLineStipple(1, 0x00FF);
	drawOneLine(50.0, 150.0, 150.0, 150.0);

	glLineStipple(1, 0x1C47);
	drawOneLine(50.0, 200.0, 150.0, 200.0);

	glLineWidth(2.0);

	glDisable(GL_LINE_STIPPLE);
	glutSwapBuffers();
}

void Test_3::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
