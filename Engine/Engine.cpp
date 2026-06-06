#include "pch.h"
#include "Engine.h"

Engine::Engine()
{
	Timer = make_unique<GameTimer>();
	Input = make_unique<InputManager>();
}

Engine::~Engine()
{
}

void Engine::Init(const WindowInfo& Info)
{
	Window = Info;

	ResizeWindow(Info.Width, Info.Height);
}

void Engine::Tick()
{
	Timer->Tick();
	// TODO
	Input->Tick();
}

void Engine::ResizeWindow(int32 Width, int32 Height)
{
	Window.Width = Width;
	Window.Height = Height;

	RECT Rect = { 0, 0, Width, Height };
	AdjustWindowRect(&Rect, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(Window.HWnd, 0, 100, 100, Width, Height, 0);
}

void Engine::SetWindowString(const string& InString)
{
	wstring Title(InString.begin(), InString.end());

	SetWindowTextW(Window.HWnd, Title.c_str());
}
