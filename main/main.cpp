#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include "../class/Test_1.h"
#include "../class/Test_2.h"
#include "../class/Test_3.h"
#include "../class/Test_4.h"
#include "../class/Test_5.h"
#include "../class/Test_6.h"

void doCase1(int argc, char* argv[]);
void doCase2(int argc, char* argv[]);
void doCase3(int argc, char* argv[]);
void doCase4(int argc, char* argv[]);
void doCase5(int argc, char* argv[]);
void doCase6(int argc, char* argv[]);//画出一个球体，由很多个圆组成
void doCase7(int argc, char* argv[]);//画出一个20面体，同时不显示被挡住的图像

int main(int argc, char* argv[])
{
	int cmd;
	while(scanf("%d",&cmd)!=EOF)
	{
		switch (cmd)
		{
		case 1:
			doCase1(argc, argv);
			break;
		case 2:
			doCase2(argc, argv);
			break;
		case 3:
			doCase3(argc, argv);
			break;
		case 4:
			doCase4(argc, argv);
			break;
		case 5:
			doCase5(argc, argv);
			break;
		case 6:
			doCase6(argc, argv);
			break;
		case 7:
			doCase7(argc, argv);
			break;
		}
		glutMainLoop();
	}

	return 0;
}

void doCase1(int argc, char* argv[])
{
	glutInit(&argc, (char**) argv); 

	/*����ˢ�µ�ģʽ*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);//GLUT_DEPTH????

	/* ����λ��*/
	glutInitWindowPosition(100, 100);

	/* ���ڵĴ�С*/
	glutInitWindowSize(320, 320);

	/* ���ڵ�����*/
	glutCreateWindow("case1");

	/* �ص����� */
	glutDisplayFunc(renderScene);
}

void doCase2(int argc, char* argv[])
{
	glutInit(&argc, (char**) argv);  // ��ʼ������
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);//GLUT_DEPTH????
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Case2");
	glutDisplayFunc(renderScene_1);
}

void doCase3(int argc, char* argv[])
{
	glutInit(&argc, (char**) argv);  // ��ʼ������
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);//GLUT_DEPTH????
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Case3");
	Test_2* test = Test_2::sharedTest_2();
	test->init();
	glutDisplayFunc(Test_2::display);
	glutReshapeFunc(Test_2::reshape);
	glutMouseFunc(Test_2::mouse);
}

void doCase4(int argc, char* argv[])
{
	glutInit(&argc, (char**) argv);  // ��ʼ������
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);//GLUT_DEPTH????
	glutInitWindowPosition(400, 400);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Case4");
	Test_3::sharedTest_3()->init();
	glutDisplayFunc(Test_3::display);
	glutReshapeFunc(Test_3::reshape);
}


void doCase5(int argc, char* argv[])
{
	glutInit(&argc, (char**) argv);  // ��ʼ������
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);//GLUT_DEPTH????
	glutInitWindowPosition(400, 400);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Case5");
	Test_4::sharedTest_4()->init();
	glutDisplayFunc(Test_4::display);
	glutReshapeFunc(Test_4::reshape);
}

void doCase6(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Case 6");
	Test_5::sharedTest_5()->init();
	glutMouseFunc(Test_5::mouse);
	glutReshapeFunc(Test_5::reshape);
	glutDisplayFunc(Test_5::display);
	glEnable(GL_DEPTH_TEST);
}
void doCase7(int argc, char*argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Case 7");
	init_7();
	glutDisplayFunc(display_7);
	glutReshapeFunc(reshape_7);
}
