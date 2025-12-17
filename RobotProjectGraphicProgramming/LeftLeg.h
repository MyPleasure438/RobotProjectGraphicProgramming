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


class LeftLeg : public RobotPart
{
private:



	const float ROT_SPEED = 0.1f;

	int legControl = 0;
	int legcounter = 1;

	float length;
	float thickness;
	float jointAngle;
	float xpositionupdate = 0;


	float FOOT_3DRotationAngleX = 0.0f;
	float FOOT_3DRotationAngleY = 0.0f;
	float FOOT_3DRotationAngleZ = 0.0f;

	float FOOT_TranslationX = 0.0f;
	float FOOT_TranslationY = 0.0f;
	float FOOT_TranslationZ = 0.0f;

	float CALF_3DRotationAngleX = 0.0f;
	float CALF_3DRotationAngleY = 0.0f;
	float CALF_3DRotationAngleZ = 0.0f;

	float CALF_TranslationX = 0.0f;
	float CALF_TranslationY = 0.0f;
	float CALF_TranslationZ = 0.0f;

	float THIGH_3DRotationAngleX = 0.0f;
	float THIGH_3DRotationAngleY = 0.0f;
	float THIGH_3DRotationAngleZ = 0.0f;

	float THIGH_TranslationX = 0.0f;
	float THIGH_TranslationY = 0.0f;
	float THIGH_TranslationZ = 0.0f;
	//___________________________________________________________________
	float RFOOT_3DRotationAngleX = 0.0f;
	float RFOOT_3DRotationAngleY = 0.0f;
	float RFOOT_3DRotationAngleZ = 0.0f;

	float RFOOT_TranslationX = 0.0f;
	float RFOOT_TranslationY = 0.0f;
	float RFOOT_TranslationZ = 0.0f;

	float RCALF_3DRotationAngleX = 0.0f;
	float RCALF_3DRotationAngleY = 0.0f;
	float RCALF_3DRotationAngleZ = 0.0f;

	float RCALF_TranslationX = 0.0f;
	float RCALF_TranslationY = 0.0f;
	float RCALF_TranslationZ = 0.0f;

	float RTHIGH_3DRotationAngleX = 0.0f;
	float RTHIGH_3DRotationAngleY = 0.0f;
	float RTHIGH_3DRotationAngleZ = 0.0f;

	float RTHIGH_TranslationX = 0.0f;
	float RTHIGH_TranslationY = 0.0f;
	float RTHIGH_TranslationZ = 0.0f;
	//___________________________________________________________________

	int animationStep = 0; 

	const float Anim_Rot_Speed = 0.5f; 
	int legSide = 0;

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

	GLUquadricObj* quad = NULL;
	GLUquadricObj* varSphere = NULL;
	GLUquadricObj* varCylinder = NULL;
	GLUquadricObj* varCylinder2 = NULL;
	GLUquadricObj* thigh = NULL;
	GLUquadricObj* joint = NULL;
	GLUquadricObj* bolt = NULL;

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
	GLuint BlackShiny = 0;
	GLuint Skin = 0;
	GLuint Krypto = 0;
	GLuint Blue = 0;
	BITMAP BMP;
	HBITMAP hBMP = NULL;


public:
	LeftLeg();
	void updateInput() override;
	void drawJointMarker();
	void drawCuboid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, float red, float green, float blue, GLuint texture);
	void drawSphere(GLUquadricObj* quad, float radius, int slices, int stacks, GLuint texture);
	void drawCylinder(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle, GLuint texture);
	void drawCylinderWithCap(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle, GLuint texture);
	void drawCircle(float circleRadius, GLuint texture);
	void drawCircleWithHole(float outerRadius, float innerRadius, int segments);
	void drawTriangularPrism(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, GLuint texture);
	LeftLeg::Vector3D findNormalVector(Point3D v1, Point3D v2, Point3D v3);
	void drawBeautifulCircleWithFlowers(float circleRadius, float baseRadius, float topRadius, float height, int numCylinders, int selectedDrawStyle);
	void drawCylinderAlongCurve(float angleBegins, float angleEnds, float circleXRadius, float circleYRadius, float cylinderRadius, int selectedDrawStyle, GLuint texture);
	void drawText3D(const char* text);
	void initFont();
	void loadTextures();
	void beginScaleTexture(float scaleX, float scaleY);
	void endScaleTexture();
	void deleteTextures();
	void draw();
	void draw2();
	void drawThigh();
	void drawShin();
	void drawFootPiece();
	void drawFootToe();
	void drawFoot();
	void drawBolt();
	void drawSeam();
	void footRotate();
	void calfRotate();
	void ObjectTransform();
	void AnimWalk();
};

