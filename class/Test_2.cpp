#include <GL/glut.h>
#include "Test_2.h"

static GLfloat spin = 0.0;
Test_2* Test_2::theTest = 0;

void Test_2::init(void)
{
	/*
	�������Ϊ��ɫ
	*/
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/*
	������ɫģʽ��
	GL_SMOOTH:
		Ĭ�������OpenGL�ǲ��ý�����ɫģʽ��
		���߶ε������˵���ɫ���ò�ͬ��
		�߶��м����ɫ�����˵�֮�����ƽ�ȹ�ɡ�
	GL_FLAT:
		ͼ���ڲ���ɫ�����õ������һ���������ɫ
	*/
	glShadeModel(GL_FLAT);
}

void Test_2::display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	/*
	glPushMatrix��
	glPopMatrix��
	������Բ����ã�ֻ�����ڱ���֮ǰ���ֳ������ⱻglRotatef
	�任֮���ֳ�Ҳ����ת��
	*/
	glPushMatrix();
	
	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glRectf(-25.0f, -25.0, 25.0, 25.0);
	
	glPopMatrix();
	glutSwapBuffers();
}

void Test_2::spinUp(void)
{
	spin = spin + 1.0;
	if(spin > 360.0)
	{
		spin = spin - 360.0;
	}
	glutPostRedisplay();
}

void Test_2::spinDown(void)
{
	spin = spin - 1.0;
	if(spin < 0)
	{
		spin = 0;
	}
	glutPostRedisplay();
}

void Test_2::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Test_2::mouse(int button, int state, int x, int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state == GLUT_DOWN)
		{
			/*func���ڳ�����е�ʱ��ͻᱻ���õĺ���ĺ�����*/
			glutIdleFunc(spinUp);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if(state == GLUT_DOWN)
		{
			glutIdleFunc(spinDown);
		}
		break;
	default:
		break;
	}
}
