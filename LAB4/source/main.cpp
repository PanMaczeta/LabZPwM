#include <Windows.h>
#include "res.h"
#include <string>
HINSTANCE g_hInstance;
bool array = false;

INT_PTR CALLBACK hWindowProcKa(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
  case WM_CLOSE:
    if (array == true) {
    DestroyWindow(hwndDlg);
    PostQuitMessage(0);
    return TRUE;
  }
  else 
  {
      DestroyWindow(hwndDlg);
      array = true;
  }
  case WM_INITDIALOG:
    HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_DRUGA));
    SendMessage(hwndDlg, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    HMENU hMenuKa = LoadMenu(g_hInstance, MAKEINTRESOURCE(IDR_MENU3));
    SetMenu(hwndDlg, hMenuKa);
    return FALSE;
  }
  return FALSE;
}

INT_PTR CALLBACK hWindowProcKo(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
  case WM_CLOSE:
    if (array == true) {
      DestroyWindow(hwndDlg);
      PostQuitMessage(0);
      return TRUE;
    }
    else
    {
      DestroyWindow(hwndDlg);
      array = true;
    }
  case WM_INITDIALOG:
    HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_TRZECIA));
    SendMessage(hwndDlg, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    HMENU hMenuKo = LoadMenu(g_hInstance, MAKEINTRESOURCE(IDR_MENU2));
    SetMenu(hwndDlg, hMenuKo);
    return FALSE;
  }
  return FALSE;
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
  g_hInstance = hInstance;
  wchar_t szText[200];
  HWND hWindowKo = CreateDialog(hInstance,MAKEINTRESOURCE(IDD_MAINVIEW),NULL, hWindowProcKo);
  wsprintfW(szText, L"Kokosz");
  SetWindowTextW(hWindowKo, szText);
  HWND hWindowKa = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, hWindowProcKa);
  wsprintfW(szText, L"Kajko");
  SetWindowTextW(hWindowKa, szText);
  ShowWindow(hWindowKa,iCmdShow);
  ShowWindow(hWindowKo,iCmdShow);
  MSG msg = {};
  while(GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return 0;
}