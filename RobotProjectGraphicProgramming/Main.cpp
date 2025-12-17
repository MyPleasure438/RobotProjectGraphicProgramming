
#include <Windows.h>
#include <gl/GL.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <cstdio>
#include <vector>
#include "InputManager.h"
#include "LeftLeg.h"
#include "LeftArm.h"
#include "Head.h"
#include "Body.h"
#include "Jetpack.h"


#include "ExperimentationStation.h"
#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"

//for perspective
#include <GL/glu.h>
#pragma comment(lib, "glu32.lib")

using namespace std;
int QuestionToRender = 0;

enum RobotDisplayParts
{
	LEFTARM = 0

};

//Global object initialization
LeftArm leftArm;
Head head;
Body body;
Jetpack jpk;
ExperimentationStation experimentationStation;

LeftLeg leftLeg;


float objectRed = 0.0f;
float objectGreen = 0.0f;
float objectBlue = 0.0f;

float translateCameraX = 0.0f;
float translateCameraY = 0.0f;
float translateCameraZ = 0.0f;
//float translateCameraZ = 5.0f;

float rotateCameraX = 0.0f;
float rotateCameraY = 0.0f;
float rotateCameraZ = 0.0f;

//projection mode Orthographic or Perspective
enum ProjectionMode
{
	Orthographic = 0,
	Perspective = 1
};
int projectionMode = Orthographic;
void orthographicProjection();
void perspectiveProjection();
void drawLightBulb();
void drawCube();

//CameraScreen
float cameraScreenWidth = 1080.0f;
float cameraScreenHeight = 1080.0f;
float currentMonitorWidth = 1920.0f;
float currentMonitorHeight = 1080.0f;

float offsetXToCenter = (currentMonitorWidth - cameraScreenWidth) / 2.0f;
float offsetYToCenter = (currentMonitorHeight - cameraScreenHeight) / 2.0f;

float aspectRatio = cameraScreenWidth / cameraScreenHeight;


//lighting
float diffuseLightPositionX = 0.0f;
float diffuseLightPositionY = 3.0f;
float diffuseLightPositionZ = 0.7f;

GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f };
GLfloat diffuseLight[] = { 0.7f, 0.7f, 0.7f };
GLfloat diffuseLightPosition[] = { diffuseLightPositionX, diffuseLightPositionY, diffuseLightPositionZ, 1.0f };

GLUquadricObj* quadLightBulb = NULL;

///textures////
/*
GLuint texture = 0;
GLuint metal = 0;
BITMAP BMP;
HBITMAP hBMP = NULL;
*/


LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;

			//case '0':
			//	//draw RobotArm 3D
			//	QuestionToRender = LEFTARM;
			//	break;

		case '1':
			//draw RobotArm 3D
			QuestionToRender = 1;
			break;

		case '8':
		case VK_NUMPAD8:
			translateCameraY = translateCameraY + 0.1f;
			break;

		case '5':
		case VK_NUMPAD5:
			translateCameraY = translateCameraY - 0.1f;

			break;

		case '4':
		case VK_NUMPAD4:
			translateCameraX = translateCameraX - 0.1f;

			break;

		case '6':
		case VK_NUMPAD6:
			translateCameraX = translateCameraX + 0.1f;

			break;

		case '7':
		case VK_NUMPAD7:
			translateCameraZ = translateCameraZ - 0.1f;

			break;

		case '9':
		case VK_NUMPAD9:
			translateCameraZ = translateCameraZ + 0.1f;

			break;

		case 'K':

			break;

		case VK_UP:
			rotateCameraY = rotateCameraY + 1.0f;
			break;

		case VK_DOWN:
			rotateCameraY = rotateCameraY - 1.0f;
			break;

		case VK_LEFT:
			rotateCameraX = rotateCameraX - 1.0f;
			break;

		case VK_RIGHT:
			rotateCameraX = rotateCameraX + 1.0f;
			break;

		case VK_NUMPAD0:
			// 0 key on numpad
			rotateCameraZ = rotateCameraZ - 1.0f;
			break;

		case VK_DECIMAL:
			// '.' key on numpad
			rotateCameraZ = rotateCameraZ + 1.0f;
			break;

		case VK_SPACE:
			//reset position
			glLoadIdentity();


			objectRed = 0.0f;
			objectGreen = 0.0f;
			objectBlue = 0.0f;


			break;


		case VK_OEM_PERIOD:
			//using '.' key
			break;

		case VK_OEM_2:
			//using '/' key
			break;

		case VK_SUBTRACT:
			projectionMode = Orthographic;
			break;

		case VK_ADD:
			projectionMode = Perspective;
			break;
		case 'P':
			diffuseLightPositionX = diffuseLightPositionX - 0.1f;
			break;

		case VK_OEM_4:
			//using [ key
			diffuseLightPositionX = diffuseLightPositionX + 0.1f;
			break;

		case VK_OEM_6:
			//] key
			diffuseLightPositionY= diffuseLightPositionY - 0.1f;
			break;

		case VK_OEM_5:
			//using \ key
			diffuseLightPositionY = diffuseLightPositionY + 0.1f;
			break;

		case VK_OEM_1:
			// button ";"
			diffuseLightPositionZ = diffuseLightPositionZ - 0.1f;
			break;

		case VK_OEM_7:
			// button "'"
			diffuseLightPositionZ = diffuseLightPositionZ + 0.1f;
			break;

		case 'R':

			break;

		case 'G':
			break;

		case 'B':
			break;
		}
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

void AttachConsoleOutput() {
	AllocConsole(); // Create a console window
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout); // Redirect stdout
	freopen_s(&fp, "CONIN$", "r", stdin);  // Optional: enable cin
	ios::sync_with_stdio();    // Sync C++ streams
}

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void Display(int QuestionsToRender)
{
	//Camera
	glMatrixMode(GL_PROJECTION);
	glViewport(offsetXToCenter, offsetYToCenter, cameraScreenWidth, cameraScreenHeight);
	if (projectionMode == Orthographic)
	{
		orthographicProjection();
	}
	if (projectionMode == Perspective)
	{
		perspectiveProjection();
	}
	glTranslatef(translateCameraX, translateCameraY, translateCameraZ);
	glRotatef(rotateCameraX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotateCameraY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotateCameraZ, 0.0f, 0.0f, 1.0f);


	//End Camera///
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(translateCameraX, translateCameraY, translateCameraZ);



	glClearColor(0.4f, 0.4f, 0.4f, 1.0f);   // set background color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // clear BOTH buffers



	//lighting///
	//diffuseLightPosition[] = { diffuseLightPositionX, diffuseLightPositionY, diffuseLightPositionZ };
	// 4. DEFINE WORLD-FIXED LIGHT POSITION
	// The matrix now contains only the View transformation (from step 3).
	// This ensures the light position is defined in world space, relative to the camera's fixed position.

	/*
	diffuseLightPosition[0] = diffuseLightPositionX;
	diffuseLightPosition[1] = diffuseLightPositionY;
	diffuseLightPosition[2] = diffuseLightPositionZ;
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_POSITION, diffuseLightPosition);
	*/
	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(diffuseLightPositionX, diffuseLightPositionY, diffuseLightPositionZ);
	//drawLightBulb(); // This function should be modified to accept the position, or just draw at the origin.
	glPopMatrix();
	
	//End Lighting///

	glEnable(GL_DEPTH_TEST);   // enable depth test (stay ON forever)
	glShadeModel(GL_SMOOTH);   // smooth shading

	switch (QuestionsToRender) {
	case LEFTARM:

		//draw the light visualiser
		glPushMatrix();
		//glTranslate3f()
			//gluSphere(quad
		glPopMatrix();
		
		
		//experimentationStation.updateInput();
		//experimentationStation.drawIceCream();
		//experimentationStation.draw();
		//experimentationStation.draw3();
		//experimentationStation.shadeModel();
		//experimentationStation.lightingTestCube();
		//experimentationStation.lightingTestPyramidAndSphere();
		//leftArm.updateInput();
		//leftArm.drawMissle();
		//leftArm.draw();
		head.updateInput();
		head.draw2();
		
		//drawCube();
    break;
  case 1:
		//Inputs
		leftArm.updateInput();
		body.updateInput();
		//jpk.jetpackInput();
		head.updateInput();
		

		//AttachLeftArmToBody
		glPushMatrix();
			glScalef(0.5f, 0.5f, 0.5f);

			//Head
			glPushMatrix();
				glTranslatef(0.0f, 8.3f, 0.0f);
				head.draw2();
			glPopMatrix();
			//left arm
			glPushMatrix();
				glTranslatef(5.3f, 0.0f, 0.0f);
				glRotatef(90, 0.0f, 0.0f, 1.0f);
				glRotatef(90, 0.0f, 1.0f, 0.0f);
				glScalef(1.5, 1.5f, 1.5f);
				leftArm.draw();
			glPopMatrix();
			//body.drawBodyFrame();
		glPopMatrix();
		
		break;
    case 2:
		leftLeg.updateInput();
		//Resh@Legs
		leftLeg.draw();
		//leftLeg.drawBolt();
  
    break;
	}



	//-------------------------------
	//	OpenGL drawing
	//--------------------------------

	//--------------------------------
	//	End of OpenGL drawing
	//--------------------------------
}
//--------------------------------------------------------------------


//int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	AttachConsoleOutput();
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 1080, 1080,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//initialize inputManager
	InputManager& inputManager = InputManager::getInstance();
	inputManager.initialization(hWnd, hInst);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	// Initialize LeftArm font (generate display lists once)
	leftArm.initFont();

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));


	//texture initialization
	experimentationStation.loadTextures();
	leftArm.loadTextures();
	head.loadTextures();
	//texture loading
	/*
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "Box.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	GetObject(hBMP, sizeof(BMP), &BMP);

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "metal.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	GetObject(hBMP, sizeof(BMP), &BMP);

	GetObject(hBMP, sizeof(BMP), &BMP);

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &metal);
	glBindTexture(GL_TEXTURE_2D, metal);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);


	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glScalef(2.0, 1.0, 1.0);
	*/

	///end texture loading///

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Display(QuestionToRender);

		SwapBuffers(hdc);
	}

	//Delete texture after closes window
	leftArm.deleteTextures();
	experimentationStation.deleteTextures();
	head.deleteTextures();
	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------


void orthographicProjection()
{
	glLoadIdentity();
	//glOrtho(-4, 4, -4, 4, -4, 4);
	//glOrtho(-8, 8, -8, 8, -8, 8);
	glOrtho(-25, 25, -25, 25, -25, 25);
}

void perspectiveProjection()
{
	glLoadIdentity();
	gluPerspective(100.0f, aspectRatio, 0.1f, 100.0f);
}


void drawLightBulb()
{
	// b) create quadric object
	quadLightBulb = gluNewQuadric();
	if (quadLightBulb == NULL)
	{
		printf("Failed to create quadric!\n");
		return;
	}

	// e) set quadric draw style
	// Options: GLU_FILL, GLU_LINE, GLU_SILHOUETTE, GLU_POINT
	gluQuadricDrawStyle(quadLightBulb, GLU_LINE);   // wireframe sphere

	glPushMatrix();
	// c) draw sphere at origin
	gluSphere(quadLightBulb, 0.1, 20, 20);   // radius = ?, slices & stacks = ?

	glPopMatrix();
	// f) delete quadric (free memory)
	gluDeleteQuadric(quadLightBulb);

	printf("diffuseLightPosition = { %.2f, %.2f, %.2f, %.2f }\n",
		diffuseLightPosition[0],
		diffuseLightPosition[1],
		diffuseLightPosition[2],
		diffuseLightPosition[3]
	);
}

void drawCube()
{
	/*
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	*/
	//ENABLE THIS TEXTURE CODE IF YOU WANT TO TEST TEXTURES

	/*
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, metal);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, -2.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f, -2.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glEnd();
	*/
}

