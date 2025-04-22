#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

int main()
{
    DWORD pid = 0;

    HWND hwnd = FindWindowA(nullptr, "Counter-Strike 2");
    GetWindowThreadProcessId(hwnd, &pid);

    HANDLE hProc = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, pid);

    int vida = 0;

    uintptr_t enderecoVida = 0x3301;//SUA OFFSET AQUI PAE

    if (ReadProcessMemory(hProc, (LPCVOID)enderecoVida, &vida, sizeof(vida), nullptr))

    std::cout << "Vida: " << vida << std::endl;
    else
    std::cout << "error" << std::endl;

    system("pause");

    int NovaVida = 111;

    if (WriteProcessMemory(hProc, (LPVOID)enderecoVida , &NovaVida, sizeof(NovaVida), nullptr));

 
    CloseHandle(hProc);
}