#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include "LeftArm.h"

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"

//for perspective
#include <GL/glu.h>
#pragma comment(lib, "glu32.lib")

#include "LeftArm.h"
#include "Body.h"
#include "Head.h"
#include "LeftLeg.h"
#include "Shield.h"
#include "Sword.h"
class Robot
{
private:
	LeftArm leftArm;
	Body body;
	Head head;
	LeftLeg leftLeg;
	Shield shield;
	Sword sword;

public:
	// Animation variables
	float armSwingAngle = 0.0f;
	float legWalkAngle = 0.0f;

	Robot();          // constructor
	void update();    // update animation logic
	void draw();      // draw entire robot
};


