#include "InputManager.h"


void InputManager::initialization(HWND g_hWnd, HINSTANCE hInstance) {

	this->hInstance = hInstance;
	this->g_hWnd = g_hWnd;

	if (g_hWnd == NULL) {
		MessageBoxA(0, "g_hWnd is NULL!", "Error", MB_OK);
	}

	createDirectInputObject();
	createMouseDevice();
	createKeyboardDevice();
	setInputDataFormat();
	setCooperativeLevelForKeyboardDevice(backgroundMode1, exclusivenessMode1);
	setCooperativeLevelForMouse(backgroundMode1, exclusivenessMode1);
	acquireInputKeyboardDevice();
	acquireInputMouseDevice();
}

void InputManager::releaseAll() {
	releaseKeyboardDevice();
	releaseMouseDevice();
	releaseDirectInput();
}


void InputManager::createDirectInputObject() {
	//	Create the Direct Input object.
	HRESULT hr = DirectInput8Create(GetModuleHandle(NULL), 0x0800, IID_IDirectInput8, (void**)&dInput, NULL);
	if (FAILED(hr)) {
		MessageBoxA(0, "createDirectInputObject failed!", "Error", MB_OK);
	}
}

void InputManager::createMouseDevice() {
	HRESULT hr = dInput->CreateDevice(GUID_SysMouse, &dInputMouseDevice, NULL);

	if (FAILED(hr)) {
		MessageBoxA(0, "createMouseDevice failed!", "Error", MB_OK);

	}
}

void InputManager::createKeyboardDevice() {
	HRESULT hr = dInput->CreateDevice(GUID_SysKeyboard, &dInputKeyboardDevice, NULL);

	if (FAILED(hr)) {
		MessageBoxA(0, "createKeyboardDevice failed!", "Error", MB_OK);

	}
}
void InputManager::setInputDataFormat() {
	HRESULT hr = dInputKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);

	if (FAILED(hr)) {
		MessageBoxA(0, "setKeyboardInputDataFormat failed!", "Error", MB_OK);
	}

	HRESULT hrM = dInputMouseDevice->SetDataFormat(&c_dfDIMouse);

	if (FAILED(hrM)) {
		MessageBoxA(0, "setMouseInputDataFormat failed!", "Error", MB_OK);
	}
}

void InputManager::setCooperativeLevelForKeyboardDevice(int backgroundMode1, int exclusivenessMode1) {
	HRESULT hr = dInputKeyboardDevice->SetCooperativeLevel(g_hWnd, backgroundMode1 | exclusivenessMode1);
	if (FAILED(hr)) {
		MessageBoxA(0, "setCooperativeLevelForKeyboardDevice failed!", "Error", MB_OK);;
	}

	if (GetForegroundWindow() != g_hWnd) {
		MessageBoxA(0, "Warning! Window is not in focus", "Error", MB_OK);;
	}
}

void InputManager::setCooperativeLevelForMouse(int backgroundMode1, int exclusivenessMode1) {
	HRESULT hr = dInputMouseDevice->SetCooperativeLevel(g_hWnd, backgroundMode1 | exclusivenessMode1);
	if (FAILED(hr)) {
		MessageBoxA(0, "setCooperativeLevelForMouseDevice failed!", "Error", MB_OK);;
	}

	if (GetForegroundWindow() != g_hWnd) {
		MessageBoxA(0, "Warning! Window is not in focus", "Error", MB_OK);;
	}
}

void InputManager::acquireInputKeyboardDevice() {
	HRESULT hr = dInputKeyboardDevice->Acquire();

	if (FAILED(hr)) {
		MessageBoxA(0, "dInputKeyboardDevice failed", "Error", MB_OK);
	}
}

void InputManager::acquireInputMouseDevice() {
	HRESULT hr = dInputMouseDevice->Acquire();

	if (FAILED(hr)) {
		MessageBoxA(0, "dInputMouseDevice failed", "Error", MB_OK);
	}
}

LPDIRECTINPUTDEVICE8 InputManager::getDInputKeyboardDevice() {
	return dInputKeyboardDevice;
}

LPDIRECTINPUTDEVICE8 InputManager::getDInputMouseDevice() {
	return dInputMouseDevice;
}


void InputManager::releaseKeyboardDevice() {
	//	Release keyboard device.
	dInputKeyboardDevice->Unacquire();
	dInputKeyboardDevice->Release();
	dInputKeyboardDevice = NULL;

}

void InputManager::releaseMouseDevice() {
	// Release mouse device.
	dInputMouseDevice->Unacquire();
	dInputMouseDevice->Release();
	dInputMouseDevice = NULL;
}

void InputManager::releaseDirectInput() {
	//	Release DirectInput.
	dInput->Release();
	dInput = NULL;
}



