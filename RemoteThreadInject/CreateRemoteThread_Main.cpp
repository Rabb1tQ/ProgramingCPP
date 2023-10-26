// CreateRemoteThread_Test.cpp : 定义控制台应用程序的入口点。
//

#include "include/stdafx.h"
#include "include/InjectDll.h"
#include "include/AdjustTokenPrivileges.h"
#include <iostream>
using namespace std;
constexpr int CHAR_LENGTH = 1000;

char* strConcat(char* str1,char* str2){

    // 计算拼接后的字符串的长度
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t totalLength = len1 + len2 + 1; // 加1是为了存储字符串结束符 '\0'

    // 分配足够的内存来存储拼接后的字符串
    char* result = new char[totalLength];

    // 使用 strcat 函数将两个字符串拼接到 result 中
    strcpy(result, str1);
    strcat(result, str2);

    return result;
}
int main(int argc, _TCHAR* argv[])
{
    char  buf[CHAR_LENGTH];
    GetCurrentDirectory(1000, buf);
    char  dllPath[CHAR_LENGTH]="/resource/libuntitled.dll";
    char* directory=strConcat(buf,dllPath);
    printf(buf);
	// 提升当前进程令牌权限
	EnbalePrivileges(::GetCurrentProcess(), SE_DEBUG_NAME);
	// 远线程注入 DLL
#ifndef _WIN64
	BOOL bRet = CreateRemoteThreadInjectDll(904, "resource/libuntitled.dll");
#else 
	BOOL bRet = CreateRemoteThreadInjectDll(15624, directory);
#endif
	
	if (FALSE == bRet)
	{
		printf("Inject Dll Error.\n");
	}
	printf("Inject Dll OK.\n");
	system("pause");
	return 0;
}

