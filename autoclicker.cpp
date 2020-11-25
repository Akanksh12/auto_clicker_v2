#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    cout << "press numpad 0 for cursor postion" << endl;
    cout << "press numpad 1 for clicking" << endl;
    cout << "press numpad 2 to exit02" << endl;

    while (true)
    {
        if (GetAsyncKeyState(VK_NUMPAD0))
        {
            POINT p;
            GetCursorPos(&p);
            cout << "x pos: " << p.x << "y pos: " << p.y << endl;
            Sleep(1000);
        }

        if (GetAsyncKeyState(VK_NUMPAD1))
        {
            INPUT iNPUT = {0};
            iNPUT.type = INPUT_MOUSE;
            iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            SendInput(1, &iNPUT, sizeof(iNPUT));
            ZeroMemory(&iNPUT, sizeof(iNPUT));
            iNPUT.type = INPUT_MOUSE;
            iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &iNPUT, sizeof(iNPUT));
        }

        if (GetAsyncKeyState(VK_NUMPAD2))
        {
            return 0;
        }
    }
}