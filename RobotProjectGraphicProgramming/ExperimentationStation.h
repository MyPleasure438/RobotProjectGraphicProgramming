#pragma once

#include "RobotPart.h"
#include <Windows.h>   // Must come first in Win32 projects
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdio>

#include <iostream>
#include <cmath>
#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")


class ExperimentationStation : public RobotPart
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

	GLUquadricObj* quad = NULL;
	GLUquadricObj* varSphere = NULL;
	GLUquadricObj* varCylinder = NULL;
	GLUquadricObj* varCylinder2 = NULL;
	int slices = 5;
	int stacks = 5;

	enum DrawStyle {
		FILL,
		LINE,
		POINT,
		SILHOUETTE
	};

	float openAndCloseGate = 0;
	float shipMovement = 5.0f;

	//vector3D
	struct Vector3D {
		float x;
		float y;
		float z;
	};

	struct Point3D {
		float x;
		float y;
		float z;
	};

	//this maccam put in main above switch
	//sorry i think is display
	//light1Pos is diffuseLightPosition
	/*GLfloat matrix[16] = {light1Pos[1], 0, 0, 0,
							-light1Pos[0], 0, -light1Pos[2], -1,
							0,0, light1Pos[1], 0,
							0, 0, 0, light1Pos[1] };
	*/

	/*
	ly, 0, 0, 0
	-lx, 0, -lz, -1
	0, 0, ly, 0
	0, 0, 0, ly

	*/

public:
	ExperimentationStation();
	void updateInput() override;
	void drawJointMarker();
	void drawCuboid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, float red, float green, float blue);
	void drawSphere(GLUquadricObj* quad, float radius, int slices, int stacks);
	void drawCylinder(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle);
	void drawCircle(float circleRadius);
	void drawCircleWithHole(float outerRadius, float innerRadius, int segments);
	void drawPyramid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ);
	ExperimentationStation::Vector3D findNormalVector(Point3D v1, Point3D v2, Point3D v3);
	void drawBeautifulCircleWithFlowers(float circleRadius, float baseRadius, float topRadius, float height, int numCylinders, int selectedDrawStyle);
	void drawCylinderAlongCurve(float angleBegins, float angleEnds, float circleXRadius, float circleYRadius, float cylinderRadius, int selectedDrawStyle);
	void drawText3D(const char* text);
	void initFont();
	void drawColumnOfTower(float translationX, float translationY, float translationZ);
	void drawWall(float translationX, float translationY, float translationZ, float length, float depth);
	void drawGroundBridge1(float translationX, float translationY, float translationZ, float length, float depth);
	void drawGroundBridge2(float translationX, float translationY, float translationZ, float length, float depth);
	void drawGroundBridge3And4(float translationX, float translationY, float translationZ, float length, float depth);
	void drawBridge(float translationX, float translationY, float translationZ, float length, float depth, float red, float green, float blue);
	void draw();
	void draw2();
	void draw3();
	void lightingTestCube();
	void lightingTestPyramidAndSphere();

	void shadeModel();


};

