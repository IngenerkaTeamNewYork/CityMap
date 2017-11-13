#include "TXLib.h"
#include "lib\\menu.cpp"
#include "lib\\debug.cpp"

int main()
{
    txCreateWindow (X_ICRANA, Y_ICRANA);
    HDC  fon = txLoadImage ("Pictures\\fon.bmp");
    HDC  arrows = txLoadImage ("Pictures\\arrows.bmp");

    for (int i = 0; i < KOLICHESTVO_KARTINOK_NA_KARTE; i++)
    {
        KART[i] = {NULL, 0, 0, false};
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

    int nomer_kartinki = zapolnenie_kartinok(KART);

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();
        txBitBlt (txDC(), 0, VISOTA_MENU, txGetExtentX(), txGetExtentY(), fon, X_COORD, 0);
        Arrows (arrows);

        shift ();

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
            KART[nomer_kartinki].X = round((15+txMouseX())/30)*30;
            KART[nomer_kartinki].Y = round((15+txMouseY())/30)*30 - 10;
        }

        debug_function(nomer_kartinki);
        bool pausa = false;
        for (int i = 0; i < KOLICHESTVO_KARTINOK_NA_KARTE; i++)
        {
            if (KART[i].KARTINKA != NULL && KART[i].RISOVAT_KARTINKU)
            {
                txBitBlt (txDC(), KART[i].X, KART[i].Y, 30, 30, KART[i].KARTINKA, 0, 0);
                nomer_kartinki = i + 1;
                pausa = true;
            }
        }

        appearance (&buttons[0], nomer_kartinki);
        appearance (&buttons[1], nomer_kartinki);
        appearance (&buttons[2], nomer_kartinki);
        appearance (&buttons[3], nomer_kartinki);

        for (int nomer_knopki = 0; nomer_knopki < KOLICHESTVO_KNOPOK_MENU; nomer_knopki++)
        {
            menu_focus(&buttons[nomer_knopki]);
            menu_draw(&buttons[nomer_knopki]);
        }

        if (pausa)
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

    return 0;
}
