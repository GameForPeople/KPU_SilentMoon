//#pragma once
#ifndef __RENDERINGMAIN_H_
#define __RENDERINGMAIN_H_

#define ONOFF_GRID 1	// �׸����� ON OFF, �۾� �ÿ��� 1 �ÿ��ÿ��� 0
class RenderClass {
	int m_sceneSelect;	//����� ������ �ִ� ����
	int m_onoffGrid;	//�׸��� (�۾���) ���ִ� ����
public:
	RenderClass() : m_sceneSelect(0), m_onoffGrid(ONOFF_GRID) {};
	 ~ RenderClass() {};

	 void RenderMain();
	 void DrawGrid();
};
#endif // !__RENDERINGMAIN_H__
