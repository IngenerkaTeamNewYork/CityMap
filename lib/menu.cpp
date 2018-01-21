#pragma once

#include "TXLib.h"
#include "configs.cpp"
#include "rounding.cpp"
#include "cartinca.cpp"
#include "file.cpp"

//Ëèñòîâîé óðîâåíü
struct Button2
{
    const char* textbutton;
    int minX;
    int minY;
    bool isPushed;
    HDC pic;
    HDC ikonka;
    const char* address;
};

struct Button
{
    const char* textbutton;
    int minX;
    int maxX;
    bool isPushed;
    Button2 knopki[15];
    int kolvo_knopok;
};

void Arrows (HDC arrows)
{
    txBitBlt (txDC(), 0, 0, 100, VISOTA_MENU - 1, arrows, 0, 0);
    txBitBlt (txDC(), X_ICRANA + 0, 0, 0, VISOTA_MENU - 1, arrows, 129, 0);
}

void draw_fon()
{
    txSetColor(TX_WHITE);
    txSetFillColor(TX_WHITE);
    txRectangle(0, 0, MAP_SIZE_X, MAP_SIZE_Y);
    txSetColor (TX_BLACK);

    for (int y = 20; y <= MAP_SIZE_Y; y = y + 30)
    {
        txLine   (0, y, MAP_SIZE_X, y);
    }

    for (int x = 0; x <= MAP_SIZE_X; x = x + 30)
    {
        txLine   (x, 0, x, MAP_SIZE_Y);
    }
}

void shift ()
{
    COLORREF color = txGetPixel(txMouseX(), txMouseY());

    //Ñòðåëêà âïðàâî
    if((txMouseButtons() & 1) && (color == RGB(0, 0, 1)) && X_COORD < 3500)
    {
        X_COORD += roundX(X_ICRANA);
        txSleep(50);
    }

    //Ñòðåëêà âëåâî
    if((txMouseButtons() & 1) && (color == RGB(1, 0, 0)) && X_COORD > 0)
    {
        X_COORD -= roundX(X_ICRANA);
        txSleep(50);
    }

    if((txMouseButtons() & 1) && (color == RGB(0, 1, 0)) && Y_COORD < 3500)
    {
        Y_COORD += roundX(Y_ICRANA);
        txSleep(50);
    }

    if((txMouseButtons() & 1) && (color == RGB(0, 2, 0)) && Y_COORD > 3500)
    {
        Y_COORD -= roundX(Y_ICRANA);
        txSleep(50);
    }
}

void zapolnenie_mosiva(Button* button)
{
    for (int kolvo_eltov = 0; kolvo_eltov < 10; kolvo_eltov++)
    {
        button->knopki[kolvo_eltov].minX = -100 ;
    }
}

int kolvo_eltov (Button* button)
{
    int kolich = 0;
    for (int kolvo_eltov = 0; kolvo_eltov <10; kolvo_eltov++)
    {
        if (button->knopki[kolvo_eltov].minX != -100)
        {
            kolich = kolich + 1;
        }
    }

    return kolich;
}

void menu_draw(Button* button)
{
    txSetColor (TX_BLACK);
    txSetFillColor (RGB(234,237,233));
    txRectangle (button->minX, 0,  button->maxX, VISOTA_MENU);
    txSelectFont("Arial", 20);
    txTextOut(button->minX + VISOTA_MENU, VISOTA_MENU / 2, button->textbutton);
}

void menu_focus(Button* button)
{
    txSetColor (TX_BLACK);
    txSetFillColor (RGB(234,237,233));

    //Íàæàëè íà êíîïêó
    if ((txMouseY() > 0  && txMouseY() < VISOTA_MENU)
     && (txMouseX () > button->minX && txMouseX () < button->maxX ))
    {
        button->isPushed = true;
    }
    //Ôîêóñ ïîòåðÿí
    else if ((txMouseX () < button->minX || txMouseX () > button->maxX || txMouseY() < 0  || txMouseY() > NIZHINIY_Y))
    {
        button->isPushed = false;
    }

    if (button->isPushed)
    {

        txRectangle (button->minX, VISOTA_MENU, button->maxX, NIZHINIY_Y);
        for (int i = 0; i < button->kolvo_knopok; i++)
        {
            txTextOut(button->knopki[i].minX, button->knopki[i].minY, button->knopki[i].textbutton);
        }
        //Ôîêóñ íà íóæíîé ïîäêíîïêå
        for (int i = 0; i < button->kolvo_knopok; i++)
        {
            if (
                txMouseY() > button->knopki[i].minY  &&
                txMouseY() < button->knopki[i].minY + VISOTA_MENU &&
                txMouseX () < button->maxX &&
                txMouseX () > button->minX)
            {
                txBitBlt (txDC(), txMouseX(), txMouseY(), txMouseX() + M_X_PLUS_COORDINATA, txMouseY() + M_Y_PLUS_COORDINATA, button->knopki[i].pic, 0, 0);
            }
        }
    }
}

void appearance (Button* button, int nomer_kartinki)
{
    for (int nom_but = 0; nom_but < button->kolvo_knopok; nom_but++)
    {
        if (txMouseY() > button->knopki[nom_but].minY  &&
            txMouseY() < button->knopki[nom_but].minY + VISOTA_MENU &&
            txMouseX () < button->maxX &&
            txMouseX () > button->minX &&
            txMouseButtons() & 1 && button->isPushed)
        {
             for (int nom_kart = nomer_kartinki; nom_kart < KOLICHESTVO_KARTINOK_NA_KARTE; nom_kart++)
             {
                KART[nom_kart].KARTINKA = button->knopki[nom_but].ikonka;
                KART[nom_kart].adress = button->knopki[nom_but].address;
                KART[nom_kart].RISOVAT_KARTINKU = false;
            }
        }
    }
}

int zapolnenie_kartinok(CartincaNaKarte* KART1)
{
    int kolvo = massive(KART1);

    for (int nomer = 0; nomer < kolvo; nomer++)
    {
        round(&KART1[nomer], KART1[nomer].X, KART1[nomer].Y);
    }

    return kolvo;
}
