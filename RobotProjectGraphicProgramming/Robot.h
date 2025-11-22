#pragma once

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

#include "Arm.h"
#include "Body.h"
#include "Head.h"
#include "Leg.h"
#include "Shield.h"
#include "Sword.h"
class Robot
{
private:
	Arm arm;
	Body body;
	Head head;
	Leg leg;
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


