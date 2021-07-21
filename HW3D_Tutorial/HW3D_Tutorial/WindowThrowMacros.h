#pragma once

// Error exception helper macro
#define D3DWND_EXCEPT(hr) Window::HrException(__LINE__, __FILE__, hr)
#define D3DWND_LAST_EXCEPT() Window::HrException(__LINE__, __FILE__, GetLastError())
#define D3DWND_NOGFX_EXCEPT() Window::NoGfxException(__LINE__, __FILE__)