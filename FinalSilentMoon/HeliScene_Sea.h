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
		m_pos.x = 0;
		m_pos.y = 0;
		m_pos.z = 0;
		m_size = 10000;
	}
	void TransSea(float x, float y, float z) {
		m_pos.x = x;
		m_pos.y = y;
		m_pos.z = z;
	}
	void Upload() {

	}
	void Load() {
		glClearColor(0.f, 0.f, 0.f, 1.f);

		m_img.SetTexture(L"Image/HeliScene/SeaTexture.png");
	}

	void Render() {
		glPushMatrix();
		{
			glTranslatef(m_pos.x, m_pos.y, m_pos.z);
			glRotatef(-80, 1, 0, 0);
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
#endif // !__HELISCENE_MOON_
