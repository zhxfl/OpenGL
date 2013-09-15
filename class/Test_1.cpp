#include <GL/glut.h>
#include "Test_1.h"

void renderScene(void)
{
	/*
	glClear������
	*/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/*
	����ǰ���û����ϵ��ԭ���Ƶ�����Ļ���ģ�������һ����λ����
	1.X�����������ң�Y�����������ϣ�Z�����������⡣
	2.OpenGL��Ļ���ĵ����ֵ��X��Y���ϵ�0.0f�㡣
	3.������������ֵ�Ǹ�ֵ����������ֵ��
	������Ļ��������ֵ��������Ļ�׶��Ǹ�ֵ��
	������Ļ��Ǹ�ֵ���Ƴ���Ļ������ֵ��
	*/
	glLoadIdentity();

	/*
	����������㣬���������������ӳ�һ��͹��
	*/

	glBegin(GL_TRIANGLES);//GL_TRIANGLES�����
	glVertex3f(-1.0, -1.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glEnd();

	/*
	˫����ģʽ
	�� glutInitDisplayMode(GLUT_RGBA) ��Ӧ
	*/
	glutSwapBuffers();
}

void renderScene_1(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	/* 
	���ʵ���ɫ
	*/
	glColor3f(1.0, 1.0, 0.0);
	
	glLoadIdentity();
	
	/* 
	http://hi.baidu.com/xun1573/item/a872977f9fbbbd366cc37c6f 
	http://www.cnblogs.com/yxnchinahlj/archive/2010/10/30/1865298.html 
	glOrtho��ȡ����
	procedure glViewPort(x:GLInt;y:GLInt;Width:GLSizei;Height:GLSizei);
	����֮�����glViewPort�ϣ�
	���glViewPort(x, y, width, height)
	�����ܵĴ����ϵ�(x, y)�����
	*/

	glViewport(0, 0, 300, 300);
	glOrtho(-0.25, 0.25, -0.25, 0.25, -0.0, 0.5);

	/* 
	��һ������
	*/

	glBegin(GL_POLYGON);
	{
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.25, -0.25, 0.0);
		glVertex3f(-0.25, -0.25, 0.0);
		glVertex3f(-0.25, 0.25, 0.0);
	}
	glEnd();

	/* 
	˫������Ⱦ
	*/

	glutSwapBuffers();
}
