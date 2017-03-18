#ifndef  __HELISCENE_H_
#define __HELISCENE_H_

#include "HeliScene_Moon.h"
#include "HeliScene_Sea.h"
#include "HeliScene_Sky.h"
#include "HeliScene_Helicopter.h"


class HeliSceneClass {
	MoonClass m_MoonC;
	SeaClass m_SeaC;
	SkyClass m_SkyC;
	HelicopterClass m_HeliC;

public:
	HeliSceneClass()  {};

	void Mouse() {}
	void Key() {}
	void Camera() {}

	void LoadScene();
	void Update();
	void Render();
};
#endif // ! __HELISCENE_H_




//#pragma once
