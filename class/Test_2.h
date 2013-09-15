/*
@author  :  zhxfl
@date    :  2012.1.2
@function:  矩形旋转，鼠标右键减速，鼠标左键加速
*/

#ifndef _OPENGL_CLASS_TEST_2_
#define _OPENGL_CLASS_TEST_2_

class Test_2
{
public:
	void init(void);
	static void display(void);
	static void reshape(int w, int h);
	static void mouse(int button, int state, int x, int y);

	static Test_2* sharedTest_2()
	{
		if(theTest == 0)
			Test_2::build();
		return theTest;
	}
private:
	static Test_2* build()
	{
		theTest = new Test_2();
		return theTest;
	}
	static void spinDisplay(void);
	static void spinUp(void);
	static void spinDown(void);
	static Test_2 *theTest;
};

#endif