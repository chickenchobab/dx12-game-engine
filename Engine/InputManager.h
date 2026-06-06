#pragma once

enum class KeyType : uint8
{
	UP = VK_UP,
	DOWN = VK_DOWN,
	LEFT = VK_LEFT,
	RIGHT = VK_RIGHT,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',
};

enum class KeyState : uint8
{
	None,
	Pressed,
	Down,
	Released,
	Max
};

enum
{
	KeyTypeCount = static_cast<int32>(UINT8_MAX + 1),
	KeyStateCount = static_cast<int32>(KeyState::Max)
};

class InputManager
{
public:
	InputManager();

	void OnKeyDown(WPARAM Key);
	void OnKeyUp(WPARAM Key);

	void Tick();

private:

	vector<KeyState> KeyStates;
};

