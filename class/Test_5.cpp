#include <GL/glut.h>
#include "Test_5.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define pi 3.1415926
double radius=150.0;
int w=400,h=400;
double angle=10;

Test_5* Test_5::theTest = 0;

void Test_5::drawSphere(void)
{
	float phir,thetar;
	float x,y,z;
	glClear(GL_COLOR_BUFFER_BIT);
	for(float phi=0; phi<=180; phi+=5)
	{
		phir = pi / 180.0 *phi;
		//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		//glFrontFace(GL_CCW); //��ʱ��Ϊ����
		glBegin(GL_LINE_LOOP);
		for(float theta=0.0; theta<=360.0; theta+=5)
		{
			thetar=pi / 180.0 * theta;
			x=radius*cos(thetar)*cos(phir);
			y=radius*cos(thetar)*sin(phir);
			z=radius*sin(thetar);
			glVertex3d(x,y,z);
		}
		glEnd();

		glBegin(GL_LINE_LOOP);
		for(float theta=0.0; theta<=360.0; theta+=5)
		{
			thetar=pi / 180.0 * theta;
			y=radius*cos(thetar)*cos(phir);
			z=radius*cos(thetar)*sin(phir);
			x=radius*sin(thetar);
			glVertex3d(x,y,z);
		}
		glEnd();

		glBegin(GL_LINE_LOOP);
		for(float theta=0.0; theta<=360.0; theta+=5)
		{
			thetar=pi / 180.0 * theta;
			x=radius*cos(thetar)*cos(phir);
			z=radius*cos(thetar)*sin(phir);
			y=radius*sin(thetar);
			glVertex3d(x,y,z);
		}
		glEnd();
	}
	glutSwapBuffers();
}

void Test_5::reshape(GLsizei ww, GLsizei hh)
{
	w=ww;


	h=hh;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-radius,radius,-radius,radius,-radius,radius);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glFlush();
}

void Test_5::init(void)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-radius,radius,-radius,radius,-radius,radius);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Test_5::mouse(int btn,int state, int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON &&state==GLUT_DOWN)
	{
		radius=radius + 15.0;
		angle = angle - 0.1;
		Test_5::sharedTest_5()->drawSphere();
	}
	if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		radius = radius - 15.0;
		angle = angle - 0.1;
		Test_5::sharedTest_5()->drawSphere();
	}
}

void Test_5::idle(void)
{
	glutPostRedisplay();
}
void Test_5::display(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	angle += 0.1;
	glRotated(30+angle,1,0,0);
	glRotated(60+angle,0,1,0);
	glRotated(90+angle,0,0,1);
	glutPostRedisplay();
	Test_5::sharedTest_5()->drawSphere();
}
