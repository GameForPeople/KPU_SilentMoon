#include <iostream>
#include "HeliScene.h"

void HeliSceneClass::Render() {
	m_MoonC.Render();
	m_SeaC.Render();
	m_SkyC.Render();
}

void HeliSceneClass::LoadScene() {
	m_MoonC.Load();
	m_SeaC.Load();
	m_SkyC.Load();
}

void HeliSceneClass::Update() {
	m_MoonC.Upload();
}