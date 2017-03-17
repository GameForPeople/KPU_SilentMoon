//#pragma once
#ifndef __MOUSEFUNCTION_H_
#define __MOUSEFUNCTION_H_

#include "LogoScene.h"
#include "HeliScene.h"

class PointClass {
public:
	int x;
	int y;
};

class MouseClass {
	PointClass m_pos;
	int m_button;
	int m_state;
	int m_sceneNow;

public:
	void ChangeSceneNow(const int nextScene) {
		this->m_sceneNow = nextScene;
	}
	int GetButton() const {
		return this->m_button;
	}
	int GetState() const {
		return this->m_state;
	}
	PointClass GetPos() const {
		return this->m_pos;
	}
	void SetButton(const int insertButton, const int insertState, LogoSceneClass * logo, HeliSceneClass * heli) {
		this->m_button = insertButton;
		this->m_state = insertState;
		ButtonFunction(logo, heli);
	}
	void SetMotion(const int mothionX, const int mothionY, LogoSceneClass * logo, HeliSceneClass * heli) {
		this->m_pos.x = mothionX;
		this->m_pos.y = mothionY;
		ButtonFunction(logo, heli);

	}
	void ButtonFunction(LogoSceneClass *, HeliSceneClass *);
	void MotionFunction(LogoSceneClass *, HeliSceneClass *);
};
#endif // !__MOUSEFUNCTION_H_
