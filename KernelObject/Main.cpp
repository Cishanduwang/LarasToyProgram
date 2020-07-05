#include <iostream>
#include <Windows.h>
#include <tchar.h>
using namespace std;

int WINAPI _tWinMain(HINSTANCE hInsrExe, HINSTANCE, LPTSTR lpszCmdLine, int nCmdShow)
{
	HANDLE hmutex = CreateMutex(NULL, FALSE, TEXT("Global\\MASHOW FARUIER"));
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		MessageBox(NULL, TEXT("This Program is already running."), TEXT("INFO"), MB_OK);
		return 0;
	}
	else {
		MessageBox(NULL, TEXT("This Program is running."), TEXT("INFO"), MB_OK);
		return 0;
	}
}