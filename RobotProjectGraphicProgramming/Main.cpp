
#include <Windows.h>
#include <gl/GL.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"

//for perspective
#include <GL/glu.h>
#pragma comment(lib, "glu32.lib")



int QuestionToRender = 0;

enum FlagsQuestionsToRender
{
	PAHANG_FLAG = 0,
	NEGERISEMBILAN_FLAG,
	ENGLAND_FLAG,
	SCOTLAND_FLAG,
	JAPAN_FLAG,
	SMILING_FACE,
	FACE = 6
};

float glTranslatefX = 0.0f;
float glTranslatefY = 0.0f;
float glTranslatefZ = 0.0f;
float objectRed = 0.0f;
float objectGreen = 0.0f;
float objectBlue = 0.0f;


enum ObjectsQuestionsToRender
{
	MOVING_OBJECT = 7,
	COLOR_CHANGING_STAR = 8,
	ANTICLOCKWISE_POINT = 9,
	EXPENDABLE_RED_BOX = 'C'
};

float starRed = 0.0f;
float starGreen = 0.0f;
float starBlue = 0.0f;
float starRotation = 0.0f;
float pointRotation = 0.0f;
float redBoxScalingX = 1.0f;
float redBoxScalingY = 1.0f;


enum RectangleTransformationToRender
{
	TWO_RECTANGLES = 'V'
};

float redBox1TranslationX = 0.0f;
float redBox1TranslationY = 0.0f;
float redBox1TranslationZ = 0.0f;
float redBox2TranslationX = 0.0f;
float redBox2TranslationY = 0.0f;
float redBox2TranslationZ = 0.0f;

enum WindMilllToRender
{
	WINDMILL = 'N'
};
float windmillRotation = 0.0f;
float windmillAcceleration = 0.0f;
float windmillSpeed = 0.0f;
struct Point {
	float x;
	float y;
};
std::vector<Point> grassPoints;
int grassNumberGenerated = 0;

enum Render3D
{
	Cube_3D = 'Q',
	Pyramid_3D = 'W',
	RobotArm_3D = 'E'

};



float Cube_3DTranslationX = 0.0f;
float Cube_3DTranslationY = 0.0f;
float Cube_3DTranslationZ = 0.0f;

float Cube_3DRotationAngleX = 0.0f;
float Cube_3DRotationAngleY = 0.0f;
float Cube_3DRotationAngleZ = 0.0f;

float Pyramid_3DTranslationX = 0.0f;
float Pyramid_3DTranslationY = 0.0f;
float Pyramid_3DTranslationZ = 0.0f;

float Pyramid_3DRotationAngleX = 0.0f;
float Pyramid_3DRotationAngleY = 0.0f;
float Pyramid_3DRotationAngleZ = 0.0f;

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
			//draw Pahang Flag
			QuestionToRender = PAHANG_FLAG;
			break;
		case '1':
			//draw NS Flag
			QuestionToRender = NEGERISEMBILAN_FLAG;
			break;
		case '2':
			//draw England Flag
			QuestionToRender = ENGLAND_FLAG;
			break;
		case '3':
			//draw Scotland Flag
			QuestionToRender = SCOTLAND_FLAG;
			break;
		case '4':
			//draw Japan Flag
			QuestionToRender = JAPAN_FLAG;
			break;
		case '5':
			//draw smiling face
			QuestionToRender = SMILING_FACE;
			break;
		case '6':
			//draw face
			QuestionToRender = FACE;
			break;
		case '7':
			//draw moving object
			QuestionToRender = MOVING_OBJECT;
			break;
		case '8':
			//draw color changing star
			QuestionToRender = COLOR_CHANGING_STAR;
			break;
		case '9':
			//draw anticlockwise point
			QuestionToRender = ANTICLOCKWISE_POINT;
			break;
		case 'C':
			//draw expandable red box
			QuestionToRender = EXPENDABLE_RED_BOX;
			break;
		case 'V':
			//draw two rectangles
			QuestionToRender = TWO_RECTANGLES;
			break;
		case 'N':
			//draw Windmill
			QuestionToRender = WINDMILL;
			break;
		case 'Q':
			//draw cube 3D
			QuestionToRender = Cube_3D;
			break;
		case 'W':
			//draw pyramid 3D
			QuestionToRender = Pyramid_3D;
			break;
		case 'E':
			//draw robotarm 3D
			QuestionToRender = RobotArm_3D;
		case 'O':
			//rotate Y axis
			Cube_3DRotationAngleY = Cube_3DRotationAngleY + 1.0f;
			Pyramid_3DRotationAngleY = Pyramid_3DRotationAngleY + 1.0f;



			//RobotLowerArm_3DRotationAngleX = -0.1f;
			RobotLowerArm_3DRotationAngleY = RobotLowerArm_3DRotationAngleY - 0.1f;
			//RobotLowerArm_3DRotationAngleZ = 0.0f;

			break;
		case 'L':
			//rotate Y axis
			Cube_3DRotationAngleX = Cube_3DRotationAngleX - 1.0f;
			Pyramid_3DRotationAngleX = Pyramid_3DRotationAngleX - 1.0f;

			RobotLowerArm_3DRotationAngleY = RobotLowerArm_3DRotationAngleY + 0.1f;
			break;
		case 'K':
			//rotate X axis
			Cube_3DRotationAngleY = Cube_3DRotationAngleY - 1.0f;
			Pyramid_3DRotationAngleY = Pyramid_3DRotationAngleY - 1.0f;


			RobotEntireArm_3DRotationAngleX = RobotEntireArm_3DRotationAngleX - 0.1f;
			//RobotEntireArm_3DRotationAngleY = 0.0f;
			//RobotEntireArm_3DRotationAngleZ = 0.0f;

			//RobotLowerArm_3DRotationAngleX = -0.1f;
			//RobotLowerArm_3DRotationAngleY = 0.0f;
			//RobotLowerArm_3DRotationAngleZ = 0.0f;
			break;
		case VK_OEM_1:
			//rotate X axis using ; key
			Cube_3DRotationAngleX = Cube_3DRotationAngleX + 1.0f;
			Pyramid_3DRotationAngleX = Pyramid_3DRotationAngleX + 1.0f;


			RobotEntireArm_3DRotationAngleX = RobotEntireArm_3DRotationAngleX + 0.1f;
			//RobotEntireArm_3DRotationAngleY = 0.0f;
			//RobotEntireArm_3DRotationAngleZ = 0.0f;

			//RobotLowerArm_3DRotationAngleX = -0.1f;
			//RobotLowerArm_3DRotationAngleY = 0.0f;
			//RobotLowerArm_3DRotationAngleZ = 0.0f;
			break;

		case VK_OEM_4:
			//rotate Z axis using [ key
			Cube_3DRotationAngleZ = Cube_3DRotationAngleZ + 1.0f;
			Pyramid_3DRotationAngleZ = Pyramid_3DRotationAngleZ + 1.0f;
			RobotEntireArm_3DRotationAngleZ = RobotEntireArm_3DRotationAngleZ - 0.1f;

			break;
		case VK_OEM_6:
			//rotate Z axis using ] key
			Cube_3DRotationAngleZ = Cube_3DRotationAngleZ - 1.0f;
			Pyramid_3DRotationAngleZ = Pyramid_3DRotationAngleZ - 1.0f;
			RobotEntireArm_3DRotationAngleZ = RobotEntireArm_3DRotationAngleZ + 0.1f;

			if (windmillRotation < 0.0f) {
				windmillRotation = windmillRotation + 0.1f;
			}

			if (windmillRotation > 0.0f) {
				windmillRotation = windmillRotation - 0.1f;
			}
			break;
		case VK_UP:
			//move object up
			glTranslatefY = glTranslatefY + 0.1f;
			redBox1TranslationY = redBox1TranslationY + 0.1f;
			redBox2TranslationY = redBox2TranslationY - 0.1f;
			Cube_3DTranslationY = Cube_3DTranslationY + 0.1f;
			Pyramid_3DTranslationY = Pyramid_3DTranslationY + 0.1f;


			RobotEntireArm_TranslationY = RobotEntireArm_TranslationY + 0.1f;
			windmillAcceleration = windmillAcceleration + 1.0f;
			break;

		case VK_DOWN:
			//move object down
			glTranslatefY = glTranslatefY - 0.1f;
			redBox1TranslationY = redBox1TranslationY - 0.1f;
			redBox2TranslationY = redBox2TranslationY + 0.1f;
			Cube_3DTranslationY = Cube_3DTranslationY - 0.1f;
			Pyramid_3DTranslationY = Pyramid_3DTranslationY - 0.1f;

			RobotEntireArm_TranslationY = RobotEntireArm_TranslationY - 0.1f;
			windmillAcceleration = windmillAcceleration - 1.0f;
			break;

		case VK_LEFT:
			//move object left
			glTranslatefX = glTranslatefX - 0.1f;
			redBox1TranslationX = redBox1TranslationX - 0.1f;
			redBox2TranslationX = redBox2TranslationX + 0.1f;
			Cube_3DTranslationX = Cube_3DTranslationX - 0.1f;
			Pyramid_3DTranslationX = Pyramid_3DTranslationX - 0.1f;

			RobotEntireArm_TranslationX = RobotEntireArm_TranslationX - 0.1f;

			windmillRotation = windmillRotation + 0.1 * windmillAcceleration;
			break;

		case VK_RIGHT:
			//move object right
			glTranslatefX = glTranslatefX + 0.1f;
			redBox1TranslationX = redBox1TranslationX + 0.1f;
			redBox2TranslationX = redBox2TranslationX - 0.1f;
			Cube_3DTranslationX = Cube_3DTranslationX + 0.1f;
			Pyramid_3DTranslationX = Pyramid_3DTranslationX + 0.1f;

			RobotEntireArm_TranslationX = RobotEntireArm_TranslationX + 0.1f;

			windmillRotation = windmillRotation + 0.1 * windmillAcceleration;
			break;

		case VK_SPACE:
			//reset position
			glLoadIdentity();
			glTranslatefX = 0;
			glTranslatefY = 0;
			glTranslatefZ = 0;

			redBox1TranslationX = 0.0f;
			redBox1TranslationY = 0.0f;
			redBox1TranslationZ = 0.0f;
			redBox2TranslationX = 0.0f;
			redBox2TranslationY = 0.0f;
			redBox2TranslationZ = 0.0f;

			Cube_3DTranslationX = 0.0f;
			Cube_3DTranslationY = 0.0f;
			Cube_3DTranslationZ = 0.0f;

			Cube_3DRotationAngleX = 0.0f;
			Cube_3DRotationAngleY = 0.0f;
			Cube_3DRotationAngleZ = 0.0f;

			Pyramid_3DTranslationX = 0.0f;
			Pyramid_3DTranslationY = 0.0f;
			Pyramid_3DTranslationZ = 0.0f;

			Pyramid_3DRotationAngleX = 0.0f;
			Pyramid_3DRotationAngleY = 0.0f;
			Pyramid_3DRotationAngleZ = 0.0f;

			objectRed = 0.0f;
			objectGreen = 0.0f;
			objectBlue = 0.0f;

			windmillAcceleration = 0.0f;

			break;


		case VK_OEM_PERIOD:
			//translate by Z axis using '.' key
			Cube_3DTranslationZ = Cube_3DTranslationZ - 0.1f;
			break;

		case VK_OEM_2:
			//translate by Z axis using '/' key
			Cube_3DTranslationZ = Cube_3DTranslationZ + 0.1f;
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