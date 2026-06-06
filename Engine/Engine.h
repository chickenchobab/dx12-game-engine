#pragma once

#include "GameTimer.h"
#include "InputManager.h"

class Engine
{
public:
	Engine();
	~Engine();

	void Init(const WindowInfo& Info);
	void Tick();

	void ResizeWindow(int32 Width, int32 Height);

	double GetDeltaTime() const { return Timer->GetDeltaTime(); }

	void OnKeyDown(WPARAM Key) { Input->OnKeyDown(Key); }
	void OnKeyUp(WPARAM Key) { Input->OnKeyUp(Key); }
	
	void SetWindowString(const string& InString);

private:

	WindowInfo Window;

	unique_ptr<GameTimer> Timer;
	unique_ptr<InputManager> Input;
};

