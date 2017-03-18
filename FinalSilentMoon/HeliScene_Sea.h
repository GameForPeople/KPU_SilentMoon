//#pragma once
#ifndef __HELISCENE_Sea_
#define __HELISCENE_Sea_

#include "TextureLib.h"

struct SeaPos {
	float x;
	float y;
	float z;
};

class SeaClass {
	CTextureLibraray m_img;
	SeaPos m_pos;
	float m_size;		// ÇÃ·§ Å©±â

public:
	SeaClass() {
		m_size = 160000;
		m_pos.x = - m_size / 2;
		m_pos.y = 0;
		m_pos.z = m_size / 2;
	}
	void TransSea(float x, float y, float z) {
		m_pos.x = x;
		m_pos.y = y;
		m_pos.z = z;
	}
	void Upload() {
		m_pos.z = m_pos.z - 50;
	}
	void Load() {
		glClearColor(0.f, 0.f, 0.f, 1.f);

		m_img.SetTexture(L"Image/HeliScene/SeaTexture.png");
	}

	void Render() {
		glPushMatrix();
		{
			glTranslatef(m_pos.x, m_pos.y, m_pos.z);
			glRotatef(-90, 1, 0, 0);
			//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1.f, 1.f, 1.f, 1.f);

			m_img.LoadTexture(0);

			CTextureLibraray::UsingTexture2D();
			{
				for (int i = 0; i < 10; i++) {
					glBegin(GL_QUADS);
					{
						glTexCoord2f(+0.0f, +10000.0f);					glVertex2f(0.0f, 0.0f);
						glTexCoord2f(+0.0f, +0.0f);					glVertex2f(0.0f, m_size * 2000);
						glTexCoord2f(+5.0f, +0.0f);					glVertex2f(m_size, m_size * 2000);
						glTexCoord2f(+5.0f, +10000.0f);					glVertex2f(m_size, 0.0f);
					}
					glEnd();

					glTranslatef(0, 0, 319920000 * i);
				}

			}
			CTextureLibraray::StopUsingTexture2D();
		}
		glPopMatrix();
	}
};
#endif // !__HELISCENE_MOON_
