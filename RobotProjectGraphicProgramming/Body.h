#pragma once

#include "RobotPart.h"

#include <Windows.h>
#include <math.h>
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

public:
	
	void updateInput() override;
	void drawBodyFrame();
	void drawBody();
	void drawEnergyStone(float cx, float cy,float cz);
	void animation();

};

