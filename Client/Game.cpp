#include "pch.h"
#include "Game.h"
#include "Engine.h"

void Game::Init(const WindowInfo& Info)
{
	GEngine->Init(Info);
}

void Game::Tick()
{
	GEngine->Tick();
}

LRESULT Game::MsgProc(HWND HWnd, UINT Message, WPARAM WParam, LPARAM LParam)
{
	switch (Message)
	{
	case WM_LBUTTONDOWN:
	case WM_MBUTTONDOWN:
	case WM_RBUTTONDOWN:
		return 0;
	case WM_LBUTTONUP:
	case WM_MBUTTONUP:
	case WM_RBUTTONUP:
		return 0;
	case WM_MOUSEMOVE:
		return 0;
	case WM_KEYDOWN:
		GEngine->OnKeyDown(WParam);
		return 0;
	case WM_KEYUP:
		GEngine->OnKeyUp(WParam);
		return 0;
	}

	return DefWindowProc(HWnd, Message, WParam, LParam);
}
