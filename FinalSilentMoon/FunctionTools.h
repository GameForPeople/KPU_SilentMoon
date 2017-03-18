#ifndef __FUNCTIONTOOLS_H_
#define __FUNCTIONTOOLS_H_

#include "glut.h"

namespace FUNCTION {
	int Function_ONOFF(int onoff_)
	{
		if (!onoff_)
			return 1;
		else if (onoff_ == 1)
			return 2;
		else
			return 0;
	}
	int Function_ONOFF_SIMPLE(int onoff_)
	{
		if (!onoff_)
			return 1;
		else
			return 0;
	}
};
namespace COLOR {
	void SetColor(int Red, int Green, int Blue) {
		glColor3f((float)((float)Red / 255), (float)((float)Green / 255), (float)((float)Blue / 255));
	}
};

namespace ROTATE {
	void RotateXYZ(float x, float y, float z) {
		glRotatef(x, 1, 0, 0);
		glRotatef(y, 0, 1, 0);
		glRotatef(z, 0, 0, 1);
	}
}

#endif // !__FUNCTIONTools_H_


