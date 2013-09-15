#include "Test_6.h"
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>


#define X 0.525731112119133606
#define Z 0.850650808352039932

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
    glVertex2f ((x1*REAL_UNIT),(y1*REAL_UNIT)); glVertex2f ((x2*REAL_UNIT),(y2*REAL_UNIT)); glEnd();

#define drawOnePoint(x,y) glBegin(GL_POINT);\
    glVertex2f ((x*REAL_UNIT),(y*REAL_UNIT)); glEnd();


static GLfloat vdata[12][3] = { { -X, 0.0, Z }, { X, 0.0, Z }, { -X, 0.0, -Z },
		{ X, 0.0, -Z }, { 0.0, Z, X }, { 0.0, Z, -X }, { 0.0, -Z, X }, { 0.0,
				-Z, -X }, { Z, X, 0.0 }, { -Z, X, 0.0 }, { Z, -X, 0.0 }, { -Z,
				-X, 0.0 } };

static GLuint tindices[20][3] = { { 1, 4, 0 }, { 4, 9, 0 }, { 4, 5, 9 }, { 8, 5,
		4 }, { 1, 8, 4 }, { 1, 10, 8 }, { 10, 3, 8 }, { 8, 3, 5 }, { 3, 2, 5 },
		{ 3, 7, 2 }, { 3, 10, 7 }, { 10, 6, 7 }, { 6, 11, 7 }, { 6, 0, 11 }, {
				6, 1, 0 }, { 10, 1, 6 }, { 11, 0, 9 }, { 2, 11, 9 },
		{ 5, 2, 9 }, { 11, 2, 9 }

};

static GLubyte colors[20][3] = {
		{ 255, 110, 110 }, { 110, 255, 110 }, { 110, 110, 255 }, {255, 255, 110 },
		{ 110, 255, 255 }, { 255, 110, 255 }, { 128, 110, 110 }, { 110,128, 110 },
		{ 110, 100, 128 }, { 128, 128, 110 }, { 110, 128, 128 }, { 128, 110, 128 },
		{ 128, 128, 101 }, { 110, 128, 128 }, { 128, 101, 128 }, { 101, 101, 128 },
		{ 128, 110, 110 }, { 110, 128, 101 }, { 128, 128, 128 }, { 128, 101, 110 }

};

void init_7() {
	glClearColor(0.2, 0.2, 0.2, 0.2); //clear background to black color
	glShadeModel(GL_FLAT);
}

void display_7() {
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	static float angle = 0;
	angle += 0.1;

	glRotated(30+angle,1,0,0);
	glRotated(60+angle,0,1,0);
	glRotated(90+angle,0,0,1);
	glutPostRedisplay();


	//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//glClearColor(1.0,1.0,1.0, 0.0);
	//glShadeModel(GL_FLAT);


	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);
	/*
	  glCullFace(GL_FRONT) =
	  glCullFace(GL_BACK);
	  glFrontFace(GL_CW);
	 */

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 20; i++) {

		glColor3ub(colors[i][0], colors[i][1], colors[i][2]);
		glVertex3fv(&vdata[tindices[i][0]][0]);
		glVertex3fv(&vdata[tindices[i][1]][0]);
		glVertex3fv(&vdata[tindices[i][2]][0]);
	}
	glEnd();

	glutSwapBuffers();    // swap buffers
}

void reshape_7(int w, int h) {

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-w,w,-h,h,-h,h);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	glFlush();
}
