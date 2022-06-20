#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    HINSTANCE LibHandle;
    char dllbuf[11] = "user32.dll";
    LibHandle = LoadLibrary(dllbuf);
    asm
    {
        sub sp,0x440
        xor ebx,ebx
        push ebx
        push 0x74736577
        push 0x6c696166
        mov eax,esp
        push ebx
        push eax
        push eax
        push ebx
        mov eax,0x75d0a490
        call eax
    }
    return 0;
}