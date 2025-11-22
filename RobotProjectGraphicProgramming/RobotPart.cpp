#include "RobotPart.h"

void RobotPart::updateInput()
{
	InputManager& inputManager = InputManager::getInstance();
	HRESULT hr = inputManager.getDInputMouseDevice()->GetDeviceState(sizeof(DIMOUSESTATE), &mouseState);
	GetCursorPos(&mousePos);
    if (BUTTONDOWN(mouseState, 0))
    {
        //do something
    }

    // BUTTONDOWN is used again to check if the second mouse button is pressed
    if (BUTTONDOWN(mouseState, 1))
    {
        //do something
    }

    // See how far in the X direction the mouse has been moved
    currentXpos += mouseState.lX;
    // See how far in the Y direction the mouse has been moved
    currentYpos += mouseState.lY;
    // Do something with the mouse movement

    LPDIRECTINPUTDEVICE8 dInputKeyboardDevice = inputManager.getDInputKeyboardDevice();
    hr = dInputKeyboardDevice->GetDeviceState(256, diKeys);
    if (diKeys[DIK_G] & 0x80) {
        

    }
}
