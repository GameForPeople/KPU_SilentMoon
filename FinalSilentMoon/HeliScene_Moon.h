//#pragma once
#ifndef __HELISCENE_MOON_
#define __HELISCENE_MOON_

#include "TextureLib.h"

struct MoonPos {
	float x;
	float y;
	float z;
};

class MoonShadowClass {
private:
	GLfloat ctrlpoints[20][10][3]{ 0 };
	MoonPos m_pos;
	float m_quadDis; //= 5;
	float m_quadCount; //= 200;				//이거 필요없는데 ㅡㅡ 너무많이껴서 버릴수가없어
	float m_type; //= 2;
	float m_waveHValue; //= 1;
	float m_allHeight; //= 0;				//파도넘실넘실효과줄거야!
	float m_heightType; //= 0;

	bool m_initOnoff; //= true;

public:
	MoonShadowClass() {
		m_quadDis = 5;
		m_quadCount= 200;				//이거 필요없는데 ㅡㅡ 너무많이껴서 버릴수가없어
		m_type= 2;
		m_waveHValue= 1;
		m_allHeight= 0;				//파도넘실넘실효과줄거야!
		m_heightType= 0;

		m_initOnoff= true;	
	};
	~MoonShadowClass() {};

	void SetWavePos(float x, float y, float z) {
		const float heliHeight = 500;

		m_pos.x = x;
		m_pos.y = y + heliHeight;
		m_pos.z = z;

		m_pos.x -= m_quadDis * m_quadCount / 2;
		m_pos.z -= 8 * m_quadDis * m_quadCount / 2;			//속지마! 사실상 매직넘버 ㅎ
	}
	void initWave() {
		if (m_initOnoff)				//최적화를 위하여
		{
			for (int i = 0; i < 20; i++)
			{
				if (i == 0 || i == 9)
					m_waveHValue = -200;
				else if (i == 2 || i == 5)
					m_waveHValue = -250;
				else if (i == 1 || i == 3 || i == 7)
					m_waveHValue = 100;

				for (int j = 0; j < 10; j++)
				{
					ctrlpoints[i][j][0] = (m_quadDis * m_quadCount / 10 * j);
					ctrlpoints[i][j][1] = m_waveHValue;
					ctrlpoints[i][j][2] = (m_quadDis * m_quadCount / 10 * i);

					if (j == 3 || j == 6) {
						ctrlpoints[i][j][1] += 150;
					}
					else if (j == 0 || j == 9) {
						ctrlpoints[i][j][1] -= 200;
					}
				}
			}
			m_initOnoff = false;
		}
	}
	void UpdateWave() {
		if (m_heightType == 0) {
			m_allHeight += 2;

			if (m_allHeight == 10) {
				m_heightType = 1;
			}
		}
		else if (m_heightType == 1) {
			m_allHeight -= 2;

			if (m_allHeight == -8) {
				m_heightType = 0;
			}
		}
	}
	void RenderWave() {
			glPushMatrix();

			glTranslatef(m_pos.x, m_pos.y + m_allHeight, m_pos.z);

			glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 10, 0.0, 1.0, 30, 10, &ctrlpoints[0][0][0]);
			glEnable(GL_MAP2_VERTEX_3);

			glMapGrid2f(100, 0.0, 1.0, 100, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0, 100, 0, 100);

			glPointSize(2.0);

			glColor3f((float)(103 / 255), 0.8f, 1);
			//SetColor(103, 203, 255);
			glPopMatrix();
	}
};

class MoonClass {
	MoonShadowClass m_MoonShadowC;
	CTextureLibraray m_img;
	MoonPos m_pos;
	float m_size;		// 플랫 크기

public:
	MoonClass() {
		m_size = 300;
		m_pos.x = - m_size / 2;
		m_pos.y = 0;
		m_pos.z = 0;

		m_MoonShadowC.initWave();
		m_MoonShadowC.SetWavePos(0, 0, 0);
	}
	void TransMoon(float x, float y, float z) {
		m_pos.x = x;
		m_pos.y = y;
		m_pos.z = z;
	}

	void Upload() {
		m_MoonShadowC.UpdateWave();
	}

	void Load() {
		glClearColor(0.f, 0.f, 0.f, 1.f);

		m_img.SetTexture(L"Image/HeliScene/MoonTexture.png");
	}

	void Render() {
			glPushMatrix();
			{
				glTranslatef(m_pos.x, m_pos.y, m_pos.z);

				//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glColor4f(1.f, 1.f, 1.f, 1.f);

				m_img.LoadTexture(0);

				CTextureLibraray::UsingTexture2D();
				{
					glBegin(GL_QUADS);
					{
						glTexCoord2f(+0.0f, +1.0f);					glVertex2f(0.0f, 0.0f);
						glTexCoord2f(+0.0f, +0.0f);					glVertex2f(0.0f, m_size);
						glTexCoord2f(+1.0f, +0.0f);					glVertex2f(m_size, m_size);
						glTexCoord2f(+1.0f, +1.0f);					glVertex2f(m_size, 0.0f);
					}
					glEnd();
				}
				CTextureLibraray::StopUsingTexture2D();
			}
			glPopMatrix();

			m_MoonShadowC.RenderWave();
	}
};
#endif // !__HELISCENE_MOON_
