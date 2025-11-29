#include "Body.h"

GLUquadricObj* ERStone = gluNewQuadric();
float time_value = 0.0f;


void Body::updateInput() {
	InputManager& inputManager = InputManager::getInstance();
	LPDIRECTINPUTDEVICE8 dInputKeyboardDevice = inputManager.getDInputKeyboardDevice();
	HRESULT hr = dInputKeyboardDevice->GetDeviceState(256, diKeys);
	if (diKeys[DIK_W] & 0x80) {
		BodyTranslateY+= 0.001f;

	}

	if (diKeys[DIK_S] & 0x80) {
		BodyTranslateY -= 0.001f;

	}

	if (diKeys[DIK_A] & 0x80) {
		//xpositionupdate = xpositionupdate - 0.0001f;
		BodyTranslateX -= 0.001f;
	}

	if (diKeys[DIK_D] & 0x80) {
		//xpositionupdate = xpositionupdate - 0.0001f;
		BodyTranslateX+= 0.001f;
	}

	if (diKeys[DIK_Q] & 0x80) {
		BodyTranslateZ -= 0.001f;

	}

	if (diKeys[DIK_E] & 0x80) {
		BodyTranslateZ += 0.001f;

	}

	if (diKeys[DIK_T] & 0x80) {
		BodyRotateY -= 0.1f;

	}

	if (diKeys[DIK_G] & 0x80) {
		BodyRotateY += 0.1f;

	}

	if (diKeys[DIK_F] & 0x80) {
		BodyRotateX -= 0.1f;
	}

	if (diKeys[DIK_H] & 0x80) {
		BodyRotateX += 0.1f;

	}

	if (diKeys[DIK_R] & 0x80) {
		BodyRotateZ -= 0.1f;

	}

	if (diKeys[DIK_Y] & 0x80) {
		BodyRotateZ += 0.1f;
	}

	if (diKeys[DIK_SPACE] & 0x80) {
		BodyTranslateX = BodyTranslateY = BodyTranslateZ = 0;
		BodyRotateX = BodyRotateY = BodyRotateZ = 0;
	}

}

void Body::drawBodyFrame() {
	glShadeModel(GL_SHADE_MODEL);
	glLineWidth(5.0);
	glPushMatrix();
	glScalef(20, 20, 20);
	glTranslatef(BodyTranslateX, BodyTranslateY, BodyTranslateZ);
	glRotatef(BodyRotateX, 1.0f, 0.0f, 0.0f);
	glRotatef(BodyRotateY+180, 0.0f, 1.0f, 0.0f);
	glRotatef(BodyRotateZ, 0.0f, 0.0f, 1.0f);
		
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINE_LOOP); //back
		glVertex3f(-0.3, 0.4, 0.2);
		glVertex3f(-0.3, -0.4, 0.2);
		glVertex3f(0.3, -0.4, 0.2);
		glVertex3f(0.3, 0.4, 0.2);
		glEnd();


		glBegin(GL_LINE_LOOP); //left
		glVertex3f(-0.3, 0.4, -0.2);
		glVertex3f(-0.3, 0.1, -0.3);
		glVertex3f(-0.3, -0.4, -0.2);
		glVertex3f(-0.3, -0.4, 0.2);
		glVertex3f(-0.3, 0.4, 0.2);
		glEnd();


		glBegin(GL_LINE_LOOP);//front
		glVertex3f(-0.3, 0.4, -0.2);
		glVertex3f(-0.3, 0.1, -0.3);
		glVertex3f(-0.3, -0.4, -0.2);
		glVertex3f(0.3, -0.4, -0.2);
		glVertex3f(0.3, 0.1, -0.3);
		glVertex3f(0.3, 0.4, -0.2);
		glEnd();


		glBegin(GL_LINE_LOOP);//right
		glVertex3f(0.3, 0.4, -0.2);
		glVertex3f(0.3, 0.1, -0.3);
		glVertex3f(0.3, -0.4, -0.2);
		glVertex3f(0.3, -0.4, 0.2);
		glVertex3f(0.3, 0.4, 0.2);
		glEnd();


		glBegin(GL_LINE_LOOP);//top
		glVertex3f(-0.3, 0.4, -0.2);
		glVertex3f(-0.3, 0.4, 0.2);
		glVertex3f(0.3, 0.4, 0.2);
		glVertex3f(0.3, 0.4, -0.2);
		glEnd();


		glBegin(GL_LINE_LOOP);//bottom
		glVertex3f(-0.3, -0.4, -0.2);
		glVertex3f(-0.3, -0.4, 0.2);
		glVertex3f(0.3, -0.4, 0.2);
		glVertex3f(0.3, -0.4, -0.2);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glVertex3f(-0.3, 0.1, -0.3);
		glVertex3f(0.3, 0.1, -0.3);
		glEnd();

		drawEnergyStone(0.0, 0.1, -0.25);

	glPopMatrix();
}

void Body::drawBody() {

}

void Body::drawEnergyStone(float cx, float cy,float cz) {
	float red = sin(time_value);
	glPushMatrix();
		glTranslatef(cx, cy, cz);
		glColor3f(red, 0.2, 0.2);
		gluSphere(ERStone, 0.1, 100, 100);
	glPopMatrix();
	time_value += 0.005;
	
}
