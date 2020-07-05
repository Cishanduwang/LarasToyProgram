#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <strsafe.h>
using namespace std;

//�Զ����쳣������
void InvalidParameterHandler(PCTSTR expression, PCTSTR function, PCTSTR file, unsigned int line, uintptr_t /*pReserved*/)
{
	TCHAR ErrorInfo[255] = TEXT("Expression is :\r\n");
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), expression);
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), TEXT("\r\n"));
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), TEXT("Function is :\r\n"));
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), function);
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), TEXT("\r\n"));
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), TEXT("File is :\r\n"));
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), file);
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), TEXT("\r\n"));
	MessageBox(NULL, ErrorInfo, TEXT("An Exption is Ocured,Program will exit!"), MB_OK);
	ExitProcess(0);
}
int main(int argc, char* argv)
{
	//�����Զ����쳣������
	_set_invalid_parameter_handler(InvalidParameterHandler);
	//����Ĭ�ϵ�Debug�쳣����Ի���
	_CrtSetReportMode(_CRT_ASSERT, 0);

	wchar_t a[30] = TEXT("wchar_t equal ");
	WCHAR *b = TEXT("WCHAR");
	_tcscat_s(a, _countof(a), b);
	int mlen = WideCharToMultiByte(CP_ACP, 0, a, -1, NULL, 0, NULL, NULL);
	char *re = (char*)malloc(mlen * sizeof(char));
	WideCharToMultiByte(CP_ACP, 0, a, -1, re, mlen, NULL, NULL);
	cout << re << endl;
	
	WCHAR c[50] = TEXT("*WCHAR equal ");
	PWSTR d = TEXT("PWSTR and ");
	PWCHAR e = TEXT("PWCHAR");
	_tcscat_s(c, _countof(c), d);
	_tcscat_s(c, _countof(c), e);
	mlen = WideCharToMultiByte(CP_ACP, 0, c, -1, NULL, 0, NULL, NULL);
	re = (char*)malloc(mlen * sizeof(char));
	WideCharToMultiByte(CP_ACP, 0, c, -1, re, mlen, NULL, NULL);
	cout << re << endl;

	wchar_t *str = TEXT("123456789");
	int wlen = _tcslen(str);
	cout << "str's lens is :" << wlen << endl;

	//��������
	TCHAR aa[20] = TEXT("NEW ");
	PTCHAR bb = TEXT("Function");
	StringCchCat(aa, _countof(aa), bb);
	system("pause");
	return 0;
}