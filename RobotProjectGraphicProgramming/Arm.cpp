#include "Arm.h"

Arm::Arm() {
    length = 1.0f;
    thickness = 0.3f;
    jointAngle = 0.0f;

    // default position relative to body
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;

    rx = ry = rz = 0.0f;
}

void Arm::update() {
    // Example: simple arm swing animation
    // jointAngle changes over time (controlled externally)
}

void Arm::draw() {
    glPushMatrix();

    // 1. Move to arm position relative to body
    glTranslatef(x, y, z);

    // 2. Apply rotation for shoulder joint
    glRotatef(jointAngle, 1.0f, 0.0f, 0.0f);

    // 3. Apply base rotation if robot wants to rotate arm in more axes
    glRotatef(rx, 1, 0, 0);
    glRotatef(ry, 0, 1, 0);
    glRotatef(rz, 0, 0, 1);

    // ------------ DRAW ARM GEOMETRY ----------------
    // Upper arm
    glPushMatrix();
    glScalef(thickness, length, thickness);
    glutSolidCube(1.0); // A cube stretched to make an arm
    glPopMatrix();

    // Forearm (optional)
    glPushMatrix();
    glTranslatef(0.0f, -length * 0.9f, 0.0f);
    glScalef(thickness, length * 0.8f, thickness);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
}