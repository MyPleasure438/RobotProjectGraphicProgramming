#include "Jetpack.h"

ExperimentationStation Es;

GLUquadricObj* rocket = gluNewQuadric();
GLUquadricObj* fire = gluNewQuadric();

float transitionX = 0;
bool jp_anim_flag = false;
static bool isKey9Pressed = false;

BITMAP BMP;
HBITMAP hBMP = NULL;
GLuint steel;
GLuint metal;

void Jetpack::initTexture() {
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL),
		"Box.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION |
		LR_LOADFROMFILE);
	GetObject(hBMP, sizeof(BMP), &BMP);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &steel);
	glBindTexture(GL_TEXTURE_2D, steel);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL),
		"Box.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION |
		LR_LOADFROMFILE);
	GetObject(hBMP, sizeof(BMP), &BMP);
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &metal);
	glBindTexture(GL_TEXTURE_2D, metal);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
}

void Jetpack::clearTexture() {
	glDeleteTextures(1, &steelTex);
	glDeleteTextures(1, &metal);
}

void Jetpack::jetpackInput() {
	InputManager& inputManager = InputManager::getInstance();
	LPDIRECTINPUTDEVICE8 dInputKeyboardDevice = inputManager.getDInputKeyboardDevice();
	HRESULT hr = dInputKeyboardDevice->GetDeviceState(256, diKeys);
	if (diKeys[DIK_9] & 0x80) {
		// Only execute if the key was NOT pressed in the previous frame
		if (!isKey9Pressed) {
			jp_anim_flag = !jp_anim_flag; // Simple toggle
			isKey9Pressed = true;         // Lock it so it doesn't run again next frame
		}
	}
	else {
		// Key released, unlock it so we can press it again later
		isKey9Pressed = false;
	}

	if (diKeys[DIK_K] & 0x80) {
		if (firepower < 1.0f) {
			firepower += 0.01f;
			std::cout << firepower;
			std::cout << "It work" << std::endl;
		}
	}
}

void Jetpack::drawJetpack(float cx, float cy, float cz) {
	if (jp_anim_flag) {
		if (transitionX < 0.23) {
			transitionX += 0.01;
		}
	}
	else {
		if (transitionX > 0) {
			transitionX -= 0.01;
		}
	}

	glPushMatrix();
	glTranslatef(cx, cy, cz);
	Es.drawCuboid(0.35, 0.3, 0.2, 0, 0, 0, 0, 1, 1,metal);

	glPushMatrix();
	glColor3f(1, 0, 0);
	glRotatef(90, 1.0, 0, 0);
	glPushMatrix();

		glTranslatef(transitionX, 0, -0.05);
		Es.drawCylinder(rocket, 0.05, 0.05, 0.15, 0,steel);
		std::cout << "Current fp" << firepower << std::endl;
		if (firepower >0) {
			glTranslatef(0, 0, 0.3);
			Es.drawCylinder(fire, 0.05, 0, firepower, 0,steel);
			std::cout << "Test" << std::endl;
		}
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-transitionX, 0, -0.05);
		Es.drawCylinder(rocket, 0.05, 0.05, 0.15, 0,steel);
		if (firepower >0) {
			glTranslatef(0, 0, 0.3);
			Es.drawCylinder(fire, 0.05, 0, firepower, 0,steel);
		}
		glPopMatrix();
	glPopMatrix();
	glPopMatrix();
} 