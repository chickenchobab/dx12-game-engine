#pragma once

#include "pch.h"

class GameTimer
{
public:
	GameTimer();

	void Tick();

	float GetDeltaTime() const { return DeltaTime; }

private:

	float DeltaTime;
	double Frequency;

	uint32 FrameCount;
	uint64 PrevCount;
	uint64 CurrCount;
};

