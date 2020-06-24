#include <stdio.h>
#include <Windows.h>

int main(void)
{
	DWORD dwError = 0;
	DWORD systemlocal = MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL);
	HLOCAL hlocal = NULL;

	printf("Please input error code you need to be translate.\n");
	scanf("%d", &dwError);
	BOOL fOK = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_ALLOCATE_BUFFER, NULL, dwError, systemlocal, (PTSTR)&hlocal, 0, NULL);
	if (fOK && (hlocal != NULL))
	{
		printf("Message is %s \n", (PCTSTR)LocalLock(hlocal));
		LocalFree(hlocal);
	}
	else
	{
		printf("No recored \n");
	}
	system("pause");
}