#pragma once
#include <chrono>

class D3DTimer
{
public:
	D3DTimer() noexcept;
	float Mark() noexcept;
	float Peek() const noexcept;

private:
	std::chrono::steady_clock::time_point last;
};