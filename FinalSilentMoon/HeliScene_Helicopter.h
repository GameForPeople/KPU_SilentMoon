#ifndef __HELISCENE_HELICOPTER_H_
#define __HELISCENE_HELICOPTER_H_

#define HELI_HEIGHT 100
#define HELI_POS_Z 100


struct HeliPos {
	float x;
	float y;
	float z;
};

class HelicopterClass {
	HeliPos m_pos;
	float m_sizeX;
	float m_sizeY;
	float m_sizeZ;

	int m_wingStyle;
	float m_wingAngle;

public:
	HelicopterClass() {
		m_pos = { 0, HELI_HEIGHT, HELI_POS_Z };

		m_sizeX = 30;
		m_sizeY = 30;
		m_sizeZ = 70;

		m_wingStyle = 1;
		m_wingAngle = 0;
	};
	~HelicopterClass() {
	};

	void MovePosition(float x, float y, float z) {
		m_pos = { x, y, z };
	}
	void UpdateWing(float speed)
	{
		m_wingAngle += speed;
		if (m_wingAngle > 90)
			m_wingAngle -= 90;
	}
	void Render();
};

#endif // !__HELISCENE_HELICOPTER_H_