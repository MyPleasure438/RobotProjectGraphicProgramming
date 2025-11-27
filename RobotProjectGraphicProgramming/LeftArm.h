#pragma once

#include "RobotPart.h"
#include <Windows.h>   // Must come first in Win32 projects
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdio>

#include <cmath>
#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")


class LeftArm : public RobotPart
{
private:
	float length;
	float thickness;
	float jointAngle;
	float xpositionupdate = 0;


	float RobotEntireArm_3DRotationAngleX = 0.0f;
	float RobotEntireArm_3DRotationAngleY = 0.0f;
	float RobotEntireArm_3DRotationAngleZ = 0.0f;

	float RobotEntireArm_TranslationX = 0.0f;
	float RobotEntireArm_TranslationY = 0.0f;
	float RobotEntireArm_TranslationZ = 0.0f;

	float RobotElbow_3DRotationAngleX = 0.0f;
	float RobotElbow_3DRotationAngleY = 0.0f;
	float RobotElbow_3DRotationAngleZ = 0.0f;

	float RobotWrist_3DRotationAngleX = 0.0f;
	float RobotWrist_3DRotationAngleY = 0.0f;
	float RobotWrist_3DRotationAngleZ = 0.0f;

	Joint shoulder = { 0.0f, 0.0f, 0.0f };
	Joint elbowOffsetFromShoulder = { 0.0f, -6.0f, 0.0f };
	Joint wristOffsetFromElbow = { 0.0f, -5.0f, 0.0f };
	Joint finger1OffsetFromWrist = { -1.5f, -2.0f, 0.0f };
	Joint finger2OffsetFromWrist = { -0.5f, -2.0f, 0.0f };
	Joint finger3OffsetFromWrist = { 0.5f, -2.0f, 0.0f };
	Joint finger4OffsetFromWrist = { 1.5f, -2.0f, 0.0f };
	char buf[64];

	GLUquadricObj *quad = NULL;
	GLUquadricObj *varSphere = NULL;
	GLUquadricObj *varCylinder = NULL;
	GLUquadricObj *varCylinder2 = NULL;
	int slices = 5;
	int stacks = 5;

	enum DrawStyle {
		FILL,
		LINE,
		POINT,
		SILHOUETTE
	};


public:
	LeftArm();
	void updateInput() override;
	void drawJointMarker();
	void drawCuboid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, float red, float green, float blue);
	void drawSphere(GLUquadricObj* quad, float radius, int slices, int stacks);
	void drawCylinder(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle);
	void drawCircle(float circleRadius);
	void drawCircleWithHole(float outerRadius, float innerRadius, int segments);
	void drawText3D(const char* text);
	void initFont();
	void drawIceCream();
	void draw();

};

