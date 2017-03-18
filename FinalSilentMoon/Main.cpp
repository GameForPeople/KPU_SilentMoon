//---------------------
//	Silent Moon project
//	원성연
//	170316 ver 0.1
//---------------------
#include <iostream>
#include <ctime>
#include "glut.h"

#include "KeyBoardFunction.h"
#include "MouseFunction.h"
#include "RenderingMain.h"
#include "Timefunction.h"

#include "LogoScene.h"
#include "HeliScene.h"

#include "DebugCameraFunction.h"

using namespace std;

#define SIZE_X 1280
#define SIZE_Y 720
#define SIZE_Z 100
#define PIE 3.141592

#define VIEW_MININUM_DISTANCE 1					//뷰볼륨 최소 거리
#define VIEW_MAXIMUM_DISTANCE 80000				//뷰볼륨 최대 거리 -> 클리핑 영역 관련.
//현재 각도는 100도 입니다!! 
#define SPACE_DISTANCE -1000						//공간을 얼마나 뒤로 밀 것인가.

//-----------------
int VIEW_TYPE = 2;					// 공간..투영??일경우 1, 직각투영(2d)일 경우 2 -> 추후 경사투영도 만들것; 은 안만들꺼얗ㅎㅎㅎㅎ
//-----------------


GLvoid drawScene(GLvoid);
GLvoid Reshape(GLint, GLint);

KeyboardClass KeyC;
MouseClass MouseC;
RenderClass RenderC;
TimeClass TimeC;

LogoSceneClass LogoSceneC;
HeliSceneClass HeliSceneC;

DebugCameraClass DCameraC;

int nowScene = 0;			// 씐 결정 변수!
// 1 -> LogoScene 2-> HeliScene

void ChangeScene(int nextScene) {
	KeyC.ChangeSceneNow(nextScene);
	MouseC.ChangeSceneNow(nextScene);
	RenderC.ChangeSceneNow(nextScene);
	TimeC.ChangeSceneNow(nextScene);

	switch (nextScene) {
	case 1:
		LogoSceneC.LoadScene();
		break;
	case 2:
		HeliSceneC.LoadScene();
		break;
	}
}
void ControlScene() {
	if (nowScene == 0) {
		nowScene = 1;
		ChangeScene(nowScene);
	}
	else if (nowScene == 1 && LogoSceneC.GetTextNum() == 7) {
		nowScene = 2;
		ChangeScene(nowScene);
		VIEW_TYPE = 1;
		Reshape(SIZE_X, SIZE_Y);
	}
}

void Keyboard(unsigned char key, int x, int y)
{
	KeyC.SetKey(key , &LogoSceneC, &HeliSceneC);
	DCameraC.Key(key);
}
void SpecialKeyboard(int key, int x, int y)
{
	KeyC.SetSpecialKey(key, &LogoSceneC, &HeliSceneC);
}
void Mouse(int button, int state, int x, int y)
{
	MouseC.SetButton(button, state , &LogoSceneC, &HeliSceneC );
}
void Motion(int x, int y)
{
	MouseC.SetMotion(x, y, &LogoSceneC, &HeliSceneC);
}
void TimerFunction(int value)
{
	glutPostRedisplay(); // 화면 재 출력

	ControlScene();

	DCameraC.Update();

	TimeC.TimeFunc(&LogoSceneC, &HeliSceneC);
	glutTimerFunc(TimeC.GetTimer(), TimerFunction, 1); // 타이머함수 재 설정
}
void main()
{
	srand((unsigned)time(NULL));

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
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

	//TOOLs_DRAW();
	
	//DCameraC.AllMove();
	DCameraC.AllRotate();

	if(nowScene == 2)
	{
		gluLookAt(DCameraC.GetDisX(), DCameraC.GetDisY()  , DCameraC.GetDisZ(),
			0.0 + DCameraC.GetDisX(), 0.0 + DCameraC.GetDisY(), 1000.0 + DCameraC.GetDisZ(), 0.0, 1.0, 0.0);
	}

	RenderC.RenderMain(&LogoSceneC, &HeliSceneC);

	glutSwapBuffers();
}
GLvoid Reshape(int w, int h)	// w 값은 SIZE_X, , y값은 SIZE_Y 임
{
	glViewport(0, 0, SIZE_X, SIZE_Y);				//이또한 이를위한 설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (VIEW_TYPE == 1) {
		//입체..투영??
		gluPerspective(90.0f, w / h, VIEW_MININUM_DISTANCE, VIEW_MAXIMUM_DISTANCE);
		glTranslatef(0.0, 0.0, SPACE_DISTANCE); // 투영 공간을 화면 안쪽으로 이동하여 시야를 확보한다.
	}
	else if (VIEW_TYPE == 2) {
		//직각투영
		//glOrtho(-1 * (w / 2), (w / 2), -1 * (h / 2), (h / 2), -1 * (SIZE_Z / 2), SIZE_Z / 2);		// x좌표  Y좌표 Z좌표 모두 - 400 부터 400 까지
		glOrtho(0, w, h, 0, -1 * (SIZE_Z / 2), SIZE_Z / 2);		// x좌표  Y좌표 Z좌표 모두 - 400 부터 400 까지
	}
}