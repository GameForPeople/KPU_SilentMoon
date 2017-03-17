//#pragma once
#ifndef __KEYBOARDFUNCTION_H_
#define __KEYBOARDFUNCTION_H_

#include "LogoScene.h"
#include "HeliScene.h"

class KeyboardClass {
	unsigned char m_key;
	int m_specialKey;
	int m_sceneNow;
public:
	KeyboardClass() : m_key(NULL), m_specialKey(NULL), m_sceneNow(0) {};
	~KeyboardClass() {};
	
	void ChangeSceneNow(const int nextScene) {
		this->m_sceneNow = nextScene;
	}

	unsigned char GetKey() const {
		return this->m_key;
	}

	int GetSpceialKey() const {
		return this->m_specialKey;
	}

	void SetKey(const unsigned char insertKey, LogoSceneClass * logo, HeliSceneClass *heli) {
		this->m_key = insertKey;
		KeyFunction(logo, heli);
	}

	void SetSpecialKey(const int insertSpecialKey, LogoSceneClass * logo, HeliSceneClass *heli) {
		this->m_specialKey = insertSpecialKey;
		SpecialKeyFunction(logo, heli);
	}

	void KeyFunction(LogoSceneClass *logo, HeliSceneClass *heli);
	void SpecialKeyFunction(LogoSceneClass * logo, HeliSceneClass *heli);

};
#endif // !__KEYBOARDFUNCTION_H_
