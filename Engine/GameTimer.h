#pragma once

#include "pch.h"

class GameTimer
{
public:
	GameTimer();

	void Tick();

	double GetDeltaTime() const { return DeltaTime; }

private:

	double DeltaTime;
	double Frequency;

	uint32 FrameCount;
	uint64 PrevCount;
	uint64 CurrCount;
};

