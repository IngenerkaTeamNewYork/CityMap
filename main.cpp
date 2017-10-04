#include "TXLib.h"
#include "lib\\menu.cpp"

void menu_focus1(BUTTON* button);

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
     }


        //x > 100 x < 300
        //y > 200 y < 500

        //x > 300 x < 500
        //y > 200 y < 500

        txSleep(5);

    return 0;
}

void menu_focus1(BUTTON* button)
{
    if ((txMouseY() > 200  && txMouseY() < 500)
     && (txMouseX () > button->minX && txMouseX () < button->maxX))
    {
        button->isPushed = true;
    }
    else if ((txMouseX () < button->minX || txMouseX () > button->maxX))
    {
        button->isPushed = false;
    }

    if (button->isPushed)
    {
       HDC Cottage;
    Cottage = txLoadImage ("C:\\Users\\Student\\Desktop\\CityMap-master\\Pictures\\Houses\\Cottage2.bmp");
    txBitBlt (txDC(), 0, 0, 200, 500, Cottage, 0, 0);
    }
}





