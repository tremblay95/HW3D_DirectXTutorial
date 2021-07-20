#include "App.h"
#include <sstream>
#include <iomanip>


App::App()
	: wnd(800, 600, L"Direct3D Tutorial")
{
}

int App::Go()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			return *ecode;
		}

		DoFrame();
	}
}

void App::DoFrame()
{
	//Todo: fix weirdness when mouse exits client section...

	const float t = timer.Peak();
	std::wostringstream woss;
	woss << "Time Elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	wnd.SetTitle(woss.str());
}
