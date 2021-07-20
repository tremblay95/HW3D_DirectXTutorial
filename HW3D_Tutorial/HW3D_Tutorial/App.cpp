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
	//Todo: fix weirdness when mouse exits client section at the top?
	/*const float t = timer.Peek();
	std::wostringstream woss;
	woss << "Time Elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	wnd.SetTitle(woss.str());*/

	const float c = sin(timer.Peek()) / 2.0f + 0.5f;

	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	wnd.Gfx().DrawTestTriangle();
	wnd.Gfx().EndFrame();
}
