#pragma once

#include "GameTimer.h"
#include "InputManager.h"

class Player;
class World;

class Engine
{
public:
	Engine();
	~Engine();

	void Init(const WindowInfo& Info);
	void Tick();

	void ResizeWindow(int32 Width, int32 Height);

	float GetDeltaTime() const { return Timer->GetDeltaTime(); }
	World& GetWorld() const { return *CurrentWorld.get(); }

	void OnKeyDown(WPARAM Key) { Input->OnKeyDown(Key); }
	void OnKeyUp(WPARAM Key) { Input->OnKeyUp(Key); }
	
	void SetWindowString(const string& InString);

protected:

	void CreateWorld();
	void CreatePlayerAndPawn();

private:

	WindowInfo Window;

	unique_ptr<GameTimer> Timer;
	unique_ptr<InputManager> Input;

	vector<unique_ptr<Player>> Players;

	unique_ptr<World> CurrentWorld;
};

