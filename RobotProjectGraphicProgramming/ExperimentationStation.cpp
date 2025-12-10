#include "ExperimentationStation.h"

ExperimentationStation::ExperimentationStation() {
    length = 1.0f;
    thickness = 0.3f;
    jointAngle = 0.0f;

    // default position relative to body
    //x = 0.0f;
    //y = 0.0f;
    //z = 0.0f;

    //rx = ry = rz = 0.0f;
}

void ExperimentationStation::updateInput() {
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

    if (diKeys[DIK_V] & 0x80) {
        shipMovement = shipMovement - 0.1f;
        slices--;
    }

    if (diKeys[DIK_B] & 0x80) {
        slices++;
    }

    if (diKeys[DIK_N] & 0x80) {
        stacks--;
        openAndCloseGate = openAndCloseGate - 1;
    }

    if (diKeys[DIK_M] & 0x80) {
        stacks++;
        openAndCloseGate = openAndCloseGate + 1;
    }

    // Example: simple arm swing animation
    // jointAngle changes over time (controlled externally)
}

void ExperimentationStation::drawJointMarker()
{
    GLUquadric* quad = gluNewQuadric();
    gluSphere(quad, 0.2f, 4, 4);
    gluDeleteQuadric(quad);
}

void ExperimentationStation::drawCuboid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, float red, float green, float blue)
{
    glPushMatrix();
    //translate the center point for transformation of the cuboid (This acts as a pivot point to rotate the cuboid)
    glTranslatef(centerPointTransformationTranslationX, centerPointTransformationTranslationY, centerPointTransformationTranslationZ);
    //scale first
    glScalef(scaleX, scaleY, scaleZ);
    glColor3f(red, green, blue);
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();

    glPopMatrix();
}

void ExperimentationStation::drawSphere(GLUquadricObj* quad, float radius, int slices, int stacks)
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

    // e) set quadric draw style
    // Options: GLU_FILL, GLU_LINE, GLU_SILHOUETTE, GLU_POINT
    gluQuadricDrawStyle(quad, GLU_FILL);   // wireframe sphere

    // c) draw sphere at origin
    gluSphere(quad, radius, slices, stacks);   // radius = 1, slices & stacks = 20

    // f) delete quadric (free memory)
    gluDeleteQuadric(quad);
}

void ExperimentationStation::drawCylinder(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle)
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

void ExperimentationStation::drawCircle(float circleRadius)
{
    glBegin(GL_POLYGON);
    for (float angle = 0; angle <= 360; angle++) {
        float convertToRadian = angle * 3.14159 / 180.0;
        glVertex3f(sin(convertToRadian) * circleRadius, cos(convertToRadian) * circleRadius, 0);
    }
    glEnd();
}

void ExperimentationStation::drawCircleWithHole(float outerRadius, float innerRadius, int segments)
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

void ExperimentationStation::drawPyramid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ)
{
    glPushMatrix();
    //translate the center point for transformation of the cuboid (This acts as a pivot point to rotate the cuboid)
    glTranslatef(centerPointTransformationTranslationX, centerPointTransformationTranslationY, centerPointTransformationTranslationZ);
    //scale first
    glScalef(scaleX, scaleY, scaleZ);

    Vector3D normal = findNormalVector(Point3D{ -0.5f, -0.5f, 0.5f }, Point3D { 0.5f, -0.5f, 0.5f }, Point3D { 0.5f, -0.5f, -0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();

    normal = findNormalVector(Point3D{ -0.5f, -0.5f, 0.5f }, Point3D{ 0.0f, 0.5f, 0.0f }, Point3D{ 0.5f, -0.5f, 0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
	glBegin(GL_TRIANGLES);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();

    normal = findNormalVector(Point3D{ 0.0f, 0.5f, 0.0f }, Point3D{ 0.5f, -0.5f, -0.5f }, Point3D{ 0.5f, -0.5f, 0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();

    normal = findNormalVector(Point3D{ 0.0f, 0.5f, 0.0f }, Point3D{ -0.5f, -0.5f, -0.5f }, Point3D{ 0.5f, -0.5f, -0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(0.5f, -0.5f, -0.5f);
    glEnd();

    normal = findNormalVector(Point3D{ 0.0f, 0.5f, 0.0f }, Point3D{ -0.5f, -0.5f, 0.5f }, Point3D{ -0.5f, -0.5f, -0.5f });
    glNormal3f(normal.x, normal.y, normal.z);
    glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();
    glPopMatrix();
}

ExperimentationStation::Vector3D ExperimentationStation::findNormalVector(Point3D v1, Point3D v2, Point3D v3)
{
    //remember to input points from most bottom to top so that it is in (clockwise order)
    //P2 - P1 (from p1 to p2)
    Vector3D vectorA = {v2.x - v1.x, v2.y - v1.y, v2.z - v1.z};
    
	//P3 - P1 (from p1 to p3)
	Vector3D vectorB = { v3.x - v1.x, v3.y - v1.y, v3.z - v1.z };
    
    Vector3D normal = {vectorA.y * vectorB.z - vectorA.z * vectorB.y, -(vectorA.x * vectorB.z - vectorA.z * vectorB.x), vectorA.x * vectorB.y - vectorA.y * vectorB.x};
    
    float lengthOfNormalTravelled = sqrt((normal.x * normal.x) + (normal.y * normal.y) + (normal.z * normal.z));

    Vector3D normalizedNormal = { normal.x / lengthOfNormalTravelled, normal.y / lengthOfNormalTravelled , normal.z / lengthOfNormalTravelled };
    
    //since for some reason this stupid code idk why it gives me the inner normal instead of outer normal, we negative to reverse it to outer normal.
    normalizedNormal = { -normalizedNormal.x, -normalizedNormal.y, -normalizedNormal.z };
    return normalizedNormal;
}   

void ExperimentationStation::drawBeautifulCircleWithFlowers(float circleRadius, float baseRadius, float topRadius, float height, int numCylinders, int selectedDrawStyle)
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

void ExperimentationStation::drawCylinderAlongCurve(float angleBegins, float angleEnds, float circleXRadius, float circleYRadius, float cylinderRadius, int selectedDrawStyle)
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
                drawCylinder(quad, cylinderRadius, cylinderRadius, 0.1f, selectedDrawStyle);
                break;
            case LINE:
                drawCylinder(quad, cylinderRadius, cylinderRadius, 0.1f, selectedDrawStyle);
                break;

            case SILHOUETTE:
                drawCylinder(quad, cylinderRadius, cylinderRadius, 0.1f, selectedDrawStyle);
                break;

            case POINT:
                drawCylinder(quad, cylinderRadius, cylinderRadius, 0.1f, selectedDrawStyle);
                break;
            }
            
        glPopMatrix();
    }
    
}

void ExperimentationStation::drawText3D(const char* text)
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

void ExperimentationStation::initFont()
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

void ExperimentationStation::drawColumnOfTower(float translationX, float translationY, float translationZ)
{
    //Cylinder Bottom
            glPushMatrix();
                glTranslatef(translationX, translationY, translationZ);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.743, 0.655, 0.572);
                drawCylinder(varCylinder, 0.2f, 0.2f, 1.0f, FILL);
                //drawCylinder(varCylinder, 0.3f, 0.3f, 6.0f, FILL);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 0.5f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.380f, 0.320f, 0.270f);
                drawCylinder(varCylinder, 0.2f, 0.2f, 0.1f, FILL);
            glPopMatrix();
            //Cylinder a bit color before reaching another black spot
            glPushMatrix();
                glTranslatef(translationX, 0.6f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.743f, 0.655f, 0.572f);
                drawCylinder(varCylinder, 0.2f, 0.2f, 0.1f, FILL);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 0.7f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.380f, 0.320f, 0.270f);
                drawCylinder(varCylinder, 0.2f, 0.2f, 0.1f, FILL);
            glPopMatrix();
            //Cylinder colors
            glPushMatrix();
                glTranslatef(translationX, 0.8f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.743f, 0.655f, 0.572f);
                drawCylinder(varCylinder, 0.2f, 0.2f, 0.7f, FILL);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 1.5f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.380f, 0.320f, 0.270f);
                drawCylinder(varCylinder, 0.2f, 0.2f, 0.1f, FILL);
            glPopMatrix();
            //Cylinder a bit color before reaching another black spot
            glPushMatrix();
                glTranslatef(translationX, 1.6f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.743f, 0.655f, 0.572f);
                drawCylinder(varCylinder, 0.2f, 0.2f, 0.1f, FILL);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 1.7f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.380f, 0.320f, 0.270f);
                drawCylinder(varCylinder, 0.2f, 0.2f, 0.1f, FILL);
            glPopMatrix();
            //Cylinder colors
            glPushMatrix();
                glTranslatef(translationX, 1.8f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.743f, 0.655f, 0.572f);
                drawCylinder(varCylinder, 0.2f, 0.2f, 0.5f, FILL);
            glPopMatrix();
            //Cylinder colors but expanded column
            glPushMatrix();
                glTranslatef(translationX, 2.3f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.743f, 0.655f, 0.572f);
                drawCylinder(varCylinder, 0.25f, 0.25f, 0.3f, FILL);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 2.6f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.380f, 0.320f, 0.270f);
                drawCylinder(varCylinder, 0.25f, 0.25f, 0.1f, FILL);
            glPopMatrix();
            //a bit Cylinder colors & expanded column
            glPushMatrix();
                glTranslatef(translationX, 2.7f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.743f, 0.655f, 0.572f);
                drawCylinder(varCylinder, 0.25f, 0.25f, 0.1f, FILL);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 2.8f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.380f, 0.320f, 0.270f);
                drawCylinder(varCylinder, 0.25f, 0.25f, 0.1f, FILL);
            glPopMatrix();
            //a bit Cylinder colors & expanded column
            glPushMatrix();
                glTranslatef(translationX, 2.9f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.743f, 0.655f, 0.572f);
                drawCylinder(varCylinder, 0.25f, 0.25f, 0.8f, FILL);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 3.7f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.380f, 0.320f, 0.270f);
                drawCylinder(varCylinder, 0.25f, 0.25f, 0.1f, FILL);
            glPopMatrix();
            //a bit Cylinder colors & expanded column
            glPushMatrix();
                glTranslatef(translationX, 3.8f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.870f, 0.800f, 0.690f);
                drawCylinder(varCylinder, 0.25f, 0.25f, 0.4f, FILL);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 4.2f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.380f, 0.320f, 0.270f);
                drawCylinder(varCylinder, 0.25f, 0.25f, 0.1f, FILL);
            glPopMatrix();
            //a bit Cylinder colors & expanded column
            glPushMatrix();
                glTranslatef(translationX, 4.3f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.870f, 0.800f, 0.690f);
                drawCylinder(varCylinder, 0.25f, 0.25f, 0.2f, FILL);
            glPopMatrix();
            //Cone Top
            glPushMatrix();
                glTranslatef(translationX, 4.5f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.743f, 0.655f, 0.572f);
                drawCylinder(varCylinder, 0.25f, 0.10f, 0.8f, FILL);
            glPopMatrix();
            //Sphere on top of cone
            glPushMatrix();
                glTranslatef(translationX, 5.3f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.743f, 0.655f, 0.572f);
			    drawSphere(varSphere, 0.1f, 50, 50);
            glPopMatrix();
            //cone on top of the top sphere
            glPushMatrix();
                glTranslatef(translationX, 5.4f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.870f, 0.800f, 0.690f);
                drawCylinder(varCylinder, 0.1f, 0.05f, 0.05f, FILL);
            glPopMatrix();
            //small cylinder on top of the cone on top of the top shere
            glPushMatrix();
                glTranslatef(translationX, 5.45f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.870f, 0.800f, 0.690f);
                drawCylinder(varCylinder, 0.05f, 0.05f, 0.2f, FILL);
            glPopMatrix();
            //wings beside the small cylinder
            glPushMatrix();
            /*
            glBegin(GL_LINE_STRIP);
                float ovalCenterCoordinateX = 0.0f;
                float ovalCenterCoordinateY = 0.1f;
                float ovalXRadius = 1.15f;
                float ovalYRadius = 1.15f;
                glTranslatef(-0.3f, 7.00f, -0.3f);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.870f, 0.800f, 0.690f);
                
                //glRotatef(30.0f, 1.0f, 0.0f, 0.0f);

                glLineWidth(5.0f);
                for (float angle = 270; angle <= 300; angle++) {
                    float convertToRadian = angle * 3.14159 / 180.0;
                    glColor3f(0.85f, 0.15f, 0.20f);
                    glVertex2f(sin(convertToRadian) * ovalXRadius + ovalCenterCoordinateX, cos(convertToRadian) * ovalYRadius + ovalCenterCoordinateY);
                }

                glEnd();*/
            glPopMatrix();
            //Cone on top of small cylinder
            glPushMatrix();
                glTranslatef(translationX, 5.65f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.870f, 0.800f, 0.690f);
                drawCylinder(varCylinder, 0.06f, 0.03f, 0.1f, FILL);

            glPopMatrix();
}

void ExperimentationStation::drawWall(float translationX, float translationY, float translationZ, float length, float depth)
{
        //Wall Bottom
        glPushMatrix();
            glTranslatef(translationX, translationY, translationZ);
            glColor3f(0.743, 0.655, 0.572);
            drawCuboid(length, 1.0f, depth, 0.0f, 0.5f, 0.0f, 0.743f, 0.655f, 0.572f);

            //drawCylinder(varCylinder, 0.3f, 0.3f, 6.0f, FILL);
        glPopMatrix();
        //Cylinder Black spot
        glPushMatrix();
            glTranslatef(translationX, 0.5f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f);

        glPopMatrix();
            //Cylinder a bit color before reaching another black spot
            glPushMatrix();
                glTranslatef(translationX, 0.6f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.743f, 0.655f, 0.572f);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 0.7f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f);
            glPopMatrix();
            //Cylinder colors
            glPushMatrix();
                glTranslatef(translationX, 0.8f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.7f, depth, 0.0f, 0.35f, 0.0f, 0.743f, 0.655f, 0.572f);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 1.5f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f);
            glPopMatrix();
            //Cylinder a bit color before reaching another black spot
            glPushMatrix();
                glTranslatef(translationX, 1.6f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.743f, 0.655f, 0.572f);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 1.7f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f);
            glPopMatrix();
            //Cylinder colors
            glPushMatrix();
                glTranslatef(translationX, 1.8f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.5f, depth, 0.0f, 0.25f, 0.0f, 0.743f, 0.655f, 0.572f);
            glPopMatrix();
            //Cylinder colors but expanded column
            glPushMatrix();
                glTranslatef(translationX, 2.3f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.3f, depth, 0.0f, 0.15f, 0.0f, 0.743f, 0.655f, 0.572f);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 2.6f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f);
            glPopMatrix();
            //a bit Cylinder colors & expanded column
            glPushMatrix();
                glTranslatef(translationX, 2.7f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.743f, 0.655f, 0.572f);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 2.8f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f);
            glPopMatrix();
            //a bit Cylinder colors & expanded column
            glPushMatrix();
                glTranslatef(translationX, 2.9f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.8f, depth, 0.0f, 0.4f, 0.0f, 0.743f, 0.655f, 0.572f);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 3.7f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f);
            glPopMatrix();
            //a bit Cylinder colors & expanded column
            glPushMatrix();
                glTranslatef(translationX, 3.8f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.4f, depth, 0.0f, 0.2f, 0.0f, 0.870f, 0.800f, 0.690f);
            glPopMatrix();
            //Cylinder Black spot
            glPushMatrix();
                glTranslatef(translationX, 4.2f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f);
            glPopMatrix();
            //a bit Cylinder colors & expanded column
            glPushMatrix();
                glTranslatef(translationX, 4.3f, translationZ);
                glTranslatef(0.f, 1.0f, 0.0f);
                drawCuboid(length, 0.2f, depth, 0.0f, 0.1f, 0.0f, 0.870f, 0.800f, 0.690f);
            glPopMatrix();
}\

void ExperimentationStation::drawGroundBridge1(float translationX, float translationY, float translationZ, float length, float depth)
{
    glPushMatrix();
    glTranslatef(translationX, translationY, translationZ);
    glRotatef(openAndCloseGate, 0, 0, 1);
    drawCuboid(length, 0.2f, depth, length/2, 0.0f, 0.0f, 0.902f, 0.902f, 0.902f);
    
    glPopMatrix();
}

void ExperimentationStation::drawGroundBridge2(float translationX, float translationY, float translationZ, float length, float depth)
{
    glPushMatrix();
    glTranslatef(translationX, translationY, translationZ);
    glRotatef(-openAndCloseGate, 0, 0, 1);
    drawCuboid(length, 0.2f, depth, -length/2, 0.0f, 0.0f, 0.902f, 0.902f, 0.902f);

    glPopMatrix();
}

void ExperimentationStation::drawGroundBridge3And4(float translationX, float translationY, float translationZ, float length, float depth)
{
    glPushMatrix();
    glTranslatef(translationX, translationY, translationZ);
    drawCuboid(length, 0.2f, depth, length / 2, 0.0f, 0.0f, 0.902f, 0.902f, 0.902f);

    glPopMatrix();
}


void ExperimentationStation::drawBridge(float translationX, float translationY, float translationZ, float length, float depth, float red, float green, float blue)
{
    glPushMatrix();
        glTranslatef(translationX, translationY, translationZ);
        //deck
        drawCuboid(length, 0.2f, depth, 0.0f, 0.1f, 0.0f, red, green, blue);
        //railing 1
        glPushMatrix();
            glTranslatef(0.0f, 0.2f, -0.15f);
            drawCuboid(length, 0.5f, 0.1f, 0.0f, 0.25f, 0.0f, 0.902f, 0.902f, 0.902f);
        glPopMatrix();
        //railing 2
        glPushMatrix();
            glTranslatef(0.0f, 0.2f, 0.15f);
            drawCuboid(length, 0.5f, 0.1f, 0.0f, 0.25f, 0.0f, 0.902f, 0.902f, 0.902f);
        glPopMatrix();
    glPopMatrix();

}

void ExperimentationStation::draw() {
   
    glPushMatrix();
    /*
    glColor3f(1.0, 0, 0);
    drawJointMarker();
    glRasterPos3f(0, 0, 0);
    sprintf_s(buf, "Ori coordinate (%.1f %.1f %.1f)", 0.0, 0.0, 0.0);
    drawText3D(buf);
    */
        glTranslatef(RobotEntireArm_TranslationX, RobotEntireArm_TranslationY, RobotEntireArm_TranslationZ);
        glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
        glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
        glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);

        glPushMatrix();
            
            //glTranslatef(shoulder.x, shoulder.y, shoulder.z);
            //Sea
            glPushMatrix();
			    glTranslatef(0.0f, -0.5f, 0.0f);
                drawCuboid(25.0f, 10.0f, 15.0f, 0.0f, -5.0f, 0.0, 0.68f, 0.85f, 0.90f);
            glPopMatrix();

            //Ship
            glPushMatrix();
                glTranslatef(3.25f, 0.0f, shipMovement);
                drawCuboid(2.0f, 1.0f, 2.5f, 0.0f, -0.5f, 0.0, 0.22f, 0.32f, 0.41f);
                glTranslatef(0.0f, 0.0f, 0.0f);
                drawCuboid(1.0f, 0.5f, 1.0f, 0.0f, 0.25f, 0.0, 0.92f, 0.92f, 0.92f);
                glTranslatef(0.0f, 0.5, 0.0f);
                drawPyramid(1.0f, 0.5f, 1.0f, 0.0f, 0.25f, 0.0f);
            glPopMatrix();

            //first tower structure
            drawCuboid(3.5f, 1.0f, 3.0f, 0.0f, 0.0f, 0.0, 0.0f, 0.58f, 0.55f);
            drawColumnOfTower(-0.65f, 0.5f, 0.90f);
            drawColumnOfTower(0.65f, 0.5f, 0.90f);
            drawColumnOfTower(-0.65f, 0.5f, -0.90f);
            drawColumnOfTower(0.65f, 0.5f, -0.90f);
            drawWall(0.0f, 0.5f, 0.65f, 1.0f, 0.3f);
            drawWall(0.0f, 0.5f, -0.65f, 1.0f, 0.3f);
            glPushMatrix();
                glColor3f(0.73f, 0.72f, 0.63f);
                drawPyramid(1.1f, 2.5f, 1.1f, 0.0f, 6.5f, 0.0f);
            glPopMatrix();
            glPushMatrix();
                glColor3f(0.10f, 0.53f, 0.70f);
                glTranslatef(-4.8f, 2.4f, -0.8f);
                drawCylinderAlongCurve(90.0f, 180.0f, 4.0f, 2.0f, 0.15f, LINE);
            glPopMatrix();
            glPushMatrix();
                glColor3f(0.10f, 0.53f, 0.70f);
                glTranslatef(-4.8f, 2.4f, 0.8f);
                drawCylinderAlongCurve(90.0f, 180.0f, 4.0f, 2.0f, 0.15f, LINE);
            glPopMatrix();
            glPushMatrix();
			    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                drawWall(0.0f, 0.5f, -0.65f, 1.5f, 0.3f);
            glPopMatrix();
            glPushMatrix();
                glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
                drawWall(0.0f, 0.5f, -0.65f, 1.5f, 0.3f);
            glPopMatrix();

            glPushMatrix();
			//bridge on Ground floor between two towers
 
            drawGroundBridge1(1.75f, 0.3f, 0.0f, 1.5f, 2.0f);
            //glRotatef(-openAndCloseGate, 0, 0, 1);
            drawGroundBridge2(4.75f, 0.3f, 0.0f, 1.5f, 2.0f);
            drawGroundBridge3And4(8.2f, 0.3f, 0.0f, 8.0f, 2.0f);
            drawGroundBridge3And4(-8.2f, 0.3f, 0.0f, 8.0f, 2.0f);
            glPopMatrix();
            //second tower structure
			glPushMatrix();
			    glTranslatef(6.5f, 0.0f, 0.0f);
                drawCuboid(3.5f, 1.0f, 3.0f, 0.0f, 0.0f, 0.0, 0.0f, 0.58f, 0.55f);
                drawColumnOfTower(-0.65f, 0.5f, 0.90f);
                drawColumnOfTower(0.65f, 0.5f, 0.90f);
                drawColumnOfTower(-0.65f, 0.5f, -0.90f);
                drawColumnOfTower(0.65f, 0.5f, -0.90f);
                glPushMatrix();
                    glColor3f(0.73f, 0.72f, 0.63f);
                    drawPyramid(1.1f, 2.5f, 1.1f, 0.0f, 6.5f, 0.0f);
                glPopMatrix();
                glPushMatrix();
                    glColor3f(0.10f, 0.53f, 0.70f);
                    glTranslatef(4.8f, 2.4f, -0.8f);
                    drawCylinderAlongCurve(180.0f, 270.0f, 4.0f, 2.0f, 0.15f, LINE);
                glPopMatrix();
                glPushMatrix();
                    glColor3f(0.10f, 0.53f, 0.70f);
                    glTranslatef(4.8f, 2.4f, 0.8f);
                    drawCylinderAlongCurve(180.0f, 270.0f, 4.0f, 2.0f, 0.15f, LINE);
                glPopMatrix();

                drawWall(0.0f, 0.5f, 0.65f, 1.0f, 0.3f);
                drawWall(0.0f, 0.5f, -0.65f, 1.0f, 0.3f);
                glPushMatrix();
                    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                    drawWall(0.0f, 0.5f, -0.65f, 1.5f, 0.3f);
                glPopMatrix();
                glPushMatrix();
                    glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
                    drawWall(0.0f, 0.5f, -0.65f, 1.5f, 0.3f);
                glPopMatrix();
            glPopMatrix();

            //bridge between two towers on upper floors
            glPushMatrix();
                drawBridge(3.25f, 4.1f, -0.6f, 4.9f, 0.4f, 0.157f, 0.600f, 0.737f);

                drawBridge(3.25f, 4.1f, 0.6f, 4.9f, 0.4f, 0.157f, 0.600f, 0.737f);
            glPopMatrix();
         glPopMatrix();

    glPopMatrix();

}

void ExperimentationStation::draw2()
{
    glTranslatef(RobotEntireArm_TranslationX, RobotEntireArm_TranslationY, RobotEntireArm_TranslationZ);
    glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);

    glPushMatrix();
    glEnable(GL_LINE_STIPPLE);
    glLineWidth(100);
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineStipple(2, 0x35AC);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0, 0);
    glVertex2f(0, 2);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glPopMatrix();
}

void ExperimentationStation::draw3() {
    glTranslatef(RobotEntireArm_TranslationX, RobotEntireArm_TranslationY, RobotEntireArm_TranslationZ);
    glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);

    glPushMatrix();
	    //drawColumnOfTower(0.0f, 0.0f, 0.0f);
        glColor3f(1.0f, 0.0f, 0.0f);
        //drawCylinderAlongCurve(0, 360, 3.0f, 3.0f, 0.5, LINE);
        //drawBeautifulCircleWithFlowers(2.0f, 2.0f, 2.0f, 1.0, 100, FILL);
        //drawBeautifulCircleWithFlowers(5.0f, 2.0f, 2.0f, 1.0, 100, FILL);
        //drawBeautifulCircleWithFlowers(5.0f, 2.0f, 2.0f, 1.0, 100, FILL);
	glPopMatrix();
}

void ExperimentationStation::lightingTestCube()
{
    glTranslatef(RobotEntireArm_TranslationX, RobotEntireArm_TranslationY, RobotEntireArm_TranslationZ);
    glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
    glPushMatrix();


    glNormal3f(0.0f, 0.0f, -1.0f);
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();
    
    //glNormal3f(?f, ?f, ?f);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();

    glNormal3f(0.0f, 1.0f, 0.0f);
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();

    glNormal3f(0.0f, 0.0f, 1.0f);
    glColor3f(1, 1, 0);
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glColor3f(1, 0, 1);
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();

    glNormal3f(0.0f, -1.0f, 0.0f);
    glColor3f(0, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();
    
    glPopMatrix();
}

void ExperimentationStation::lightingTestPyramidAndSphere()
{
    glPushMatrix();

    glTranslatef(RobotEntireArm_3DRotationAngleX*0.1, RobotEntireArm_3DRotationAngleY*0.1, RobotEntireArm_3DRotationAngleZ*0.1);
    glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    drawSphere(varSphere, 0.5f, 50, 50);
    glPopMatrix();
    glPushMatrix();
    glRotatef(RobotElbow_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(RobotElbow_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(RobotElbow_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    drawPyramid(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f);
    glPopMatrix();
}



