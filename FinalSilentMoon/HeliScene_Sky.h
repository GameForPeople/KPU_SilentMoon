//#pragma once
#ifndef __HELISCENE_SKY_H_
#define __HELISCENE_SKY_H_

#include "TextureLib.h"

struct SkyPos {
	float x;
	float y;
	float z;
};

class SkyClass {
	CTextureLibraray m_img;
	SkyPos m_pos;
	float m_size;		// ÇÃ·§ Å©±â

public:
	SkyClass() {
		m_size = 1000;
		m_pos.x = -m_size / 2;
		m_pos.y = 0;
		m_pos.z = 500;
	}
	void TransSky(float x, float y, float z) {
		m_pos.x = x;
		m_pos.y = y;
		m_pos.z = z;
	}
	void Upload() {

	}
	void Load() {
		glClearColor(0.f, 0.f, 0.f, 1.f);

		m_img.SetTexture(L"Image/HeliScene/SkyTexture.png");
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
	}
};
#endif // ! __HELOSCENE_SKY_H_


