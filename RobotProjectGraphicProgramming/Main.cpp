
#include <Windows.h>
#include <gl/GL.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include "InputManager.h"

#include "LeftArm.h"

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"

//for perspective
#include <GL/glu.h>
#pragma comment(lib, "glu32.lib")



int QuestionToRender = 0;

enum RobotDisplayParts
{
	LEFTARM = 0
};

//Global object initialization
LeftArm leftArm;


float glTranslatefX = 0.0f;
float glTranslatefY = 0.0f;
float glTranslatefZ = 0.0f;
float objectRed = 0.0f;
float objectGreen = 0.0f;
float objectBlue = 0.0f;


float RobotEntireArm_3DRotationAngleX = 0.0f;
float RobotEntireArm_3DRotationAngleY = 0.0f;
float RobotEntireArm_3DRotationAngleZ = 0.0f;

float RobotLowerArm_3DRotationAngleX = 0.0f;
float RobotLowerArm_3DRotationAngleY = 0.0f;
float RobotLowerArm_3DRotationAngleZ = 0.0f;

float RobotEntireArm_TranslationX = 0.0f;
float RobotEntireArm_TranslationY = 0.0f;
float RobotEntireArm_TranslationZ = 0.0f;

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

		case '0':
			//draw RobotArm 3D
			QuestionToRender = LEFTARM;
			break;
		
		case 'O':
			//rotate Y axis


			//RobotLowerArm_3DRotationAngleX = -0.1f;
			RobotEntireArm_3DRotationAngleY = RobotEntireArm_3DRotationAngleY - 0.5f;
			//RobotLowerArm_3DRotationAngleZ = 0.0f;

			break;
		case 'L':
			//rotate Y axis
			
			RobotEntireArm_3DRotationAngleY = RobotEntireArm_3DRotationAngleY + 0.5;
			break;
		case 'K':
			//rotate X axis
			
			RobotEntireArm_3DRotationAngleX = RobotEntireArm_3DRotationAngleX - 0.5f;
			break;
		case VK_OEM_1:
			//rotate X axis using ; key
			
			RobotEntireArm_3DRotationAngleX = RobotEntireArm_3DRotationAngleX + 0.5f;
			break;

		case VK_OEM_4:
			//rotate Z axis using [ key
			RobotEntireArm_3DRotationAngleZ = RobotEntireArm_3DRotationAngleZ - 0.5f;

			break;
		case VK_OEM_6:
			//rotate Z axis using ] key
			RobotEntireArm_3DRotationAngleZ = RobotEntireArm_3DRotationAngleZ + 0.5f;

			break;
		case VK_UP:
			//move object up
			RobotEntireArm_TranslationY = RobotEntireArm_TranslationY + 0.5f;
			break;

		case VK_DOWN:
			//move object down
			RobotEntireArm_TranslationY = RobotEntireArm_TranslationY - 0.5f;
			break;

		case VK_LEFT:
			//move object left
			glTranslatefX = glTranslatefX - 0.1f;
			RobotEntireArm_TranslationX = RobotEntireArm_TranslationX - 0.5f;
			break;

		case VK_RIGHT:
			//move object right
			glTranslatefX = glTranslatefX + 0.1f;
			RobotEntireArm_TranslationX = RobotEntireArm_TranslationX + 0.5f;
			break;

		case VK_SPACE:
			//reset position
			glLoadIdentity();
			glTranslatefX = 0;
			glTranslatefY = 0;
			glTranslatefZ = 0;

			
			objectRed = 0.0f;
			objectGreen = 0.0f;
			objectBlue = 0.0f;

			
			break;


		case VK_OEM_PERIOD:
			//translate by Z axis using '.' key
			RobotEntireArm_TranslationZ = RobotEntireArm_TranslationZ - 0.5f;
			break;

		case VK_OEM_2:
			//translate by Z axis using '/' key
			RobotEntireArm_TranslationZ = RobotEntireArm_TranslationZ + 0.5f;
			break;

		case 'R':
			//turn object red
			objectRed = 1.0f;
			objectGreen = 0.0f;
			objectBlue = 0.0f;
			break;

		case 'G':
			//turn object green
			objectRed = 0.0f;
			objectGreen = 1.0f;
			objectBlue = 0.0f;
			break;

		case 'B':
			//turn object blue
			objectRed = 0.0f;
			objectGreen = 0.0f;
			objectBlue = 1.0f;
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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float cameraScreenWidth = 1850.0f;
	float cameraScreenHeight = 980.0f;
	float currentMonitorWidth = 1920.0f;
	float currentMonitorHeight = 1080.0f;

	float offsetXToCenter = (currentMonitorWidth - cameraScreenWidth) / 2.0f;
	float offsetYToCenter = (currentMonitorHeight - cameraScreenHeight) / 2.0f;

	float aspectRatio = cameraScreenWidth / cameraScreenHeight;
	float cameraZoomOutZTranslation = -10.0f;

	gluPerspective(100.0f, aspectRatio, 0.1f, 100.0f);
	glViewport(offsetXToCenter, offsetYToCenter, cameraScreenWidth, cameraScreenHeight);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, cameraZoomOutZTranslation);

	glClearColor(0.4f, 0.4f, 0.4f, 1.0f);   // set background color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // clear BOTH buffers

	glEnable(GL_DEPTH_TEST);   // enable depth test (stay ON forever)
	glShadeModel(GL_SMOOTH);   // smooth shading

	switch (QuestionsToRender) {
	case LEFTARM:

		glTranslatef(RobotEntireArm_TranslationX, RobotEntireArm_TranslationY, RobotEntireArm_TranslationZ);
		glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
		glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
		glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
		
		//press k to start
		leftArm.updateInput();
		leftArm.draw();
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



int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 800,
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

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

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

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------