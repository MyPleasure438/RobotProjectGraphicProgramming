#include "Jetpack.h"
/*
ExperimentationStation Es;

GLUquadricObj* rocket = gluNewQuadric();
GLUquadricObj* fire = gluNewQuadric();

float transitionX = 0;
float firepower = 0;
bool jp_anim_flag = false;

void Jetpack::jetpackInput() {
	InputManager& inputManager = InputManager::getInstance();
	LPDIRECTINPUTDEVICE8 dInputKeyboardDevice = inputManager.getDInputKeyboardDevice();
	HRESULT hr = dInputKeyboardDevice->GetDeviceState(256, diKeys);
	if (diKeys[DIK_9] & 0x80) {
		if (!jp_anim_flag) {
			jp_anim_flag = true;
		}
		else {
			jp_anim_flag = false;
			firepower = 0;
		}
	}
	if (diKeys[DIK_8] & 0x80) {
		if (firepower < 1) {
			firepower += 0.01;
		}
	}
}

void Jetpack::drawJetpack(float cx, float cy, float cz) {
	glPushMatrix();
	glTranslatef(cx, cy, cz);
	Es.drawCuboid(0.35, 0.3, 0.2, 0, 0, 0, 0, 1, 1);

	glPushMatrix();
	glColor3f(1, 0, 0);
	glRotatef(90, 1.0, 0, 0);

		if (jp_anim_flag && transitionX <= 0.23) {
			glPushMatrix();
			glTranslatef(transitionX, 0, -0.05);
			Es.drawCylinder(rocket, 0.05, 0.05, 0.15, 0);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-transitionX, 0, -0.05);
			Es.drawCylinder(rocket, 0.05, 0.05, 0.15, 0);
			glPopMatrix();
			transitionX += 0.01;
		}
		else if (!jp_anim_flag && transitionX > 0) {
			glPushMatrix();
			glTranslatef(transitionX, 0, -0.05);
			Es.drawCylinder(rocket, 0.05, 0.05, 0.15, 0);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-transitionX, 0, -0.05);
			Es.drawCylinder(rocket, 0.05, 0.05, 0.15, 0);
			glPopMatrix();
			transitionX -= 0.01;
		}
		else {
			glPushMatrix();
			glTranslatef(transitionX, 0, -0.05);
			Es.drawCylinder(rocket, 0.05, 0.05, 0.15, 0);
			glTranslatef(0, 0, 0.1);
			Es.drawCylinder(fire, 0.05, 0, firepower, 0);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-transitionX, 0, -0.05);
			Es.drawCylinder(rocket, 0.05, 0.05, 0.15, 0);
			glTranslatef(0, 0, 0.1);
			Es.drawCylinder(fire, 0.05, 0, firepower, 0);
			glPopMatrix();
		}
	glPopMatrix();
	glPopMatrix();
} 

*/