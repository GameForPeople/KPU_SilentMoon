#include <iostream>
#include "DebugCameraFunction.h"
#include "glut.h"

#define DIS_CONTROL 1000

namespace DEBUGCAMERA {
	int Function_ONOFF(int onoff_)
	{
		if (!onoff_)
			return 1;
		else if (onoff_ == 1)
			return 2;
		else
			return 0;
	}
	int Function_ONOFF_SIMPLE(int onoff_)
	{
		if (!onoff_)
			return 1;
		else
			return 0;
	}
};

void DebugCameraClass::AllRotate() {
	glRotatef(m_angleX, 1, 0, 0);
	glRotatef(m_angleY, 0, 1, 0);
	glRotatef(m_angleZ, 0, 0, 1);
}

void DebugCameraClass::AllMove(){
	glTranslatef(m_disX, m_disY, m_disZ);
}

void DebugCameraClass::Init() {
	m_onoffX = 0, m_onoffY = 0, m_onoffZ = 0,
		m_angleX = 0, m_angleY = 0, m_angleZ = 0,
		m_disX = 0, m_disY = 0, m_disZ = 0;
}
void DebugCameraClass::Key(unsigned char keyValue) {
	if (keyValue == 'w') {
		m_disZ += DIS_CONTROL;
	}
	else if (keyValue == 's') {
		m_disZ -= DIS_CONTROL;
	}
	else if (keyValue == 'a') {
		m_disX -= DIS_CONTROL;
	}
	else if (keyValue == 'd') {
		m_disX += DIS_CONTROL;
	}
	else if (keyValue == 'q') {
		m_disY += DIS_CONTROL;
	}
	else if (keyValue == 'e') {
		m_disY -= DIS_CONTROL;
	}
	else if (keyValue == 'x') {
		m_onoffX = DEBUGCAMERA::Function_ONOFF_SIMPLE(m_onoffX);
	}
	else if (keyValue == 'y') {
		m_onoffY = DEBUGCAMERA::Function_ONOFF_SIMPLE(m_onoffY);
	}
	else if (keyValue == 'z') {
		m_onoffZ = DEBUGCAMERA::Function_ONOFF_SIMPLE(m_onoffZ);
	}
	else if (keyValue == 'c') {
		Init();
	}

	std::cout << "X : " << m_disX << ", Y : " << m_disY << ", Z : " << m_disZ 
		<< ", aX : "<< m_angleX << ", aY : " << m_angleY << ", aZ : " << m_angleZ <<std::endl;
}

void DebugCameraClass::Update() {
	if (m_onoffX)
		m_angleX += 5;
	if (m_onoffY)
		m_angleY += 5;
	if (m_onoffZ)
		m_angleZ += 5;
}