#include "Body.h"

ExperimentationStation ES;

GLUquadricObj* ERStone = gluNewQuadric();

bool anim_flag = false;
static bool isAnim_flag = false;

void Body::initBodyTexture() {
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL),
		"bodyTex.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION |
		LR_LOADFROMFILE);
	GetObject(hBMP, sizeof(BMP), &BMP);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &bodyTex);
	glBindTexture(GL_TEXTURE_2D, bodyTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL),
		"finsTex.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION |
		LR_LOADFROMFILE);
	GetObject(hBMP, sizeof(BMP), &BMP);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &finsTex);
	glBindTexture(GL_TEXTURE_2D, finsTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
}

void Body::clearBodyTexture() {
	glDeleteTextures(1, &bodyTex);
	glDeleteTextures(1, &finsTex);
}

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

	if (diKeys[DIK_0] & 0x80) {
		std::cout << "try33";
		if (!isAnim_flag) {
			anim_flag = !anim_flag;
			isAnim_flag = true;
		}
	}
	else {
		isAnim_flag = false;
	}

}

void Body::drawBodyFrame(Jetpack *jpk, bool isShadow) {
	
	glLineWidth(5.0);
	glPushMatrix();

	if (!isShadow) { //Draw Color
		glColor3f(1.0, 1.0, 1.0);
	}

	//glTranslatef(BodyTranslateX, BodyTranslateY, BodyTranslateZ);
	glRotatef(BodyRotateX, 1.0f, 0.0f, 0.0f);
	glRotatef(BodyRotateY+180, 0.0f, 1.0f, 0.0f);
	glRotatef(BodyRotateZ, 0.0f, 0.0f, 1.0f);
	
	glPushMatrix();

		if (!isShadow) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, bodyTex);
		}
		else {
			// If it IS a shadow, ensure texture is OFF so it draws solid black
			glDisable(GL_TEXTURE_2D);
		}

		glNormal3f(0, 0, 1);
		glBegin(GL_QUADS); //back
		glTexCoord2f(0, 0);
		glVertex3f(-0.3, 0.4, 0.2);
		glTexCoord2f(1, 0);
		glVertex3f(-0.3, -0.4, 0.2);
		glTexCoord2f(1, 1);
		glVertex3f(0.3, -0.4, 0.2);
		glTexCoord2f(0, 1);
		glVertex3f(0.3, 0.4, 0.2);
		glEnd();

		glNormal3f(-1, 0, 0);
		glBegin(GL_POLYGON); //left
		glTexCoord2f(0.2f, 1.0f);
		glVertex3f(-0.3, 0.4, -0.2);
		glTexCoord2f(0.0f, 0.625f);
		glVertex3f(-0.3, 0.1, -0.3);
		glTexCoord2f(0.2f, 0.0f);
		glVertex3f(-0.3, -0.4, -0.2);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-0.3, -0.4, 0.2);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-0.3, 0.4, 0.2);
		glEnd();

		glNormal3f(0.0f, 0.316f, -0.948f);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.3, 0.4, -0.2);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-0.3, 0.1, -0.3);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.3, 0.1, -0.3);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.3, 0.4, -0.2);
		glEnd();

		glNormal3f(0.0f, -0.196f, -0.980f);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.3, 0.1, -0.3);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-0.3, -0.4, -0.2);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.3, -0.4, -0.2);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.3, 0.1, -0.3);
		glEnd();

		glNormal3f(1, 0, 0);
		glBegin(GL_POLYGON);//right
		glTexCoord2f(0.2f, 1.0f);
		glVertex3f(0.3, 0.4, -0.2);
		glTexCoord2f(0.0f, 0.625f);
		glVertex3f(0.3, 0.1, -0.3);
		glTexCoord2f(0.2f, 0.0f);
		glVertex3f(0.3, -0.4, -0.2);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(0.3, -0.4, 0.2);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.3, 0.4, 0.2);
		glEnd();

		glNormal3f(0, 1, 0);
		glBegin(GL_QUADS);//top
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.3, 0.4, -0.2);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-0.3, 0.4, 0.2);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.3, 0.4, 0.2);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.3, 0.4, -0.2);
		glEnd();

		glNormal3f(0, -1, 0);
		glBegin(GL_QUADS);//bottom
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-0.3, -0.4, -0.2);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-0.3, -0.4, 0.2);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(0.3, -0.4, 0.2);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.3, -0.4, -0.2);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glVertex3f(-0.3, 0.1, -0.3);
		glVertex3f(0.3, 0.1, -0.3);
		glEnd();
		glPopMatrix();

		//----------------------------------------------------------------------
		drawEnergyStone(0.0, 0.1, -0.25,isShadow);

		if (isShadow) { glDisable(GL_TEXTURE_2D); glColor3f(0, 0, 0); } //Draw shadow for rest of the parts
		//----------------------------------------------------------------------

		for (int i = 0; i < 20; i++) {
			float zPos = 0.19 - (i * 0.02);
			float offset = 0 + (i * 0.5);
			drawScales(0.3001, 0.45, zPos, 90, offset);
		}

		for (int j = 0; j < 16; j++) {
			float yPos = 0.45 - (j * 0.05);
			float offset = 0 + (j * 0.5);
			for (int i = 0; i < 30; i++) {
				float xPos = -0.29 + (i * 0.02);
				float offset2 = 0 + (i * 0.1);
				if ((i <= 5 || i >= 25)) {
					drawScales(xPos, yPos, 0.2001, 0, offset + offset2);
				}
				else if(j<5 || j>10){
					drawScales(xPos, yPos, 0.2001, 0, offset + offset2);
				}
			}
		}

		if (isShadow) { glDisable(GL_TEXTURE_2D); glColor3f(0, 0, 0); }

		jpk->drawJetpack(0.01, 0, anim_value, isShadow);

		// 2. Handle the math separately
		// Wrap this in (!isShadow) to prevent the animation running 2x faster!
		if (!isShadow) {
			if (anim_flag && anim_value < 0.31) {
				anim_value += 0.001;
			}
			else if (!anim_flag && anim_value > 0) {
				anim_value -= 0.001;
			}
		}
		waves_time += 0.01;

	glPopMatrix();
}

void Body :: drawScales(float cx, float cy, float cz,float facingR, float offset){
	float swing = (sin(waves_time+ offset) + 1.0f) * 7.5f;
	glPushMatrix();
	glTranslatef(cx, cy, cz);
	glTranslatef(0, -0.05, 0);
	glRotatef(facingR, 0, 1.0, 0);
	glRotatef(-swing, 1.0, 0, 0);

	glBindTexture(GL_TEXTURE_2D, finsTex);
	glNormal3f(0, 0, 0.7);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-0.01,0,0);
	glTexCoord2f(1, 0);
	glVertex3f(-0.01, -0.05, 0);
	glTexCoord2f(1, 1);
	glVertex3f(0.01, -0.05, 0);
	glTexCoord2f(0, 1);
	glVertex3f(0.01, 0, 0);
	glEnd();
	glPopMatrix();
}

void Body::drawEnergyStone(float cx, float cy,float cz, bool isShadow) {
	float red = abs(sin(time_value * 0.5));

	glPushMatrix();
		glTranslatef(cx, cy, cz);

		if (!isShadow) {
			glColor3f(red, 0.2f, 0.2f);
			GLfloat glow[] = { red * 0.5f, 0.0f, 0.0f, 1.0f };
			glMaterialfv(GL_FRONT, GL_EMISSION, glow);
		}

		gluQuadricNormals(ERStone, GLU_SMOOTH);
		gluSphere(ERStone, 0.1, 100, 100);

		if (!isShadow) {
			glColor3f(1.0f, 1.0f, 1.0f);
			GLfloat noGlow[] = { 0.0f, 0.0f, 0.0f, 1.0f };
			glMaterialfv(GL_FRONT, GL_EMISSION, noGlow);
		}

	glPopMatrix();
	time_value += 0.01;
}
