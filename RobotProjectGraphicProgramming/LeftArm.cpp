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
        RobotEntireArm_TranslationY = RobotEntireArm_TranslationY + 0.5f;
    }

    if (diKeys[DIK_S] & 0x80) {
        RobotEntireArm_TranslationY = RobotEntireArm_TranslationY - 0.5f;

    }

    if (diKeys[DIK_A] & 0x80) {
        xpositionupdate = xpositionupdate - 0.0001f;
        RobotEntireArm_TranslationX = RobotEntireArm_TranslationX - 0.5f;
    }

    if (diKeys[DIK_D] & 0x80) {
        xpositionupdate = xpositionupdate - 0.0001f;
        RobotEntireArm_TranslationX = RobotEntireArm_TranslationX + 0.5f;
    }

    if (diKeys[DIK_Q] & 0x80) {
        RobotEntireArm_TranslationZ = RobotEntireArm_TranslationZ - 0.5f;

    }

    if (diKeys[DIK_E] & 0x80) {
        RobotEntireArm_TranslationZ = RobotEntireArm_TranslationZ + 0.5f;

    }

    if (diKeys[DIK_T] & 0x80) {
        RobotEntireArm_3DRotationAngleY = RobotEntireArm_3DRotationAngleY + 0.5f;

    }

    if (diKeys[DIK_G] & 0x80) {
        RobotEntireArm_3DRotationAngleY = RobotEntireArm_3DRotationAngleY - 0.5f;

    }

    if (diKeys[DIK_F] & 0x80) {
        RobotEntireArm_3DRotationAngleX = RobotEntireArm_3DRotationAngleX - 0.5f;

    }

    if (diKeys[DIK_H] & 0x80) {
        RobotEntireArm_3DRotationAngleX = RobotEntireArm_3DRotationAngleX + 0.5f;

    }

    if (diKeys[DIK_R] & 0x80) {
        RobotEntireArm_3DRotationAngleZ = RobotEntireArm_3DRotationAngleZ - 0.5f;

    }

    if (diKeys[DIK_Y] & 0x80) {
        RobotEntireArm_3DRotationAngleZ = RobotEntireArm_3DRotationAngleZ + 0.5f;

    }

    if (diKeys[DIK_I] & 0x80) {
        RobotElbow_3DRotationAngleY = RobotElbow_3DRotationAngleY + 0.5f;

    }

    if (diKeys[DIK_K] & 0x80) {
        RobotElbow_3DRotationAngleY = RobotElbow_3DRotationAngleY - 0.5f;

    }

    if (diKeys[DIK_J] & 0x80) {
        RobotElbow_3DRotationAngleX = RobotElbow_3DRotationAngleX - 0.5f;

    }

    if (diKeys[DIK_L] & 0x80) {
        RobotElbow_3DRotationAngleX = RobotElbow_3DRotationAngleX + 0.5f;

    }

    if (diKeys[DIK_U] & 0x80) {
        RobotElbow_3DRotationAngleZ = RobotElbow_3DRotationAngleZ - 0.5f;

    }

    if (diKeys[DIK_O] & 0x80) {
        RobotElbow_3DRotationAngleZ = RobotElbow_3DRotationAngleZ + 0.5f;

    }

    if (diKeys[DIK_V] & 0x80) {
        slices--;
    }

    if (diKeys[DIK_B] & 0x80) {
        slices++;
    }

    if (diKeys[DIK_N] & 0x80) {
        stacks--;
    }

    if (diKeys[DIK_M] & 0x80) {
        stacks++;
    }

    // Example: simple arm swing animation
    // jointAngle changes over time (controlled externally)
}

void LeftArm::drawJointMarker()
{
    GLUquadric* quad = gluNewQuadric();
    gluSphere(quad, 1.0f, 4, 4);
    gluDeleteQuadric(quad);
}

void LeftArm::drawCuboid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, float red, float green, float blue, GLuint texture)
{
    glPushMatrix();
    //translate the center point for transformation of the cuboid (This acts as a pivot point to rotate the cuboid)
    glTranslatef(centerPointTransformationTranslationX, centerPointTransformationTranslationY, centerPointTransformationTranslationZ);
    //scale first
    glScalef(scaleX, scaleY, scaleZ);
    glColor3f(red, green, blue);
    glBindTexture(GL_TEXTURE_2D, texture);
    Vector3D normal = findNormalVector(Point3D{ -0.5f, -0.5f, -0.5f }, Point3D{ 0.5f, -0.5f, -0.5f }, Point3D{ 0.5f, 0.5f, -0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    //done
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    normal = findNormalVector(Point3D{ 0.5f, 0.5f, -0.5f }, Point3D{ 0.5f, -0.5f, -0.5f }, Point3D{ 0.5f, -0.5f, 0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();

    normal = findNormalVector(Point3D{ -0.5f, 0.5f, 0.5f }, Point3D{ -0.5f, 0.5f, -0.5f }, Point3D{ 0.5f, 0.5f, -0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();

    normal = findNormalVector(Point3D{ -0.5f, -0.5f, 0.5f }, Point3D{ -0.5f, 0.5f, 0.5f }, Point3D{ 0.5f, 0.5f, 0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();

    normal = findNormalVector(Point3D{ -0.5f, 0.5f, -0.5f }, Point3D{ -0.5f, 0.5f, 0.5f }, Point3D{ -0.5f, -0.5f, 0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();

    normal = findNormalVector(Point3D{ -0.5f, -0.5f, 0.5f }, Point3D{ 0.5f, -0.5f, 0.5f }, Point3D{ 0.5f, -0.5f, -0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();

    glPopMatrix();
}

void LeftArm::drawSlantedCuboid(float scaleX, float scaleY, float scaleZ, float additionalSlantedHeight, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, float red, float green, float blue, GLuint texture)
{
    glPushMatrix();
    //translate the center point for transformation of the cuboid (This acts as a pivot point to rotate the cuboid)
    glTranslatef(centerPointTransformationTranslationX, centerPointTransformationTranslationY, centerPointTransformationTranslationZ);
    //scale first
    glScalef(scaleX, scaleY, scaleZ);
    
    glBindTexture(GL_TEXTURE_2D, texture);
    Vector3D normal = findNormalVector(Point3D{ -0.5f, -0.5f, -0.5f }, Point3D{ 0.5f, -0.5f, -0.5f }, Point3D{ 0.5f, 0.5f, -0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    //done
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    //additional slanted height
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f + additionalSlantedHeight, -0.5f);
    //additional slanted height ends///
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    normal = findNormalVector(Point3D{ 0.5f, 0.5f, -0.5f }, Point3D{ 0.5f, -0.5f, -0.5f }, Point3D{ 0.5f, -0.5f, 0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_QUADS);
    //additional slanted height
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.5f, 0.5f + additionalSlantedHeight, -0.5f);
    //additional slanted height ends///
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    //additional slanted height
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f + additionalSlantedHeight, 0.5f);
    //additional slanted height ends///
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    normal = findNormalVector(Point3D{ -0.5f, 0.5f, 0.5f }, Point3D{ -0.5f, 0.5f, -0.5f }, Point3D{ 0.5f, 0.5f, -0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    //additional slanted height
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, 0.5f + additionalSlantedHeight, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f + additionalSlantedHeight, 0.5f);
    //additional slanted height ends///
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    normal = findNormalVector(Point3D{ -0.5f, -0.5f, 0.5f }, Point3D{ -0.5f, 0.5f, 0.5f }, Point3D{ 0.5f, 0.5f, 0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    //additional slanted height
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.5f, 0.5f + additionalSlantedHeight, 0.5f);
    //additional slanted height ends///
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    normal = findNormalVector(Point3D{ -0.5f, 0.5f, -0.5f }, Point3D{ -0.5f, 0.5f, 0.5f }, Point3D{ -0.5f, -0.5f, 0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    normal = findNormalVector(Point3D{ -0.5f, -0.5f, 0.5f }, Point3D{ 0.5f, -0.5f, 0.5f }, Point3D{ 0.5f, -0.5f, -0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();

    glPopMatrix();

}
void LeftArm::drawSphere(GLUquadricObj* quad, float radius, int slices, int stacks, GLuint texture)
{
    // a) declare quadric pointer
    quad = NULL;

    // b) create quadric object
    quad = gluNewQuadric();
    if (quad == NULL)
    {
        printf("Failed to create quadric!\n");
        return;
    }

    gluQuadricTexture(quad, GL_TRUE);
    // e) set quadric draw style
    // Options: GLU_FILL, GLU_LINE, GLU_SILHOUETTE, GLU_POINT
    gluQuadricDrawStyle(quad, GLU_FILL);   // wireframe sphere

    glBindTexture(GL_TEXTURE_2D, texture);

    // c) draw sphere at origin
    gluSphere(quad, radius, slices, stacks);   // radius = 1, slices & stacks = 20

    // f) delete quadric (free memory)
    gluDeleteQuadric(quad);
}

void LeftArm::drawCylinder(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle, GLuint texture)
{
    // a) declare quadric pointer
    quad = NULL;

    // b) create quadric object
    quad = gluNewQuadric();
    if (quad == NULL)
    {
        printf("Failed to create quadric!\n");
        return;
    }

    gluQuadricTexture(quad, GL_TRUE);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    // e) set quadric draw style
    // Options: GLU_FILL, GLU_LINE, GLU_SILHOUETTE, GLU_POINT

    switch (selectedDrawStyle)
    {
    case FILL:
        gluQuadricDrawStyle(quad, GLU_FILL);   // wireframe sphere
        break;
    case LINE:
        gluQuadricDrawStyle(quad, GLU_LINE);   // wireframe sphere
        break;

    case SILHOUETTE:
        gluQuadricDrawStyle(quad, GLU_SILHOUETTE);   // wireframe sphere
        break;

    case POINT:
        gluQuadricDrawStyle(quad, GLU_POINT);   // wireframe sphere
        break;
    }


    // c) draw sphere at origin
    gluCylinder(quad,
        baseRadius,     // bottom radius
        topRadius,      // top radius
        height,         // height
        20,             // slices
        10);            // stacks

    // f) delete quadric (free memory)
    gluDeleteQuadric(quad);
    glPopMatrix();
}

void LeftArm::drawCylinderWithCap(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle, GLuint texture)
{
    // a) declare quadric pointer
    quad = NULL;

    // b) create quadric object
    quad = gluNewQuadric();
    if (quad == NULL)
    {
        printf("Failed to create quadric!\n");
        return;
    }

    gluQuadricTexture(quad, GL_TRUE);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    // e) set quadric draw style
    // Options: GLU_FILL, GLU_LINE, GLU_SILHOUETTE, GLU_POINT

    switch (selectedDrawStyle)
    {
    case FILL:
        gluQuadricDrawStyle(quad, GLU_FILL);   // wireframe sphere
        break;
    case LINE:
        gluQuadricDrawStyle(quad, GLU_LINE);   // wireframe sphere
        break;

    case SILHOUETTE:
        gluQuadricDrawStyle(quad, GLU_SILHOUETTE);   // wireframe sphere
        break;

    case POINT:
        gluQuadricDrawStyle(quad, GLU_POINT);   // wireframe sphere 
        break;
    }
    drawCircle(baseRadius, texture);
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, height);
		drawCircle(topRadius, texture);
    glPopMatrix();
    // c) draw sphere at origin
    gluCylinder(quad,
        baseRadius,     // bottom radius
        topRadius,      // top radius
        height,         // height
        20,             // slices
        10);            // stacks

    // f) delete quadric (free memory)
    gluDeleteQuadric(quad);
    glPopMatrix();
}

void LeftArm::drawCircle(float circleRadius, GLuint texture)
{
    // 1. Bind the texture
    glBindTexture(GL_TEXTURE_2D, texture);

    // 2. Set the color filter to white so the texture appears in its true colors

    // Use GL_TRIANGLE_FAN for better performance and guaranteed behavior
    glBegin(GL_TRIANGLE_FAN);

    // --- CENTER VERTEX ---
    // A. Texture Coordinate: Center of the texture (U=0.5, V=0.5)
    glTexCoord2f(0.5f, 0.5f);
    // B. Geometry: Center of the circle (0, 0, 0)
    glVertex3f(0.0f, 0.0f, 0.0f);

    // --- PERIMETER VERTICES ---
    // Calculate 360 points (or 36-60 for better performance)
    int segments = 60; // Use fewer segments for better performance
    for (int i = 0; i <= segments; i++)
    {
        float angle = i * 360.0f / segments;
        float convertToRadian = angle * 3.14159f / 180.0f;

        // Calculate X and Y vertex positions
        float x = sin(convertToRadian) * circleRadius;
        float y = cos(convertToRadian) * circleRadius;

        // Texture mapping principle for a circle:
        // The position on the circle is mapped to a radius of 0.5 on the texture map.
        // U = 0.5 + 0.5 * cos(angle)
        // V = 0.5 + 0.5 * sin(angle)

        // A. Texture Coordinate: 
        glTexCoord2f(
            0.5f + 0.5f * sin(convertToRadian),
            0.5f + 0.5f * cos(convertToRadian)
        );

        // B. Geometry: 
        glVertex3f(x, y, 0.0f);
    }

    glEnd();

    /*
    glBegin(GL_POLYGON);
    for (float angle = 0; angle <= 360; angle++) {
        float convertToRadian = angle * 3.14159 / 180.0;
        glVertex3f(sin(convertToRadian) * circleRadius, cos(convertToRadian) * circleRadius, 0);
    }
    glEnd();
    */
}

void LeftArm::drawCircleWithHole(float outerRadius, float innerRadius, int segments)
{
    glColor3f(1.0f, 0.88f, 0.74f);
    glBegin(GL_TRIANGLE_STRIP);

    for (float angle = 0; angle <= 360; angle++)
    {
        float rad = angle * 3.14159f / 180.0f;

        float xOuter = sin(rad) * outerRadius;
        float yOuter = cos(rad) * outerRadius;

        float xInner = sin(rad) * innerRadius;
        float yInner = cos(rad) * innerRadius;

        glVertex3f(xOuter, yOuter, 0);
        glVertex3f(xInner, yInner, 0);
    }
    glEnd();
}

void LeftArm::drawPyramid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, GLuint texture)
{
    glPushMatrix();
    //translate the center point for transformation of the cuboid (This acts as a pivot point to rotate the cuboid)
    glTranslatef(centerPointTransformationTranslationX, centerPointTransformationTranslationY, centerPointTransformationTranslationZ);
    //scale first
    glScalef(scaleX, scaleY, scaleZ);

    Vector3D normal = findNormalVector(Point3D{ -0.5f, -0.5f, 0.5f }, Point3D{ 0.5f, -0.5f, 0.5f }, Point3D{ 0.5f, -0.5f, -0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();

    normal = findNormalVector(Point3D{ -0.5f, -0.5f, 0.5f }, Point3D{ 0.0f, 0.5f, 0.0f }, Point3D{ 0.5f, -0.5f, 0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();

    normal = findNormalVector(Point3D{ 0.0f, 0.5f, 0.0f }, Point3D{ 0.5f, -0.5f, -0.5f }, Point3D{ 0.5f, -0.5f, 0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();

    normal = findNormalVector(Point3D{ 0.0f, 0.5f, 0.0f }, Point3D{ -0.5f, -0.5f, -0.5f }, Point3D{ 0.5f, -0.5f, -0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glEnd();

    normal = findNormalVector(Point3D{ 0.0f, 0.5f, 0.0f }, Point3D{ -0.5f, -0.5f, 0.5f }, Point3D{ -0.5f, -0.5f, -0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();
    glPopMatrix();
}

LeftArm::Vector3D LeftArm::findNormalVector(Point3D v1, Point3D v2, Point3D v3)
{
    //remember to input points from most bottom to top so that it is in (clockwise order)
    //P2 - P1 (from p1 to p2)
    Vector3D vectorA = { v2.x - v1.x, v2.y - v1.y, v2.z - v1.z };

    //P3 - P1 (from p1 to p3)
    Vector3D vectorB = { v3.x - v1.x, v3.y - v1.y, v3.z - v1.z };

    Vector3D normal = { vectorA.y * vectorB.z - vectorA.z * vectorB.y, -(vectorA.x * vectorB.z - vectorA.z * vectorB.x), vectorA.x * vectorB.y - vectorA.y * vectorB.x };

    float lengthOfNormalTravelled = sqrt((normal.x * normal.x) + (normal.y * normal.y) + (normal.z * normal.z));

    Vector3D normalizedNormal = { normal.x / lengthOfNormalTravelled, normal.y / lengthOfNormalTravelled , normal.z / lengthOfNormalTravelled };

    //since for some reason this stupid code idk why it gives me the inner normal instead of outer normal, we negative to reverse it to outer normal.
    normalizedNormal = { -normalizedNormal.x, -normalizedNormal.y, -normalizedNormal.z };
    return normalizedNormal;
}

void LeftArm::drawBeautifulCircleWithFlowers(float circleRadius, float baseRadius, float topRadius, float height, int numCylinders, int selectedDrawStyle)
{
    // a) declare quadric pointer
    quad = NULL;

    // b) create quadric object
    quad = gluNewQuadric();
    if (quad == NULL)
    {
        printf("Failed to create quadric!\n");
        return;
    }


    glPushMatrix();
    // e) set quadric draw style
    // Options: GLU_FILL, GLU_LINE, GLU_SILHOUETTE, GLU_POINT

    switch (selectedDrawStyle)
    {
    case FILL:
        gluQuadricDrawStyle(quad, GLU_FILL);   // wireframe sphere
        break;
    case LINE:
        gluQuadricDrawStyle(quad, GLU_LINE);   // wireframe sphere
        break;

    case SILHOUETTE:
        gluQuadricDrawStyle(quad, GLU_SILHOUETTE);   // wireframe sphere
        break;

    case POINT:
        gluQuadricDrawStyle(quad, GLU_POINT);   // wireframe sphere
        break;
    }
    for (int i = 0; i < numCylinders; i++)
    {
        float angle = (float)i * (360.0 / numCylinders); // Calculate angle for current cylinder
        float convertToRadian = angle * 3.14159 / 180.0;

        // Calculate the position (x, y) on the circle's circumference
        float x = sin(convertToRadian) * circleRadius;
        float y = cos(convertToRadian) * circleRadius;

        glPushMatrix(); // Save the current matrix (the world/scene matrix)

        // 1. Translate the drawing origin to the calculated position (x, y)
        glTranslatef(x, y, 0.0);

        // 2. Rotate the cylinder to be perpendicular to the circle's radius
        // We rotate it around the Z-axis by the current angle + 90 degrees
        // (since a cylinder is typically drawn standing up along the Z-axis)
        glRotatef(-angle + 90.0, 0.0, 0.0, 1.0);

        // 3. Draw the cylinder
        gluCylinder(quad,
            baseRadius,     // bottom radius
            topRadius,      // top radius
            height,         // height
            10,             // slices
            5);             // stacks

        glPopMatrix(); // Restore the previous matrix (remove the translation and rotation)
    }

    // f) Delete quadric (free memory)
    gluDeleteQuadric(quad);

    glPopMatrix(); // Restore the matrix before the cylinder drawing loop
}

void LeftArm::drawCylinderAlongCurve(float angleBegins, float angleEnds, float circleXRadius, float circleYRadius, float cylinderRadius, int selectedDrawStyle, GLuint texture)
{
    for (float angle = angleBegins; angle <= angleEnds; angle++) {
        float convertToRadian = angle * 3.14159 / 180.0;
        glPushMatrix();
        glTranslatef(sin(convertToRadian) * circleXRadius, cos(convertToRadian) * circleYRadius, 0);
        glRotatef(90.0f - angle, 0.0f, 0.0f, 1.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        switch (selectedDrawStyle)
        {
        case FILL:
            drawCylinder(quad, cylinderRadius, cylinderRadius, 0.1f, selectedDrawStyle, texture);
            break;
        case LINE:
            drawCylinder(quad, cylinderRadius, cylinderRadius, 0.1f, selectedDrawStyle, texture);
            break;

        case SILHOUETTE:
            drawCylinder(quad, cylinderRadius, cylinderRadius, 0.1f, selectedDrawStyle, texture);
            break;

        case POINT:
            drawCylinder(quad, cylinderRadius, cylinderRadius, 0.1f, selectedDrawStyle, texture);
            break;
        }

        glPopMatrix();
    }

}

void LeftArm::drawText3D(const char* text)
{
    for (int i = 0; text[i] != '\0'; i++)
        glCallList(1000 + text[i]);
    /*
    HDC hdc = wglGetCurrentDC(); // get current device context
    HFONT font = CreateFont(
        12, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
        ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS,
        ANTIALIASED_QUALITY, FF_DONTCARE, "Arial"
    );
    SelectObject(hdc, font);

    wglUseFontBitmaps(hdc, 0, 255, 1000); // generate display lists

    for (int i = 0; text[i] != '\0'; i++)
        glCallList(1000 + text[i]);

    DeleteObject(font);
    */
}

void LeftArm::initFont()
{
    HDC hdc = wglGetCurrentDC();
    HFONT font = CreateFont(
        12, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
        ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS,
        ANTIALIASED_QUALITY, FF_DONTCARE, "Arial"
    );
    SelectObject(hdc, font);
    wglUseFontBitmaps(hdc, 0, 255, 1000); // generate display lists
    DeleteObject(font); // delete the HFONT; display lists remain
}

void LeftArm::loadTextures()
{
    //first texture
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "Box.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);


    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //second texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "metal.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &metal);
    glBindTexture(GL_TEXTURE_2D, metal);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //camouflageWhite texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "camouflageWhite.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &camouflageWhite);
    glBindTexture(GL_TEXTURE_2D, camouflageWhite);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //energyPulse texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "energyPulse.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &energyPulse);
    glBindTexture(GL_TEXTURE_2D, energyPulse);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //minigunCover texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "minigunCover.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &minigunCover);
    glBindTexture(GL_TEXTURE_2D, minigunCover);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //minigunCylinder texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "minigunCylinder.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &minigunCylinder);
    glBindTexture(GL_TEXTURE_2D, minigunCylinder);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //blackMetalic texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "blackMetalic.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &blackMetalic);
    glBindTexture(GL_TEXTURE_2D, blackMetalic);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //glass texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "glass.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &glass);
    glBindTexture(GL_TEXTURE_2D, glass);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //whitePattern texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "whitePattern.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &whitePattern);
    glBindTexture(GL_TEXTURE_2D, whitePattern);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //white texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "white.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &white);
    glBindTexture(GL_TEXTURE_2D, white);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //wristPattern texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "wristPattern.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &wristPattern);
    glBindTexture(GL_TEXTURE_2D, wristPattern);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //deadlyPattern texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "deadlyPattern.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &deadlyPattern);
    glBindTexture(GL_TEXTURE_2D, deadlyPattern);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
    
    //glMatrixMode(GL_TEXTURE);
    //glLoadIdentity();
    //glScalef(30.0, 20.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

void LeftArm::beginScaleTexture(float scaleX, float scaleY)
{
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glScalef(scaleX, scaleY, 1.0f);
    glMatrixMode(GL_MODELVIEW); // Switch back to MODELVIEW for drawing
}

void LeftArm::endScaleTexture()
{
    glMatrixMode(GL_TEXTURE); // Switch to TEXTURE mode to access the stack
    glPopMatrix();            // Restore the saved 1x matrix
    glMatrixMode(GL_MODELVIEW); // Switch back to MODELVIEW for rendering the next object
}

void LeftArm::deleteTextures()
{
    // a) Disable state change (Optional at exit)
    glDisable(GL_TEXTURE_2D);

    // b) Free the Windows GDI object
    DeleteObject(hBMP);

    glDeleteTextures(1, &texture);
    glDeleteTextures(1, &metal);
}

void LeftArm::drawMissle()
{
    //missle
    glPushMatrix();
        glColor3f(0.5f, 0.5f, 0.5f);
        glRotatef(270, 1.0f, 0.0f, 0.0f);
        //    beginScaleTexture(2, 1 );

        drawCylinderWithCap(varCylinder, 1.3f, 0.1f, 1.0f, FILL, wristPattern);
        //red line
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, -0.2f);
            glColor3f(0.5f, 0.0f, 0.0f);
            drawCylinder(varCylinder, 1.5f, 1.3f, 0.2f, FILL, white);
            //light gray area
            glPushMatrix();
                glTranslatef(0.0f, 0.0f, -2.0f);
                glColor3f(0.8f, 0.8f, 0.8f);
                drawCylinder(varCylinder, 1.8f, 1.5f, 2.0f, FILL, deadlyPattern);
                //red line
                glPushMatrix();
                    glTranslatef(0.0f, 0.0f, -0.2f);
                    glColor3f(1.0f, 0.0f, 0.0f);
                    drawCylinder(varCylinder, 1.9f, 1.8f, 0.2f, FILL, white);
                    //little dark gray area
                    glPushMatrix();
                        glTranslatef(0.0f, 0.0f, -0.5f);
                        glColor3f(1.0f, 1.0f, 1.0f);
                        drawCylinder(varCylinder, 2.0f, 1.9f, 0.5f, FILL, white);
                        //red line
                        glPushMatrix();
                            glTranslatef(0.0f, 0.0f, -0.2f);
                            glColor3f(1.0f, 0.0f, 0.0f);
                            drawCylinder(varCylinder, 2.1f, 2.0f, 0.2f, FILL, white);
                            // light gray area
                            glPushMatrix();
                                glTranslatef(0.0f, 0.0f, -6.0f);
                                glColor3f(0.2f, 0.2f, 0.2f);
                                drawCylinderWithCap(varCylinder, 1.3f, 2.1f, 6.0f, FILL, wristPattern );

                                //rocket fins
                                glPushMatrix();
                                    glTranslatef(0.0f, 0.0f, 5.0f);
                                    glRotatef(180, 0.0f, 0.0f, 1.0f);
                                    glRotatef(90, 1.0f, 0.0f, 0.0f);
                                    
                                    for (float angle = 90; angle <= 450; angle = angle+120) {
                                        glPushMatrix();
                                            float convertToRadian = angle * 3.14159 / 180.0;
                                            glTranslatef(0.0f, 0.0f, 0.0f);
                                            glRotatef(angle, 0.0f, 1.0f, 0.0f);
                                            drawSlantedCuboid(4.0f, 1.0f, 0.2f, 0.7f, -2.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, camouflageWhite);
                                        glPopMatrix();
                                    }
                                    
                                glPopMatrix();

                                //second rocket fins
                                glPushMatrix();
                                    glTranslatef(0.0f, 0.0f, 1.0f);
                                    glRotatef(180, 0.0f, 0.0f, 1.0f);
                                    glRotatef(90, 1.0f, 0.0f, 0.0f);

                                    for (float angle = 0; angle <= 360; angle = angle + 90) {
                                        glPushMatrix();
                                            float convertToRadian = angle * 3.14159 / 180.0;
                                            glTranslatef(0.0f, 0.0f, 0.0f);
                                            glRotatef(angle, 0.0f, 1.0f, 0.0f);
                                            drawSlantedCuboid(1.5f, 0.7f, 0.2f, 0.7f, -2.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, camouflageWhite);
                                        glPopMatrix();
                                    }

                                glPopMatrix();
                                //dark gray area
                                glPushMatrix();
                                    glColor3f(0.3f, 0.3f, 0.3f);
                                    glTranslatef(0.0f, 0.0f, -0.5f);
                                    drawCylinderWithCap(varCylinder, 1.3f, 1.3f, 0.5f, FILL, blackMetalic);
                                glPopMatrix();
                            glPopMatrix();
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
            
        glPopMatrix();
    glPopMatrix();
}

void LeftArm::drawRocketLauncher()
{
    //Missle Equpment
    glColor3f(0.92f, 0.92f, 0.92f);
    drawPyramid(2.7f, 2.0f, 2.7f, 0.0f, 0.0f, 0.0f, camouflageWhite);
    
    glPushMatrix();
        glTranslatef(0.0f, -1.0f, 0.0f);
        drawCuboid(2.7f, 5.5f, 2.7f, 0.0f, -2.75f, 0.0f, 0.0f, 0.0f, 0.0f, whitePattern);
        //gray block
        glPushMatrix();
            glTranslatef(0.0f, -5.5f, 0.0f);
            drawCuboid(2.7f, 0.5f, 2.7f, 0.0f, -0.25f, 0.0f, 0.3f, 0.3f, 0.3f, whitePattern);
            //circle hole 1
            glPushMatrix();
                glColor3f(0.0f, 0.0f, 0.0f);
                glTranslatef(-0.5f, -0.5f, 0.5f);
                glRotatef(90, 1.0f, 0.0f, 0.0f);
                drawCylinderAlongCurve(0, 360, 0.4f, 0.4f, 0.05f, FILL, minigunCover);
            glPopMatrix();

            //circle hole 2
            glPushMatrix();
                glColor3f(0.0f, 0.0f, 0.0f);
                glTranslatef(0.5f, -0.5f, 0.5f);
                glRotatef(90, 1.0f, 0.0f, 0.0f);
                drawCylinderAlongCurve(0, 360, 0.4f, 0.4f, 0.05f, FILL, minigunCover);
            glPopMatrix();

            //circle hole 3
            glPushMatrix();
                glColor3f(0.0f, 0.0f, 0.0f);
                glTranslatef(-0.5f, -0.5f, -0.5f);
                glRotatef(90, 1.0f, 0.0f, 0.0f);
                drawCylinderAlongCurve(0, 360, 0.4f, 0.4f, 0.05f, FILL, minigunCover);
            glPopMatrix();

            //circle hole 4
            glPushMatrix();
                glColor3f(0.0f, 0.0f, 0.0f);
                glTranslatef(0.5f, -0.5f, -0.5f);
                glRotatef(90, 1.0f, 0.0f, 0.0f);
                drawCylinderAlongCurve(0, 360, 0.4f, 0.4f, 0.05f, FILL, minigunCover);
            glPopMatrix();

            //scanner circle
            glPushMatrix();
                glColor3f(0.85f, 0.15f, 0.15f);
                glTranslatef(-1.0f, -0.5f, 1.1f);
                glRotatef(90, 1.0f, 0.0f, 0.0f);
                drawCylinderWithCap(quad, 0.2f, 0.2f, 0.1f, FILL, glass);
            glPopMatrix();
            
            // missle projectiles 1
            glPushMatrix();
            bool keyBPressedThisFrame = (diKeys[DIK_B] & 0x80) && !(prevDiKeys[DIK_B] & 0x80);

            if (keyBPressedThisFrame) {
                if (nextMissileToFire == 0) {
                    missiles[0].isActive = true;
                    nextMissileToFire = 1; // Set up to fire the next missile next time
                }
                else if (nextMissileToFire == 1) {
                    missiles[1].isActive = true;
                    nextMissileToFire = 2; // Loop back to the first missile
                }
                else if (nextMissileToFire == 2) {
                    missiles[2].isActive = true;
                    nextMissileToFire = 3; // Loop back to the first missile
                }
                else if (nextMissileToFire == 3) {
                    missiles[3].isActive = true;
                    nextMissileToFire = 4; // Loop back to the first missile
                }
            }
                if (missiles[0].isActive) {
                    missiles[0].currentY -= 5.0f;
                }
                glTranslatef(0.0f, missiles[0].currentY, 0.0f);
                glTranslatef(-0.5f, -0.8f, 0.5f);
                glScalef(0.2f, 0.2f, 0.2f);
                glRotatef(180, 1.0f, 0.0f, 0.0f);
                drawMissle();
            glPopMatrix();

            // missle projectiles 2
            glPushMatrix();
                if (missiles[1].isActive) {
                    missiles[1].currentY -= 5.0f;
                }
                glTranslatef(0.0f, missiles[1].currentY, 0.0f);
                glTranslatef(-0.5f, -0.8f, -0.5f);
                glScalef(0.2f, 0.2f, 0.2f);
                glRotatef(180, 1.0f, 0.0f, 0.0f);
                drawMissle();
            glPopMatrix();

            // missle projectiles 3
            glPushMatrix();
                if (missiles[2].isActive) {
                    missiles[2].currentY -= 5.0f;
                }
                glTranslatef(0.0f, missiles[2].currentY, 0.0f);
                glTranslatef(0.5f, -0.8f, 0.5f);
                glScalef(0.2f, 0.2f, 0.2f);
                glRotatef(180, 1.0f, 0.0f, 0.0f);
                drawMissle();
            glPopMatrix();

            // missle projectiles 4
            glPushMatrix();
                if (missiles[3].isActive) {
                    missiles[3].currentY -= 5.0f;
                }
                glTranslatef(0.0f, missiles[3].currentY, 0.0f);
                glTranslatef(0.5f, -0.8f, -0.5f);
                glScalef(0.2f, 0.2f, 0.2f);
                glRotatef(180, 1.0f, 0.0f, 0.0f);
                drawMissle();

                
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void LeftArm::draw() {
    /*drawJointMarker();
    glRasterPos3f(0, 0, 1);
    sprintf_s(buf, "Ori coordinate (%.1f %.1f %.1f)", 0.0, 0.0, 0.0);
    drawText3D(buf);
    */
    //points for references
    glPushMatrix();
        glTranslatef(shoulder.x, shoulder.y, shoulder.z);
        drawJointMarker();
        glRasterPos3f(0, 0, 1);
        sprintf_s(buf, "Shoulder (%.1f %.1f %.1f)", shoulder.x, shoulder.y, shoulder.z);
        drawText3D(buf);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(shoulder.x, shoulder.y, shoulder.z);
        glTranslatef(elbowOffsetFromShoulder.x, elbowOffsetFromShoulder.y, elbowOffsetFromShoulder.z);
        drawJointMarker();
        glRasterPos3f(0.0f, 1.5f, 3.0f); // slightly above joint
        sprintf_s(buf, "Elbow (%.1f, %.1f, %.1f)", shoulder.x + elbowOffsetFromShoulder.x , shoulder.y + elbowOffsetFromShoulder.y, shoulder.z + elbowOffsetFromShoulder.z);
        drawText3D(buf);
    glPopMatrix();

    

    glPushMatrix();
        glTranslatef(shoulder.x, shoulder.y, shoulder.z);
        glTranslatef(elbowOffsetFromShoulder.x, elbowOffsetFromShoulder.y, elbowOffsetFromShoulder.z);
        glTranslatef(wristOffsetFromElbow.x, wristOffsetFromElbow.y, wristOffsetFromElbow.z);
        drawJointMarker();
        glRasterPos3f(0.0f, 1.5f, 3.0f); // slightly above joint
        sprintf_s(buf, "Wrist (%.1f, %.1f, %.1f)", shoulder.x + elbowOffsetFromShoulder.x + wristOffsetFromElbow.x, shoulder.y + elbowOffsetFromShoulder.y + wristOffsetFromElbow.y, shoulder.z + elbowOffsetFromShoulder.z + wristOffsetFromElbow.z);
        drawText3D(buf);
    glPopMatrix();

    //New Arm
    glPushMatrix();
        glTranslatef(RobotEntireArm_TranslationX, RobotEntireArm_TranslationY, RobotEntireArm_TranslationZ);
        glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
        glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);       
        glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
        
        bool keyMPressedThisFrame = (diKeys[DIK_M] & 0x80) && !(prevDiKeys[DIK_M] & 0x80);
        if (keyMPressedThisFrame) {
            if (nextEntireArmSpeed == 0) {
                entireArmSpeed[0].isActive = true;
                entireArmSpeed[2].isActive = false;
                nextEntireArmSpeed = 1; // Set up to next hand movement next time
            }
            else if (nextEntireArmSpeed == 1) {
                entireArmSpeed[1].isActive = true;
                entireArmSpeed[0].isActive = false;
                nextEntireArmSpeed = 2; // Set up to next hand movement next time
            }
            else if (nextEntireArmSpeed == 2) {
                entireArmSpeed[2].isActive = true;
                entireArmSpeed[1].isActive = false;
                nextEntireArmSpeed = 0; // Loop back to the first hand movement
            }
        }

        if (entireArmSpeed[0].isActive == true)
        {
            anim_value_entireArm += 10;
        }

        if (entireArmSpeed[1].isActive == true)
        {
            anim_value_entireArm += 40;
        }

        if (entireArmSpeed[2].isActive == true)
        {
            anim_value_entireArm += 0;
        }
        glRotatef(anim_value_entireArm, 0.0f, 1.0f, 0.0f);

        glPushMatrix();
	        glTranslatef(shoulder.x, shoulder.y, shoulder.z);
            glColor3f(0.2, 0.2, 0.2);
            //beginScaleTexture(0.1, 0.1);
			drawSphere(varSphere, 1.0f, 100, 100, blackMetalic);

            glColor3f(0.0f, 1.0f, 0.0f);

            
            //small connecting nerve
            glPushMatrix();
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.7, 0.7, 0.7);
			    drawCylinder(varCylinder, 0.7f, 0.5f, 1.0f, FILL, blackMetalic);
            glPopMatrix();
            //Large connecting nerve
            glPushMatrix();
                glTranslatef(0.0f, -1.0f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                drawCylinder(varCylinder, 0.5f, 1.4f, 0.5f, FILL, blackMetalic);
            glPopMatrix();
                
            //upper arm cover cap
            glPushMatrix();
                glTranslatef(0.0f, -1.5f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.2, 0.2, 0.2);
                drawCircle(1.7f, blackMetalic);
            glPopMatrix();
            
            //upper arm
            glPushMatrix();
                glColor3f(1.0, 1.0, 1.0);
                glTranslatef(0.0f, -1.5f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                drawCylinder(varCylinder, 1.7f, 1.3f, 6.0f, FILL, white);  
            glPopMatrix();

            //energy pulse / shield 1

            glPushMatrix();
                glColor3f(0.0f, 0.6f, 1.0f);
                glTranslatef(0.0f, -3.0f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                drawCylinderAlongCurve(0, 360, 1.5f, 1.5f, 0.5f, FILL, glass);
            glPopMatrix();

            //5 spheres on upper arm 1
            glPushMatrix();
                glTranslatef(0.0f, -3.0f, 0.0f);
                for (float angle = 20; angle <= 450; angle = angle + 72) {
                    glPushMatrix();
                        float convertToRadian = angle * 3.14159 / 180.0;
                        glRotatef(angle, 0.0f, 1.0f, 0.0f);
                        glTranslatef(2.4f, 0.0f, 0.0f);
                        drawSphere(quad, 0.5f, 30, 30, energyPulse);
                    glPopMatrix();
                }
                //glColor3f(0.0f, 0.30f, 0.50f);
                //glTranslatef(0.0f, -6.5f, 0.0f);
                //glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                //drawCylinderAlongCurve(0, 360, 1.8f, 1.8f, 0.5f, FILL, NULL);
            glPopMatrix();

            //energy pulse / shield 2

            glPushMatrix();
                glColor3f(0.0f, 0.45f, 0.75f);
                glTranslatef(0.0f, -4.75f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                drawCylinderAlongCurve(0, 360, 1.8f, 1.8f, 0.5f, FILL, glass);
            glPopMatrix();

            //4 spheres on upper arm 2
            glPushMatrix();
                glTranslatef(0.0f, -4.75f, 0.0f);
                for (float angle = 90; angle <= 450; angle = angle + 90) {
                    glPushMatrix();
                        float convertToRadian = angle * 3.14159 / 180.0;
                        glRotatef(angle, 0.0f, 1.0f, 0.0f);
                        glTranslatef(2.4f, 0.0f, 0.0f);
                        drawSphere(quad, 0.5f, 30, 30, energyPulse);
                    glPopMatrix();
                }
                //glColor3f(0.0f, 0.30f, 0.50f);
                //glTranslatef(0.0f, -6.5f, 0.0f);
                //glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                //drawCylinderAlongCurve(0, 360, 1.8f, 1.8f, 0.5f, FILL, NULL);
            glPopMatrix();


            //energy pulse / shield 3

            glPushMatrix();
                glColor3f(0.0f, 0.30f, 0.50f);
                glTranslatef(0.0f, -6.5f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                drawCylinderAlongCurve(0, 360, 1.8f, 1.8f, 0.5f, FILL, glass);
            glPopMatrix();

            //3 spheres on upper arm 3
            glPushMatrix();
                glTranslatef(0.0f, -6.5f, 0.0f);
                for (float angle = 90; angle <= 330; angle = angle + 120) {
                    glPushMatrix();
                        float convertToRadian = angle * 3.14159 / 180.0;
                        glRotatef(angle, 0.0f, 1.0f, 0.0f);
                        glTranslatef(2.4f, 0.0f, 0.0f);
                        drawSphere(quad, 0.5f, 30, 30, energyPulse);
                    glPopMatrix();
                }
                //glColor3f(0.0f, 0.30f, 0.50f);
                //glTranslatef(0.0f, -6.5f, 0.0f);
                //glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                //drawCylinderAlongCurve(0, 360, 1.8f, 1.8f, 0.5f, FILL, NULL);
            glPopMatrix();


            //Small connecting nerve to elbow
            glPushMatrix();
                glColor3f(0.0f, 0.15f, 0.25f);
                glTranslatef(0.0f, -7.5f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                drawCylinder(varCylinder, 1.3f, 0.5f, 1.00f, FILL, blackMetalic);
            glPopMatrix();

            //elbow joint
            glPushMatrix();
                glTranslatef(elbowOffsetFromShoulder.x, elbowOffsetFromShoulder.y, elbowOffsetFromShoulder.z);
                glRotatef(RobotElbow_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
                glRotatef(RobotElbow_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
                glRotatef(RobotElbow_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
                glPushMatrix();
                    glColor3f(0.2, 0.2, 0.2);
                    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
				    drawSphere(varSphere, 1.0f, 100, 100, blackMetalic);
                glPopMatrix();
                
                

                //Minigun
                glPushMatrix();
                    glTranslatef(0.0f, -1.6f, -3.7f);
                    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                    glScalef(0.5f, 0.5f, 1.0f);

                    glPushMatrix();
                    
                    bool keyNPressedThisFrame = (diKeys[DIK_N] & 0x80) && !(prevDiKeys[DIK_N] & 0x80);

                    if (keyNPressedThisFrame) {
                        if (nextMinigunSpeed == 0) {
                            minigunSpeed[0].isActive = true;
                            minigunSpeed[2].isActive = false;
                            nextMinigunSpeed = 1; // Set up to next hand movement next time
                        }
                        else if (nextMinigunSpeed == 1) {
                            minigunSpeed[1].isActive = true;
                            minigunSpeed[0].isActive = false;
                            nextMinigunSpeed = 2; // Set up to next hand movement next time
                        }
                        else if (nextMinigunSpeed == 2) {
                            minigunSpeed[2].isActive = true;
                            minigunSpeed[1].isActive = false;
                            nextMinigunSpeed = 0; // Loop back to the first hand movement
                        }
                    }

                    if (minigunSpeed[0].isActive == true)
                    {
                        anim_value_minigun += 10;
                    }

                    if (minigunSpeed[1].isActive == true)
                    {
                        anim_value_minigun += 40;
                    }

                    if (minigunSpeed[2].isActive == true)
                    {
                        anim_value_minigun += 0;
                    }
                    //std::cout << "anim_value_minigun:" << anim_value_minigun;
                    glRotatef(anim_value_minigun, 0.0f, 0.0f, 1.0f);

                        glPushMatrix();
                            glColor3f(0.0f, 0.0f, 0.0f);
                            glTranslatef(0.0f, 0.0f, 0.0f);
                            drawCylinderWithCap(varCylinder, 1.2f, 1.2f, 12.0f, FILL, minigunCylinder);
                        glPopMatrix();

                        glColor3f(0.0f, 0.0f, 0.0f);
                        for (float angle = 0; angle <= 360; angle = angle + 60) {
                            glPushMatrix();
                                float convertToRadian = angle * 3.14159 / 180.0;
                                glTranslatef(sin(convertToRadian) * 2.6f, cos(convertToRadian) * 2.6f, 0);
                                drawCylinderWithCap(varCylinder, 1.0f, 1.0f, 12.0f, FILL, minigunCylinder);
                            glPopMatrix();
                            //glVertex3f(sin(convertToRadian) * circleRadius, cos(convertToRadian) * circleRadius, 0);
                        }
                        glPopMatrix();
                    //minigun cover
                    glPushMatrix();
                        glColor3f(1.0f, 1.0f, 1.0f);
                        glTranslatef(0.0f, 0.0f, -0.1f);
                        drawCylinderWithCap(varCylinder, 4.0f, 4.0f, 2.0f, FILL, minigunCover);
                        glPushMatrix();
                            glTranslatef(0.0f, 0.0f, 4.0f);
                            drawCylinderWithCap(varCylinder, 3.7f, 3.7f, 0.6f, FILL, minigunCover);
                            glPushMatrix();
                                glTranslatef(0.0f, 0.0f, 4.0f);
                                drawCylinderWithCap(varCylinder, 3.7f, 3.7f, 0.6f, FILL, minigunCover);
                                glPushMatrix();
                                    glTranslatef(0.0f, 0.0f, 2.0f);
                                    drawCylinderWithCap(varCylinder, 3.7f, 3.7f, 0.6f, FILL, minigunCover);
                                glPopMatrix();
                            glPopMatrix();
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();

                //rocket launcher
                glPushMatrix();
                    glTranslatef(0.0f, 0.0f, 3.0f);
                    drawRocketLauncher();
                glPopMatrix();
                //elbow joint small connecting nerve
                glPushMatrix();
                    glTranslatef(0.0f, 0.0f, 0.0f);
				    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                    glColor3f(0.7, 0.7, 0.7);
                    drawCylinder(varCylinder, 0.7f, 0.5f, 1.0f, FILL, blackMetalic);
                glPopMatrix();
                //elbow joint large connecting nerve
                glPushMatrix();
                    glTranslatef(0.0f, -1.0f, 0.0f);
                    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                    drawCylinder(varCylinder, 0.5f, 1.4f, 0.5f, FILL, blackMetalic);
                glPopMatrix();

                // lowerarm cover cap
                glPushMatrix();
                    glTranslatef(0.0f, -1.5f, 0.0f);
                    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                    glColor3f(0.2, 0.2, 0.2);
                    drawCircle(1.7f, white);
                glPopMatrix();

                //lower arm
                glPushMatrix();
                    glTranslatef(0.0f, -1.5f, 0.0f);
                    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                    glColor3f(0.7, 0.7, 0.7);
                    drawCylinder(varCylinder, 1.7f, 1.5f, 6.0f, FILL, camouflageWhite);
                glPopMatrix();

                // lowerarm bottom cover cap
                glPushMatrix();
                    glTranslatef(0.0f, -7.5f, 0.0f);
                    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                    glColor3f(0.7f, 0.7f, 0.7f); 
                    drawCircle(1.5f, blackMetalic);
                glPopMatrix();
                
				//Small connecting nerve to wrist
                glPushMatrix();
                    glTranslatef(0.0f, -7.5f, 0.0f);
                    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                    glColor3f(0.7f, 0.7f, 0.7f);
                    drawCylinder(varCylinder, 1.3f, 0.5f, 1.00f, FILL, blackMetalic);
                glPopMatrix();


				//wrist joint
                glPushMatrix();
                    glTranslatef(wristOffsetFromElbow.x, wristOffsetFromElbow.y, wristOffsetFromElbow.z);
                    glRotatef(RobotWrist_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
                    glRotatef(RobotWrist_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
                    glRotatef(RobotWrist_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
                    
                    
                    bool keyVPressedThisFrame = (diKeys[DIK_V] & 0x80) && !(prevDiKeys[DIK_V] & 0x80);

                    if (keyVPressedThisFrame) {
                        if (nextHandMovement == 0) {
                            handMovement[0].isActive = true;
                            nextHandMovement = 1; // Set up to next hand movement next time
                        }
                        else if (nextHandMovement == 1) {
                            handMovement[1].isActive = true;
                            handMovement[0].isActive = false;
                            nextHandMovement = 2; // Set up to next hand movement next time
                        }
                        else if (nextHandMovement == 2) {
                            handMovement[2].isActive = true;
                            handMovement[1].isActive = false;
                            nextHandMovement = 0; // Loop back to the first hand movement
                        }
                    }
                    //hand movement 1
                    if (handMovement[0].isActive) {
                        //rotate wrist upwards
                        if (handMovement[0].currentRotationX >= -90)
                        {
                            handMovement[0].currentRotationX = handMovement[0].currentRotationX - 5.0f;
                        }
                    }

                    //hand movement2
                    if (handMovement[1].isActive) {
                        //rotate wrist upwards
                        if (handMovement[0].currentRotationX <= 0)
                        {
                            handMovement[0].currentRotationX = handMovement[0].currentRotationX + 5.0f;
                        }
                    }

                    glRotatef(handMovement[0].currentRotationX, 1.0f, 0.0f, 0.0f);

                    glPushMatrix();
                        glTranslatef(0.0f, -1.0f, 0.0f);
                        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                        glColor3f(0.0f, 0.0f, 0.0f); 
                        drawCylinder(varCylinder, 0.5f, 0.7f, 0.3f, FILL, blackMetalic);
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(0.0f, -1.3f, 0.0f);
                        drawCuboid(3.4f, 3.8f, 1.4f, 0.0f, -1.9f, 0.0f, 0.0f, 0.0f, 0.0f, wristPattern);
                        //drawSphere(varSphere, 1.0f, 100, 100
                    
                    glPopMatrix();
                    //thumb finger
                    glPushMatrix();
                        glTranslatef(-1.0f, -3.6f, 0.0f);
                        glRotatef(300.0f, 0.0f, 0.0f, 1.0f);
                        glPushMatrix();
                            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                            glColor3f(1.0f, 0.0f, 0.0f);
                            drawCylinder(varCylinder, 0.6f, 0.3f, 1.6f, FILL, whitePattern);
                        glPopMatrix();

                        glPushMatrix();
                            glTranslatef(0.0f, -1.2f, 0.0f);
                            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                            glColor3f(1.0f, 0.0f, 0.0f);
                            drawCylinder(varCylinder, 0.3f, 0.2f, 1.4f, FILL, whitePattern);

							//for cylinder cap, supposingly is y axis negative offset, but because of rotation it becomes z axis positive
                            glTranslatef(0.0f, 0.0f, 1.4f);
                            glColor3f(0.0f, 0.0f, 0.0f);
                            drawCircle(0.2f, NULL);
                        glPopMatrix();
                    glPopMatrix();
                  

                    //four fingers
                    glPushMatrix();
                        //fingers rotate transformation if needed
                        /*
                        glRotatef(RobotElbow_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
                        glRotatef(RobotElbow_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
                        glRotatef(RobotElbow_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
                        */
					    glTranslatef(finger1OffsetFromWrist.x, finger1OffsetFromWrist.y, finger1OffsetFromWrist.z);
                        //glRotatef(150, 1.0f, 0.0f, 0.0f);
                        glPushMatrix();
                            glRotatef(90.0f, 1.0f, 0.0f , 0.0f);
                            glColor3f(1.0f, 0.0f, 0.0f);
                            drawCylinder(varCylinder, 0.425f, 0.2f, 2.0f, FILL, whitePattern);
                        glPopMatrix();
                        glPushMatrix();
                            glTranslatef(fingerMiddleJoint1OffsetFromFinger.x, fingerMiddleJoint1OffsetFromFinger.y, fingerMiddleJoint1OffsetFromFinger.z);
                            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
							drawCylinder(varCylinder, 0.2f, 0.15f, 1.6f, FILL, whitePattern);
                            glPushMatrix();
							//supposingly is y axis negative offset, but because of rotation it becomes z axis
                                glTranslatef(0.0f, 0.0f, 1.6f);
                                glColor3f(0.0f, 0.0f, 0.0f);
                                drawCircle(0.15f, whitePattern);
                            glPopMatrix();
                        glPopMatrix();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(finger2OffsetFromWrist.x, finger2OffsetFromWrist.y, finger2OffsetFromWrist.z);
                        glPushMatrix();
                            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                            glColor3f(1.0f, 0.0f, 0.0f);
                            drawCylinder(varCylinder, 0.425f, 0.2f, 2.0f, FILL, whitePattern);
                        glPopMatrix();
                        glPushMatrix();
                            glTranslatef(fingerMiddleJoint2OffsetFromFinger.x, fingerMiddleJoint2OffsetFromFinger.y, fingerMiddleJoint2OffsetFromFinger.z);
                            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                            drawCylinder(varCylinder, 0.2f, 0.15f, 1.6f, FILL, whitePattern);
                            glPushMatrix();
							//supposingly is y axis negative offset, but because of rotation it becomes z axis
                                glTranslatef(0.0f, 0.0f, 1.6f);
                                glColor3f(0.0f, 0.0f, 0.0f);
                                drawCircle(0.15f, whitePattern);
                            glPopMatrix();
                        glPopMatrix();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(finger3OffsetFromWrist.x, finger3OffsetFromWrist.y, finger3OffsetFromWrist.z);
                        glPushMatrix();
                            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                            glColor3f(1.0f, 0.0f, 0.0f);
                            drawCylinder(varCylinder, 0.425f, 0.2f, 2.0f, FILL, whitePattern);
                        glPopMatrix();
                        glPushMatrix();
                            glTranslatef(fingerMiddleJoint3OffsetFromFinger.x, fingerMiddleJoint3OffsetFromFinger.y, fingerMiddleJoint3OffsetFromFinger.z);
                            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                            drawCylinder(varCylinder, 0.2f, 0.15f, 1.6f, FILL, whitePattern);
                            glPushMatrix();
							//supposingly is y axis negative offset, but because of rotation it becomes z axis
                                glTranslatef(0.0f, 0.0f, 1.6f);
                                glColor3f(0.0f, 0.0f, 0.0f);
                                drawCircle(0.15f, whitePattern);
                            glPopMatrix();
                        glPopMatrix();
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(finger4OffsetFromWrist.x, finger4OffsetFromWrist.y, finger4OffsetFromWrist.z);
                        glPushMatrix();
                            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                            glColor3f(1.0f, 0.0f, 0.0f);
                            drawCylinder(varCylinder, 0.425f, 0.2f, 2.0f, FILL, whitePattern);
                        glPopMatrix();
                        glPushMatrix();
                            glTranslatef(fingerMiddleJoint4OffsetFromFinger.x, fingerMiddleJoint4OffsetFromFinger.y, fingerMiddleJoint4OffsetFromFinger.z);
                            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                            drawCylinder(varCylinder, 0.2f, 0.15f, 1.6f, FILL, whitePattern);
                            glPushMatrix();
							//supposingly is y axis negative offset, but because of rotation it becomes z axis
                                glTranslatef(0.0f, 0.0f, 1.6f);
                                glColor3f(0.0f, 0.0f, 0.0f);
                                drawCircle(0.15f, whitePattern);
                            glPopMatrix();
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    //*** CRITICAL STEP ***: Save the current input state for the next frame's check (Put at after everything done)
    memcpy(prevDiKeys, diKeys, sizeof(diKeys));

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


 

void LeftArm::draw2()
{
    //
    glPushMatrix();
        glTranslatef(RobotEntireArm_TranslationX, RobotEntireArm_TranslationY, RobotEntireArm_TranslationZ);
        glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
        glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);       
        glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
    
        //first Joint
        glPushMatrix();
            glColor3f(0.0f, 0.0f, 0.0f);
            drawSphere(varSphere, 1.0f, 30, 30, NULL);
            glPushMatrix();
                glColor3f(1.0f, 1.0f, 1.0f);
                glTranslatef(0.0f, 3.0f, 0.0f);
                drawSphere(varSphere, 3.0f, 30, 30, NULL);
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();
    //Minigun
    /*
    glTranslatef(RobotEntireArm_TranslationX, RobotEntireArm_TranslationY, RobotEntireArm_TranslationZ);
    glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
    glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f);
        glTranslatef(0.0f, 0.0f, 0.0f);
        drawCylinderWithCap(varCylinder, 1.2f, 1.2f, 12.0f, FILL, NULL);
    glPopMatrix();

    glColor3f(0.0f, 0.0f, 0.0f);
    for (float angle = 0; angle <= 360; angle = angle + 60) {
        glPushMatrix();
        float convertToRadian = angle * 3.14159 / 180.0;
        glTranslatef(sin(convertToRadian) * 2.6f, cos(convertToRadian) * 2.6f, 0);
        drawCylinderWithCap(varCylinder, 1.0f, 1.0f, 12.0f, FILL, NULL);
        glPopMatrix();
        //glVertex3f(sin(convertToRadian) * circleRadius, cos(convertToRadian) * circleRadius, 0);
    }
    //minigun cover
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(0.0f, 0.0f, -0.1f);
        drawCylinderWithCap(varCylinder, 4.0f, 4.0f, 2.0f, FILL, NULL);
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, 4.0f);
            drawCylinderWithCap(varCylinder, 3.7f, 3.7f, 0.6f, FILL, NULL);
            glPushMatrix();
                glTranslatef(0.0f, 0.0f, 4.0f);
                drawCylinderWithCap(varCylinder, 3.7f, 3.7f, 0.6f, FILL, NULL);
                glPushMatrix();
                    glTranslatef(0.0f, 0.0f, 2.0f);
                    drawCylinderWithCap(varCylinder, 3.7f, 3.7f, 0.6f, FILL, NULL);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    */
}