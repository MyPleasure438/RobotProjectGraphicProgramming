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
	float waves_value;

public:
	/*
	void updateInput() override;
	void drawBodyFrame();
	void drawScales(float cx,float cy, float cz,float facingR, float offset);
	void drawEnergyStone(float cx, float cy,float cz);
	void animation();
	*/

};

