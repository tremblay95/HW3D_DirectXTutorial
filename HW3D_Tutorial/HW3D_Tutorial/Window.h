#pragma once
#include "WINclude.h"


class Window 
{
private:
	// singleton manages registration/cleanup of window class
	class WindowClass
	{
	public:
		static const wchar_t *GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		
		//explicitly delete copy constructor & assignment operator
		WindowClass(const WindowClass &) = delete;
		WindowClass &operator=(const WindowClass &) = delete;

		static constexpr const wchar_t *wndClassName = L"D3D_Tutorial_Window";
		static WindowClass wndClass;
		HINSTANCE hInst;
	};
public:
	Window(int width, int height, const wchar_t *name) noexcept;
	~Window();
	Window(const Window &) = delete;
	Window &operator=(const Window &) = delete;
private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
private:
	int width;
	int height;
	HWND hWnd;
};