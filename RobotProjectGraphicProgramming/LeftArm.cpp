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

void LeftArm::drawCuboid(float scaleX, float scaleY, float scaleZ, float centerPointTransformationTranslationX, float centerPointTransformationTranslationY, float centerPointTransformationTranslationZ, float red, float green, float blue)
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

void LeftArm::drawSphere(GLUquadricObj* quad, float radius, int slices, int stacks)
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

void LeftArm::drawCylinder(GLUquadricObj* quad, float baseRadius, float topRadius, float height, int selectedDrawStyle)
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

void LeftArm::drawCircle(float circleRadius) 
{
    glBegin(GL_POLYGON);
    for (float angle = 0; angle <= 360; angle++) {
        float convertToRadian = angle * 3.14159 / 180.0;
        glVertex3f(sin(convertToRadian) * circleRadius, cos(convertToRadian) * circleRadius, 0);
    }
    glEnd();
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

void LeftArm::drawIceCream()
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
    drawCylinder(varCylinder, 1.0f, 0.0f, 3.0f, FILL);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.41f, 0.30f, 0.165f);
    glTranslatef(0.0f, -1.0f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(varCylinder, 1.0f, 0.0f, 3.0f, LINE);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.96f, 0.36f, 0.50f);
    glTranslatef(0.0f, -0.5f, 0.0f);
    drawSphere(varSphere, 1.0f, 100, 100);
    glPopMatrix(); 

    glPushMatrix();
    glColor3f(1.00f, 0.95f, 0.82f);
    glTranslatef(0.0f, 0.5f, 0.0f);
    //glTranslatef(0.0f, 0.5f, 0.0f);
    drawSphere(varSphere, 1.0f, 100, 100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.00f, 0.95f, 0.82f);
    glTranslatef(0.0f, 0.5f, 0.0f);
    //glTranslatef(0.0f, 0.5f, 0.0f);
    drawSphere(varSphere, 1.0f, 100, 100);
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
	drawCylinder(varCylinder2, 0.2f, 0.2f, 2.0f, FILL);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(0.22f, 0.10f, 0.05f);


        glTranslatef(-0.85f, 1.1f, 0.6f);
        glRotatef(-160.0f, 1.0f, 0.0f, 0.0f);
        //glRotatef(60.0f, 1.0f, 0.0f, 1.0f);
        //glTranslatef(2.0f, 2.0f, 2.0f);
        drawCylinder(varCylinder2, 0.5f, 0.5f, 0.15f, FILL);
        glPushMatrix();
            drawCircle(0.5f);

            glPushMatrix();
                glColor3f(1.0f, 1.0f, 1.0f);
			    glTranslatef(0.0f, 0.0f, 0.15f);
                drawCylinder(varCylinder2, 0.5f, 0.5f, 0.15f, FILL);
                glPushMatrix();
                    glColor3f(0.22f, 0.10f, 0.05f);
                    glTranslatef(0.0f, 0.0f, 0.15f);
                    drawCylinder(varCylinder2, 0.5f, 0.5f, 0.15f, FILL);
					drawCircle(0.5f);
					glTranslatef(0.0f, 0.0f, 0.15f);
                    drawCircle(0.5f);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-0.6f, 1.45f, 0.0f);
    glColor3f(0.85f, 0.08f, 0.10f);
	drawSphere(varSphere, 0.2f, 100, 100);
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
        drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f);
	glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0f, 1.45f, 0.1f);
        drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1f, 1.45f, -0.15f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3f, 1.45f, 0.05f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3f, 1.45f, 0.05f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f, 1.35f, 0.05f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f, 1.20f, 0.5f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3f, 1.3f, 0.5f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1f, 1.35f, 0.5f);
    glRotatef(45.0f, 1.0f, 0.0f, 1.0f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 1.35f, 0.4f);
    glRotatef(-45.0f, 1.0f, 0.0f, 1.0f);
    drawCuboid(0.1f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.45f, 0.75f, 1.00f);
    glPopMatrix();
}




void LeftArm::draw() {
    

    
    /*drawJointMarker();
    glRasterPos3f(0, 0, 1);
    sprintf_s(buf, "Ori coordinate (%.1f %.1f %.1f)", 0.0, 0.0, 0.0);
    drawText3D(buf);
    */
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

    glPushMatrix();
            

        glTranslatef(RobotEntireArm_TranslationX, RobotEntireArm_TranslationY, RobotEntireArm_TranslationZ);
        glRotatef(RobotEntireArm_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
        glRotatef(RobotEntireArm_3DRotationAngleY, 0.0f, 1.0f, 0.0f);       
        glRotatef(RobotEntireArm_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
    
        glPushMatrix();
	        glTranslatef(shoulder.x, shoulder.y, shoulder.z);
            glColor3f(0.2, 0.2, 0.2);
			drawSphere(varSphere, 1.0f, 100, 100);

            glColor3f(0.0f, 1.0f, 0.0f);

            //small connecting nerve
            glPushMatrix();
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                glColor3f(0.7, 0.7, 0.7);
			    drawCylinder(varCylinder, 0.7f, 0.5f, 1.0f, FILL);
            glPopMatrix();
            glPushMatrix();

                glTranslatef(0.0f, -1.0f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                drawCylinder(varCylinder, 0.5f, 1.4f, 0.5f, FILL);
            glPopMatrix();
                glTranslatef(0.0f, -1.5f, 0.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
                drawCylinder(varCylinder, 1.7f, 1.3f, 6.0f, FILL);
            //upper arm
            glPushMatrix();

            //glTranslatef(0.0f, -1.5f, 0.0f);
            //glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            //drawCylinder(varCylinder, 0.5f, 2.0f, 0.3f);
            glPopMatrix();


			//drawCuboid(3.0f, 6.0f, 3.0f, 0.0f, -3.0f, 0.0f, 0.75f, 0.75f, 0.75f );
            //drawSphere(varSphere, 2.0f, slices, stacks);
            glPushMatrix();
			    /*
                glTranslatef(0.0f, 0.0f, -2.0f);
                glRotatef(90.0f, 1.0f, 0.0f, 0.0f); 
                drawCylinder(varCylinder, 1.0f, 0.0f, 4.0f);
				drawCylinder(varCylinder2, 0.8f, 0.8f, 3.6f);
                
                drawCircleWithHole(1.0f, 0.5f, 180);
                glEnd();
                */
            glPopMatrix();
            glPushMatrix();

                glTranslatef(elbowOffsetFromShoulder.x, elbowOffsetFromShoulder.y, elbowOffsetFromShoulder.z);
                glRotatef(RobotElbow_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
                glRotatef(RobotElbow_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
                glRotatef(RobotElbow_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
				drawCuboid(3.0f, 6.0f, 3.0f, 0.0f, -2.0f, 0.0f, 0.10f, 0.10f, 0.10f);
               
                glPushMatrix();
                    glTranslatef(wristOffsetFromElbow.x, wristOffsetFromElbow.y, wristOffsetFromElbow.z);
                    glRotatef(RobotWrist_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
                    glRotatef(RobotWrist_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
                    glRotatef(RobotWrist_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
					drawCuboid(4.0f, 3.0f, 2.0f, 0.0f, -0.5f, 0.0f, 0.10f, 0.10f, 0.10f);

                    glPushMatrix();
                        //fingers rotate transformation if needed
                        /*
                        glRotatef(RobotElbow_3DRotationAngleX, 1.0f, 0.0f, 0.0f);
                        glRotatef(RobotElbow_3DRotationAngleY, 0.0f, 1.0f, 0.0f);
                        glRotatef(RobotElbow_3DRotationAngleZ, 0.0f, 0.0f, 1.0f);
                        */
					    glTranslatef(finger1OffsetFromWrist.x, finger1OffsetFromWrist.y, finger1OffsetFromWrist.z);
                        drawCuboid(1.0f, 1.0f, 2.0f, 0.0f, -0.5f, 0.0f, 0.75f, 0.75f, 0.75f);
                    glPopMatrix();
                    glPushMatrix();
                        glTranslatef(finger2OffsetFromWrist.x, finger2OffsetFromWrist.y, finger2OffsetFromWrist.z);
						drawCuboid(1.0f, 1.0f, 2.0f, 0.0f, -0.5f, 0.0f, 0.75f, 0.75f, 0.75f);
                    glPopMatrix();
                    glPushMatrix();
                    glTranslatef(finger3OffsetFromWrist.x, finger3OffsetFromWrist.y, finger3OffsetFromWrist.z);
                    drawCuboid(1.0f, 1.0f, 2.0f, 0.0f, -0.5f, 0.0f, 0.75f, 0.75f, 0.75f);
                    glPopMatrix();
                    glPushMatrix();
                    glTranslatef(finger4OffsetFromWrist.x, finger4OffsetFromWrist.y, finger4OffsetFromWrist.z);
                    drawCuboid(1.0f, 1.0f, 2.0f, 0.0f, -0.5f, 0.0f, 0.75f, 0.75f, 0.75f);
                    glPopMatrix();

                glPopMatrix();
            glPopMatrix();
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

