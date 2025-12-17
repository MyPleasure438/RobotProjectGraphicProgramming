#pragma once

#include "RobotPart.h"
#include <Windows.h>   // Must come first in Win32 projects
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdio>
#include <cmath>
#include <iostream>
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
	Joint elbowOffsetFromShoulder = { 0.0f, -8.5f, 0.0f };
	Joint wristOffsetFromElbow = { 0.0f, -7.5f, 0.0f };
	Joint finger1OffsetFromWrist = { -1.275f, -5.1f, 0.275f };
	Joint finger2OffsetFromWrist = { -0.425f, -5.1f, 0.275f };
	Joint finger3OffsetFromWrist = { 0.425f, -5.1f, 0.275f };
	Joint finger4OffsetFromWrist = { 1.275f, -5.1f, 0.275f };

	Joint fingerMiddleJoint1OffsetFromFinger = { 0.0f, -2.0f, 0.0f };
	Joint fingerMiddleJoint2OffsetFromFinger = { 0.0f, -2.0f, 0.0f };
	Joint fingerMiddleJoint3OffsetFromFinger = { 0.0f, -2.0f, 0.0f };
	Joint fingerMiddleJoint4OffsetFromFinger = { 0.0f, -2.0f, 0.0f };
	char buf[64];

	GLUquadricObj *quad = NULL;
	GLUquadricObj *varSphere = NULL;
	GLUquadricObj* varPyramid = NULL;
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

	//Load Texture///
	GLuint texture = 0;
	GLuint metal = 0;
	GLuint camouflageWhite = 0;
	GLuint energyPulse= 0;
	GLuint minigunCover = 0;
	GLuint minigunCylinder = 0;
	GLuint blackMetalic = 0;
	GLuint glass = 0;
	GLuint whitePattern = 0;
	GLuint white = 0;

	BITMAP BMP;
	HBITMAP hBMP = NULL;

	float time_value = 0.0f;
	float waves_time = 0.0f;
	float anim_value = 0.0f;
	float anim_value_missle = 0.0f;
	float anim_value_minigun = 0.0f;
	float anim_value_entireArm = 0.0f;

	//Missle
	struct Missle
	{
		bool isActive;
		float currentY;
	};

	Missle missiles[4] =
	{
		{false, 0.0f}, // Missle 1
		{false, 0.0f}, // Missle 2
		{false, 0.0f}, // Missle 3
		{false, 0.0f} // Missle 4
	};

	int nextMissileToFire = 0;

	//Hand from wrist
	struct Hand
	{
		bool isActive;
		float currentRotationX;
		float currentRotationY;
		float currentRotationZ;
	};

	Hand handMovement[3] =
	{
		{false, 0.0f, 0.0f, 0.0f}, //Hand movement 1 
		{false, 0.0f, 0.0f, 0.0f}, //Hand movement 2
		{false, 0.0f, 0.0f, 0.0f}  //Hand movement 3
	};

	int nextHandMovement = 0;

	//Minigun
	struct Minigun
	{
		bool isActive;
		float currentRotationZ;
	};

	Minigun minigunSpeed[3] =
	{
		{false, 0.0f}, //Minigun speed 1 
		{false, 0.0f}, //Minigun speed 2
		{false, 0.0f}  //Minigun speed 3
	};

	int nextMinigunSpeed = 0;
	
	//EntireArm
	struct EntireArm
	{
		bool isActive;
		float currentRotationZ;
	};

	EntireArm entireArmSpeed[3] =
	{
		{false, 0.0f}, //EntireArm speed 1 
		{false, 0.0f}, //EntireArm speed 2
		{false, 0.0f}  //EntireArm speed 3
	};

	int nextEntireArmSpeed = 0;

	//store previous tate
	char prevDiKeys[256];
	
public:
	LeftArm();
	void updateInput() override;
	void drawJointMarker();
	void drawCuboid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, float red, float green, float blue, GLuint texture);
	void drawSlantedCuboid(float scaleX, float scaleY, float scaleZ, float additionalSlantedHeight, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, float red, float green, float blue, GLuint texture);
	void drawSphere(GLUquadricObj* quad, float radius, int slices, int stacks, GLuint texture);
	void drawCylinder(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle, GLuint texture);
	void drawCylinderWithCap(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle, GLuint texture);
	void drawCircle(float circleRadius, GLuint texture);
	void drawCircleWithHole(float outerRadius, float innerRadius, int segments);
	void drawPyramid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, GLuint texture);
	LeftArm::Vector3D findNormalVector(Point3D v1, Point3D v2, Point3D v3);
	void drawBeautifulCircleWithFlowers(float circleRadius, float baseRadius, float topRadius, float height, int numCylinders, int selectedDrawStyle);
	void drawCylinderAlongCurve(float angleBegins, float angleEnds, float circleXRadius, float circleYRadius, float cylinderRadius, int selectedDrawStyle, GLuint texture);
	void drawText3D(const char* text);
	void initFont();
	void loadTextures();
	void beginScaleTexture(float scaleX, float scaleY);
	void endScaleTexture();
	void deleteTextures();
	void drawIceCream();
	void drawMissle();
	void drawRocketLauncher();
	void draw();
	void draw2();

};

