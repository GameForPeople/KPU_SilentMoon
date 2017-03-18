#include <iostream>
#include "LogoScene.h"
#include "glut.h"

#define SIZE_X 1280
#define SIZE_Y 720

void LogoSceneClass::Update(){

	if (m_textNum < 2) {
		m_fFadein += 0.05 * m_light;	//float 형변환 되는지 확인
		if (m_fFadein > 1.48 && m_light == 1) {
			m_light = -m_light;
		}
		else if (m_fFadein < 0.02 && m_light == -1) {
			m_light = -m_light;
			m_textNum++;
		}
	}

	else if (m_textNum >= 2 && m_textNum < 4) {		
		if (m_textNum == 2) {
			m_fFadein += 0.025 * m_light;	//float 형변환 되는지 확인
			if (m_fFadein >= 1.0) {
				m_textNum = 3;
				m_fFadein = 0.1f;
				m_light = 1;
			}
		}
		else if (m_textNum == 3) {
			m_fFadein += 0.05 * m_light;	//float 형변환 되는지 확인
			if (m_fFadein >= 1.5 && m_light == 1) {
				m_light = -1;
			}
			else if (m_fFadein <= - 1.00 && m_light == -1) {
				m_light = -m_light;
				m_textNum++;
			}
		}
	}

	else if (m_textNum >= 4 && m_textNum < 7) {
		if (m_textNum == 4) {
			m_fFadein += 0.05 * m_light;	//float 형변환 되는지 확인
			if (m_fFadein >= 1.0) {
				m_textNum = 5;
				m_fFadein = 0.1f;
				m_light = 1;
			}
		}
		else if (m_textNum == 5 || m_textNum == 6) {
			m_fFadein += 0.04 * m_light;	//float 형변환 되는지 확인
			if (m_fFadein >= 1.5 && m_light == 1) {
				m_light = -1;
			}
			else if (m_textNum == 5 && m_fFadein <= 0.05 && m_light == -1) {
				m_light = -m_light;
				m_textNum++;
			}
			else if (m_textNum == 6 && m_fFadein <= - 1.00 && m_light == -1) {
				m_light = -m_light;
				m_textNum++;
			}
		}
	}
}

void LogoSceneClass::LoadScene()
{
	glClearColor(0.f, 0.f, 0.f, 1.f);

	m_textNum = 0;

	m_Logo.SetTexture(L"Image/LogoScene/warpLogo.png");
	m_Logo2.SetTexture(L"Image/LogoScene/GFP.png");
	m_Logo3.SetTexture(L"Image/LogoScene/StoryImg_1.png");
	m_Logo4.SetTexture(L"Image/LogoScene/StoryImg_2.png");
	m_Logo4_Mask.SetTexture(L"Image/LogoScene/StoryImg_2_Mask.png");

	m_Logo5.SetTexture(L"Image/LogoScene/StoryImg_3.png");
	m_Logo5_Mask.SetTexture(L"Image/LogoScene/StoryImg_3_Mask.png");

	m_Logo6.SetTexture(L"Image/LogoScene/StoryImg_4.png");
	m_Logo7.SetTexture(L"Image/LogoScene/StoryImg_5.png");
}

void LogoSceneClass::Render() {
	GLfloat windowX = SIZE_X;
	GLfloat windowY = SIZE_Y;
	glEnable(GL_BLEND);

	if (m_textNum == 0) {
		glPushMatrix();
		{
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1.f, 1.f, 1.f, min(m_fFadein, 1.f));
			
			m_Logo.LoadTexture(0);

			CTextureLibraray::UsingTexture2D();
			{
				glBegin(GL_QUADS);
				{
					glTexCoord2f(+0.0f, +1.0f);					glVertex2f(0.0f, 0.0f);
					glTexCoord2f(+0.0f, +0.0f);					glVertex2f(0.0f, windowY);
					glTexCoord2f(+1.0f, +0.0f);					glVertex2f(windowX, windowY);
					glTexCoord2f(+1.0f, +1.0f);					glVertex2f(windowX, 0.0f);
				}
				glEnd();
			}
			CTextureLibraray::StopUsingTexture2D();
		}
		glPopMatrix();
	}
	else if (m_textNum == 1) {
		glPushMatrix();
		{
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1.f, 1.f, 1.f, min(m_fFadein, 1.f));

			m_Logo2.LoadTexture(0);

			CTextureLibraray::UsingTexture2D();
			{
				glBegin(GL_QUADS);
				{
					glTexCoord2f(+0.0f, +1.0f);					glVertex2f(0.0f, 0.0f);
					glTexCoord2f(+0.0f, +0.0f);					glVertex2f(0.0f, windowY);
					glTexCoord2f(+1.0f, +0.0f);					glVertex2f(windowX, windowY);
					glTexCoord2f(+1.0f, +1.0f);					glVertex2f(windowX, 0.0f);
				}
				glEnd();
			}
			CTextureLibraray::StopUsingTexture2D();
		}
		glPopMatrix();
	}
	else if (m_textNum == 2) {
		glPushMatrix();
		{
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1.f, 1.f, 1.f, min(m_fFadein, 1.f));

			m_Logo3.LoadTexture(0);

			CTextureLibraray::UsingTexture2D();
			{
				glBegin(GL_QUADS);
				{
					glTexCoord2f(+0.0f, +1.0f);					glVertex2f(0.0f, 0.0f);
					glTexCoord2f(+0.0f, +0.0f);					glVertex2f(0.0f, windowY);
					glTexCoord2f(+1.0f, +0.0f);					glVertex2f(windowX, windowY);
					glTexCoord2f(+1.0f, +1.0f);					glVertex2f(windowX, 0.0f);
				}
				glEnd();
			}
			CTextureLibraray::StopUsingTexture2D();
		}
		glPopMatrix();
	}
	else if (m_textNum == 3) {
		glPushMatrix();	// 여기는 뒤에 이미지를 100으로 깐후에 글자만 비춰줍니다.
		{
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			if (m_light == 1)
				glColor4f(1.f, 1.f, 1.f, 1.0f);
			else if (m_light == -1)
				glColor4f(1.f, 1.f, 1.f, m_fFadein + 1.0f);// min(m_fFadein, 1.f));

			m_Logo4_Mask.LoadTexture(0);

			CTextureLibraray::UsingTexture2D();
			{
				glBegin(GL_QUADS);
				{
					glTexCoord2f(+0.0f, +1.0f);					glVertex2f(0.0f, 0.0f);
					glTexCoord2f(+0.0f, +0.0f);					glVertex2f(0.0f, windowY - 80);
					glTexCoord2f(+1.0f, +0.0f);					glVertex2f(windowX, windowY - 80);
					glTexCoord2f(+1.0f, +1.0f);					glVertex2f(windowX, 0.0f);
				}
				glEnd();
			}
			CTextureLibraray::StopUsingTexture2D();

			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1.f, 1.f, 1.f, min(m_fFadein, 1.f));

			m_Logo4.LoadTexture(0);

			CTextureLibraray::UsingTexture2D();
			{
				glBegin(GL_QUADS);
				{
					glTexCoord2f(+0.0f, +1.0f);					glVertex2f(0.0f, 0.0f);
					glTexCoord2f(+0.0f, +0.0f);					glVertex2f(0.0f, windowY);
					glTexCoord2f(+1.0f, +0.0f);					glVertex2f(windowX, windowY);
					glTexCoord2f(+1.0f, +1.0f);					glVertex2f(windowX, 0.0f);
				}
				glEnd();
			}
			CTextureLibraray::StopUsingTexture2D();
		}
		glPopMatrix();
	}
	else if (m_textNum == 4) {
		glPushMatrix();
		{
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1.f, 1.f, 1.f, min(m_fFadein, 1.f));

			m_Logo5.LoadTexture(0);

			CTextureLibraray::UsingTexture2D();
			{
				glBegin(GL_QUADS);
				{
					glTexCoord2f(+0.0f, +1.0f);					glVertex2f(0.0f, 0.0f);
					glTexCoord2f(+0.0f, +0.0f);					glVertex2f(0.0f, windowY);
					glTexCoord2f(+1.0f, +0.0f);					glVertex2f(windowX, windowY);
					glTexCoord2f(+1.0f, +1.0f);					glVertex2f(windowX, 0.0f);
				}
				glEnd();
			}
			CTextureLibraray::StopUsingTexture2D();
		}
		glPopMatrix();
	}
	else if (m_textNum == 5) {
		glPushMatrix();
		{
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1.f, 1.f, 1.f, 1.f);//min(m_fFadein, 1.f));

			m_Logo5_Mask.LoadTexture(0);

			CTextureLibraray::UsingTexture2D();
			{
				glBegin(GL_QUADS);
				{
					glTexCoord2f(+0.0f, +1.0f);					glVertex2f(0.0f, 0.0f);
					glTexCoord2f(+0.0f, +0.0f);					glVertex2f(0.0f, windowY -80);
					glTexCoord2f(+1.0f, +0.0f);					glVertex2f(windowX, windowY - 80);
					glTexCoord2f(+1.0f, +1.0f);					glVertex2f(windowX, 0.0f);
				}
				glEnd();
			}
			CTextureLibraray::StopUsingTexture2D();

			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1.f, 1.f, 1.f, min(m_fFadein, 1.f));

			m_Logo6.LoadTexture(0);

			CTextureLibraray::UsingTexture2D();
			{
				glBegin(GL_QUADS);
				{
					glTexCoord2f(+0.0f, +1.0f);					glVertex2f(0.0f, 0.0f);
					glTexCoord2f(+0.0f, +0.0f);					glVertex2f(0.0f, windowY);
					glTexCoord2f(+1.0f, +0.0f);					glVertex2f(windowX, windowY);
					glTexCoord2f(+1.0f, +1.0f);					glVertex2f(windowX, 0.0f);
				}
				glEnd();
			}
			CTextureLibraray::StopUsingTexture2D();

		}
		glPopMatrix();
	}
	else if (m_textNum == 6) {
		glPushMatrix();
		{
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1.f, 1.f, 1.f, m_fFadein + 1.f);//min(m_fFadein, 1.f));

			m_Logo5_Mask.LoadTexture(0);

			CTextureLibraray::UsingTexture2D();
			{
				glBegin(GL_QUADS);
				{
					glTexCoord2f(+0.0f, +1.0f);					glVertex2f(0.0f, 0.0f);
					glTexCoord2f(+0.0f, +0.0f);					glVertex2f(0.0f, windowY - 80);
					glTexCoord2f(+1.0f, +0.0f);					glVertex2f(windowX, windowY - 80);
					glTexCoord2f(+1.0f, +1.0f);					glVertex2f(windowX, 0.0f);
				}
				glEnd();
			}
			CTextureLibraray::StopUsingTexture2D();

			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4f(1.f, 1.f, 1.f, min(m_fFadein, 1.f));

			m_Logo7.LoadTexture(0);

			CTextureLibraray::UsingTexture2D();
			{
				glBegin(GL_QUADS);
				{
					glTexCoord2f(+0.0f, +1.0f);					glVertex2f(0.0f, 0.0f);
					glTexCoord2f(+0.0f, +0.0f);					glVertex2f(0.0f, windowY);
					glTexCoord2f(+1.0f, +0.0f);					glVertex2f(windowX, windowY);
					glTexCoord2f(+1.0f, +1.0f);					glVertex2f(windowX, 0.0f);
				}
				glEnd();
			}
			CTextureLibraray::StopUsingTexture2D();

		}
		glPopMatrix();
	}
}

