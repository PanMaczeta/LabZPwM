#include <Windows.h>
#include "res.h"
#include <time.h>  
#include <stdlib.h>  

  int random;
  int counter=0;
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
  case WM_COMMAND:
    switch (HIWORD(wParam))
    {
      case BN_CLICKED:
        switch(LOWORD(wParam))
        {
        case IDC_BUTTON1:
          //MessageBox(hwndDlg, TEXT("Prosze o nie uiszczanie klikniecia"), TEXT("Klikniecie"), MB_OK);
          HWND hwndEditBox = GetDlgItem(hwndDlg, IDC_EDIT1);
            int iTextLength = GetWindowTextLength(hwndEditBox);
            wchar_t szText[500];
            GetWindowText(hwndEditBox, szText, iTextLength + 1);
            int number;
            if (iTextLength == 2) {
              number = (szText[0] - 48) * 10 + (szText[1] - 48);
            }
            if (iTextLength == 1) {
              number = (szText[0] - 48);
            }
            wchar_t szText3[200];
            wsprintf(szText3, L"liczba to: %d" , random);
            if (number > random) {
              counter++;
              MessageBox(hwndDlg, TEXT("Mniej"), TEXT("Klikniecie"), MB_OK);
             // MessageBox(hwndDlg, szText3, TEXT("Klikniecie"), MB_OK);
            }
            if (number < random) {
              counter++;
              MessageBox(hwndDlg, TEXT("Wiêcej"), TEXT("Klikniecie"), MB_OK);
            //  MessageBox(hwndDlg, szText3, TEXT("Klikniecie"), MB_OK);
            }
            if (number == random) {
              counter++;
              MessageBox(hwndDlg, TEXT("Gratki"), TEXT("Klikniecie"), MB_OK);
              wchar_t szText2[200];
              MessageBox(hwndDlg, szText3, TEXT("Klikniecie"), MB_OK);
              wsprintf(szText2, L"liczba prób %d", counter);
              MessageBox(hwndDlg, szText2, TEXT("Klikniecie"), MB_OK);
              counter = 0;
            }
         // SetWindowText((HWND)lParam, szText);
          return TRUE;
        }
    }
    return FALSE;
  case WM_CLOSE:
    DestroyWindow(hwndDlg); //niszczenie okienka
    PostQuitMessage(0); //Polecenie zakoñczenia aplikacji
    return TRUE;
  case WM_LBUTTONDOWN:
    CHAR szText2[200];
   // wsprintf(szText, "Kliknales myszka x=%d, y=%d", LOWORD(lParam), HIWORD(lParam));
    //MessageBox(hwndDlg, szText, TEXT("Klikniecie"), MB_OK);
    return TRUE;
  }
  return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
  {
  srand((unsigned int)time(NULL));
  random= (rand() % 40) +1;

  HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogProc);
  ShowWindow(hwndMainWindow, iCmdShow);

  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
    return 0;
  }