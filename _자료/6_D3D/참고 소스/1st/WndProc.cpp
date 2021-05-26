#include "d3dUtility.h"

LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if(wParam == VK_ESCAPE)
			::DestroyWindow(hwnd);
		if(wParam == VK_SPACE)
		{
		}
		break;
	}
	return ::DefWindowProc(hwnd, msg, wParam, lParam);
}