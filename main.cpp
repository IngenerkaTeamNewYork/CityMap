#include "TXLib.h"
#include "lib\\menu.cpp"

int main()
{
    txCreateWindow (X_ICRANA, Y_ICRANA);
    HDC  fon = txLoadImage ("Pictures\\fon.bmp");
    HDC  arrows = txLoadImage ("Pictures\\arrows.bmp");
    HDC  PrivateHouse = txLoadImage ("Icons\\Houses\\PrivateHouse.bmp");
    HDC  skyscraper = txLoadImage ("Icons\\Houses\\skyscraper.bmp");

    for (int i = 0; i < KOLICHESTVO_KARTINOK_NA_KARTE; i++)
    {
        KART[i] = {nullptr, 0, 0, false};
    }
    Button buttons[KOLICHESTVO_KNOPOK_MENU];

    buttons[0] = {"House",  50, 250, false, {}};
    buttons[1] = {"Public houses", 250, 450, false, {}};
    buttons[2] = {"Sightseens", 450, 650, false, {}};
    buttons[3] = {"Landscape", 650, 850, false, {}};

    zapolnenie_mosiva1(&buttons[0]);
    zapolnenie_mosiva2(&buttons[1]);
    zapolnenie_mosiva3(&buttons[2]);
    zapolnenie_mosiva4(&buttons[3]);

    int nomer_kartinki = 0;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();
        txBitBlt (txDC(), 0, VISOTA_MENU, txGetExtentX(), txGetExtentY(), fon, X_COORD, 0);
        Arrows (arrows);
        map1 (PrivateHouse, skyscraper);

        shift ();
        appearance (&buttons[0], nomer_kartinki);
        appearance (&buttons[1], nomer_kartinki);
        appearance (&buttons[2], nomer_kartinki);
        appearance (&buttons[3], nomer_kartinki);

        txSetColor (TX_LIGHTBLUE);

        for (int nomer_knopki = 0; nomer_knopki < KOLICHESTVO_KNOPOK_MENU; nomer_knopki++)
        {
            menu_focus(&buttons[nomer_knopki]);
            menu_draw(&buttons[nomer_knopki]);
        }

        bool knopka_najata = false;
        for (int nomer_knopki = 0; nomer_knopki < KOLICHESTVO_KNOPOK_MENU; nomer_knopki++)
        {
            if (buttons[nomer_knopki].isPushed)
            {
                knopka_najata = true;
            }
        }

        if (txMouseY() > VISOTA_MENU && !KART[nomer_kartinki].RISOVAT_KARTINKU && !knopka_najata &&
            txMouseButtons() & 1)
        {
            KART[nomer_kartinki].X = txMouseX();
            KART[nomer_kartinki].Y = txMouseY();
            KART[nomer_kartinki].RISOVAT_KARTINKU = true;
            //nomer_kartinki++;
            //txSleep(100);
        }

        bool b = false;
        for (int i = 0; i < KOLICHESTVO_KARTINOK_NA_KARTE; i++)
        {
            if (KART[i].KARTINKA != nullptr && KART[i].RISOVAT_KARTINKU)
            {
                txBitBlt (txDC(), KART[i].X, KART[i].Y, X_ICRANA, Y_ICRANA, KART[i].KARTINKA, 0, 0);

                nomer_kartinki = i + 1;
                b = true;
            }
        }
        if (DEBUG_MODE)
        {
            if (KART[nomer_kartinki].RISOVAT_KARTINKU)
                txTextOut(450, 500, "RISOVAT");
            if (KART[nomer_kartinki].KARTINKA != nullptr)
                txTextOut(450, 600, "KARTINKA");
            if (nomer_kartinki == 0)
                txTextOut(450, 550, "0");
            if (nomer_kartinki == 1)
                txTextOut(450, 550, "1");
            if (nomer_kartinki == 2)
                txTextOut(450, 550, "2");
                if (nomer_kartinki == 3)
                txTextOut(450, 550, "3");
                if (nomer_kartinki == 4)
                txTextOut(450, 550, "4");
                if (nomer_kartinki == 5)
                txTextOut(450, 550, "5");
                if (nomer_kartinki == 6)
                txTextOut(450, 550, "6");
                if (nomer_kartinki == 7)
                txTextOut(450, 550, "7");
        }
        if (b)
        {
            txSleep(100);
        }
        txSleep(10);
        txEnd();
    }

    for (int nomer_zagolovka = 0;
        nomer_zagolovka < KOLICHESTVO_KNOPOK_MENU;
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
