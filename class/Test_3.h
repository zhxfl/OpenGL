/*
@author  :  zhxfl
@date    :  2012.1.3
@function:
			OPENGL »­Ö±Ïß
*/

#ifndef _OPENGL_CLASS_TEST_3_
#define _OPENGL_CLASS_TEST_3_

class Test_3
{
public:
	void init(void);
	static void display(void);
	static void reshape(int w, int h);
	static Test_3* sharedTest_3()
	{
		if(theTest == 0)
			Test_3::build();
		return theTest;
	}
private:
	static Test_3* build()
	{
		theTest = new Test_3();
		return theTest;
	}
	static Test_3 *theTest;
};

#endif