#include "TXLib.h"
#include "lib\\menu.cpp"

int main()
{
    txCreateWindow (900, 900);
    BUTTON buttons[4];
    buttons[0] = {"sdfsdf",  10, 225, false, {}};
    buttons[1] = {"uhuhli", 225, 440, false, {}};
    buttons[2] = {"dtudud", 440, 665, false, {}};
    buttons[3] = {"aseyer", 665, 900, false, {}};

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColor(TX_BLACK);
        txClear();
        txSetColor (TX_LIGHTBLUE);

        menu_draw(&buttons[0]);
        menu_draw(&buttons[1]);
        menu_draw(&buttons[2]);
        menu_draw(&buttons[3]);
        menu_focus(&buttons[0]);
        menu_focus(&buttons[1]);
        menu_focus(&buttons[2]);
        menu_focus(&buttons[3]);

        txSleep(5);
    }
    return 0;
    }





