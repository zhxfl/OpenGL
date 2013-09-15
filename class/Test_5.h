/*
@author   : zhxfl
@date     : 2012.1.4
@function : ����һ����
球体，使用多个圆形交叉构成
*/

#ifndef _OPENGL_CLASS_TEST_5_
#define _OPENGL_CLASS_TEST_5_

class Test_5
{
public:
	void init(void);
	static Test_5* sharedTest_5()
	{
		if(theTest == 0)
			Test_5::build();
		return theTest;
	}
	static void reshape(GLsizei ww, GLsizei hh);
	static void mouse(int btn,int state, int x,int y);
	static void idle(void);
	static void display(void);
private:
	static Test_5* build()
	{
		theTest = new Test_5();
		return theTest;
	}
	static Test_5 *theTest;
	void drawSphere(void);
};

#endif
