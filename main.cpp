#include "TXLib.h"
#include "lib\\menu.cpp"

int main()
{
    txCreateWindow (X_ICRANA, Y_ICRANA);
    HDC  fon = txLoadImage ("Pictures\\fon.bmp");
    HDC  arrows = txLoadImage ("Pictures\\arrows.bmp");
    HDC  PrivateHouse = txLoadImage ("Icons\\Houses\\PrivateHouse.bmp");
    HDC  skyscraper = txLoadImage ("Icons\\Houses\\skyscraper.bmp");

    for (int i = 0; i < w; i++)
    {
        KART[i] = {nullptr, 0, 0, false};
    }
    BUTTON buttons[w];

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
        txBitBlt (txDC(), 0, VISOTA_MENU, txGetExtentX(), txGetExtentY(), fon, X_COORD, 0);
        Arrows (arrows);
        map1 (PrivateHouse, skyscraper);

        shift ();
        appearance (&buttons[0]);
        appearance (&buttons[1]);
        appearance (&buttons[2]);
        appearance (&buttons[3]);

        txSetColor (TX_LIGHTBLUE);

        for (int nomer_knopki = 0; nomer_knopki < w; nomer_knopki++)
        {
            menu_focus(&buttons[nomer_knopki]);
            menu_draw(&buttons[nomer_knopki]);
        }

        bool knopka_najata = false;
        for (int nomer_knopki = 0; nomer_knopki < w; nomer_knopki++)
        {
            if (buttons[nomer_knopki].isPushed)
            {
                knopka_najata = true;
            }
        }

        if (txMouseY() > VISOTA_MENU && !KART[0].RISOVAT_KARTINKU && !knopka_najata &&
            txMouseButtons() & 1)
        {
            KART[0].X = txMouseX();
            KART[0].Y = txMouseY();
            KART[0].RISOVAT_KARTINKU = true;
        }

        if (KARTINKA != nullptr && KART[0].RISOVAT_KARTINKU)
        {
            txBitBlt (txDC(), KART[0].X, KART[0].Y, X_ICRANA, Y_ICRANA, KART[0].KARTINKA, 0, 0);
        }

        if (DEBUG_MODE)
        {
            if (KART[0].RISOVAT_KARTINKU)
                txTextOut(450, 500, "RISOVAT");
            if (KART[0].KARTINKA != nullptr)
                txTextOut(450, 600, "KARTINKA");
        }
        txSleep(10);
        txEnd();
    }

    for (int nomer_zagolovka = 0;
        nomer_zagolovka < w;
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
    txDeleteDC (&PrivateHouse);
    txDeleteDC (&skyscraper);

    return 0;
}
