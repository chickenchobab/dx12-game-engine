#include "pch.h"
#include "GameTimer.h"

GameTimer::GameTimer()
	: DeltaTime(-1), FrameCount(0), PrevCount(0), CurrCount(0)
{
	QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&Frequency));
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&PrevCount));
}

void GameTimer::Tick()
{
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&CurrCount));

	DeltaTime = (CurrCount - PrevCount) / static_cast<float>(Frequency);

	PrevCount = CurrCount;
	++FrameCount;
}
