#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <strsafe.h>
using namespace std;

//自定义异常处理函数
void InvalidParameterHandler(PCTSTR expression, PCTSTR function, PCTSTR file, unsigned int line, uintptr_t /*pReserved*/)
{
	TCHAR ErrorInfo[255] = L"Expression is :\r\n";
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), expression);
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), L"\r\n");
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), L"Function is :\r\n");
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), function);
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), L"\r\n");
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), L"File is :\r\n");
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), file);
	_tcscat_s(ErrorInfo, _countof(ErrorInfo), L"\r\n");
	MessageBox(NULL, ErrorInfo, L"An Exption is Ocured,Program will exit!", MB_OK);
	ExitProcess(0);
}
int main(int argc, char* argv)
{
	//设置自定义异常处理函数
	_set_invalid_parameter_handler(InvalidParameterHandler);
	//禁用默认的Debug异常处理对话框
	_CrtSetReportMode(_CRT_ASSERT, 0);

	wchar_t a[30] = L"wchar_t equal ";
	WCHAR *b = L"WCHAR";
	cout << _tcscat_s(a, _countof(a), b) << endl;
	MessageBox(NULL, a, L"Info", MB_OK);
	
	WCHAR c[50] = L"*WCHAR equal ";
	PWSTR d = L"PWSTR and ";
	PWCHAR e = L"PWCHAR";
	_tcscat_s(c, _countof(c), d);
	_tcscat_s(c, _countof(c), e);
	cout << c << endl;
	MessageBox(NULL, c, L"Info", MB_OK);

	wchar_t *str = L"123456789";
	int wlen = _tcslen(str);
	cout << "str's lens is :" << wlen << endl;

	//新增函数
	TCHAR aa[20] = L"NEW ";
	PTCHAR bb = L"Function";
	StringCchCat(aa, _countof(aa), bb);
	MessageBox(NULL, aa, L"Info", MB_OK);
	system("pause");
	return 0;
}