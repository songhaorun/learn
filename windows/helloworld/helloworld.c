#include <Windows.h>
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR IpCmdLine,int nCmdShow){
    //弹出一个窗口
    MessageBox(NULL,"Hello World","第一个Win32窗口程序",MB_OK);
    return 0;
}