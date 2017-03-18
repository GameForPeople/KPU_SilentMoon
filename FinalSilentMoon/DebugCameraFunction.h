//#pragma once
#ifndef __DEBUGCAMERAFUNCTION_H_
#define __DEBUGCAMERAFUNCTION_H_

class DebugCameraClass {
	int m_onoffX; 
	int m_onoffY; 
	int m_onoffZ;

	float m_angleX;
	float m_angleY;
	float m_angleZ;

	float m_disX;
	float m_disY;
	float m_disZ;

public:
	DebugCameraClass() : m_onoffX(0), m_onoffY(0), m_onoffZ(0),
						 m_angleX (0), m_angleY(0), m_angleZ(0),
						 m_disX(0), m_disY(0), m_disZ(0){
	}
	float GetDisX() const { return m_disX; }
	float GetDisY() const { return m_disY; }
	float GetDisZ() const { return m_disZ; }

	float GetAngleX() const { return m_angleX; }
	float GetAngleY() const { return m_angleY; }
	float GetAngleZ() const { return m_angleZ; }

	void Init();
	void AllRotate();
	void AllMove();
	void Key(unsigned char);
	void Update();
};
#endif // !__DEBUGCAMERAFUNCTION_H_
