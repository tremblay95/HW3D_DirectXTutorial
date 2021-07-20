#include "D3DTimer.h"

using namespace std::chrono;

D3DTimer::D3DTimer() noexcept
{
    last = steady_clock::now();
}

float D3DTimer::Mark() noexcept
{
    const auto old = last;
    last = steady_clock::now();
    const duration<float> frameTime = last - old;
    return frameTime.count();
}

float D3DTimer::Peek() const noexcept
{
    return duration<float>(steady_clock::now() - last).count();
}
