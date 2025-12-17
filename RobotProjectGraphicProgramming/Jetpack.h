#pragma once

#include "RobotPart.h"
#include "ExperimentationStation.h"

#include <Windows.h>
#include <cmath>
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment (lib,"OpenGL32.lib")
#pragma comment (lib,"GLU32.lib")

class Jetpack : public RobotPart
{
private:
	float transitionX;
	float firepower;

	BITMAP BMP;
	HBITMAP hBMP;
	GLuint metal = 0;
	GLuint logo = 0;
	GLuint flame = 0;

public:
	void initTexture();
	void clearTexture();
	void jetpackInput();
	void drawJetpack(float cx, float cy, float cz);
};

