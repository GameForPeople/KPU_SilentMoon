//#pragma once
#ifndef __RENDERINGMAIN_H_
#define __RENDERINGMAIN_H_

#include "LogoScene.h"
#include "HeliScene.h"

#define ONOFF_GRID 1	// 그리드의 ON OFF, 작업 시에는 1 시연시에는 0

class RenderClass {
	int m_sceneNow;	//장면을 결정해 주는 변수
	int m_onoffGrid;	//그리드 (작업용) 켜주는 변수
public:
	RenderClass() : m_sceneNow(0), m_onoffGrid(ONOFF_GRID) {};
	 ~ RenderClass() {};

	 void ChangeSceneNow(const int nextScene) {
		 this->m_sceneNow = nextScene;
	 }

	 void RenderMain(LogoSceneClass *, HeliSceneClass *);
	 void DrawGrid();
};
#endif // !__RENDERINGMAIN_H__
