//#pragma once
#ifndef  __LOGOSCENE_H_
#define __LOGOSCENE_H_

#include "TextureLib.h"

class LogoSceneClass {
	int m_textNum;
	float m_fFadein;
	int m_light;	//페이드 인인지 아웃인지 결정하는 놈 1일떄는 밝아 -1 일떄는 어두웡
	//------------------------타이틀 로고
	CTextureLibraray m_Logo;
	CTextureLibraray m_Logo2;

	//------------------------스토리 이미지
	CTextureLibraray m_Logo3;
	CTextureLibraray m_Logo4;
	CTextureLibraray m_Logo4_Mask;

	CTextureLibraray m_Logo5;
	CTextureLibraray m_Logo5_Mask;

	CTextureLibraray m_Logo6;
	CTextureLibraray m_Logo7;


public:
	LogoSceneClass() : m_textNum(0), m_fFadein(0.0f), m_light(1) {};

	int GetTextNum() const {
		return m_textNum;
	}
	int GetLight() const {
		return m_light;
	}
	void ChangeTextNum(int n) {
		m_textNum = n;
	}

	void Update();
	void Render();
	void LoadScene();
	void Mouse() {}
	void Key() {}

};
#endif // ! __1SCENELOGO_H_
