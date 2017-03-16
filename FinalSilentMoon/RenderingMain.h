//#pragma once
#ifndef __RENDERINGMAIN_H_
#define __RENDERINGMAIN_H_

#define ONOFF_GRID 1	// 그리드의 ON OFF, 작업 시에는 1 시연시에는 0
class RenderClass {
	int m_sceneSelect;	//장면을 결정해 주는 변수
	int m_onoffGrid;	//그리드 (작업용) 켜주는 변수
public:
	RenderClass() : m_sceneSelect(0), m_onoffGrid(ONOFF_GRID) {};
	 ~ RenderClass() {};

	 void RenderMain();
	 void DrawGrid();
};
#endif // !__RENDERINGMAIN_H__
