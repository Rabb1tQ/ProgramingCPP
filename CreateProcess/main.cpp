#include <iostream>
#include <Windows.h>

void WinExecFunc(){
    int result = WinExec("notepad.exe WinExec", SW_NORMAL);
    if (result > 31) {
        // WinExec 返回大于 31 表示成功启动
        printf("Notepad started successfully.\n");
    } else {
        printf("Failed to start Notepad.\n");
    }
}
void ShellExecFunc(){
    HINSTANCE hInst = ShellExecute(NULL, "open", "notepad.exe", "ShellExecute", NULL, SW_SHOWNORMAL);

    if ((int)(intptr_t)hInst > 32) {
        printf("Notepad started successfully.\n");
    } else {
        printf("Failed to start Notepad. Error code: %d\n", (int)(intptr_t)hInst);
    }
}
void CreateProcessFunc(){
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

    // 启动记事本
    if (CreateProcess(
            NULL,                 // 应用程序名称，可以设为 NULL
            "notepad.exe CreateProcess",        // 命令行，表示要启动记事本
            NULL,                 // 进程安全属性，可以设为 NULL
            NULL,                 // 线程安全属性，可以设为 NULL
            FALSE,                // 不继承句柄
            0,                    // 标志，通常为 0
            NULL,                 // 环境变量，可以设为 NULL
            NULL,                 // 当前工作目录，可以设为 NULL
            &si,                  // STARTUPINFO 结构
            &pi                   // PROCESS_INFORMATION 结构
    )) {
        printf("Notepad started successfully.\n");
        CloseHandle(pi.hProcess); // 关闭进程句柄
        CloseHandle(pi.hThread);  // 关闭线程句柄
    } else {
        printf("Failed to start Notepad. Error code: %d\n", GetLastError());
    }
}
void systemFunc(){
    int result = system("notepad system");

    if (result == 0) {
        printf("Command executed successfully.\n");
    } else {
        printf("Command failed to execute.\n");
    }

}
void popenFunc(){
    FILE *fp;
    char buffer[128];
    // 打开管道并执行命令
    fp = popen("notepad popen", "r");
    if (fp == NULL) {
        printf("Failed to execute command.\n");
        exit(0);
    }
    // 读取子进程的输出
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("Output: %s", buffer);
    }
    // 关闭管道
    pclose(fp);
}
int main() {
    WinExecFunc();
    ShellExecFunc();
    CreateProcessFunc();
    systemFunc();
    popenFunc();
}
