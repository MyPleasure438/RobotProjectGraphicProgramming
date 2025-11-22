#pragma once
//For keyboard and mouse last time i no add dao  #define DIRECTINPUT_VERSION 0x0800, can try mouse and keyboard again to see if it works
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

//from slide,  // Define the macro needed to check the state of the keys on the keyboard, even though its under mouse code
#define BUTTONDOWN (name, key) (name.rgbButtons[key] & 0x80)

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")


class InputManager
{
private:
	HWND g_hWnd;
	HINSTANCE hInstance;
	LPDIRECTINPUT8 dInput;

	enum backgroundMode
	{
		Discl_Background = DISCL_BACKGROUND,
		Discl_Foreground = DISCL_FOREGROUND,
	};
	enum exclusivenessMode
	{
		Discl_Exclusive = DISCL_EXCLUSIVE,
		Discl_Non_Exclusive = DISCL_NONEXCLUSIVE,
	};

	backgroundMode backgroundMode1 = Discl_Background;
	exclusivenessMode exclusivenessMode1 = Discl_Non_Exclusive;


	//	Direct Input keyboard device.
	LPDIRECTINPUTDEVICE8  dInputKeyboardDevice;
	LPDIRECTINPUTDEVICE8  dInputMouseDevice;
	


	

public:
	static InputManager& getInstance() {
		static InputManager instance;
		return instance;
	}
	
	void initialization(HWND g_hWnd, HINSTANCE hInstance);
	void releaseAll();
	//Only use above 2 methods.
	void createDirectInputObject();
	void createMouseDevice();
	void createKeyboardDevice();
	void setInputDataFormat();
	void setCooperativeLevelForKeyboardDevice(int backgroundMode1, int exclusivenessMode1);
	void setCooperativeLevelForMouse(int backgroundMode1, int exclusivenessMode1);
	void acquireInputKeyboardDevice();
	void acquireInputMouseDevice();
	LPDIRECTINPUTDEVICE8 getDInputKeyboardDevice();
	LPDIRECTINPUTDEVICE8 getDInputMouseDevice();
	void releaseKeyboardDevice();
	void releaseMouseDevice();
	void releaseDirectInput();
};

