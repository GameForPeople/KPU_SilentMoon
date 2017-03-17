#include <iostream>
#include "MouseFunction.h"


void MouseClass::ButtonFunction(LogoSceneClass *logo, HeliSceneClass *heli) {
	switch (this->m_sceneNow) {
	case 1:		
		logo->Mouse();	// ºóÇÔ¼ö
		break;
	case 2:
		heli->Mouse();
		break;
	}
}

void MouseClass::MotionFunction(LogoSceneClass *logo, HeliSceneClass *heli) {
	switch (this->m_sceneNow) {
	case 1:
		logo->Mouse();	// ºóÇÔ¼ö
		break;
	case 2:
		heli->Mouse();
		break;
	}
}