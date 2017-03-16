//#pragma once
#ifndef __MOUSEFUNCTION_H_
#define __MOUSEFUNCTION_H_

class PointClass {
public:
	int x;
	int y;
};

class MousClass {
	PointClass m_pos;
	int m_button;
	int m_state;

public:
	int GetButton() const {
		return this->m_button;
	}
	int GetState() const {
		return this->m_state;
	}
	PointClass GetPos() const {
		return this->m_pos;
	}
	void SetButton(const int insertButton, const int insertState) {
		this->m_button = insertButton;
		this->m_state = insertState;
	}
	void SetMotion(const int mothionX, const int mothionY) {
		this->m_pos.x = mothionX;
		this->m_pos.y = mothionY;
	}
};
#endif // !__MOUSEFUNCTION_H_
