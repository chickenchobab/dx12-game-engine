#pragma once

#include <windows.h>
#include <memory>
#include <vector>
#include <string>
#include <map>
using namespace std;

#include <DirectXMath.h>
#include "d3dx12.h"
#include <wrl.h>

using namespace DirectX;
using namespace Microsoft::WRL;

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
using Matrix = XMFLOAT4X4;

struct WindowInfo
{
	HWND HWnd; // 출력 윈도우
	int32 Width;
	int32 Height;
	bool Windowed;
};

struct Vertex
{
	Vertex(){}
	Vertex(
		const Vec3& p,
		const Vec3& n,
		const Vec3& t,
		const Vec2& uv):
		Position(p),
		Normal(n),
		Tangent(t),
		TexCoord(uv){ }
	Vertex(
		float px, float py, float pz,
		float nx, float ny, float nz,
		float tx, float ty, float tz,
		float u, float v) :
		Position(px, py, pz),
		Normal(nx, ny, nz),
		Tangent(tx, ty, tz),
		TexCoord(u, v){ }

	Vec3 Position;
	Vec3 Normal;
	Vec3 Tangent;
	Vec2 TexCoord;
};

struct MeshData
{
	vector<Vertex> Vertices;
	vector<uint32> Indices;
};

extern unique_ptr<class Engine> GEngine;