#pragma once
#include "D3DWin.h"
#include "D3DTutException.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include <optional>
#include <memory>

class Window 
{
public:
	class Exception : public D3DTutException
	{
		using D3DTutException::D3DTutException;
	public:
		static std::string TranslateErrorCode(HRESULT hr) noexcept;
	};
	class HrException : public Exception
	{
	public:
		HrException(int line, const char* file, HRESULT hr) noexcept;
		const char* what() const noexcept override;
		const char* GetType() const noexcept override;

		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorDescription() const noexcept;
	
	private:
		HRESULT hr;
	};
	class NoGfxException : public Exception
	{
	public:
		using Exception::Exception;
		const char* GetType() const noexcept override;
	};

private:
	// singleton manages registration/cleanup of window class
	class WindowClass
	{
	public:
		static const WCHAR* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		
		//explicitly delete copy constructor & assignment operator
		WindowClass(const WindowClass &) = delete;
		WindowClass &operator=(const WindowClass &) = delete;

		static constexpr const WCHAR *wndClassName = L"D3D_Tutorial_Window";
		static WindowClass wndClass;
		HINSTANCE hInst;
	};

public:
	Window(int width, int height, const WCHAR *name);
	~Window();
	Window(const Window &) = delete;
	Window &operator=(const Window &) = delete;
	void SetTitle(const std::wstring& title);
	static std::optional<int> ProcessMessages();
	Graphics& Gfx();

private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

public:
	Keyboard kbd;
	Mouse mouse;

private:
	int width;
	int height;
	HWND hWnd;
	std::unique_ptr<Graphics> pGfx;
};

// Error exception helper macro
#define D3DWND_EXCEPT(hr) Window::HrException(__LINE__, __FILE__, hr)
#define D3DWND_LAST_EXCEPT() Window::HrException(__LINE__, __FILE__, GetLastError())
#define D3DWND_NOGFX_EXCEPT() Window::NoGfxException(__LINE__, __FILE__)