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
        choice = 0;
    }

    if (diKeys[DIK_M] & 0x80) {
        stacks++;
        openAndCloseGate = openAndCloseGate + 1;
        choice = 1;
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

void ExperimentationStation::drawCuboid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, float red, float green, float blue, GLuint texture)
{
    glPushMatrix();
    //translate the center point for transformation of the cuboid (This acts as a pivot point to rotate the cuboid)
    glTranslatef(centerPointTransformationTranslationX, centerPointTransformationTranslationY, centerPointTransformationTranslationZ);
    //scale first
    glScalef(scaleX, scaleY, scaleZ);
    glColor3f(red, green, blue);

    glBindTexture(GL_TEXTURE_2D, texture);
    
    glNormal3f(0.0f, 0.0f, -1.0f);
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

    glNormal3f(1.0f, 0.0f, 0.0f);
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

    glNormal3f(0.0f, 1.0f, 0.0f);
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

    glNormal3f(0.0f, 0.0f, 1.0f);
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

    glNormal3f(-1.0f, 0.0f, 0.0f);
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

    glNormal3f(0.0f, -1.0f, 0.0f);
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

void ExperimentationStation::drawSphere(GLUquadricObj* quad, float radius, int slices, int stacks, GLuint texture)
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

void ExperimentationStation::drawCylinder(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle, GLuint texture)
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

void ExperimentationStation::drawCircle(float circleRadius, GLuint texture)
{
    // 1. Bind the texture
    glBindTexture(GL_TEXTURE_2D, texture);

    // 2. Set the color filter to white so the texture appears in its true colors
    glColor3f(1.0f, 1.0f, 1.0f);

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

void ExperimentationStation::drawPyramid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, GLuint texture)
{
    glPushMatrix();
    //translate the center point for transformation of the cuboid (This acts as a pivot point to rotate the cuboid)
    glTranslatef(centerPointTransformationTranslationX, centerPointTransformationTranslationY, centerPointTransformationTranslationZ);
    //scale first
    glScalef(scaleX, scaleY, scaleZ);

    Vector3D normal = findNormalVector(Point3D{ -0.5f, -0.5f, 0.5f }, Point3D { 0.5f, -0.5f, 0.5f }, Point3D { 0.5f, -0.5f, -0.5f });
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

void ExperimentationStation::drawCylinderAlongCurve(float angleBegins, float angleEnds, float circleXRadius, float circleYRadius, float cylinderRadius, int selectedDrawStyle, GLuint texture)
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

void ExperimentationStation::loadTextures()
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

	//tower brick texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "lightTowerBrick.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &lightTowerBrick);
    glBindTexture(GL_TEXTURE_2D, lightTowerBrick);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "darkTowerBrick.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &darkTowerBrick);
    glBindTexture(GL_TEXTURE_2D, darkTowerBrick);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //Ground Bridge texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "groundBridge.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &groundBridge);
    glBindTexture(GL_TEXTURE_2D, groundBridge);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	//Upper Bridge texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "bridgeRailing.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &bridgeRailing);
    glBindTexture(GL_TEXTURE_2D, bridgeRailing);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //sea texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "sea.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &sea);
    glBindTexture(GL_TEXTURE_2D, sea);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //ship texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "shipHull.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &shipHull);
    glBindTexture(GL_TEXTURE_2D, shipHull);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "shipUpperPart.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &shipUpperPart);
    glBindTexture(GL_TEXTURE_2D, shipUpperPart);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //pyramid Roof Texture
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "pyramidRoof.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &pyramidRoof);
    glBindTexture(GL_TEXTURE_2D, pyramidRoof);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //tower Window
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "towerWindow.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &towerWindow);
    glBindTexture(GL_TEXTURE_2D, towerWindow);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //Bridge Rope
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "bridgeRope.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &bridgeRope);
    glBindTexture(GL_TEXTURE_2D, bridgeRope);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //Wall window
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "wallWindow.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &wallWindow);
    glBindTexture(GL_TEXTURE_2D, wallWindow);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //tower Entrance
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "towerEntrance.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &towerEntrance);
    glBindTexture(GL_TEXTURE_2D, towerEntrance);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //white color brick
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "whiteColorBrick.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &whiteColorBrick);
    glBindTexture(GL_TEXTURE_2D, whiteColorBrick);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //strawberry ice cream 
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "strawberryIceCream.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &strawberryIceCream);
    glBindTexture(GL_TEXTURE_2D, strawberryIceCream);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //chocolate ice cream 
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "chocolateIceCream.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &chocolateIceCream);
    glBindTexture(GL_TEXTURE_2D, chocolateIceCream);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
    //glMatrixMode(GL_TEXTURE);
    //glLoadIdentity();
    //glScalef(30.0, 20.0, 1.0);

	glMatrixMode(GL_MODELVIEW);

    //chocolate cylinder
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "chocolateCylinder.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &chocolateCylinder);
    glBindTexture(GL_TEXTURE_2D, chocolateCylinder);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //oreo
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "oreo.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &oreo);
    glBindTexture(GL_TEXTURE_2D, oreo);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

    //ice cream cone
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), "iceCreamCone.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &iceCreamCone);
    glBindTexture(GL_TEXTURE_2D, iceCreamCone);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
    //glMatrixMode(GL_TEXTURE);
    //glLoadIdentity();
    //glScalef(30.0, 20.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

void ExperimentationStation::beginScaleTexture(float scaleX, float scaleY)
{
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glScalef(scaleX, scaleY, 1.0f);
    glMatrixMode(GL_MODELVIEW); // Switch back to MODELVIEW for drawing
}

void ExperimentationStation::endScaleTexture()
{
    glMatrixMode(GL_TEXTURE); // Switch to TEXTURE mode to access the stack
    glPopMatrix();            // Restore the saved 1x matrix
    glMatrixMode(GL_MODELVIEW); // Switch back to MODELVIEW for rendering the next object
}

void ExperimentationStation::deleteTextures()
{
    // a) Disable state change (Optional at exit)
    glDisable(GL_TEXTURE_2D);

    // b) Free the Windows GDI object
    DeleteObject(hBMP);

    glDeleteTextures(1, &texture);
    glDeleteTextures(1, &metal);
    glDeleteTextures(1, &lightTowerBrick);
    glDeleteTextures(1, &darkTowerBrick);
    glDeleteTextures(1, &groundBridge);
    glDeleteTextures(1, &bridgeRailing);
    glDeleteTextures(1, &sea);
    glDeleteTextures(1, &shipHull);
    glDeleteTextures(1, &shipUpperPart);
	glDeleteTextures(1, &pyramidRoof);
}

void ExperimentationStation::drawColumnOfTower(float translationX, float translationY, float translationZ)
{
    //Cylinder Bottom
        glPushMatrix();
            glTranslatef(translationX, translationY, translationZ);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.743, 0.655, 0.572);
            drawCylinder(varCylinder, 0.2f, 0.2f, 1.0f, FILL, towerWindow);
            //drawCylinder(varCylinder, 0.3f, 0.3f, 6.0f, FILL);
        glPopMatrix();
        //Cylinder Black spot
        glPushMatrix();
            glTranslatef(translationX, 0.5f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.380f, 0.320f, 0.270f);
            drawCylinder(varCylinder, 0.2f, 0.2f, 0.1f, FILL, darkTowerBrick);
        glPopMatrix();
        //Cylinder a bit color before reaching another black spot
        glPushMatrix();
            glTranslatef(translationX, 0.6f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.743f, 0.655f, 0.572f);
            drawCylinder(varCylinder, 0.2f, 0.2f, 0.1f, FILL, lightTowerBrick);
        glPopMatrix();
        //Cylinder Black spot
        glPushMatrix();
            glTranslatef(translationX, 0.7f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.380f, 0.320f, 0.270f);
            drawCylinder(varCylinder, 0.2f, 0.2f, 0.1f, FILL, darkTowerBrick);
        glPopMatrix();
        //Cylinder colors
        glPushMatrix();
            glTranslatef(translationX, 0.8f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.743f, 0.655f, 0.572f);
            drawCylinder(varCylinder, 0.2f, 0.2f, 0.7f, FILL, towerWindow);
        glPopMatrix();
        //Cylinder Black spot
        glPushMatrix();
            glTranslatef(translationX, 1.5f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.380f, 0.320f, 0.270f);
            drawCylinder(varCylinder, 0.2f, 0.2f, 0.1f, FILL, darkTowerBrick);
        glPopMatrix();
        //Cylinder a bit color before reaching another black spot
        glPushMatrix();
            glTranslatef(translationX, 1.6f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.743f, 0.655f, 0.572f);
            drawCylinder(varCylinder, 0.2f, 0.2f, 0.1f, FILL, lightTowerBrick);
        glPopMatrix();
        //Cylinder Black spot
        glPushMatrix();
            glTranslatef(translationX, 1.7f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.380f, 0.320f, 0.270f);
            drawCylinder(varCylinder, 0.2f, 0.2f, 0.1f, FILL, darkTowerBrick);
        glPopMatrix();
        //Cylinder colors
        glPushMatrix();
            glTranslatef(translationX, 1.8f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.743f, 0.655f, 0.572f);
            drawCylinder(varCylinder, 0.2f, 0.2f, 0.5f, FILL, towerWindow);
        glPopMatrix();
        //Cylinder colors but expanded column
        glPushMatrix();
            glTranslatef(translationX, 2.3f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.743f, 0.655f, 0.572f);
            drawCylinder(varCylinder, 0.25f, 0.25f, 0.3f, FILL, lightTowerBrick);
        glPopMatrix();
        //Cylinder Black spot
        glPushMatrix();
            glTranslatef(translationX, 2.6f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.380f, 0.320f, 0.270f);
            drawCylinder(varCylinder, 0.25f, 0.25f, 0.1f, FILL, darkTowerBrick);
        glPopMatrix();
        //a bit Cylinder colors & expanded column
        glPushMatrix();
            glTranslatef(translationX, 2.7f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.743f, 0.655f, 0.572f);
            drawCylinder(varCylinder, 0.25f, 0.25f, 0.1f, FILL, lightTowerBrick);
        glPopMatrix();
        //Cylinder Black spot
        glPushMatrix();
            glTranslatef(translationX, 2.8f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.380f, 0.320f, 0.270f);
            drawCylinder(varCylinder, 0.25f, 0.25f, 0.1f, FILL, darkTowerBrick);
        glPopMatrix();
        //a bit Cylinder colors & expanded column
        glPushMatrix();
            glTranslatef(translationX, 2.9f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.743f, 0.655f, 0.572f);
            drawCylinder(varCylinder, 0.25f, 0.25f, 0.8f, FILL, towerWindow);
        glPopMatrix();
        //Cylinder Black spot
        glPushMatrix();
            glTranslatef(translationX, 3.7f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.380f, 0.320f, 0.270f);
            drawCylinder(varCylinder, 0.25f, 0.25f, 0.1f, FILL, darkTowerBrick);
        glPopMatrix();
        //a bit Cylinder colors & expanded column
        glPushMatrix();
            glTranslatef(translationX, 3.8f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.870f, 0.800f, 0.690f);
            drawCylinder(varCylinder, 0.25f, 0.25f, 0.4f, FILL, towerWindow);
        glPopMatrix();
        //Cylinder Black spot
        glPushMatrix();
            glTranslatef(translationX, 4.2f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.380f, 0.320f, 0.270f);
            drawCylinder(varCylinder, 0.25f, 0.25f, 0.1f, FILL, darkTowerBrick);
        glPopMatrix();
        //a bit Cylinder colors & expanded column
        glPushMatrix();
            glTranslatef(translationX, 4.3f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.870f, 0.800f, 0.690f);
            drawCylinder(varCylinder, 0.25f, 0.25f, 0.2f, FILL, lightTowerBrick);
        glPopMatrix();
        //Cone Top
        glPushMatrix();
            glTranslatef(translationX, 4.5f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.743f, 0.655f, 0.572f);
            drawCylinder(varCylinder, 0.25f, 0.10f, 0.8f, FILL, lightTowerBrick);
        glPopMatrix();
        //Sphere on top of cone
        glPushMatrix();
            glTranslatef(translationX, 5.3f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.743f, 0.655f, 0.572f);
		    drawSphere(varSphere, 0.1f, 50, 50, NULL);
        glPopMatrix();
        //cone on top of the top sphere
        glPushMatrix();
            glTranslatef(translationX, 5.4f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.870f, 0.800f, 0.690f);
            drawCylinder(varCylinder, 0.1f, 0.05f, 0.05f, FILL, lightTowerBrick);
        glPopMatrix();
        //small cylinder on top of the cone on top of the top shere
        glPushMatrix();
            glTranslatef(translationX, 5.45f, translationZ);
            glTranslatef(0.f, 1.0f, 0.0f);
            glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.870f, 0.800f, 0.690f);
            drawCylinder(varCylinder, 0.05f, 0.05f, 0.2f, FILL, lightTowerBrick);
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
            drawCylinder(varCylinder, 0.06f, 0.03f, 0.1f, FILL, lightTowerBrick);

        glPopMatrix();
}

void ExperimentationStation::drawWall(float translationX, float translationY, float translationZ, float length, float depth, GLuint texture)
{
        //Wall Bottom
glPushMatrix();
    glTranslatef(translationX, translationY, translationZ);
    glColor3f(0.743, 0.655, 0.572);
    drawCuboid(length, 1.0f, depth, 0.0f, 0.5f, 0.0f, 0.743f, 0.655f, 0.572f, texture);

    //drawCylinder(varCylinder, 0.3f, 0.3f, 6.0f, FILL);
glPopMatrix();
//Cylinder Black spot
glPushMatrix();
    glTranslatef(translationX, 0.5f, translationZ);
    glTranslatef(0.f, 1.0f, 0.0f);
    drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f, darkTowerBrick);

glPopMatrix();
    //Cylinder a bit color before reaching another black spot
    glPushMatrix();
        glTranslatef(translationX, 0.6f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.743f, 0.655f, 0.572f, lightTowerBrick);
    glPopMatrix();
    //Cylinder Black spot
    glPushMatrix();
        glTranslatef(translationX, 0.7f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f, darkTowerBrick);
    glPopMatrix();
    //Cylinder colors
    glPushMatrix();
        glTranslatef(translationX, 0.8f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.7f, depth, 0.0f, 0.35f, 0.0f, 0.743f, 0.655f, 0.572f, wallWindow);
    glPopMatrix();
    //Cylinder Black spot
    glPushMatrix();
        glTranslatef(translationX, 1.5f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f, darkTowerBrick);
    glPopMatrix();
    //Cylinder a bit color before reaching another black spot
    glPushMatrix();
        glTranslatef(translationX, 1.6f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.743f, 0.655f, 0.572f, lightTowerBrick);
    glPopMatrix();
    //Cylinder Black spot
    glPushMatrix();
        glTranslatef(translationX, 1.7f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f, darkTowerBrick);
    glPopMatrix();
    //Cylinder colors
    glPushMatrix();
        glTranslatef(translationX, 1.8f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.5f, depth, 0.0f, 0.25f, 0.0f, 0.743f, 0.655f, 0.572f, wallWindow);
    glPopMatrix();
    //Cylinder colors but expanded column
    glPushMatrix();
        glTranslatef(translationX, 2.3f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.3f, depth, 0.0f, 0.15f, 0.0f, 0.743f, 0.655f, 0.572f, lightTowerBrick);
    glPopMatrix();
    //Cylinder Black spot
    glPushMatrix();
        glTranslatef(translationX, 2.6f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f, darkTowerBrick);
    glPopMatrix();
    //a bit Cylinder colors & expanded column
    glPushMatrix();
        glTranslatef(translationX, 2.7f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.743f, 0.655f, 0.572f, lightTowerBrick);
    glPopMatrix();
    //Cylinder Black spot
    glPushMatrix();
        glTranslatef(translationX, 2.8f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f, darkTowerBrick);
    glPopMatrix();
    //a bit Cylinder colors & expanded column
    glPushMatrix();
        glTranslatef(translationX, 2.9f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.8f, depth, 0.0f, 0.4f, 0.0f, 0.743f, 0.655f, 0.572f, wallWindow);
    glPopMatrix();
    //Cylinder Black spot
    glPushMatrix();
        glTranslatef(translationX, 3.7f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f, darkTowerBrick);
    glPopMatrix();
    //a bit Cylinder colors & expanded column
    glPushMatrix();
        glTranslatef(translationX, 3.8f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.4f, depth, 0.0f, 0.2f, 0.0f, 0.870f, 0.800f, 0.690f, lightTowerBrick);
    glPopMatrix();
    //Cylinder Black spot
    glPushMatrix();
        glTranslatef(translationX, 4.2f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.1f, depth, 0.0f, 0.05f, 0.0f, 0.380f, 0.320f, 0.270f, darkTowerBrick);
    glPopMatrix();
    //a bit Cylinder colors & expanded column
    glPushMatrix();
        glTranslatef(translationX, 4.3f, translationZ);
        glTranslatef(0.f, 1.0f, 0.0f);
        drawCuboid(length, 0.2f, depth, 0.0f, 0.1f, 0.0f, 0.870f, 0.800f, 0.690f, lightTowerBrick);
    glPopMatrix();
}

void ExperimentationStation::drawGroundBridge1(float translationX, float translationY, float translationZ, float length, float depth)
{
    glPushMatrix();
    glTranslatef(translationX, translationY, translationZ);
    glRotatef(openAndCloseGate, 0, 0, 1);
    drawCuboid(length, 0.2f, depth, length / 2, 0.0f, 0.0f, 0.902f, 0.902f, 0.902f, groundBridge);

    glPopMatrix();
}

void ExperimentationStation::drawGroundBridge2(float translationX, float translationY, float translationZ, float length, float depth)
{
    glPushMatrix();
    glTranslatef(translationX, translationY, translationZ);
    glRotatef(-openAndCloseGate, 0, 0, 1);
    drawCuboid(length, 0.2f, depth, -length / 2, 0.0f, 0.0f, 0.902f, 0.902f, 0.902f, groundBridge);

    glPopMatrix();
}

void ExperimentationStation::drawGroundBridge3And4(float translationX, float translationY, float translationZ, float length, float depth)
{
    glPushMatrix();
    glTranslatef(translationX, translationY, translationZ);
    drawCuboid(length, 0.2f, depth, length / 2, 0.0f, 0.0f, 0.902f, 0.902f, 0.902f, groundBridge);

    glPopMatrix();
}


void ExperimentationStation::drawBridge(float translationX, float translationY, float translationZ, float length, float depth, float red, float green, float blue)
{
    glPushMatrix();
    glTranslatef(translationX, translationY, translationZ);
    //deck
    drawCuboid(length, 0.2f, depth, 0.0f, 0.1f, 0.0f, red, green, blue, groundBridge);
    //railing 1
    glPushMatrix();
        glTranslatef(0.0f, 0.2f, -0.15f);
        drawCuboid(length, 0.5f, 0.1f, 0.0f, 0.25f, 0.0f, 0.902f, 0.902f, 0.902f, bridgeRailing);
    glPopMatrix();
    //railing 2
    glPushMatrix();
        glTranslatef(0.0f, 0.2f, 0.15f);
        drawCuboid(length, 0.5f, 0.1f, 0.0f, 0.25f, 0.0f, 0.902f, 0.902f, 0.902f, bridgeRailing);
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
            drawCuboid(25.0f, 10.0f, 15.0f, 0.0f, -5.0f, 0.0, 0.68f, 0.85f, 0.90f, sea);
        glPopMatrix();

        //Ship
        glPushMatrix();
            glTranslatef(3.25f, 0.0f, shipMovement);
            drawCuboid(2.0f, 1.0f, 2.5f, 0.0f, -0.5f, 0.0, 0.22f, 0.32f, 0.41f, shipHull);
            glTranslatef(0.0f, 0.0f, 0.0f);
            drawCuboid(1.0f, 0.5f, 1.0f, 0.0f, 0.25f, 0.0, 0.92f, 0.92f, 0.92f, shipHull);
            glTranslatef(0.0f, 0.5, 0.0f);
            drawPyramid(1.0f, 0.5f, 1.0f, 0.0f, 0.25f, 0.0f, shipUpperPart);
        glPopMatrix();

        //first tower structure
        drawCuboid(3.5f, 1.0f, 3.0f, 0.0f, 0.0f, 0.0, 0.594, 0.524, 0.457, whiteColorBrick);
        drawColumnOfTower(-0.65f, 0.5f, 0.90f);
        drawColumnOfTower(0.65f, 0.5f, 0.90f);
        drawColumnOfTower(-0.65f, 0.5f, -0.90f);
        drawColumnOfTower(0.65f, 0.5f, -0.90f);
        drawWall(0.0f, 0.5f, 0.65f, 1.0f, 0.3f, lightTowerBrick);
        drawWall(0.0f, 0.5f, -0.65f, 1.0f, 0.3f, lightTowerBrick);
        glPushMatrix();
            glColor3f(0.73f, 0.72f, 0.63f);
            drawPyramid(1.1f, 2.5f, 1.1f, 0.0f, 6.5f, 0.0f, pyramidRoof);
        glPopMatrix();
        glPushMatrix();
            glColor3f(1.0f, 1.0f, 1.0f);
            glTranslatef(-4.8f, 2.4f, -0.8f);
            drawCylinderAlongCurve(90.0f, 180.0f, 4.0f, 2.0f, 0.15f, FILL, bridgeRope);
        glPopMatrix();
        glPushMatrix();
            glColor3f(1.0f, 1.0f, 1.0f);
            glTranslatef(-4.8f, 2.4f, 0.8f);
            drawCylinderAlongCurve(90.0f, 180.0f, 4.0f, 2.0f, 0.15f, FILL, bridgeRope);
        glPopMatrix();
        glPushMatrix();
		    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
            drawWall(0.0f, 0.5f, -0.65f, 1.5f, 0.3f, towerEntrance);
        glPopMatrix();
        glPushMatrix();
            glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
            drawWall(0.0f, 0.5f, -0.65f, 1.5f, 0.3f, towerEntrance);
        glPopMatrix();

        glPushMatrix();
		//bridge on Ground floor between two towers
 
        drawGroundBridge1(1.75f, 0.3f, 0.0f, 1.5f, 2.0f);
        //glRotatef(-openAndCloseGate, 0, 0, 1);
        drawGroundBridge2(4.75f, 0.3f, 0.0f, 1.5f, 2.0f);
        beginScaleTexture(5, 1);
        drawGroundBridge3And4(8.2f, 0.3f, 0.0f, 8.0f, 2.0f);
        drawGroundBridge3And4(-8.2f, 0.3f, 0.0f, 8.0f, 2.0f);
		endScaleTexture();
        glPopMatrix();
        //second tower structure
		glPushMatrix();
		    glTranslatef(6.5f, 0.0f, 0.0f);
            drawCuboid(3.5f, 1.0f, 3.0f, 0.0f, 0.0f, 0.0, 0.594, 0.524, 0.457, whiteColorBrick);
            drawColumnOfTower(-0.65f, 0.5f, 0.90f);
            drawColumnOfTower(0.65f, 0.5f, 0.90f);
            drawColumnOfTower(-0.65f, 0.5f, -0.90f);
            drawColumnOfTower(0.65f, 0.5f, -0.90f);
            glPushMatrix();
                glColor3f(0.73f, 0.72f, 0.63f);
                drawPyramid(1.1f, 2.5f, 1.1f, 0.0f, 6.5f, 0.0f, pyramidRoof);
            glPopMatrix();
            glPushMatrix();;
                glTranslatef(4.8f, 2.4f, -0.8f);
				glColor3f(1.0f, 1.0f, 1.0f);
                drawCylinderAlongCurve(180.0f, 270.0f, 4.0f, 2.0f, 0.15f, FILL, bridgeRope);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(4.8f, 2.4f, 0.8f);
                glColor3f(1.0f, 1.0f, 1.0f);
                drawCylinderAlongCurve(180.0f, 270.0f, 4.0f, 2.0f, 0.15f, FILL, bridgeRope);
            glPopMatrix();

            drawWall(0.0f, 0.5f, 0.65f, 1.0f, 0.3f, lightTowerBrick);
            drawWall(0.0f, 0.5f, -0.65f, 1.0f, 0.3f, lightTowerBrick);
            glPushMatrix();
                glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
                drawWall(0.0f, 0.5f, -0.65f, 1.5f, 0.3f, towerEntrance);
            glPopMatrix();
            glPushMatrix();
                glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
                drawWall(0.0f, 0.5f, -0.65f, 1.5f, 0.3f, towerEntrance);
            glPopMatrix();
        glPopMatrix();

        //bridge between two towers on upper floors
        glPushMatrix();
            beginScaleTexture(5, 1);
            drawBridge(3.25f, 4.1f, -0.6f, 4.9f, 0.4f, 0.157f, 0.600f, 0.737f);

            drawBridge(3.25f, 4.1f, 0.6f, 4.9f, 0.4f, 0.157f, 0.600f, 0.737f);
            endScaleTexture();
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
        drawCylinder(quad, 2.0f, 2.0f, 3.0f, FILL, NULL);
        //drawCircleWithHole(3.0f, 1.0f, 50);
        //drawCylinderAlongCurve(0, 360, 3.0f, 3.0f, 0.5, FILL);
        //drawBeautifulCircleWithFlowers(2.0f, 2.0f, 2.0f, 1.0, 100, FILL);
        //drawBeautifulCircleWithFlowers(5.0f, 2.0f, 2.0f, 1.0, 100, FILL);
        //drawBeautifulCircleWithFlowers(5.0f, 2.0f, 2.0f, 1.0, 100, FILL);
	glPopMatrix();

    
    /*
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();
    */
}

void ExperimentationStation::drawIceCream()
{   /*
    glPushMatrix();
    glTranslatef(shoulder.x, shoulder.y, shoulder.z);
    drawJointMarker();
    glRasterPos3f(0, 0, 1);
    sprintf_s(buf, "Shoulder (%.1f %.1f %.1f)", 0.0f, -1.0f, 0.0f);
    drawText3D(buf);
    glPopMatrix();
    */

    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    glTranslatef(RobotEntireArm_TranslationX, RobotEntireArm_TranslationY, RobotEntireArm_TranslationZ);
    glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);

    glPushMatrix();
    glColor3f(0.82f, 0.60f, 0.33f);
    glTranslatef(0.0f, -1.0f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 1.0f, 0.0f, 3.0f, FILL, iceCreamCone);
    glPopMatrix();

    /*
    glPushMatrix();
    glColor3f(0.41f, 0.30f, 0.165f);
    glTranslatef(0.0f, -1.0f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 1.0f, 0.0f, 3.0f, LINE);
    glPopMatrix();
    */

    glPushMatrix();
    glColor3f(0.96f, 0.36f, 0.50f);
    glTranslatef(0.0f, -0.5f, 0.0f);
    drawSphere(varSphere, 1.0f, 100, 100, strawberryIceCream);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.00f, 0.95f, 0.82f);
    glTranslatef(0.0f, 0.5f, 0.0f);
    //glTranslatef(0.0f, 0.5f, 0.0f);
    drawSphere(varSphere, 1.0f, 100, 100, chocolateIceCream);
    glPopMatrix();


    /*
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    float circleRadius = 1.05f;
    glBegin(GL_POLYGON);
    for (int j = 0; j <= 4; j++)
    {
        glPushMatrix();
        glRotatef(70.0f * j, 1.0f, 0.0f, 0.0f);
        glRotatef(70.0f * j, 0.0f, 1.0f, 0.0f);
        glRotatef(70.0f * j, 0.0f, 0.0f, 1.0f);
        for (float angle = 270; angle <= 450; angle++) {
            float convertToRadian = angle * 3.14159 / 180.0;
            glColor3f(0.22f, 0.10f, 0.05f);
            glVertex3f(sin(convertToRadian) * circleRadius, cos(convertToRadian) * circleRadius, 0);
        }
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();
    */

    glPushMatrix();
    glColor3f(0.22f, 0.10f, 0.05f);


    glTranslatef(0.6f, 0.6f, 0.0f);
    glRotatef(-110.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(60.0f, 1.0f, 0.0f, 1.0f);
    drawCylinder(varCylinder2, 0.2f, 0.2f, 2.0f, FILL, chocolateCylinder);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.22f, 0.10f, 0.05f);


    glTranslatef(-0.85f, 1.1f, 0.6f);
    glRotatef(-160.0f, 1.0f, 0.0f, 0.0f);
    //glRotatef(60.0f, 1.0f, 0.0f, 1.0f);
    //glTranslatef(2.0f, 2.0f, 2.0f);
    drawCylinder(varCylinder2, 0.5f, 0.5f, 0.15f, FILL, oreo);
    glPushMatrix();
    drawCircle(0.5f, oreo);

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f, 0.0f, 0.15f);
    drawCylinder(varCylinder2, 0.5f, 0.5f, 0.15f, FILL, NULL);
    glPushMatrix();
    glColor3f(0.22f, 0.10f, 0.05f);
    glTranslatef(0.0f, 0.0f, 0.15f);
    drawCylinder(varCylinder2, 0.5f, 0.5f, 0.15f, FILL, oreo);
    drawCircle(0.5f, oreo);
    glTranslatef(0.0f, 0.0f, 0.15f);
    drawCircle(0.5f, oreo);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-0.6f, 1.45f, 0.0f);
    glColor3f(0.85f, 0.08f, 0.10f);
    drawSphere(varSphere, 0.2f, 100, 100, NULL);
    glPushMatrix();
    glTranslatef(1.15f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    float ovalCenterCoordinateX = 0.0f;
    float ovalCenterCoordinateY = 0.1f;
    float ovalXRadius = 1.15f;
    float ovalYRadius = 1.15f;
    glRotatef(30.0f, 1.0f, 0.0f, 0.0f);

    glLineWidth(5.0f);
    for (float angle = 270; angle <= 300; angle++) {
        float convertToRadian = angle * 3.14159 / 180.0;
        glColor3f(0.85f, 0.15f, 0.20f);
        glVertex2f(sin(convertToRadian) * ovalXRadius + ovalCenterCoordinateX, cos(convertToRadian) * ovalYRadius + ovalCenterCoordinateY);
    }

    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f, NULL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.45f, 0.1f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f, NULL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1f, 1.45f, -0.15f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f, NULL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3f, 1.45f, 0.05f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f, NULL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3f, 1.45f, 0.05f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f, NULL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f, 1.35f, 0.05f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f, NULL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f, 1.20f, 0.5f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f, NULL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3f, 1.3f, 0.5f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f, NULL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1f, 1.35f, 0.5f);
    glRotatef(45.0f, 1.0f, 0.0f, 1.0f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f, NULL);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 1.35f, 0.4f);
    glRotatef(-45.0f, 1.0f, 0.0f, 1.0f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f, NULL);
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

    drawCylinder(quad, 2.0f, 2.0f, 2.0f, FILL, NULL);
    glTranslatef(RobotEntireArm_3DRotationAngleX * 0.1, RobotEntireArm_3DRotationAngleY * 0.1, RobotEntireArm_3DRotationAngleZ * 0.1);
    glTranslatef(1.5f, 0.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    drawSphere(varSphere, 0.5f, 50, 50, NULL);
    glPopMatrix();
    glPushMatrix();
    glRotatef(RobotElbow_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(RobotElbow_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(RobotElbow_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    if (choice == 0)
    {
        drawPyramid(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL);
    }
    else
    {
        drawPyramid(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL);
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.8f, 0.0f, 0.0f);
    if (choice == 0)
    {
        drawCuboid(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, NULL);
    }
    else
    {
        drawCuboid(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, NULL);
    }
    
    glPopMatrix();
}

void ExperimentationStation::shadeModel()
{
    // create ground plane
    glPushMatrix();
        glTranslatef(RobotEntireArm_TranslationX, RobotEntireArm_TranslationY, RobotEntireArm_TranslationZ);
        glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
        glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
        glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);


        glPushMatrix();
            glScalef(5.0f, 5.0f, 5.0f);
            glColor3f(0.0f, 0.0f, 0.0f);
            glBegin(GL_QUADS);
            //glTranslatef(0, -0.5f, 0.0f);
            glVertex3f(0.5f, 0.5f, -0.5f);
            glVertex3f(0.5f, 0.5f, 0.5f);
            glVertex3f(-0.5f, 0.5f, 0.5f);
            glVertex3f(-0.5f, 0.5f, -0.5f);
            glEnd();
        glPopMatrix();

        //create sphere object

        //drawSphere(varSphere, 1.0f, 20, 20);
        glPushMatrix();
            /*
            glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cyanColour);
            glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cyanColour);
            glTranslatef(0, 1, 0);
            gluQuadricTeture(var, true);
            gluSphere(var, 0.2, starPoints, starPoints);*/
            glTranslatef(0, 1, 0);
            drawSphere(varSphere, 1.0f, 20, 20, NULL);
        glPopMatrix();

        //clone the sphere above
        //translate the clone, to the same location as the sphere
        //squash the clone
        //translate the clone to the ground
        //transform the clone to be scaled and translated to match the light position

    glPopMatrix();
}

