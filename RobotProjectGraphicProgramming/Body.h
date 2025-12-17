#pragma once

#include "RobotPart.h"
#include "ExperimentationStation.h"
#include "Jetpack.h"

#include <Windows.h>
#include <cmath>
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment (lib,"OpenGL32.lib")
#pragma comment (lib,"GLU32.lib")


class Body :public RobotPart
{
private:
	float BodyInitPlacementX;
	float BodyInitPlacementY;
	float BodyInitPlacementZ;

	float BodyRotateX;
	float BodyRotateY;
	float BodyRotateZ;
	
	float BodyTranslateX;
	float BodyTranslateY;
	float BodyTranslateZ;

	float time_value;
	float waves_time;
	float anim_value;

	

	BITMAP BMP;
	HBITMAP hBMP;
	GLuint bodyTex = 0;
	GLuint finsTex = 0;

public:
	
	void updateInput() override;	
	void drawBodyFrame(Jetpack *jpk);
	void drawScales(float cx,float cy, float cz,float facingR, float offset);
	void drawEnergyStone(float cx, float cy,float cz);
	void initBodyTexture();
	void clearBodyTexture();
};

