#include <iostream>
#include "TimeFunction.h"

void TimeClass::TimeFunc(LogoSceneClass * logo, HeliSceneClass *heli) {
	switch (this->m_sceneNow) {
	case 1:
		logo->Update();
		break;
	case 2:
		heli->Update();
		break;
	}
}