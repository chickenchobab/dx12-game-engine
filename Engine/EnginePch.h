#pragma once

#include <windows.h>
#include <memory>
#include <vector>
#include <string>
#include <map>
using namespace std;

#include <DirectXMath.h>
#include "d3dx12.h"
using namespace DirectX;

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;
using Vec2 = XMFLOAT2;
using Vec3 = XMFLOAT3;
using Vec4 = XMFLOAT4;
using Matrix = XMMATRIX;

struct WindowInfo
{
	HWND HWnd; // 출력 윈도우
	int32 Width;
	int32 Height;
	bool Windowed;
};

extern unique_ptr<class Engine> GEngine;