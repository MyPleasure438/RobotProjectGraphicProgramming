#include "Head.h"

Head::Head() {
    length = 1.0f;
    thickness = 0.3f;
    jointAngle = 0.0f;

    // default position relative to body
    //x = 0.0f;
    //y = 0.0f;
    //z = 0.0f;

    //rx = ry = rz = 0.0f;
}

void Head::updateInput() {
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

void Head::drawJointMarker()
{
    GLUquadric* quad = gluNewQuadric();
    gluSphere(quad, 1.0f, 4, 4);
    gluDeleteQuadric(quad);
}

void Head::drawCuboid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, float red, float green, float blue, GLuint texture, bool isShadow)
{
    glPushMatrix();
    //translate the center point for transformation of the cuboid (This acts as a pivot point to rotate the cuboid)
    glTranslatef(centerPointTransformationTranslationX, centerPointTransformationTranslationY, centerPointTransformationTranslationZ);
    //scale first
    glScalef(scaleX, scaleY, scaleZ);

    if (!isShadow) {
        glColor3f(red, green, blue);
    }

    if (isShadow) {
        texture = 0;
    }

    
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

void Head::drawSlantedCuboid(float scaleX, float scaleY, float scaleZ, float additionalSlantedHeight, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, float red, float green, float blue, GLuint texture)
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

void Head::drawSphere(GLUquadricObj* quad, float radius, int slices, int stacks, GLuint texture)
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

void Head::drawCylinder(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle, GLuint texture)
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

void Head::drawCylinderWithCap(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle, GLuint texture, bool isShadow)
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

    if(isShadow) {
        gluQuadricTexture(quad, GL_FALSE); 
        glDisable(GL_TEXTURE_2D);          
        glBindTexture(GL_TEXTURE_2D, 0);   
    }
    else {
        gluQuadricTexture(quad, GL_TRUE);  
        glEnable(GL_TEXTURE_2D);           
        glBindTexture(GL_TEXTURE_2D, texture); 
    }

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

    drawCircle(baseRadius, texture,isShadow);
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, height);
    drawCircle(topRadius, texture, isShadow);
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

void Head::drawCircle(float circleRadius, GLuint texture, bool isShadow)
{
    // 1. Bind the texture
    if (isShadow) {
        texture = 0;
    }

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

void Head::drawCircleWithHole(float outerRadius, float innerRadius, int segments)
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

void Head::drawPyramid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, GLuint texture)
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

Head::Vector3D Head::findNormalVector(Point3D v1, Point3D v2, Point3D v3)
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

void Head::drawBeautifulCircleWithFlowers(float circleRadius, float baseRadius, float topRadius, float height, int numCylinders, int selectedDrawStyle)
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

void Head::drawCylinderAlongCurve(float angleBegins, float angleEnds, float circleXRadius, float circleYRadius, float cylinderRadius, int selectedDrawStyle, GLuint texture)
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

void Head::drawText3D(const char* text)
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

void Head::initFont()
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

void Head::loadTextures()
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

    //blackGlossy texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "blackGlossy.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &blackGlossy);
    glBindTexture(GL_TEXTURE_2D, blackGlossy);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //fire texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "fire.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &fire);
    glBindTexture(GL_TEXTURE_2D, fire);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
}

void Head::beginScaleTexture(float scaleX, float scaleY)
{
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glScalef(scaleX, scaleY, 1.0f);
    glMatrixMode(GL_MODELVIEW); // Switch back to MODELVIEW for drawing
}

void Head::endScaleTexture()
{
    glMatrixMode(GL_TEXTURE); // Switch to TEXTURE mode to access the stack
    glPopMatrix();            // Restore the saved 1x matrix
    glMatrixMode(GL_MODELVIEW); // Switch back to MODELVIEW for rendering the next object
}

void Head::deleteTextures()
{
    // a) Disable state change (Optional at exit)
    glDisable(GL_TEXTURE_2D);

    // b) Free the Windows GDI object
    DeleteObject(hBMP);

    glDeleteTextures(1, &texture);
    glDeleteTextures(1, &metal);
}

void Head::drawMissle()
{
    //missle
    glPushMatrix();
        glColor3f(0.5f, 0.5f, 0.5f);
        glRotatef(270, 1.0f, 0.0f, 0.0f);
        drawCylinderWithCap(varCylinder, 1.3f, 0.1f, 1.0f, FILL, NULL,false);
        //red line
        glPushMatrix();
            glTranslatef(0.0f, 0.0f, -0.2f);
            glColor3f(0.5f, 0.0f, 0.0f);
            drawCylinder(varCylinder, 1.5f, 1.3f, 0.2f, FILL, NULL);
            //light gray area
            glPushMatrix();
                glTranslatef(0.0f, 0.0f, -2.0f);
                glColor3f(0.8f, 0.8f, 0.8f);
                drawCylinder(varCylinder, 1.8f, 1.5f, 2.0f, FILL, NULL);
                //red line
                glPushMatrix();
                    glTranslatef(0.0f, 0.0f, -0.2f);
                    glColor3f(1.0f, 0.0f, 0.0f);
                    drawCylinder(varCylinder, 1.9f, 1.8f, 0.2f, FILL, NULL);
                    //little dark gray area
                    glPushMatrix();
                        glTranslatef(0.0f, 0.0f, -0.5f);
                        glColor3f(0.5f, 0.5f, 0.5f);
                        drawCylinder(varCylinder, 2.0f, 1.9f, 0.5f, FILL, NULL);
                        //red line
                        glPushMatrix();
                            glTranslatef(0.0f, 0.0f, -0.2f);
                            glColor3f(0.5f, 0.0f, 0.0f);
                            drawCylinder(varCylinder, 2.1f, 2.0f, 0.2f, FILL, NULL);
                            // light gray area
                            glPushMatrix();
                                glTranslatef(0.0f, 0.0f, -6.0f);
                                glColor3f(0.8f, 0.8f, 0.8f);
                                drawCylinderWithCap(varCylinder, 1.3f, 2.1f, 6.0f, FILL, NULL,false);

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
                                            drawSlantedCuboid(4.0f, 1.0f, 0.2f, 0.7f, -2.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, NULL);
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
                                            drawSlantedCuboid(1.5f, 0.7f, 0.2f, 0.7f, -2.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, NULL);
                                        glPopMatrix();
                                    }

                                glPopMatrix();
                                //dark gray area
                                glPushMatrix();
                                    glColor3f(0.3f, 0.3f, 0.3f);
                                    glTranslatef(0.0f, 0.0f, -0.5f);
                                    drawCylinderWithCap(varCylinder, 1.3f, 1.3f, 0.5f, FILL, NULL,false);
                                glPopMatrix();
                            glPopMatrix();
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
            
        glPopMatrix();
    glPopMatrix();
}

void Head::drawRocketLauncher(bool isShadow)
{
    //Missle Equpment
    glColor3f(0.92f, 0.92f, 0.92f);
    drawPyramid(2.7f, 2.0f, 2.7f, 0.0f, 0.0f, 0.0f, NULL);
    
    glPushMatrix();
        glTranslatef(0.0f, -1.0f, 0.0f);
        drawCuboid(2.7f, 5.5f, 2.7f, 0.0f, -2.75f, 0.0f, 0.0f, 0.0f, 0.0f, NULL,isShadow);
        //gray block
        glPushMatrix();
            glTranslatef(0.0f, -5.5f, 0.0f);
            drawCuboid(2.7f, 0.5f, 2.7f, 0.0f, -0.25f, 0.0f, 0.3f, 0.3f, 0.3f, NULL,isShadow);
            //circle hole 1
            glPushMatrix();
                glColor3f(0.0f, 0.0f, 0.0f);
                glTranslatef(-0.5f, -0.5f, 0.5f);
                glRotatef(90, 1.0f, 0.0f, 0.0f);
                drawCylinderAlongCurve(0, 360, 0.4f, 0.4f, 0.05f, FILL, NULL);
            glPopMatrix();

            //circle hole 2
            glPushMatrix();
                glColor3f(0.0f, 0.0f, 0.0f);
                glTranslatef(0.5f, -0.5f, 0.5f);
                glRotatef(90, 1.0f, 0.0f, 0.0f);
                drawCylinderAlongCurve(0, 360, 0.4f, 0.4f, 0.05f, FILL, NULL);
            glPopMatrix();

            //circle hole 3
            glPushMatrix();
                glColor3f(0.0f, 0.0f, 0.0f);
                glTranslatef(-0.5f, -0.5f, -0.5f);
                glRotatef(90, 1.0f, 0.0f, 0.0f);
                drawCylinderAlongCurve(0, 360, 0.4f, 0.4f, 0.05f, FILL, NULL);
            glPopMatrix();

            //circle hole 4
            glPushMatrix();
                glColor3f(0.0f, 0.0f, 0.0f);
                glTranslatef(0.5f, -0.5f, -0.5f);
                glRotatef(90, 1.0f, 0.0f, 0.0f);
                drawCylinderAlongCurve(0, 360, 0.4f, 0.4f, 0.05f, FILL, NULL);
            glPopMatrix();

            //scanner circle
            glPushMatrix();
                glColor3f(0.85f, 0.15f, 0.15f);
                glTranslatef(-1.0f, -0.5f, 1.1f);
                glRotatef(90, 1.0f, 0.0f, 0.0f);
                drawCylinderWithCap(quad, 0.2f, 0.2f, 0.1f, FILL, NULL,false);
            glPopMatrix();
            
            // missle projectiles 1
            glPushMatrix();
                glTranslatef(-0.5f, -0.8f, 0.5f);
                glScalef(0.2f, 0.2f, 0.2f);
                glRotatef(180, 1.0f, 0.0f, 0.0f);
                drawMissle();
            glPopMatrix();

            // missle projectiles 2
            glPushMatrix();
                glTranslatef(-0.5f, -0.8f, -0.5f);
                glScalef(0.2f, 0.2f, 0.2f);
                glRotatef(180, 1.0f, 0.0f, 0.0f);
                drawMissle();
            glPopMatrix();

            // missle projectiles 3
            glPushMatrix();
                glTranslatef(0.5f, -0.8f, 0.5f);
                glScalef(0.2f, 0.2f, 0.2f);
                glRotatef(180, 1.0f, 0.0f, 0.0f);
                drawMissle();
            glPopMatrix();

            // missle projectiles 4
            glPushMatrix();
                glTranslatef(0.5f, -0.8f, -0.5f);
                glScalef(0.2f, 0.2f, 0.2f);
                glRotatef(180, 1.0f, 0.0f, 0.0f);
                drawMissle();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Head::draw() {
   
}

void Head::draw2(bool isShadow)
{
    //
    glPushMatrix();
        glTranslatef(RobotEntireArm_TranslationX, RobotEntireArm_TranslationY, RobotEntireArm_TranslationZ);
        glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
        glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);       
        glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);

        //first Head Joint
        glPushMatrix();
            glColor3f(0.0f, 0.0f, 0.0f);
            drawSphere(varSphere, 1.0f, 30, 30, blackMetalic);
            glTranslatef(0.0f, -0.5f, 0.0f);

            //Cuboid Gun
            glPushMatrix();
                glTranslatef(0.0f, 1.2f, 6.5f);
                drawCuboid(4.0f, 5.0f, 10.0f, 0.0f, 2.5f, 0.0f, 0.8f, 0.8f, 0.8f, camouflageWhite,isShadow);
            glPopMatrix();

            //Cuboid Gun on Top
            glPushMatrix();
                glTranslatef(0.0f, 5.0f, 10.0f);
                drawCuboid(1.5f, 1.5f, 3.0f, 0.0f, 2.5f, 0.0f, 0.5f, 0.5f, 0.5f, blackGlossy,isShadow);
            glPopMatrix();
            
            //Cuboid Gun on Top down part
            glPushMatrix();
                glTranslatef(0.0f, 4.0f, 6.5f);
                drawCuboid(3.8f, 0.5f, 10.0f, 0.0f, 2.5f, 0.0f, 0.1f, 0.1f, 0.1f, blackGlossy,isShadow);
            glPopMatrix();

            //Cylindrical Top head gun part
            glPushMatrix();
                glTranslatef(0.0f, 7.0f, 1.5f);
                glColor3f(0.30f, 0.05f, 0.05f);
                drawCylinderWithCap(varCylinder, 0.7f, 0.7f, 7.0f, FILL, blackGlossy,isShadow);
            glPopMatrix();

            //Front Gunhead Energy cylinders right long horizontal 1
            glPushMatrix();
                glTranslatef(2.1f, 2.0f, 1.5f);
                glColor3f(0.90f, 0.1f, 0.1f);
                drawCylinderWithCap(varCylinder, 0.3f, 0.3f, 7.0f, FILL, glass,isShadow);
            glPopMatrix();

            //Front Gunhead Energy cylinders right vertical 1
            glPushMatrix();
                glTranslatef(2.1f, 5.2f, 8.5f);
                glRotatef(90, 1.0f, 0.0f, 0.0f);
                glColor3f(0.90f, 0.1f, 0.1f);
                drawCylinderWithCap(varCylinder, 0.3f, 0.3f, 3.5f, FILL, glass,isShadow);
            glPopMatrix();

            //Front Gunhead Energy cylinders short right horizontal 2
            glPushMatrix();
                glTranslatef(2.1f, 5.2f, 8.2f);
                
                glColor3f(0.90f, 0.1f, 0.1f);
                drawCylinderWithCap(varCylinder, 0.3f, 0.3f, 3.25f, FILL, glass,isShadow);
            glPopMatrix();

            //Front Gunhead Energy cylinders Left long horizontal 1
            glPushMatrix();
                glTranslatef(-2.1f, 2.0f, 1.5f);
                glColor3f(0.05f, 0.05f, 0.3f);
                drawCylinderWithCap(varCylinder, 0.3f, 0.3f, 7.0f, FILL, glass,isShadow);
            glPopMatrix();

            //Front Gunhead Energy cylinders Left vertical 1
            glPushMatrix();
                glTranslatef(-2.1f, 5.2f, 8.5f);
                glRotatef(90, 1.0f, 0.0f, 0.0f);
                glColor3f(0.05f, 0.05f, 0.3f);
                drawCylinderWithCap(varCylinder, 0.3f, 0.3f, 3.5f, FILL, glass,isShadow);
            glPopMatrix();

            //Front Gunhead Energy cylinders short Left horizontal 2
            glPushMatrix();
                glTranslatef(-2.1f, 5.2f, 8.2f);
                
                glColor3f(0.05f, 0.05f, 0.3f);
                drawCylinderWithCap(varCylinder, 0.3f, 0.3f, 3.25f, FILL, glass,isShadow);
            glPopMatrix();

            //Front Gunhead Mark
            glPushMatrix();
                glTranslatef(-0.0f, 4.0f, 11.5f);
                glRotatef(-50, 0.0f, 0.0f, 1.0f);
                glScalef(0.4f, 0.4f, 1.0f);
                for (float angle = 0; angle <= 360; angle = angle + 45) {
                    glPushMatrix();
                        float convertToRadian = angle * 3.14159 / 180.0;
                        glTranslatef(sin(convertToRadian) * 1.5f, cos(convertToRadian) * 1.5f, 0);
                        glRotatef(angle, 0.0f, 0.0f, 1.0f);
                        drawSlantedCuboid(4.0f, 1.0f, 0.2f, 0.7f, -2.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, energyPulse);
                    glPopMatrix();
                }
            glPopMatrix();

            //Front Gunhead Eye
            glPushMatrix();
                glTranslatef(1.3f, 5.2f, 11.45f);
                
                glColor3f(0.90f, 0.1f, 0.1f);
                drawCylinderWithCap(varCylinder, 0.3f, 0.3f, 0.3f, FILL, glass,isShadow);
            glPopMatrix();

            //Cylindrical Head 1
            glPushMatrix();
                glTranslatef(0.0f, 4.0f, 1.5f);
                glColor3f(0.8f, 0.5f, 0.9f);
                drawCylinderWithCap(varCylinder, 3.5f, 2.0f, 4.5f, FILL, fire,isShadow);
            glPopMatrix();

            //Cylindrical Head 2
            glPushMatrix();
                glTranslatef(0.0f, 4.0f, -3.5f);
                glColor3f(0.1f, 0.1f, 0.1f);
                //glColor3f(0.7f, 0.7f, 0.7f);
                drawCylinderWithCap(varCylinder, 3.5f, 3.5f, 5.0f, FILL, fire,isShadow);

                //Cylindrical Head 3
                
                glPushMatrix();
                    glTranslatef(0.0f, 0.0f, -3.5f);
                    glColor3f(0.7f, 0.6f, 0.9f);
                    drawCylinderWithCap(varCylinder, 2.5f, 3.5f, 3.5f, FILL, fire,isShadow);
                    
                    //Cylinder Head BackPlug
                    
                    glPushMatrix();
                        glTranslatef(0.0f, 0.0f, -5.0f);
                        glColor3f(0.3f, 0.3f, 0.3f);
                        drawCylinderWithCap(varCylinder, 1.5f, 1.5f, 5.0f, FILL, energyPulse,isShadow);

                        //Cylinder Head BackPlug Cover cap
                        glPushMatrix();
                            glTranslatef(0.0f, 0.0f, 5.0f);
                            glTranslatef(0.0f, 0.0f, -0.4f);
                            glColor3f(0.1f, 0.1f, 0.1f);
                            drawCylinderWithCap(varCylinder, 1.7f, 1.7f, 0.4f, FILL, blackGlossy,isShadow);
                        glPopMatrix();

                        
                        //Cylinder Head BackPlug Cover cap fins
                        /*
                        glPushMatrix();
                        glTranslatef(0.0f, 6.0f, 4.2f);
                        glRotatef(-50, 0.0f, 0.0f, 1.0f);
                        //glRotatef(90, 1.0f, 0.0f, 0.0f);
                        //glRotatef(180, 1.0f, 0.0f, 0.0f);
                        //glRotatef(90, 0.0f, 0.0f, 1.0f);
                        //glRotatef(90, 0.0f, 1.0f, 0.0f);
                        //glScalef(0.1f, 0.1f, 0.1f);
                            for (float angle = 0; angle <= 360; angle = angle + 45) {
                                glPushMatrix();
                                float convertToRadian = angle * 3.14159 / 180.0;
                                glTranslatef(sin(convertToRadian) * 1.5f, cos(convertToRadian) * 1.5f, 0);
                                glRotatef(angle, 0.0f, 0.0f, 1.0f);
                                drawSlantedCuboid(4.0f, 1.0f, 0.2f, 0.7f, -2.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, NULL);
                                glPopMatrix();
                            }
                        glPopMatrix();

                        */


                        //Cylinder energy bars
                        glPushMatrix();
                            glTranslatef(0.0f, 0.0f, 5.0f);
                            glTranslatef(0.0f, 0.0f, -2.3f);
                            glColor3f(0.0f, 0.9f, 1.0f);
                            for (float angle = 0; angle <= 360; angle = angle + 45)
                            {
                                glPushMatrix();
                                    float convertToRadian = angle * 3.14159 / 180.0;
                                    glTranslatef(sin(convertToRadian) * 1.5f, cos(convertToRadian) * 1.5f, 0);
                                    drawCylinderWithCap(quad, 0.2f, 0.2f, 2.0f, FILL, glass,isShadow);
                                glPopMatrix();
                            }
                        glPopMatrix();

                        //Cylinder Head BackPlug little black stripes
                        glPushMatrix();
                            glTranslatef(0.0f, 0.0f, -0.3);
                            glColor3f(0.0f, 0.0f, 0.0f);
                            drawCylinderWithCap(varCylinder, 1.5f, 1.5f, 0.3f, FILL, white,isShadow);

                            //Cylinder Head BackPlug little gray stripes
                            glPushMatrix();
                                glTranslatef(0.0f, 0.0f, -0.3);
                                glColor3f(0.6f, 0.6f, 0.6f);
                                drawCylinderWithCap(varCylinder, 1.5f, 1.5f, 0.3f, FILL, energyPulse,isShadow);

                                //Cylinder Head BackPlug little black stripes
                                glPushMatrix();
                                    glTranslatef(0.0f, 0.0f, -0.3);
                                    glColor3f(0.0f, 0.0f, 0.0f);
                                    drawCylinderWithCap(varCylinder, 1.5f, 1.5f, 0.3f, FILL, energyPulse,isShadow);

                                    //Cylinder Head BackPlug little olive brown stripes
                                    glPushMatrix();
                                        glTranslatef(0.0f, 0.0f, -0.4);
                                        glColor3f(0.35f, 0.35f, 0.2f);
                                        drawCylinderWithCap(varCylinder, 1.5f, 1.5f, 0.4f, FILL, white,isShadow);
                                        
                                        //Cylinder Head BackPlug last little gray stripes
                                        glPushMatrix();
                                            glTranslatef(0.0f, 0.0f, -0.3);
                                            glColor3f(0.7f, 0.7f, 0.7f);
                                            drawCylinderWithCap(varCylinder, 1.5f, 1.5f, 0.3f, FILL, energyPulse,isShadow);
                                        glPopMatrix();
                                    glPopMatrix();
                                glPopMatrix();
                            glPopMatrix();
                        glPopMatrix();

                    glPopMatrix();
                    
                glPopMatrix();

            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
   
}