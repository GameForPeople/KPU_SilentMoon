#include <iostream>
#include "KeyboardFunction.h"

void KeyboardClass::KeyFunction(LogoSceneClass *logo , HeliSceneClass *heli) {
	switch (this->m_sceneNow) {
	case 1:
		logo->Key();	// ���Լ�
	case 2:
		heli->Key();
	}
}

void KeyboardClass::SpecialKeyFunction(LogoSceneClass *logo, HeliSceneClass *heli) {
	switch (this->m_sceneNow) {
	case 1:
		logo->Key();	// ���Լ�
	case 2:
		logo->Key();
	}
}
/*
void MouseClass::ButtonFunction(LogoSceneClass *logo) {
	switch (this->m_sceneNow) {
	case 1:
		logo->Mouse();	// ���Լ�
	}
}
*/