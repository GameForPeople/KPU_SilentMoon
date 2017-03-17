#include <iostream>
#include "RenderingMain.h"

#include "glut.h"

void RenderClass::RenderMain(LogoSceneClass *logo, HeliSceneClass *Heli) {
	switch (m_sceneNow) {
	case 1:
		logo->Render();
		break;
	case 2:
		Heli->Render();
		break;
	}

	if (m_onoffGrid)
		DrawGrid();
}

void RenderClass::DrawGrid() {
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(50, 0, 0);
	glColor3f(0, 1, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 50, 0);
	glColor3f(0, 0, 1);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 50);
	glEnd();
}