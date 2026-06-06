#include "pch.h"
#include "InputManager.h"
#include "Engine.h"

InputManager::InputManager()
{
	KeyStates.assign(KeyTypeCount, KeyState::None);
}

void InputManager::OnKeyDown(WPARAM Key)
{
	uint8 KeyIndex = static_cast<uint8>(Key);

	if (KeyStates[KeyIndex] == KeyState::None)
	{
		KeyStates[KeyIndex] = KeyState::Pressed;
	}
	else if (KeyStates[KeyIndex] == KeyState::Pressed || KeyStates[KeyIndex] == KeyState::Down)
	{
		KeyStates[KeyIndex] = KeyState::Down;
	}

	GEngine->SetWindowString("Key down");
}

void InputManager::OnKeyUp(WPARAM Key)
{
	uint8 KeyIndex = static_cast<uint8>(Key);

	KeyStates[KeyIndex] = KeyState::Released;

	GEngine->SetWindowString("Key up");
}

void InputManager::Tick()
{
	for (auto& State : KeyStates)
	{
		if (State == KeyState::Released)
		{
			State = KeyState::None;
		}
	}
}
