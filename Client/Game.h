#pragma once

class Game
{
public:
	void Init(const WindowInfo& Info);
	void Tick();
	LRESULT MsgProc(HWND HWnd, UINT Msg, WPARAM WParam, LPARAM LParam);
};

