#include <iostream>
#include "HeliScene.h"

#define WING_ROTATE_SPEED 10

void HeliSceneClass::Render() {
	m_MoonC.Render();
	m_SeaC.Render();
	m_SkyC.Render();
	m_HeliC.Render();
}

void HeliSceneClass::LoadScene() {
	m_MoonC.Load();
	m_SeaC.Load();
	m_SkyC.Load();
}

void HeliSceneClass::Update() {
	m_MoonC.Upload();
	m_SeaC.Upload();
	m_HeliC.UpdateWing(WING_ROTATE_SPEED);
}