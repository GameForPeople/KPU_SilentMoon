//#pragma once
#ifndef __RENDERINGMAIN_H_
#define __RENDERINGMAIN_H_

#include "LogoScene.h"
#include "HeliScene.h"

#define ONOFF_GRID 1	// �׸����� ON OFF, �۾� �ÿ��� 1 �ÿ��ÿ��� 0

class RenderClass {
	int m_sceneNow;	//����� ������ �ִ� ����
	int m_onoffGrid;	//�׸��� (�۾���) ���ִ� ����
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
