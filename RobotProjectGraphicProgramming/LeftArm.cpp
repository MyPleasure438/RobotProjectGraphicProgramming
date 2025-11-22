#include "LeftArm.h"

LeftArm::LeftArm() {
    length = 1.0f;
    thickness = 0.3f;
    jointAngle = 0.0f;

    // default position relative to body
    //x = 0.0f;
    //y = 0.0f;
    //z = 0.0f;

    //rx = ry = rz = 0.0f;
}

void LeftArm::updateInput() {
    InputManager& inputManager = InputManager::getInstance();
    LPDIRECTINPUTDEVICE8 dInputKeyboardDevice = inputManager.getDInputKeyboardDevice();
    HRESULT hr = dInputKeyboardDevice->GetDeviceState(256, diKeys);
    if (diKeys[DIK_W] & 0x80) {
        RobotEntireArm_TranslationY = RobotEntireArm_TranslationY + 0.001f;
        
    }

    if (diKeys[DIK_S] & 0x80) {
        RobotEntireArm_TranslationY = RobotEntireArm_TranslationY - 0.001f;

    }

    if (diKeys[DIK_A] & 0x80) {
        xpositionupdate = xpositionupdate - 0.0001f;
        RobotEntireArm_TranslationX = RobotEntireArm_TranslationX - 0.001f;
    }

    if (diKeys[DIK_D] & 0x80) {
        xpositionupdate = xpositionupdate - 0.0001f;
        RobotEntireArm_TranslationX = RobotEntireArm_TranslationX + 0.001f;
    }

    if (diKeys[DIK_Q] & 0x80) {
        RobotEntireArm_TranslationZ = RobotEntireArm_TranslationZ - 0.001f;

    }

    if (diKeys[DIK_E] & 0x80) {
        RobotEntireArm_TranslationZ = RobotEntireArm_TranslationZ + 0.001f;

    }

    if (diKeys[DIK_T] & 0x80) {
        RobotEntireArm_3DRotationAngleY = RobotEntireArm_3DRotationAngleY + 0.1f;

    }

    if (diKeys[DIK_G] & 0x80) {
        RobotEntireArm_3DRotationAngleY = RobotEntireArm_3DRotationAngleY - 0.1f;

    }

    if (diKeys[DIK_F] & 0x80) {
        RobotEntireArm_3DRotationAngleX = RobotEntireArm_3DRotationAngleX - 0.1f;

    }

    if (diKeys[DIK_H] & 0x80) {
        RobotEntireArm_3DRotationAngleX = RobotEntireArm_3DRotationAngleX + 0.1f;

    }

    if (diKeys[DIK_R] & 0x80) {
        RobotEntireArm_3DRotationAngleZ = RobotEntireArm_3DRotationAngleZ - 0.1f;

    }

    if (diKeys[DIK_Y] & 0x80) {
        RobotEntireArm_3DRotationAngleZ = RobotEntireArm_3DRotationAngleZ + 0.1f;

    }

    if (diKeys[DIK_I] & 0x80) {
        RobotElbow_3DRotationAngleY = RobotElbow_3DRotationAngleY + 0.1f;

    }

    if (diKeys[DIK_K] & 0x80) {
        RobotElbow_3DRotationAngleY = RobotElbow_3DRotationAngleY - 0.1f;

    }

    if (diKeys[DIK_J] & 0x80) {
        RobotElbow_3DRotationAngleX = RobotElbow_3DRotationAngleX - 0.1f;

    }

    if (diKeys[DIK_L] & 0x80) {
        RobotElbow_3DRotationAngleX = RobotElbow_3DRotationAngleX + 0.1f;

    }

    if (diKeys[DIK_U] & 0x80) {
        RobotElbow_3DRotationAngleZ = RobotElbow_3DRotationAngleZ - 0.1f;

    }

    if (diKeys[DIK_O] & 0x80) {
        RobotElbow_3DRotationAngleZ = RobotElbow_3DRotationAngleZ + 0.1f;

    }

    // Example: simple arm swing animation
    // jointAngle changes over time (controlled externally)
}

void LeftArm::draw() {
    glPushMatrix();
    glTranslatef(RobotEntireArm_TranslationX, RobotEntireArm_TranslationY, RobotEntireArm_TranslationZ);
    glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
    glTranslatef(shoulder.x, shoulder.y, shoulder.z);
    glPushMatrix();     
        glScalef(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red color for the arm
        glVertex3f(-2.0f, 0.0f, 1.0f);
        glVertex3f(-2.0f, 0.0f, -1.0f);
        glVertex3f(2.0f, 0.0f, -1.0f);
        glVertex3f(2.0f, 0.0f, 1.0f);
    
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-2.0f, 0.0f, 1.0f);
        glVertex3f(-2.0f, 6.0f, 1.0f);
        glVertex3f(-2.0f, 6.0f, -1.0f);
        glVertex3f(-2.0f, 0.0f, -1.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-2.0f, 0.0f, -1.0f);
        glVertex3f(-2.0f, 6.0f, -1.0f);
        glVertex3f(2.0f, 6.0f, -1.0f);
        glVertex3f(2.0f, 0.0f, -1.0f);

        glColor3f(0.7f, 1.0f, 0.0f);
        glVertex3f(-2.0f, 0.0f, 1.0f);
        glVertex3f(2.0f, 0.0f, 1.0f);
        glVertex3f(2.0f, 6.0f, 1.0f);
        glVertex3f(-2.0f, 6.0f, 1.0f);

        glColor3f(0.0f, 1.0f, 0.7f);
        glVertex3f(2.0f, 0.0f, 1.0f);
        glVertex3f(2.0f, 0.0f, -1.0f);
        glVertex3f(2.0f, 6.0f, -1.0f);
        glVertex3f(2.0f, 6.0f, 1.0f);

        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(-2.0f, 6.0f, 1.0f);
        glVertex3f(2.0f, 6.0f, 1.0f);
        glVertex3f(2.0f, 6.0f, -1.0f);
        glVertex3f(-2.0f, 6.0f, -1.0f);
        glEnd();

    glPopMatrix();
    glPushMatrix();
        glRotatef(RobotElbow_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
        glRotatef(RobotElbow_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
        glRotatef(RobotElbow_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
        glTranslatef(elbow.x, elbow.y, elbow.z);
        
        glScalef(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // Red color for the arm
        glVertex3f(-2.0f, 0.0f, 1.0f);
        glVertex3f(-2.0f, 0.0f, -1.0f);
        glVertex3f(2.0f, 0.0f, -1.0f);
        glVertex3f(2.0f, 0.0f, 1.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-2.0f, 0.0f, 1.0f);
        glVertex3f(-2.0f, 6.0f, 1.0f);
        glVertex3f(-2.0f, 6.0f, -1.0f);
        glVertex3f(-2.0f, 0.0f, -1.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-2.0f, 0.0f, -1.0f);
        glVertex3f(-2.0f, 6.0f, -1.0f);
        glVertex3f(2.0f, 6.0f, -1.0f);
        glVertex3f(2.0f, 0.0f, -1.0f);

        glColor3f(0.7f, 1.0f, 0.0f);
        glVertex3f(-2.0f, 0.0f, 1.0f);
        glVertex3f(2.0f, 0.0f, 1.0f);
        glVertex3f(2.0f, 6.0f, 1.0f);
        glVertex3f(-2.0f, 6.0f, 1.0f);

        glColor3f(0.0f, 1.0f, 0.7f);
        glVertex3f(2.0f, 0.0f, 1.0f);
        glVertex3f(2.0f, 0.0f, -1.0f);
        glVertex3f(2.0f, 6.0f, -1.0f);
        glVertex3f(2.0f, 6.0f, 1.0f);

        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(-2.0f, 6.0f, 1.0f);
        glVertex3f(2.0f, 6.0f, 1.0f);
        glVertex3f(2.0f, 6.0f, -1.0f);
        glVertex3f(-2.0f, 6.0f, -1.0f);
        glEnd();
    glPopMatrix();

    glPopMatrix();
    //glPushMatrix();

    // 1. Move to arm position relative to body
    //glTranslatef(x, y, z);

    // 2. Apply rotation for shoulder joint
    //glRotatef(jointAngle, 1.0f, 0.0f, 0.0f);

    // 3. Apply base rotation if robot wants to rotate arm in more axes
    //glRotatef(rx, 1, 0, 0);
    //glRotatef(ry, 0, 1, 0);
    //glRotatef(rz, 0, 0, 1);

    // ------------ DRAW ARM GEOMETRY ----------------
    // Upper arm
    



    //glPushMatrix();
    //glScalef(thickness, length, thickness);
    //glutSolidCube(1.0); // A cube stretched to make an arm
    //glPopMatrix();

    // Forearm (optional)
    //glPushMatrix();
    //glTranslatef(0.0f, -length * 0.9f, 0.0f);
    //glScalef(thickness, length * 0.8f, thickness);
    //glutSolidCube(1.0);
    //glPopMatrix();

    //glPopMatrix();
}

