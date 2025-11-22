#pragma once
#include "InputManager.h"
class RobotPart
{
protected:
	BYTE  dikeys[256];
	DIMOUSESTATE mousestate;
	static POINT mouseposition;

    //keyboard
    char diKeys[256];
    LPDIRECTINPUTDEVICE8 dInputKeyboardDevice;

    //mouse
    LPDIRECTINPUTDEVICE8 dInputMouseDevice;
    LONG currentXpos = 0;
    LONG currentYpos = 0;
    POINT mousePos;
    bool mouseDown = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
#define BUTTONDOWN(name, key) ((name.rgbButtons[key] & 0x80) != 0)
    DIMOUSESTATE mouseState;

    struct Joint {
        float x, y, z;
    };

public:
	virtual void updateInput();
	void initializeCursor();
	void updateCursor();
};

