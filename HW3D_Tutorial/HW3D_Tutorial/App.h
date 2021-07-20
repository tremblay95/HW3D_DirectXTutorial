#pragma once
#include "Window.h"
#include "D3DTimer.h"

class App
{
public:
	App();
	// Master frame / message loop
	int Go();
	
private:
	void DoFrame();
	
private:
	Window wnd;
	D3DTimer timer;
};