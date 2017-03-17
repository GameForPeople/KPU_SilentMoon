//#pragma once
#ifndef __TIMEFUNCTION_H_
#define __TIMEFUNCTION_H_

#include "LogoScene.h"
#include "HeliScene.h"

#define TIME_RATE 60 // ���� Ÿ�̸��� ���� 30���� �մϴ�.

class TimeClass {
	int m_timeRate;
	int m_sceneNow;
public:
	TimeClass() : m_timeRate(TIME_RATE) {

	}
	void ChangeSceneNow(const int nextScene) {
		this->m_sceneNow = nextScene;
	}
	int GetTimer() const {
		return this->m_timeRate;
	}
	void SetTimer() {

	}
	void TimeFunc(LogoSceneClass *, HeliSceneClass *);
};

#endif // !__TIMEFUNCTION_H_
