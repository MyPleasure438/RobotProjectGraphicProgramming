#pragma once

#include "RobotPart.h"
#include <Windows.h>   // Must come first in Win32 projects
#include <GL/gl.h>
#include <GL/glu.h>
#pragma comment (lib, "OpenGL32.lib")



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


	Joint shoulder = { 1.0f, 0.0f, 1.0f };
	Joint elbow = { 1.0f, -6.0f, 1.0f };
	Joint wrist = { 1.0f, -9.0f, 1.0f };
	




public:
	LeftArm();
	void updateInput() override;
	void draw();
	void setLength(float len);
	void setThickness(float thick);
	void setJointAngle(float angle);
	float getLength() const;
	float getThickness() const;
	float getJointAngle() const;

};

