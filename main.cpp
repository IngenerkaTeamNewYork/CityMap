#include "TXLib.h"
#include "lib\\menu.cpp"

int main()
{
    txCreateWindow (900, 900);
    HDC  fon = txLoadImage ("panorama.bmp");


    BUTTON buttons[4];

    buttons[0] = {"House",  10, 225, false, {}};
    buttons[1] = {"Public houses", 225, 440, false, {}};
    buttons[2] = {"Sightseens", 440, 665, false, {}};
    buttons[3] = {"Landscape", 665, 900, false, {}};

    zapolnenie_mosiva1(&buttons[0]);
    zapolnenie_mosiva2(&buttons[1]);
    zapolnenie_mosiva3(&buttons[2]);
    zapolnenie_mosiva4(&buttons[3]);

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();
        txBitBlt (txDC(), 0, 0, 900, 900, fon, X_COORD, 0);
        Arrows ();

        shift ();

        txSetColor (TX_LIGHTBLUE);

        for (int nomer_knopki = 0; nomer_knopki < 4; nomer_knopki++)
        {
            menu_focus(&buttons[nomer_knopki]);
            menu_draw(&buttons[nomer_knopki]);
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
        }
    }
        txDeleteDC (&fon);

    return 0;
}
