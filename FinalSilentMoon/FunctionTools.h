//#pragma once
#ifndef __FUNCTIONTOOLS_H_
#define __FUNCTIONTOOLS_H_

namespace FUNCTION {
	int Function_ONOFF(int onoff_)
	{
		if (!onoff_)
			return 1;
		else if (onoff_ == 1)
			return 2;
		else if (onoff_)
			return 0;
	}
	int Function_ONOFF_SIMPLE(int onoff_)
	{
		if (!onoff_)
			return 1;
		else if (onoff_)
			return 0;
	}
}

#endif // !__FUNCTIONTOOLS_H_
