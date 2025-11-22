#include "Robot.h"
Robot::Robot() {
    // Position parts relative to body
    //head.y = 1.5f;
    //leftArm.x = -0.8f;
    //rightArm.x = 0.8f;
    //leftLeg.x = -0.3f;
    //rightLeg.x = 0.3f;
}

void Robot::update() {
    // Example walking animation
    //armSwingAngle = sin(glutGet(GLUT_ELAPSED_TIME) * 0.005f) * 30.0f;
    //legWalkAngle = sin(glutGet(GLUT_ELAPSED_TIME) * 0.005f) * 45.0f;

    //leftArm.rx = armSwingAngle;
    //rightArm.rx = -armSwingAngle;

    //leftLeg.rx = -legWalkAngle;
    //rightLeg.rx = legWalkAngle;
}

void Robot::draw() {
    glPushMatrix();

    //body.draw();

    glPushMatrix();
    glTranslatef(0, head.y, 0);
    //head.draw();
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(leftArm.x, leftArm.y, leftArm.z);
    //leftArm.draw();
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(rightArm.x, rightArm.y, rightArm.z);
    //rightArm.draw();
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(leftLeg.x, leftLeg.y, leftLeg.z);
    //leftLeg.draw();
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(rightLeg.x, rightLeg.y, rightLeg.z);
    //rightLeg.draw();
    glPopMatrix();

    glPopMatrix();
}
