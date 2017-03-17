//#pragma once
#ifndef __DEBUGCAMERAFUNCTION_H_
#define __DEBUGCAMERAFUNCTION_H_

class DebugCameraClass {
	int onoffX; 
	int onoffY; 
	int onoffZ;

	float angleX;
	float angleY;
	float angleZ;

	float disX;
	float disY;
	float disZ;

public:
	DebugCameraClass() : onoffX(0), onoffY(0), onoffZ(0), 
						 angleX (0), angleY(0), angleZ(0), 
						 disX(0), disY(0), disZ(0){
	}

	void Init();
	void AllRotate();
	void AllMove();
	void Key(unsigned char);
	void Update();
};
#endif // !__DEBUGCAMERAFUNCTION_H_
