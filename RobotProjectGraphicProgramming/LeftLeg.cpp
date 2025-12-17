#include "LeftLeg.h"

LeftLeg::LeftLeg() {
    length = 1.0f;
    thickness = 0.3f;
    jointAngle = 0.0f;
    legControl = 0;
    // default position relative to body
    //x = 0.0f;
    //y = 0.0f;
    //z = 0.0f;

    //rx = ry = rz = 0.0f;
}


//Input Keys
void LeftLeg::updateInput() {
    InputManager& inputManager = InputManager::getInstance();
    LPDIRECTINPUTDEVICE8 dInputKeyboardDevice = inputManager.getDInputKeyboardDevice();


    HRESULT hr = dInputKeyboardDevice->GetDeviceState(256, diKeys);
    if (diKeys[DIK_W] & 0x80) {

        THIGH_3DRotationAngleX = THIGH_3DRotationAngleX + 0.2;

      /*  if (legControl == 0) 
        {
            if (THIGH_3DRotationAngleX < 0.90)
            {
                
            } 
       }
        else if (legControl == 1)
        {
            if (CALF_3DRotationAngleX < 0.90)
            {
                CALF_3DRotationAngleX++;
            }
        }*/
        

    }

    if (diKeys[DIK_S] & 0x80) {

        if (legControl = 0) {
            if (THIGH_3DRotationAngleX > -0.90)
            {
                THIGH_3DRotationAngleX--;
            }
        }
      

    }

    if (diKeys[DIK_A] & 0x80) {
   
    }

    if (diKeys[DIK_D] & 0x80) {
        
    }

    if (diKeys[DIK_Q] & 0x80) {
        

    }

    if (diKeys[DIK_E] & 0x80) {
       

    }

    if (diKeys[DIK_T] & 0x80) {
        

    }

    if (diKeys[DIK_G] & 0x80) {
        

    }

    if (diKeys[DIK_F] & 0x80) {
       
    }

    if (diKeys[DIK_H] & 0x80) {
        

    }

    if (diKeys[DIK_R] & 0x80) {
        

    }

    if (diKeys[DIK_Y] & 0x80) {
        

    }

    if (diKeys[DIK_I] & 0x80) {
       
    }

    if (diKeys[DIK_K] & 0x80) {
        

    }

    if (diKeys[DIK_J] & 0x80) {
        

    }

    if (diKeys[DIK_L] & 0x80) {
        

    }

    if (diKeys[DIK_U] & 0x80) {
       

    }

    if (diKeys[DIK_O] & 0x80) {
        
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


    if (diKeys[DIK_P] & 0x80) {
        legControl++;
        if (legControl > 3)
        {
            legControl = 0;
        }
    }

    // Example: simple arm swing animation
    // jointAngle changes over time (controlled externally)
}

void LeftLeg::drawJointMarker()
{
    GLUquadric* quad = gluNewQuadric();
    gluSphere(quad, 1.0f, 4, 4);
    gluDeleteQuadric(quad);
}

void LeftLeg::drawCuboid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, float red, float green, float blue, GLuint texture)
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

void LeftLeg::drawSphere(GLUquadricObj* quad, float radius, int slices, int stacks, GLuint texture)
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

void LeftLeg::drawCylinder(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle, GLuint texture)
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

void LeftLeg::drawCylinderWithCap(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle, GLuint texture)
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
    drawCircle(baseRadius, NULL);
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, height);
    drawCircle(topRadius, NULL);
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

void LeftLeg::drawCircle(float circleRadius, GLuint texture)
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

void LeftLeg::drawCircleWithHole(float outerRadius, float innerRadius, int segments)
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


LeftLeg::Vector3D LeftLeg::findNormalVector(Point3D v1, Point3D v2, Point3D v3)
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

void LeftLeg::drawTriangularPrism(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX,float centerPointTransformationTranslationY,float centerPointTransformationTranslationZ,GLuint texture)
{
    glPushMatrix();

    glTranslatef(centerPointTransformationTranslationX,
        centerPointTransformationTranslationY,
        centerPointTransformationTranslationZ);

    glScalef(scaleX, scaleY, scaleZ);

    glBindTexture(GL_TEXTURE_2D, texture);

    // ===== Front triangle (Z = +0.5) =====
    Vector3D normal = findNormalVector(
        Point3D{ -0.5f, -0.5f, 0.5f },
        Point3D{ 0.5f, -0.5f, 0.5f },
        Point3D{ -0.5f,  0.5f, 0.5f }
    );
    glNormal3f(normal.x, normal.y, normal.z);

    glBegin(GL_TRIANGLES);
    glTexCoord2f(0, 0); glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1, 0); glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f, 0.5f, 0.5f);
    glEnd();

    // ===== Back triangle (Z = -0.5) =====
    normal = findNormalVector(
        Point3D{ -0.5f, -0.5f, -0.5f },
        Point3D{ -0.5f,  0.5f, -0.5f },
        Point3D{ 0.5f, -0.5f, -0.5f }
    );
    glNormal3f(normal.x, normal.y, normal.z);

    glBegin(GL_TRIANGLES);
    glTexCoord2f(0, 0); glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(1, 0); glVertex3f(0.5f, -0.5f, -0.5f);
    glEnd();

    // ===== Bottom face =====
    normal = findNormalVector(
        Point3D{ -0.5f, -0.5f, -0.5f },
        Point3D{ 0.5f, -0.5f, -0.5f },
        Point3D{ 0.5f, -0.5f,  0.5f }
    );
    glNormal3f(normal.x, normal.y, normal.z);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1, 0); glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1, 1); glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f, -0.5f, 0.5f);
    glEnd();

    // ===== Left face =====
    normal = findNormalVector(
        Point3D{ -0.5f, -0.5f, -0.5f },
        Point3D{ -0.5f, -0.5f,  0.5f },
        Point3D{ -0.5f,  0.5f,  0.5f }
    );
    glNormal3f(normal.x, normal.y, normal.z);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1, 0); glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1, 1); glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    // ===== Hypotenuse face =====
    normal = findNormalVector(
        Point3D{ 0.5f, -0.5f, -0.5f },
        Point3D{ -0.5f,  0.5f, -0.5f },
        Point3D{ -0.5f,  0.5f,  0.5f }
    );
    glNormal3f(normal.x, normal.y, normal.z);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1, 0); glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(1, 1); glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();

    glPopMatrix();
}

void LeftLeg::drawBeautifulCircleWithFlowers(float circleRadius, float baseRadius, float topRadius, float height, int numCylinders, int selectedDrawStyle)
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

void LeftLeg::drawCylinderAlongCurve(float angleBegins, float angleEnds, float circleXRadius, float circleYRadius, float cylinderRadius, int selectedDrawStyle, GLuint texture)
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

void LeftLeg::drawText3D(const char* text)
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

void LeftLeg::initFont()
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

void LeftLeg::loadTextures()
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


    //glMatrixMode(GL_TEXTURE);
    //glLoadIdentity();
    //glScalef(30.0, 20.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

void LeftLeg::beginScaleTexture(float scaleX, float scaleY)
{
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glScalef(scaleX, scaleY, 1.0f);
    glMatrixMode(GL_MODELVIEW); // Switch back to MODELVIEW for drawing
}

void LeftLeg::endScaleTexture()
{
    glMatrixMode(GL_TEXTURE); // Switch to TEXTURE mode to access the stack
    glPopMatrix();            // Restore the saved 1x matrix
    glMatrixMode(GL_MODELVIEW); // Switch back to MODELVIEW for rendering the next object
}

void LeftLeg::deleteTextures()
{
    // a) Disable state change (Optional at exit)
    glDisable(GL_TEXTURE_2D);

    // b) Free the Windows GDI object
    DeleteObject(hBMP);

    glDeleteTextures(1, &texture);
    glDeleteTextures(1, &metal);
}



void LeftLeg::drawBolt() {

    //Bolt Cover   
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(0.2, 0.2, 0.2);
    drawCircle(0.3f, NULL);
    glPopMatrix();

    //Bolt
    glPushMatrix();
    glColor3f(0.9, 0.5, 0.5);
    //glTranslatef(0.0f, -5.3f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 0.3f, 0.3f, 0.3f, FILL, NULL);
    glPopMatrix();;

    //Bolt Cover   
    glPushMatrix();
    glTranslatef(0.0f, -0.3f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(0.2, 0.2, 0.2);
    drawCircle(0.3f, NULL);
    glPopMatrix();
}

void LeftLeg::drawThigh() {

    //Butt
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0f, 0.25f, 0.0f);
    drawSphere(thigh, 2.0f, 20, 20, NULL);
    glPopMatrix();

    //ThighTop
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0f, 0.5f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 1.9f, 2.5f, 2.0f, FILL, NULL);
    glPopMatrix();

    //ThighMeat
    glPushMatrix();
    glColor3f(0.7, 0.7, 0.7);
    glTranslatef(0.0f, -1.5f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 2.5f, 2.5f, 2.0f, FILL, NULL);
    glPopMatrix();

    //ThighMeat - LINE
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0f, -1.5f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 2.55f, 2.55f, 2.0f, LINE, NULL);
    glPopMatrix();

    //ThighMid
    glPushMatrix();
    glColor3f(0.7, 0.7, 0.7);
    glTranslatef(0.0f, -3.45f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 2.5f, 1.9f, 2.0f, FILL, NULL);
    glPopMatrix();

    //ThighMid - LINE
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0f, -3.45f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 2.55f, 1.95f, 2.0f, LINE, NULL);
    glPopMatrix();

    //ThighLow
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0f, -5.3f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 1.9f, 1.4f, 2.0f, FILL, NULL);
    glPopMatrix();
}

void LeftLeg::drawShin() {

    //ShinMuc
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0f, 0.25f, 0.0f);
    drawSphere(thigh, 1.6f, 10, 10, NULL);
    glPopMatrix();

    //ThighTop
    glPushMatrix();
    glColor3f(0.7, 0.7, 0.7);
    glTranslatef(0.0f, 0.5f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 1.6f ,1.8f, 2.0f, FILL, NULL);
    glPopMatrix();

    //ThighTop - LINE
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0f, 0.5f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 1.6f, 1.8f, 2.0f, LINE, NULL);
    glPopMatrix();

    //ThighMeat
    glPushMatrix();
    glColor3f(0.7, 0.7, 0.7);
    glTranslatef(0.0f, -1.5f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 1.8f, 1.8f, 2.0f, FILL, NULL);
    glPopMatrix();

    //ThighMeat -LINE
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0f, -1.5f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 1.8f, 1.8f, 2.1f, LINE, NULL);
    glPopMatrix();

    //ThighMid
    glPushMatrix();
    glColor3f(0.7, 0.7, 0.7);
    glTranslatef(0.0f, -3.45f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 1.8f, 1.4f, 2.0f, FILL, NULL);
    glPopMatrix();

    //ThighMid - line
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0f, -3.45f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 1.85f, 1.4f, 2.0F, LINE, NULL);
    glPopMatrix();

    //ThighLow
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(0.0f, -5.3f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 1.4f, 1.0f, 2.0f, FILL, NULL);
    glPopMatrix();


    //Bolts
        //Left
        glPushMatrix();
        glTranslatef(-1.9f, -3.3f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        drawBolt();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.9f, -2.7f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        drawBolt();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.9f, -2.1f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        drawBolt();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.9f, -1.5f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        drawBolt();
        glPopMatrix();

     //Right
        glPushMatrix();
        glTranslatef(1.75f, -3.3f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        drawBolt();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.75f, -2.7f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        drawBolt();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.75f, -2.1f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        drawBolt();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.75f, -1.5f, 0.0f);
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glScalef(0.6f, 0.6f, 0.6f);
        drawBolt();
        glPopMatrix();

        //Bolts
        //Left -z
            glPushMatrix();
            glTranslatef(0.0f, -3.3f, -1.7f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glScalef(0.6f, 0.6f, 0.6f);
            drawBolt();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.0f, -2.7f, -1.7f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glScalef(0.6f, 0.6f, 0.6f);
            drawBolt();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.0f, -2.1f, -1.7f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glScalef(0.6f, 0.6f, 0.6f);
            drawBolt();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.0f, -1.5f, -1.7f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glScalef(0.6f, 0.6f, 0.6f);
            drawBolt();
            glPopMatrix();

        //Right -z
            glPushMatrix();
            glTranslatef(0.0, -3.3f, 1.95f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glScalef(0.6f, 0.6f, 0.6f);
            drawBolt();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.0, -2.7f, 1.95f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glScalef(0.6f, 0.6f, 0.6f);
            drawBolt();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.0, -2.1f, 1.95f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glScalef(0.6f, 0.6f, 0.6f);
            drawBolt();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.0, -1.5f, 1.95f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            glScalef(0.6f, 0.6f, 0.6f);
            drawBolt();
            glPopMatrix();

}

void LeftLeg::drawFootPiece() {
    glPushMatrix();
    //Top
    glPushMatrix();
    glTranslatef(-0.3f, 0.4, 0.0f);
    //glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glColor3f(0.7f, 0.7f, 0.7f); // orange pyramid
    drawTriangularPrism(1.0f,.59f,  0.8f, 0.0f, 0.0f,  0.0f,  NULL);
    glPopMatrix();

    //Heel
    glPushMatrix();
    glTranslatef(-1.2f, 0.3, 0.0f);
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    drawCuboid(0.8f, 0.8f, 0.8f, 0.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f, NULL);
    glPopMatrix();

    //footSole
    glPushMatrix();
    glTranslatef(-0.3f, 0.0f, 0.0f);
    drawCuboid(1.0f, 0.2f, 0.8f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL);
    glPopMatrix();
    glPopMatrix();
}

void LeftLeg::drawFootToe() {
    glPushMatrix();


    // ===== Top (triangular prism) =====
    glPushMatrix();
    glTranslatef(-0.3f, 0.4f, 0.0f);
    glColor3f(0.7f, 0.7f, 0.7f); // brown
    drawTriangularPrism(1.0f, 0.59f, 0.8f, 0.0f, 0.0f, 0.0f, NULL);
    glPopMatrix();

    // ===== Heel =====
    glPushMatrix();
    glTranslatef(-1.1f, 0.3f, 0.0f);
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.2f, 0.2f, 0.2f); // dark grey
    drawCuboid(0.8f, 0.6f, 0.8f, 0.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f, NULL);
    glPopMatrix();

    // ===== Foot sole =====
    glPushMatrix();
    glTranslatef(-0.3f, 0.0f, 0.0f);
    glColor3f(0.1f, 0.4f, 0.8f); // blue
    drawCuboid(1.0f, 0.2f, 0.8f, 0.0f, 0.0f, 0.0f,0.0f, 0.0f, 0.0f, NULL);
    glPopMatrix();

    glPopMatrix();
}

void LeftLeg::drawFoot() {
    glPushMatrix();
    drawFootPiece();
    glPopMatrix();

    glPushMatrix();
    //Toe1
    glTranslatef(0.62f, -0.075, 0.31f);
    glScalef(0.3f, 0.2f, 0.25f);
    drawFootToe();
    glPopMatrix();


    glPushMatrix();
    //Toe2
    glTranslatef(0.62f, -0.075, 0.1f);
    glScalef(0.3f, 0.2f, 0.25f);
    drawFootToe();
    glPopMatrix();

    glPushMatrix();
    //Toe3
    glTranslatef(0.62f, -0.075, -0.11f);
    glScalef(0.3f, 0.2f, 0.25f);
    drawFootToe();
    glPopMatrix();


    glPushMatrix();
    //Toe4
    glTranslatef(0.62f, -0.075, -0.31f);
    glScalef(0.3f, 0.2f, 0.23f);
    drawFootToe();
    glPopMatrix();
}

void ObjectTransform() {
    //glTranslatef(xT, yT, zT);

}

void LeftLeg::draw() {


    //Whole Leg

    glPushMatrix();

             glTranslatef(0.0f, 0.5, 0.0f);

            glRotatef(0.45, 1.0f, 0.0f, 0.0f);
            glRotatef(THIGH_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
            glRotatef(THIGH_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);

            glTranslatef(0.0f, -0.5, 0.0f);

            glPushMatrix();
            //Tigh
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 0.0f);
            drawThigh();
            glPopMatrix();

            //Joint
            glPushMatrix();
            glColor3f(0.0, 0.0, 0.0);
            glTranslatef(0.0f, -7.8f, 0.0f);
            drawSphere(joint, 1.6f, 10, 10, NULL);
            glPopMatrix();

            //Whole Calf
            glPushMatrix();

                //Calf
                glPushMatrix();
                glTranslatef(0.0f, -9.5f, 0.3f);
                drawShin();
                glPopMatrix();

                //Joint
                glPushMatrix();
                glColor3f(0.0, 0.0, 0.0);
                glTranslatef(0.0f, -16.8f, 0.2f);
                drawSphere(joint, 0.9f, 10, 10, NULL);
                glPopMatrix();

                glPushMatrix();
        
                    //Foot
                    glPushMatrix();
                    glTranslatef(-0.0f, -19.0f, 2.5f);
                    glRotatef(-90.0f, 0.0, 1.0, 0.0);
                    glScalef(2.0f, 3.0f, 3.0f);
                    drawFoot();
                    glPopMatrix();

                    //glTranslatef(-0.0f, -19.0f, 2.5f);
                    //glRotatef(-40.0f, 1.0, 0.0, 0.0);

                glPopMatrix();

             glPopMatrix();

        glPopMatrix();
    glPopMatrix();

}

