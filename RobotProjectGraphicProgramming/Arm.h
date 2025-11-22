#pragma once

#include "RobotPart.h"
class Arm : public RobotPart
{
private:
	float length;
	float thickness;
	float jointAngle;
	// Additional properties can be added here

public:
	Arm();
	void update();
	void draw();
	void setLength(float len);
	void setThickness(float thick);
	void setJointAngle(float angle);
	float getLength() const;
	float getThickness() const;
	float getJointAngle() const;
	void draw() const;

};

