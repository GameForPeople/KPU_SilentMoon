
#include <iostream>

#include "HeliScene_Helicopter.h"
#include "FunctionTools.h"
#include "glut.h"

void HelicopterClass::Render() {
	glPushMatrix();
	{
		glEnable(GL_DEPTH_TEST);
		ROTATE::RotateXYZ(0, 180, 0);
		glScalef(30,30,30);
		glTranslatef(m_pos.x, m_pos.y, m_pos.z);
		//������ ����ž�
		glPushMatrix();
		{
			//������ �밡��		//������ �׸��ϱ� ��������... // -> Quads�� �مf�� ���߿� �ѹ� �� �տ� ������!! -> �Ⱥ��ϰŰ�����
			glPushMatrix();
			{
				glTranslatef(0, 0, -m_sizeZ);

				COLOR::SetColor(170, 170, 170);

				//glutSolidSphere(m_sizeY, 10, 10);

				glBegin(GL_QUADS); {

					glVertex3f(-m_sizeX + 10, m_sizeY - 10, -30);
					glVertex3f(-m_sizeX, m_sizeY, 0);
					glVertex3f(m_sizeX, m_sizeY, 0);
					glVertex3f(m_sizeX - 10, m_sizeY - 10, -30);


					glEnd();
				}

			}
			glPopMatrix();

			if (m_wingStyle == 1) {
				//���� �߾�!!!


				glPushMatrix();
				{
					COLOR::SetColor(255, 255, 255);

					//glTranslatef(-3 * m_sizeX, 0, -10);
					//m_wingAngle = 0;

					//�����Ѹ�!!!!
					glPushMatrix();
					{
						glTranslatef(0, m_sizeY + m_sizeY / 2, 0);
						glScalef(1, (float)1 / 5, 1);
						glutSolidSphere(10, 10, 10);
					}
					glPopMatrix();
					//��������!!
					glPushMatrix();
					{
						ROTATE::RotateXYZ(0, m_wingAngle, 0);
						glTranslatef(0, m_sizeY + m_sizeY / 2 - 5, 0);

						COLOR::SetColor(110, 110, 110);

						glBegin(GL_QUADS); {


							glVertex3f(0, 3, 6);
							glVertex3f(5 * m_sizeX, 3, 6);
							glVertex3f(5 * m_sizeX, -3, -6);
							glVertex3f(0, -3, -6);

							glVertex3f(0, -3, 6);
							glVertex3f(-5 * m_sizeX, -3, 6);
							glVertex3f(-5 * m_sizeX, 3, -6);
							glVertex3f(0, 3, -6);

							glVertex3f(6, -3, 0);
							glVertex3f(6, -3, 5 * m_sizeX);
							glVertex3f(-6, 3, 5 * m_sizeX);
							glVertex3f(-6, 3, 0);

							glVertex3f(6, 3, 0);
							glVertex3f(6, 3, -5 * m_sizeX);
							glVertex3f(-6, -3, -5 * m_sizeX);
							glVertex3f(-6, -3, 0);

							glEnd();
						}


					}
					glPopMatrix();
					//���� ���׶��!!
				}
				glPopMatrix();
			}

			/*else if (wing_style == 2) {
			//���� ����!!!
			glPushMatrix();
			{
			SetColor(255, 255, 0);

			glTranslatef(-3 * m_sizeX, 0, -10);
			//m_wingAngle = 0;
			Rotate_XYZ(0, m_wingAngle, 0);

			//�����Ѹ�!!!!
			glPushMatrix();
			{
			glTranslatef(0, m_sizeY + m_sizeY / 2, 0);

			glScalef(1, (float)1 / 5, 1);
			glutSolidSphere(10, 10, 10);
			}
			glPopMatrix();
			//��������!!
			glPushMatrix(); {
			glTranslatef(0, m_sizeY + m_sizeY / 2 - 5, 0);

			SetColor(100, 200, 0);

			glBegin(GL_QUADS); {


			glVertex3f(0, 3, 6);
			glVertex3f(2 * m_sizeX, 3, 6);
			glVertex3f(2 * m_sizeX, -3, -6);
			glVertex3f(0, -3, -6);

			glVertex3f(0, -3, 6);
			glVertex3f(-2 * m_sizeX, -3, 6);
			glVertex3f(-2 * m_sizeX, 3, -6);
			glVertex3f(0, 3, -6);

			glVertex3f(6, -3, 0);
			glVertex3f(6, -3, 2 * m_sizeX);
			glVertex3f(-6, 3, 2 * m_sizeX);
			glVertex3f(-6, 3, 0);

			glVertex3f(6, 3, 0);
			glVertex3f(6, 3, -2 * m_sizeX);
			glVertex3f(-6, -3, -2 * m_sizeX);
			glVertex3f(-6, -3, 0);

			glEnd();
			}

			glPopMatrix();
			}

			//���� ���׶��!!
			glPushMatrix(); {
			glTranslatef(0, m_sizeY + m_sizeY / 2 - 5, 0);

			SetColor(255, 0, 255);

			glBegin(GL_LINE_LOOP); {
			for (int j = 0; j < 20; j++) {
			for (float i = 0; i < 6.28; i += 0.01) {
			glVertex3d(2 * m_sizeX * cos(i), j - 10, 2 * m_sizeX * sin(i));
			glVertex3d(2 * m_sizeX * cos(i + 1), j - 10, 2 * m_sizeX * sin(i + 1));
			}
			}
			glEnd();
			}
			glPopMatrix();
			}

			glPopMatrix();
			}

			//���� ������!!
			glPushMatrix();
			{
			SetColor(255, 255, 0);

			glTranslatef(3 * m_sizeX, 0, 0);

			Rotate_XYZ(0, m_wingAngle, 0);

			//�����Ѹ�!!!!
			glPushMatrix(); {
			glTranslatef(0, m_sizeY + m_sizeY / 2, 0);

			glScalef(1, (float)1 / 5, 1);
			glutSolidSphere(12, 10, 10);

			glPopMatrix();
			}

			//��������!!

			glPushMatrix(); {
			glTranslatef(0, m_sizeY + m_sizeY / 2 - 10, 0);

			SetColor(100, 200, 0);

			glBegin(GL_QUADS); {

			glVertex3f(0, 0, 6);
			glVertex3f(2 * m_sizeX, 0, 6);
			glVertex3f(2 * m_sizeX, 0, -6);
			glVertex3f(0, 0, -6);

			glVertex3f(0, 0, 6);
			glVertex3f(-2 * m_sizeX, 0, 6);
			glVertex3f(-2 * m_sizeX, 0, -6);
			glVertex3f(0, 0, -6);

			glVertex3f(6, 0, 0);
			glVertex3f(6, 0, 2 * m_sizeX);
			glVertex3f(-6, 0, 2 * m_sizeX);
			glVertex3f(-6, 0, 0);

			glVertex3f(6, 0, 0);
			glVertex3f(6, 0, -2 * m_sizeX);
			glVertex3f(-6, 0, -2 * m_sizeX);
			glVertex3f(-6, 0, 0);

			glEnd();
			}

			glPopMatrix();
			}

			//���� ���׶��!!
			glPushMatrix();
			{
			glTranslatef(0, m_sizeY + m_sizeY / 2 - 5, 0);

			SetColor(255, 0, 255);

			glBegin(GL_LINE_LOOP); {
			for (int j = 0; j < 20; j++) {
			for (float i = 0; i < 6.28; i += 0.01) {
			glVertex3d(2 * m_sizeX * cos(i), j - 10, 2 * m_sizeX * sin(i));
			glVertex3d(2 * m_sizeX * cos(i + 1), j - 10, 2 * m_sizeX * sin(i + 1));
			}
			}
			glEnd();
			}
			glPopMatrix();
			}


			glPopMatrix();
			}

			//���뿡�� ���� ��ġ�� ����

			glPushMatrix(); {
			glBegin(GL_QUADS); {

			glVertex3f(-2 * m_sizeX, 0, -m_sizeZ + 10);
			glVertex3f(-3 * m_sizeX, 0, m_sizeZ - 20);
			glVertex3f(-1 * m_sizeX, 0, m_sizeZ - 20);
			glVertex3f(-1 * m_sizeX, 0, -m_sizeZ + 10);


			glEnd();
			}
			glPopMatrix();
			}
			}*/

			COLOR::SetColor(140, 140, 140);

			glPushMatrix();
			{
				//����
				glBegin(GL_QUADS); {
					//����
					{
						// ��
						glVertex3f(-m_sizeX, m_sizeY, m_sizeZ);
						glVertex3f(-m_sizeX, m_sizeY, -m_sizeZ);
						glVertex3f(m_sizeX, m_sizeY, -m_sizeZ);
						glVertex3f(m_sizeX, m_sizeY, m_sizeZ);


						//�Ʒ�
						glVertex3f(-m_sizeX, -m_sizeY, m_sizeZ);
						glVertex3f(-m_sizeX, -m_sizeY, -m_sizeZ);
						glVertex3f(m_sizeX, -m_sizeY, -m_sizeZ);
						glVertex3f(m_sizeX, -m_sizeY, m_sizeZ);

						// ��
						glVertex3f(-m_sizeX, m_sizeY, -m_sizeZ);
						glVertex3f(-m_sizeX, -m_sizeY, -m_sizeZ);
						glVertex3f(-m_sizeX, -m_sizeY, m_sizeZ);
						glVertex3f(-m_sizeX, m_sizeY, m_sizeZ);

						// ����
						glVertex3f(m_sizeX, m_sizeY, -m_sizeZ);
						glVertex3f(m_sizeX, -m_sizeY, -m_sizeZ);
						glVertex3f(m_sizeX, -m_sizeY, m_sizeZ);
						glVertex3f(m_sizeX, m_sizeY, m_sizeZ);

						//back
						glVertex3f(m_sizeX, m_sizeY, -m_sizeZ);
						glVertex3f(-m_sizeX, m_sizeY, -m_sizeZ);
						glVertex3f(-m_sizeX, 0, m_sizeZ);
						glVertex3f(m_sizeX, 0, m_sizeZ);
					}
					glEnd();
				}
			}
			glPopMatrix();

			//���� !!
			glPushMatrix();
			{
				glBegin(GL_QUADS); {

					{

						// ���� �Ʒ� ū ����

						COLOR::SetColor(53, 53, 53);

						glVertex3f(-m_sizeX * 2 / 3, 0,/*m_sizeY,			  */	m_sizeZ);
						glVertex3f(-m_sizeX * 2 / 3 + 12, -m_sizeY / 2,/*m_sizeY - 3/2*m_sizeY,*/m_sizeZ + m_sizeZ * 2);
						glVertex3f(m_sizeX * 2 / 3 - 12, -m_sizeY / 2,/*m_sizeY - 3/2*m_sizeY,*/m_sizeZ + m_sizeZ * 2);
						glVertex3f(m_sizeX * 2 / 3, 0,/*m_sizeY,				*/	m_sizeZ);

						glVertex3f(-m_sizeX * 2 / 3, -m_sizeY, m_sizeZ);
						glVertex3f(-m_sizeX * 2 / 3 + 12, -m_sizeY, m_sizeZ + m_sizeZ * 2);
						glVertex3f(m_sizeX * 2 / 3 - 12, -m_sizeY, m_sizeZ + m_sizeZ * 2);
						glVertex3f(m_sizeX * 2 / 3, -m_sizeY, m_sizeZ);

						glVertex3f(-m_sizeX * 2 / 3, -m_sizeY, m_sizeZ);
						glVertex3f(-m_sizeX * 2 / 3 + 12, -m_sizeY, m_sizeZ + m_sizeZ * 2);
						glVertex3f(-m_sizeX * 2 / 3 + 12, -m_sizeY / 2 /*m_sizeY - 3/2*m_sizeY*/, m_sizeZ + m_sizeZ * 2);
						glVertex3f(-m_sizeX * 2 / 3, 0 /*m_sizeY*/, m_sizeZ);

						glVertex3f(m_sizeX * 2 / 3, -m_sizeY, m_sizeZ);
						glVertex3f(m_sizeX * 2 / 3 - 12, -m_sizeY, m_sizeZ + m_sizeZ * 2);
						glVertex3f(m_sizeX * 2 / 3 - 12, -m_sizeY / 2/*m_sizeY - 3/2*m_sizeY*/, m_sizeZ + m_sizeZ * 2);
						glVertex3f(m_sizeX * 2 / 3, 0/*m_sizeY*/, m_sizeZ);

						// �߰� ���� ����
						COLOR::SetColor(70, 70, 70);

						glVertex3f(-m_sizeX * 1 / 2, m_sizeY / 2,/*m_sizeY,			  */	m_sizeZ);
						glVertex3f(-m_sizeX * 1 / 2 + 12, 0,/*m_sizeY - 3/2*m_sizeY,*/m_sizeZ + m_sizeZ * 3 / 2);
						glVertex3f(m_sizeX * 1 / 2 - 12, 0,/*m_sizeY - 3/2*m_sizeY,*/m_sizeZ + m_sizeZ * 3 / 2);
						glVertex3f(m_sizeX * 1 / 2, m_sizeY / 2,/*m_sizeY,				*/	m_sizeZ);

						glVertex3f(-m_sizeX * 1 / 2, m_sizeY / 2 - m_sizeY, m_sizeZ);
						glVertex3f(-m_sizeX * 1 / 2 + 12, m_sizeY / 2 - m_sizeY, m_sizeZ + m_sizeZ * 3 / 2);
						glVertex3f(m_sizeX * 1 / 2 - 12, m_sizeY / 2 - m_sizeY, m_sizeZ + m_sizeZ * 3 / 2);
						glVertex3f(m_sizeX * 1 / 2, m_sizeY / 2 - m_sizeY, m_sizeZ);

						glVertex3f(-m_sizeX * 1 / 2, m_sizeY / 2 - m_sizeY, m_sizeZ);
						glVertex3f(-m_sizeX * 1 / 2 + 12, m_sizeY / 2 - m_sizeY, m_sizeZ + m_sizeZ * 3 / 2);
						glVertex3f(-m_sizeX * 1 / 2 + 12, 0/*m_sizeY - 3/2*m_sizeY*/, m_sizeZ + m_sizeZ * 3 / 2);
						glVertex3f(-m_sizeX * 1 / 2, m_sizeY / 2/*m_sizeY*/, m_sizeZ);

						glVertex3f(m_sizeX * 1 / 2, m_sizeY / 2 - m_sizeY, m_sizeZ);
						glVertex3f(m_sizeX * 1 / 2 - 12, m_sizeY / 2 - m_sizeY, m_sizeZ + m_sizeZ * 3 / 2);
						glVertex3f(m_sizeX * 1 / 2 - 12, 0/*m_sizeY - 3/2*m_sizeY*/, m_sizeZ + m_sizeZ * 3 / 2);
						glVertex3f(m_sizeX * 1 / 2, m_sizeY / 2/*m_sizeY*/, m_sizeZ);
						//���� �ٱ�!
						//glVertex3f(-m_sizeX + 25, m_sizeY - 25, m_sizeZ + 20);
						//glVertex3f(-m_sizeX + 25, m_sizeY - 25, m_sizeZ + 70);
						//glVertex3f(m_sizeX - 25, m_sizeY - 25, m_sizeZ + 70);
						//glVertex3f(m_sizeX - 25, m_sizeY - 25, m_sizeZ + 20);

						//���� ��

						COLOR::SetColor(35, 35, 35);

						glVertex3f(-m_sizeX * 1, -m_sizeY / 2 + 6, m_sizeZ + m_sizeZ * 7 / 4);
						glVertex3f(-m_sizeX * 3 / 2, -m_sizeY / 2 + 6, m_sizeZ + m_sizeZ * 8 / 4);
						glVertex3f(m_sizeX * 3 / 2, -m_sizeY / 2 + 6, m_sizeZ + m_sizeZ * 8 / 4);
						glVertex3f(m_sizeX * 1, -m_sizeY / 2 + 6, m_sizeZ + m_sizeZ * 7 / 4);

						glVertex3f(-m_sizeX * 1, -m_sizeY / 2, m_sizeZ + m_sizeZ * 7 / 4);
						glVertex3f(-m_sizeX * 3 / 2, -m_sizeY / 2, m_sizeZ + m_sizeZ * 8 / 4);
						glVertex3f(m_sizeX * 3 / 2, -m_sizeY / 2, m_sizeZ + m_sizeZ * 8 / 4);
						glVertex3f(m_sizeX * 1, -m_sizeY / 2, m_sizeZ + m_sizeZ * 7 / 4);

					}

					glEnd();
				}
			}
			glPopMatrix();



		}
		glPopMatrix();

	}
	glPopMatrix();
}