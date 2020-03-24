#include <Windows.h>
#include "res.h"

INT_PTR CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
HICON LoadIconA(HINSTANCE hInstance, LPCSTR IDI_MAINICON3) ;


int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR szCmdLine, _In_ int iCmdShow)
{
  
  return 0;
}

INT_PTR CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}