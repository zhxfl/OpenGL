/*
@author   : zhxfl
@date     : 2012.1.3
@function : 画出三角形的轮廓
*/

#ifndef _OPENGL_CLASS_TEST_4_
#define _OPENGL_CLASS_TEST_4_

class Test_4
{
public:
	void init(void);
	static void display(void);
	static void reshape(int w, int h);
	static Test_4* sharedTest_4()
	{
		if(theTest == 0)
			Test_4::build();
		return theTest;
	}
private:
	static Test_4* build()
	{
		theTest = new Test_4();
		return theTest;
	}
	static Test_4 *theTest;
};

#endif