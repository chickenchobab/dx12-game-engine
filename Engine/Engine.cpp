#include "pch.h"
#include "Engine.h"
#include "Player.h"
#include "World.h"

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
	
	CreateWorld();
	CreatePlayerAndPawn();
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

void Engine::CreateWorld()
{
	CurrentWorld = make_unique<World>();
	CurrentWorld->InitWorld();
}

void Engine::CreatePlayerAndPawn()
{
	Players.push_back(make_unique<Player>());
	Players.back()->InitPlayer(CurrentWorld->SpawnActor());
}
