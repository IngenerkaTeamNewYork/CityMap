#include "TXLib.h"
#include "lib\\menu.cpp"
#include "lib\\debug.cpp"
#include "lib\\file.cpp"
#include "lib\\rounding.cpp"
#include "lib\\read.cpp"

int main()
{
    txCreateWindow (X_ICRANA, Y_ICRANA);
    HDC fon = txLoadImage ("Pictures\\fon.bmp");
    HDC arrows = txLoadImage ("Pictures\\arrows.bmp");

    for (int i = 0; i < KOLICHESTVO_KARTINOK_NA_KARTE; i++)
    {
        KART[i] = {NULL, 0, 0, false};
    }
    Button buttons[KOLICHESTVO_KNOPOK_MENU];
    read(buttons);


    int nomer_kartinki = zapolnenie_kartinok(KART);

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();
        draw_fon();
        Arrows (arrows);

        shift ();

        if (txMouseButtons() &2)
        {
            for (int nomer = 0; nomer < nomer_kartinki; nomer++)
            {
                if (KART[nomer].X - X_COORD >= txMouseX() - 15 &&
                    KART[nomer].X - X_COORD <= txMouseX() + 15 &&
                    KART[nomer].Y >= txMouseY() - 15 &&
                    KART[nomer].Y <= txMouseY() + 15)
                {
                  KART[nomer].RISOVAT_KARTINKU = false;
                  KART[nomer].KARTINKA = NULL;
                  //nomer_kartinki = nomer - 1;
                  txSleep (1);
                }
            }
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
            round (&KART[nomer_kartinki], X_COORD + txMouseX(), txMouseY());
            bool many = false;

            for (int p = 0; p < nomer_kartinki; p++)
            {
                if (KART[nomer_kartinki].X == KART[p].X && KART[nomer_kartinki].Y == KART[p].Y
                    && KART[p].RISOVAT_KARTINKU)
                {
                    many = true;
                }
            }

            if (!many)
            {
                KART[nomer_kartinki].RISOVAT_KARTINKU = true;
            }
        }

        debug_function(nomer_kartinki);
        bool pausa = false;
        for (int i = 0; i < KOLICHESTVO_KARTINOK_NA_KARTE; i++)
        {
            if (KART[i].KARTINKA != NULL && KART[i].RISOVAT_KARTINKU)
            {
                txBitBlt (txDC(), KART[i].X - X_COORD, KART[i].Y - Y_COORD, 30, 30, KART[i].KARTINKA, 0, 0);
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
            skritie_munu(&buttons[nomer_knopki]);
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
    saveMassive(KART, nomer_kartinki);

    for (int nomer = 0; nomer < nomer_kartinki; nomer++)
    {
        txDeleteDC (KART[nomer].KARTINKA);
    }

    return 0;
}
