#ifndef  __HELISCENE_H_
#define __HELISCENE_H_

#include "HeliScene_Moon.h"
#include "HeliScene_Sea.h"
#include "HeliScene_Sky.h"


class HeliSceneClass {
	//HelicopterClass Helic;
	MoonClass m_MoonC;
	SeaClass m_SeaC;
	SkyClass m_SkyC;

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
