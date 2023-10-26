#include <Windows.h>
#include<stdio.h>

HHOOK g_hHook;
LRESULT GetMsgProc(
	int code,
	WPARAM wParam,
	LPARAM lParam)
{

	return ::CallNextHookEx(g_hHook, code, wParam, lParam);
}

int main()
{
	HMODULE hDll;
	hDll = ::LoadLibrary("libuntitled.dll");
	g_hHook = SetWindowsHookEx(WH_GETMESSAGE, (HOOKPROC)GetMsgProc, hDll, 0);
	if (g_hHook == NULL) {
		printf("Hook Failed!\n");
		return -1;
	}
	else
	{
		printf("Hook Success!\n");
		system("pause");
	}
	UnhookWindowsHookEx(g_hHook);
	printf("UnHook");

}