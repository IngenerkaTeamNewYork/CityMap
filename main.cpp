#include "TXLib.h"
#include "lib\\menu.cpp"

int main()
{
    txCreateWindow (900, 900);
    HDC  fon = txLoadImage ("Pictures\\fon.bmp");
    HDC  arrows = txLoadImage ("Pictures\\arrows.bmp");


    BUTTON buttons[4];

    buttons[0] = {"House",  50, 250, false, {}};
    buttons[1] = {"Public houses", 250, 450, false, {}};
    buttons[2] = {"Sightseens", 450, 650, false, {}};
    buttons[3] = {"Landscape", 650, 850, false, {}};

    zapolnenie_mosiva1(&buttons[0]);
    zapolnenie_mosiva2(&buttons[1]);
    zapolnenie_mosiva3(&buttons[2]);
    zapolnenie_mosiva4(&buttons[3]);

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();
        txBitBlt (txDC(), 0, 50, 900, 900, fon, X_COORD, 0);
        Arrows (arrows);

        shift ();
        appearance (&buttons[0]);
        appearance (&buttons[1]);
        appearance (&buttons[2]);
        appearance (&buttons[3]);

        txSetColor (TX_LIGHTBLUE);

        for (int nomer_knopki = 0; nomer_knopki < 4; nomer_knopki++)
        {
            menu_focus(&buttons[nomer_knopki]);
            menu_draw(&buttons[nomer_knopki]);
        }

        if (KARTINKA != nullptr)
        {
            txBitBlt (txDC(), 600, 500, 900, 900, KARTINKA, 0, 0);
        }

        txSleep(10);
        txEnd();
    }

    for (int nomer_zagolovka = 0;
        nomer_zagolovka < 4;
        nomer_zagolovka++)
    {
        for (int nomer_knopki = 0;
            nomer_knopki < buttons[nomer_zagolovka].kolvo_knopok;
            nomer_knopki++)
        {
           txDeleteDC (buttons[nomer_zagolovka].knopki[nomer_knopki].pic);
           txDeleteDC (buttons[nomer_zagolovka].knopki[nomer_knopki].ikonka);
        }
    }

    txDeleteDC (&fon);
    txDeleteDC (&arrows);

    return 0;
}
