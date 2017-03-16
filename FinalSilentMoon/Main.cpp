//---------------------
//	Silent Moon project
//	원성연
//	170316 ver 0.1
//---------------------
#include <iostream>
#include <time.h>
#include "glut.h"

#include "KeyBoardFunction.h"
#include "MouseFunction.h"
#include "RenderingMain.h"
#include "Timefunction.h"

using namespace std;

#define SIZE_X 1920
#define SIZE_Y 1080
#define SIZE_Z 100
#define PIE 3.141592

#define VIEW_MININUM_DISTANCE 1					//뷰볼륨 최소 거리
#define VIEW_MAXIMUM_DISTANCE 3000				//뷰볼륨 최대 거리 -> 클리핑 영역 관련.
//현재 각도는 100도 입니다!! 
#define SPACE_DISTANCE -1000						//공간을 얼마나 뒤로 밀 것인가.

//-----------------
int VIEW_TYPE = 1;					// 공간..투영??일경우 1, 직각투영(2d)일 경우 2 -> 추후 경사투영도 만들것; 은 안만들꺼얗ㅎㅎㅎㅎ
//-----------------


GLvoid drawScene(GLvoid);
GLvoid Reshape(GLint, GLint);

KeyboardClass KeyC;
MousClass MouseC;
RenderClass RenderC;
TimeClass TimeC;

namespace TOOLs {

	//----draw에다가 훅!
	void TOOLs_DRAW();
	//----스페셜key입력에다가 훅!
	void TOOLs_KEY_SPECIAL(int key);
	//----key입력에다가 훅!
	void TOOLs_KEY(unsigned char key);
	//----시간에다가 훅!
	void TOOLs_TIME();

	typedef class point {
	public:
		float x;
		float y;
		float z;
	}POINT;
	namespace FUNCTION {
		int Function_ONOFF(int onoff_)
		{
			if (!onoff_)
				return 1;
			else if (onoff_ == 1)
				return 2;
			else if (onoff_)
				return 0;
		}
		int Function_ONOFF_SIMPLE(int onoff_)
		{
			if (!onoff_)
				return 1;
			else if (onoff_)
				return 0;
		}
	}using namespace FUNCTION;
	namespace ROTATE {
		int onoff_x = 0, onoff_y = 0, onoff_z = 0;
		float angle_x = 0, angle_y = 0, angle_z = 0;
		void AllRotate() {
			glRotatef(angle_x, 1, 0, 0);
			glRotatef(angle_y, 0, 1, 0);
			glRotatef(angle_z, 0, 0, 1);
		}
		void Rotate_XYZ(float x, float y, float z) {
			glRotatef(x, 1, 0, 0);
			glRotatef(y, 0, 1, 0);
			glRotatef(z, 0, 0, 1);
		}
		void Insert_Key_Rotate(unsigned char key) {
			if (key == 'x' || key == 'X') {
				if (onoff_x == 0) onoff_x = 1;	else onoff_x = 0;
			}

			if (key == 'y' || key == 'Y') {
				if (onoff_y == 0) onoff_y = 1;	else onoff_y = 0;
			}

			if (key == 'z' || key == 'Z') {
				if (onoff_z == 0) onoff_z = 1;	else onoff_z = 0;
			}

			if (key == 'i' || key == 'I') {
				angle_x = 0; angle_y = 0; angle_z = 0;
				onoff_x = 0; onoff_y = 0; onoff_z = 0;
			}
		}
		void Plus_Rotate() {
			if (onoff_x)
				angle_x += 10;
			if (onoff_y)
				angle_y += 10;
			if (onoff_z)
				angle_z += 10;
		}
	}using namespace ROTATE;
	namespace CAMERA {
		int onoff_ZUM = 0;
		int ZUM_value = 0;
		int oldX = 300;
		int oldY = 300;

		void Change_view(unsigned char key) {
			if (key == '+') {
				onoff_ZUM = Function_ONOFF(onoff_ZUM);
			}
		}
		void Change_View_mouse(int x, int y) {
			if (y > SIZE_Y / 2) {
				if (x > oldX)
				{
					angle_z += (x - oldX) / 2;
				}
				else if (x < oldX)
				{
					angle_z -= (oldX - x) / 2;
				}
			}
			else if (y <  SIZE_Y / 2) {
				if (x > oldX)
				{
					angle_z -= (x - oldX) / 2;
				}
				else if (x < oldX)
				{
					angle_z += (oldX - x) / 2;
				}
			}

			if (x <  SIZE_Y / x) {
				if (y > oldY)
				{
					angle_z += (y - oldY) / 2;
				}
				else if (y < oldY)
				{
					angle_z -= (oldY - y) / 2;
				}
			}
			else if (x >  SIZE_Y / x) {
				if (y > oldY)
				{
					angle_z -= (y - oldY) / 2;
				}
				else if (y < oldY)
				{
					angle_z += (oldY - y) / 2;
				}
			}

			if (angle_z > 360)
				angle_z -= 360;
			if (angle_z < 0)
				angle_z += 360;

			oldX = x;
			oldY = y;
		}
		void View_Timer() {
			if (onoff_ZUM == 1)
				ZUM_value += 20;
			else if (onoff_ZUM == 2)
				ZUM_value -= 20;
		}
	}using namespace CAMERA;
	namespace COLOR {
		void SetColor(float x, float y, float z) {
			glColor3f((float)(x / 255), (float)(y / 255), (float)(z / 255));
		}
	}using namespace COLOR;
	namespace UNDER {
		void Draw_Under() {
			SetColor(140, 140, 140);

			glPushMatrix(); {
				glTranslatef(0, -SIZE_Y / 2, 0);
				glScalef(1, (float)1 / (float)20, 1);

				glutSolidCube(SIZE_X * 2);
				SetColor(255, 255, 255);
				glutWireCube(SIZE_X * 2 + 1);
				glPopMatrix();
			}
		}
	}using namespace UNDER;
	namespace BACKGROUND {
		void Draw_back() {
			SetColor(255, 255, 255);
			glutWireCube(SIZE_X * 2);
		}
	}using namespace BACKGROUND;
	namespace GRID {

		void Draw_Grid() {

			glBegin(GL_LINES);
			glColor3f(1, 0, 0);
			glVertex3d(0, 0, 0);
			glVertex3d(50, 0, 0);
			glColor3f(0, 1, 0);
			glVertex3d(0, 0, 0);
			glVertex3d(0, 50, 0);
			glColor3f(0, 0, 1);
			glVertex3d(0, 0, 0);
			glVertex3d(0, 0, 50);

			glEnd();
		}
	}using namespace GRID;
	namespace TIME {
		int Time_Rate = 80;
		void TIME_CHANGE(int key) {
			if (key == GLUT_KEY_UP && Time_Rate > 11)
				Time_Rate -= 10;
			else if (key == GLUT_KEY_DOWN)
				Time_Rate += 10;
		}
	}using namespace TIME;
	namespace MAKE {
		void NormalVector(float(*v)[3], float out[3])
		{
			/* function NormalVector()
			: 점 3개를 받아 해당 삼각형의 normal vector를 구하는 함수
			v[3][3] : (x, y, z) 점 좌표 3개
			out[3] : normal 벡터를 반환받을 벡터 3개
			※ glut함수를 쓰면 느리므로 직접 제작
			*/
			float v1[3], v2[3], length;
			static const int x = 0;
			static const int y = 1;
			static const int z = 2;

			v1[x] = v[0][x] - v[1][x]; v1[y] = v[0][y] - v[1][y]; v1[z] = v[0][z] - v[1][z];
			v2[x] = v[2][x] - v[1][x]; v2[y] = v[2][y] - v[1][y]; v2[z] = v[2][z] - v[1][z];

			out[x] = v1[y] * v2[z] - v1[z] * v2[y];
			out[y] = v1[z] * v2[x] - v1[x] * v2[z];
			out[z] = v1[x] * v2[y] - v1[y] * v2[x];

			length = (float)sqrt(out[x] * out[x] + out[y] * out[y] + out[z] * out[z]);
			if (length == 0.0f)
				length = 1.0f;

			out[x] /= length;
			out[y] /= length;
			out[z] /= length;
		}
		void MakeRing(GLfloat centerx, GLfloat centery, GLfloat centerz, GLfloat radius, GLfloat h, GLfloat thick)
		{
			/* function createRing()
			링의 중심 x,y,z좌표, 반지름, 높이, 두께를 받아 링을 생성하는 함수
			centerx : 링의 중심 x좌표
			centery : 링의 중심 y좌표
			centerz : 링의 중심 z좌표
			radius : 링의 반지름
			h  : 링의 높이
			thick : 링의 두께
			*/
			GLfloat x, y, angle;

			glColor3ub(148, 0, 211);
			glBegin(GL_QUAD_STRIP);           //링의 윗면
			for (angle = (2.0f*PIE); angle > 0.0f; angle -= (PIE / 8.0f))
			{
				x = centerx + radius*sin(angle);
				y = centery + radius*cos(angle);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(x, y, centerz);
				x = centerx + (radius - thick)*sin(angle);
				y = centery + (radius - thick)*cos(angle);
				glVertex3f(x, y, centerz);
			}
			glEnd();

			int color = 0;
			glBegin(GL_QUAD_STRIP);            //링의 바깥쪽 옆면
			for (angle = 0.0f; angle < (2.0f*PIE); angle += (PIE / 8.0f))
			{
				x = centerx + radius*sin(angle);
				y = centery + radius*cos(angle);
				glNormal3f(sin(angle), cos(angle), 0.0f);
				glVertex3f(x, y, centerz);
				glVertex3f(x, y, centerz + h);
				color++;
			}
			glEnd();

			glColor3ub(148, 0, 211);
			glBegin(GL_QUAD_STRIP);            //링의 안쪽 옆면
			for (angle = (2.0f*PIE); angle > 0.0f; angle -= (PIE / 8.0f))
			{
				x = centerx + (radius - thick)*sin(angle);
				y = centery + (radius - thick)*cos(angle);
				glNormal3f(-sin(angle), -cos(angle), 0.0f);
				glVertex3f(x, y, centerz);
				glVertex3f(x, y, centerz + h);
			}
			glEnd();

			glBegin(GL_QUAD_STRIP);           //원기둥의 밑면
			for (angle = 0.0f; angle < (2.0f*PIE); angle += (PIE / 8.0f))
			{
				x = centerx + radius*sin(angle);
				y = centery + radius*cos(angle);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(x, y, centerz + h);
				x = centerx + (radius - thick)*sin(angle);
				y = centery + (radius - thick)*cos(angle);
				glVertex3f(x, y, centerz + h);
			}
			glEnd();
		}
		void MakeCylinder(GLfloat centerx, GLfloat centery, GLfloat centerz, GLfloat radius, GLfloat h)
		{
			/* function createCyliner()
			원기둥의 중심 x,y,z좌표, 반지름, 높이를 받아 원기둥을 생성하는 함수(+z방향으로 원에서 늘어남)
			centerx : 원기둥 원의 중심 x좌표
			centery : 원기둥 원의 중심 y좌표
			centerz : 원기둥 원의 중심 z좌표
			radius : 원기둥의 반지름
			h : 원기둥의 높이
			*/
			GLfloat x, y, angle;

			glBegin(GL_TRIANGLE_FAN);           //원기둥의 윗면
			glNormal3f(0.0f, 0.0f, -1.0f);
			glVertex3f(centerx, centery, centerz);

			for (angle = 0.0f; angle < (2.0f*PIE); angle += (PIE / 8.0f))
			{
				x = centerx + radius*sin(angle);
				y = centery + radius*cos(angle);
				glNormal3f(0.0f, 0.0f, -1.0f);
				glVertex3f(x, y, centerz);
			}
			glEnd();

			glBegin(GL_QUAD_STRIP);            //원기둥의 옆면
			for (angle = 0.0f; angle < (2.0f*PIE); angle += (PIE / 8.0f))
			{
				x = centerx + radius*sin(angle);
				y = centery + radius*cos(angle);
				glNormal3f(sin(angle), cos(angle), 0.0f);
				glVertex3f(x, y, centerz);
				glVertex3f(x, y, centerz + h);
			}
			glEnd();

			glBegin(GL_TRIANGLE_FAN);           //원기둥의 밑면
			glNormal3f(0.0f, 0.0f, 1.0f);
			glVertex3f(centerx, centery, centerz + h);
			for (angle = (2.0f*PIE); angle > 0.0f; angle -= (PIE / 8.0f))
			{
				x = centerx + radius*sin(angle);
				y = centery + radius*cos(angle);
				glNormal3f(0.0f, 0.0f, 1.0f);
				glVertex3f(x, y, centerz + h);
			}
			glEnd();
		}

		void Maketree(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat theight)
		{
			/* function tree()
			중심 x, y, z 좌표를 받아 사각뿔의 밑면 길이가 width이고 사각뿔 높이가 height이고 줄기 부분 높이가 theight인 나무 생성
			x : x 좌표
			y : y 좌표
			z : z 좌표
			width : 나무 잎 부분 사각뿔 밑면 길이
			eight : 나무 잎 부분 사각뿔 높이 길이
			theight : 나무 줄기 부분 원기둥 높이
			*/
			float v[3][3];
			float out[3];

			v[0][0] = x; v[0][1] = y; v[0][2] = z;
			v[1][0] = x - width; v[1][1] = y - height; v[1][2] = z - width;
			v[2][0] = x - width; v[2][1] = y - height; v[2][2] = z + width;

			glPushMatrix();
			glTranslated(x, y + height + theight, z);
			glColor3ub(34, 139, 34);

			glBegin(GL_TRIANGLE_FAN);   //나무 윗부분 사각뿔
			NormalVector(v, out);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(x, y, z);
			glNormal3fv(out);
			glVertex3f(x - width, y - height, z - width);
			glNormal3fv(out);
			glVertex3f(x - width, y - height, z + width);
			v[1][0] = x - width; v[1][1] = y - height; v[1][2] = z + width;
			v[2][0] = x + width; v[2][1] = y - height; v[2][2] = z - width;
			NormalVector(v, out);

			glNormal3fv(out);
			glVertex3f(x + width, y - height, z + width);
			v[1][0] = x + width; v[1][1] = y - height; v[1][2] = z + width;
			v[2][0] = x + width; v[2][1] = y - height; v[2][2] = z - width;
			NormalVector(v, out);

			glNormal3fv(out);
			glVertex3f(x + width, y - height, z - width);
			v[1][0] = x + width; v[1][1] = y - height; v[1][2] = z - width;
			v[2][0] = x - width; v[2][1] = y - height; v[2][2] = z - width;
			NormalVector(v, out);

			glNormal3fv(out);
			glVertex3f(x - width, y - height, z - width);
			glEnd();

			glBegin(GL_QUADS);       //사각뿔 밑면
			glNormal3f(0.0f, -1.0f, 0.0f);
			glVertex3f(x - width, y - height, z - width);
			glVertex3f(x + width, y - height, z - width);
			glVertex3f(x + width, y - height, z + width);
			glVertex3f(x - width, y - height, z + width);
			glEnd();

			glTranslatef(x, y - height, z);
			glRotated(90.0f, 1.0f, 0.0f, 0.0f);
			MakeCylinder(0.0f, 0.0f, 0.0f, 10.0f, theight);  //나무 원기둥 함수
			glPopMatrix();
		}
		void MakeChair(GLfloat x, GLfloat y, GLfloat z, GLfloat thick, GLfloat width, GLfloat height)
		{
			/* function createChair()
			의자 왼쪽 위 끝 x,y,z좌표, 등받이 높이, 앉는부분 길이를 받아 의자를 생성하는 함수
			x : 의자 왼쪽 위 끝 x좌표
			y : 의자 왼쪽 위 끝 y좌표
			z : 의자 오른쪽 위 끝 z좌표
			thick : 의자 두께
			width : 의자 가로길이
			height : 의자 세로길이
			*/
			glColor3ub(0, 0, 0);
			glBegin(GL_QUADS);
			glNormal3f(-1.0f, 0.0f, 0.0f);   //등받이 왼쪽 옆면
			glVertex3f(x, y, z);
			glVertex3f(x + thick, y, z);
			glVertex3f(x + thick, y + height, z);
			glVertex3f(x, y + height, z);

			glNormal3f(0.0f, 0.0f, 1.0f);   //등받이 앞면
			glVertex3f(x + thick, y, z);
			glVertex3f(x + thick, y, z + width);
			glVertex3f(x + thick, y + height, z + width);
			glVertex3f(x + thick, y + height, z);

			glNormal3f(1.0f, 0.0f, 0.0f);   //등받이 오른쪽 옆면
			glVertex3f(x + thick, y, z + width);
			glVertex3f(x, y, z + width);
			glVertex3f(x, y + height, z + width);
			glVertex3f(x + thick, y + height, z + width);

			glNormal3f(0.0f, 0.0f, -1.0f);   //등받이 뒷면
			glVertex3f(x, y, z + width);
			glVertex3f(x, y, z);
			glVertex3f(x, y + height + thick, z);
			glVertex3f(x, y + height + thick, z + width);

			glNormal3f(0.0f, 1.0f, 0.0f);   //등받이 윗면
			glVertex3f(x, y, z);
			glVertex3f(x, y, z + width);
			glVertex3f(x + thick, y, z + width);
			glVertex3f(x + thick, y, z);

			glNormal3f(0.0f, 1.0f, 0.0f);   //앉는 부분 윗면
			glVertex3f(x, y + height, z);
			glVertex3f(x, y + height, z + width);
			glVertex3f(x + height, y + height, z + width);
			glVertex3f(x + height, y + height, z);

			glNormal3f(-1.0f, 0.0f, 0.0f);   //앉는 부분 왼쪽 옆면
			glVertex3f(x, y + height, z);
			glVertex3f(x + height, y + height, z);
			glVertex3f(x + height, y + height + thick, z);
			glVertex3f(x, y + height + thick, z);
			glNormal3f(0.0f, 0.0f, -1.0f);   //앉는 부분 앞쪽
			glVertex3f(x + height, y + height, z);
			glVertex3f(x + height, y + height, z + width);
			glVertex3f(x + height, y + height + thick, z + width);
			glVertex3f(x + height, y + height + thick, z);

			glNormal3f(1.0f, 0.0f, 0.0f);   //앉는 부분 오른쪽 옆면
			glVertex3f(x, y + height, z + width);
			glVertex3f(x, y + height + thick, z + width);
			glVertex3f(x + height, y + height + thick, z + width);
			glVertex3f(x + height, y + height, z + width);

			glNormal3f(0.0f, -1.0f, 0.0f);   //앉는 부분 밑면
			glVertex3f(x, y + height + thick, z);
			glVertex3f(x + height, y + height + thick, z);
			glVertex3f(x + height, y + height + thick, z + width);
			glVertex3f(x, y + height + thick, z + width);
			glEnd();
		}
		void MakeShip(GLfloat x, GLfloat y, GLfloat z, GLfloat size)
		{
			/* function createShip()
			중심 (x,y,z)로 부터 z축으로 길게 배 생성, 옆면 길이는 size * 2, 총 길이는 size * 4
			x : x 좌표
			y : y 좌표
			z : z 좌표
			size : 배 크기의 기본단위
			*/
			float v[3][3];
			float out[3];

			glBegin(GL_TRIANGLES);
			glColor3f(0.65f, 0.16f, 0.16f);   //바이킹 뒷 왼쪽 삼각형
			v[0][0] = x - size; v[0][1] = y; v[0][2] = z - size;
			v[1][0] = x; v[1][1] = y; v[1][2] = z - 2 * size;
			v[2][0] = x; v[2][1] = y - size; v[2][2] = z - size;
			NormalVector(v, out);
			glNormal3fv(out);
			glVertex3f(x - size, y, z - size);
			glVertex3f(x, y, z - 2 * size);
			glVertex3f(x, y - size, z - size);

			v[0][0] = x; v[0][1] = y - size; v[0][2] = z + size;
			v[1][0] = x; v[1][1] = y; v[1][2] = z - 2 * size;
			v[2][0] = x - size; v[2][1] = y; v[2][2] = z + size;
			NormalVector(v, out);
			glNormal3fv(out);
			glVertex3f(x, y - size, z + size);  //바이킹 앞 왼쪽 삼각형
			glVertex3f(x, y, z + 2 * size);
			glVertex3f(x - size, y, z + size);

			glColor3f(0.65f, 0.16f, 0.16f);   //바이킹 왼쪽 몸통
			v[0][0] = x; v[0][1] = y - size; v[0][2] = z + size;
			v[1][0] = x - size; v[1][1] = y; v[1][2] = z - size;
			v[2][0] = x; v[2][1] = y - size; v[2][2] = z - size;
			NormalVector(v, out);
			glNormal3fv(out);
			glVertex3f(x, y - size, z + size);
			glVertex3f(x - size, y, z - size);
			glVertex3f(x, y - size, z - size);

			v[0][0] = x - size; v[0][1] = y; v[0][2] = z - size;
			v[1][0] = x; v[1][1] = y - size; v[1][2] = z + size;
			v[2][0] = x - size; v[2][1] = y; v[2][2] = z + size;
			NormalVector(v, out);
			glNormal3fv(out);
			glVertex3f(x - size, y, z - size);
			glVertex3f(x, y - size, z + size);
			glVertex3f(x - size, y, z + size);

			glColor3f(0.65f, 0.16f, 0.16f);   //바이킹 뒷 오른쪽 삼각형
			v[0][0] = x; v[0][1] = y; v[0][2] = z - 2 * size;
			v[1][0] = x + size; v[1][1] = y; v[1][2] = z - size;
			v[2][0] = x; v[2][1] = y - size; v[2][2] = z - size;
			NormalVector(v, out);
			glNormal3fv(out);
			glVertex3f(x, y, z - 2 * size);
			glVertex3f(x + size, y, z - size);
			glVertex3f(x, y - size, z - size);

			v[0][0] = x; v[0][1] = y - size; v[0][2] = z + size;
			v[1][0] = x + size; v[1][1] = y; v[1][2] = z + size;
			v[2][0] = x; v[2][1] = y; v[2][2] = z + 2 * size;
			NormalVector(v, out);
			glNormal3fv(out);
			glVertex3f(x, y - size, z + size);  //바이킹 앞 오른쪽 삼각형
			glVertex3f(x + size, y, z + size);
			glVertex3f(x, y, z + 2 * size);

			glColor3f(0.65f, 0.16f, 0.16f);   //바이킹 오른쪽 몸통
			v[0][0] = x + size; v[0][1] = y; v[0][2] = z - size;
			v[1][0] = x; v[1][1] = y - size; v[1][2] = z + size;
			v[2][0] = x; v[2][1] = y - size; v[2][2] = z - size;
			NormalVector(v, out);
			glNormal3fv(out);
			glVertex3f(x + size, y, z - size);
			glVertex3f(x, y - size, z + size);
			glVertex3f(x, y - size, z - size);

			v[0][0] = x + size; v[0][1] = y; v[0][2] = z - size;
			v[1][0] = x + size; v[1][1] = y; v[1][2] = z + size;
			v[2][0] = x; v[2][1] = y - size; v[2][2] = z + size;
			NormalVector(v, out);
			glNormal3fv(out);
			glVertex3f(x + size, y, z - size);
			glVertex3f(x + size, y, z + size);
			glVertex3f(x, y - size, z + size);
			glEnd();

			glBegin(GL_POLYGON);     //바이킹 갑판
			glColor3f(0.65f, 0.16f, 0.16f);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(x + size, y, z - size);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(x, y, z - 2 * size);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(x - size, y, z - size);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(x - size, y, z + size);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(x, y, z + 2 * size);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(x + size, y, z + size);
			glEnd();
		}
	}using namespace MAKE;
	namespace GLFUNCTION {

		int onoff_HiddenSurface = 1;
		int onoff_Curling = 0;
		int onoff_Shading = 1;

		void GL_FUNCTION_draw() {
			if (onoff_HiddenSurface)
				glEnable(GL_DEPTH_TEST);
			else if (!onoff_HiddenSurface)
				glDisable(GL_DEPTH_TEST);

			if (onoff_Curling)
				glEnable(GL_CULL_FACE);
			else if (!onoff_Curling)
				glDisable(GL_CULL_FACE);

			if (onoff_Shading)
				glShadeModel(GL_SMOOTH);
			else if (!onoff_Shading)
				glShadeModel(GL_FLAT);
		}
		void GL_FUNCTION_Insert(unsigned char key)
		{
			if (key == '1')
			{
				onoff_HiddenSurface = Function_ONOFF_SIMPLE(onoff_HiddenSurface);
				if (onoff_HiddenSurface)
					cout << "은면기능이 활성화 되었습니다." << endl;
				else cout << "은면기능이 비활성화 되었습니다." << endl;
			}
			else if (key == '2')
			{
				onoff_Curling = Function_ONOFF_SIMPLE(onoff_Curling);
				if (onoff_Curling)
					cout << "컬링기능이 활성화 되었습니다." << endl;
				else cout << "컬링기능이 비활성화 되었습니다." << endl;
			}
			else if (key == '3')
				onoff_Shading = Function_ONOFF_SIMPLE(onoff_Shading);
		}

	}using namespace GLFUNCTION;
	namespace VIEWTYPE {
		void VIEWTYPE_Insert(unsigned char key) {
			if (key == '0') {
				if (VIEW_TYPE == 1)
					VIEW_TYPE = 2;
				else if (VIEW_TYPE == 2)
					VIEW_TYPE = 1;

				Reshape(SIZE_X, SIZE_Y);
			}
		}
		void VIEWTYPE_Edit() {
			if (VIEW_TYPE == 1) {
				//입체..투영??
				gluPerspective(100.0f, SIZE_X / SIZE_Y, VIEW_MININUM_DISTANCE, VIEW_MAXIMUM_DISTANCE);
				glTranslatef(0.0, 0.0, SPACE_DISTANCE); // 투영 공간을 화면 안쪽으로 이동하여 시야를 확보한다.
				cout << "투영 방식 - > 입체투영으로 설정되었습니다." << endl;
			}
			else if (VIEW_TYPE == 2) {
				//직각투영
				glOrtho(-1 * (SIZE_X / 2), (SIZE_X / 2), -1 * (SIZE_Y / 2), (SIZE_Y / 2), -1 * (SIZE_Z / 2), SIZE_Z / 2);		// x좌표  Y좌표 Z좌표 모두 - 400 부터 400 까지
				cout << "투영 방식 - > 직각투영으로 설정되었습니다." << endl;
			}
		}
	}using namespace VIEWTYPE;

	void TOOLs_DRAW() {
		AllRotate();
		Draw_back();
		Draw_Under();
		Draw_Grid();
		GL_FUNCTION_draw();
		//VIEWTYPE_Edit();
	}
	void TOOLs_KEY_SPECIAL(int key) {
		TIME_CHANGE(key);
	}
	void TOOLs_KEY(unsigned char key) {
		Insert_Key_Rotate(key);
		Change_view(key);
		GL_FUNCTION_Insert(key);
		VIEWTYPE_Insert(key);
	}
	void TOOLs_TIME() {
		Plus_Rotate();
		View_Timer();
	}
	void TOOLs_MOUSE(int x, int y) {
		Change_View_mouse(x, y);
	}
}using namespace TOOLs;

void Mouse(int button, int state, int x, int y)
{
	MouseC.SetButton(button, state);
}
void Keyboard(unsigned char key, int x, int y)
{
	KeyC.SetKey(key);
}
void SpecialKeyboard(int key, int x, int y)
{
	KeyC.SetSpecialKey(key);
}
void Motion(int x, int y)
{
	MouseC.SetMotion(x, y);
}

void TimerFunction(int value)
{
	glutPostRedisplay(); // 화면 재 출력

	TimeC.TimeFunc();

	glutTimerFunc(TimeC.GetTimer(), TimerFunction, 1); // 타이머함수 재 설정
}
void main()
{
	srand((unsigned)time(NULL));

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(SIZE_X, SIZE_Y);
	glutCreateWindow("project_Silent Moon");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(Reshape);
	glutMouseFunc(Mouse);
	glutSpecialFunc(SpecialKeyboard);
	glutKeyboardFunc(Keyboard);
	glutPassiveMotionFunc(Motion);
	glutTimerFunc(TimeC.GetTimer(), TimerFunction, 1);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}

GLvoid drawScene()
{
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();	// 좌표계 초기화

	glTranslatef(0, 0, 0);

	//TOOLs_DRAW();

	RenderC.RenderMain();

	glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);				//이또한 이를위한 설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (VIEW_TYPE == 1) {
		//입체..투영??
		gluPerspective(100.0f, w / h, VIEW_MININUM_DISTANCE, VIEW_MAXIMUM_DISTANCE);
		glTranslatef(0.0, 0.0, SPACE_DISTANCE); // 투영 공간을 화면 안쪽으로 이동하여 시야를 확보한다.
	}
	else if (VIEW_TYPE == 2) {
		//직각투영
		glOrtho(-1 * (w / 2), (w / 2), -1 * (h / 2), (h / 2), -1 * (SIZE_Z / 2), SIZE_Z / 2);		// x좌표  Y좌표 Z좌표 모두 - 400 부터 400 까지
	}
}
