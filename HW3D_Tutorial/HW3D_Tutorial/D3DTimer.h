#pragma once
#include <chrono>

class D3DTimer
{
public:
	D3DTimer();
	float Mark();
	float Peak() const;

private:
	std::chrono::steady_clock::time_point last;
};