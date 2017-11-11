#pragma once

#include "TXLib.h"
#include "configs.cpp"
#include "cartinca.cpp"

//Листовой уровень
struct Button2
{
    const char* textbutton;
    int minX;
    int minY;
    bool isPushed;
    HDC pic;
    HDC ikonka;
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
    txBitBlt (txDC(), 0, 0, X_ICRANA, VISOTA_MENU - 1, arrows, 0, 0);
}

void shift ()
{
    COLORREF color = txGetPixel(txMouseX(), txMouseY());

    //Стрелка вправо
    if((txMouseButtons() & 1) && (color == RGB(0, 0, 1)) && X_COORD < 3500)
    {
        X_COORD += X_ICRANA;
        txSleep(1000);
    }

    //Стрелка влево
    if((txMouseButtons() & 1) && (color == RGB(1, 0, 0)) && X_COORD > 0)
    {
        X_COORD -= X_ICRANA;
        txSleep(1000);
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

void zapolnenie_mosiva1(Button* button)
{
    int y = VISOTA_MENU / 2;
    int nomer_elementa = 0;
    zapolnenie_mosiva(button);

    button->knopki[nomer_elementa++] =  {"PrivateHouse",     button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\Houses\\PrivateHouse.bmp"),     txLoadImage("Icons\\Houses\\PrivateHouse.bmp")};
    button->knopki[nomer_elementa++] =  {"Five-building",     button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\Houses\\Five-building.bmp"),    txLoadImage("Icons\\Houses\\Five-building.bmp")};
    button->knopki[nomer_elementa++] =  {"SkyScraper",     button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\Houses\\SkyScraper.bmp"),       txLoadImage("Icons\\Houses\\SkyScraper.bmp")};

    button->kolvo_knopok = kolvo_eltov (button);
}

void zapolnenie_mosiva2(Button* button)
{
    int y = 25;
    zapolnenie_mosiva(button);

    button->knopki[0] =  {"hotel",          button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\PublicHouses\\hotel.bmp"), txLoadImage("Icons\\PublicHouses\\hotel.bmp")};
    button->knopki[1] =  {"pochta",         button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\PublicHouses\\pochta.bmp"), txLoadImage("Icons\\PublicHouses\\pochta.bmp")};
    button->knopki[2] =  {"Pyatyorochka",   button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\PublicHouses\\Pyatyorochka.bmp"), txLoadImage("Icons\\PublicHouses\\Pyatyorochka.bmp")};
    button->knopki[3] =  {"klinika",        button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\PublicHouses\\klinika.bmp"), txLoadImage("Icons\\PublicHouses\\klinika.bmp")};
    button->knopki[4] =  {"museum",         button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\PublicHouses\\museum.bmp"), txLoadImage("Icons\\PublicHouses\\museum.bmp")};
    button->knopki[5] =  {"tyurima",        button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\PublicHouses\\tyurima.bmp"), txLoadImage("Icons\\PublicHouses\\tyurima.bmp")};

    button->kolvo_knopok = kolvo_eltov (button);
}

void zapolnenie_mosiva3 (Button* button)
{
    int y = 25;
    zapolnenie_mosiva(button);

    button->knopki[0] =  {"Lenin",          button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\Monuments\\Lenin.bmp"), txLoadImage("Icons\\Monuments\\Lenin.bmp")};
    button->knopki[1] =  {"EiffelTower",    button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\Monuments\\EiffelTower.bmp"), txLoadImage("Icons\\Monuments\\EiffelTower.bmp")};
    button->knopki[2] =  {"StatuyaSvobodi", button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\Monuments\\StatuyaSvobodi.bmp"), txLoadImage("Icons\\Monuments\\StatuyaSvobodi.bmp")};

    button->kolvo_knopok = kolvo_eltov (button);
}

void zapolnenie_mosiva4 (Button* button)
{
    int y = 25;
    zapolnenie_mosiva(button);

    button->knopki[0] =  {"Reka",          button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\Roads\\Reka.bmp"), txLoadImage("Icons\\Roads\\Reka.bmp")};
    button->knopki[1] =  {"Pole",          button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\Roads\\Pole.bmp"), txLoadImage("Icons\\Roads\\Pole.bmp")};
    button->knopki[2] =  {"SosnoviyLes",   button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\Roads\\SosnoviyLes.bmp"), txLoadImage("Icons\\Roads\\SosnoviyLes.bmp")};
    button->knopki[3] =  {"Gora",          button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\Roads\\Gora.bmp"), txLoadImage("Icons\\Roads\\Gora.bmp")};
    button->knopki[4] =  {"Kamni",         button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\Roads\\Kamni.bmp"), txLoadImage("Icons\\Roads\\Kamni.bmp")};
    button->knopki[5] =  {"Railway",       button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\Roads\\Railway.bmp"), txLoadImage("Icons\\Roads\\Railway.bmp")};
    button->knopki[6] =  {"Doroga",        button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\Roads\\Doroga.bmp"), txLoadImage("Icons\\Roads\\Doroga.bmp")};

    button->kolvo_knopok = kolvo_eltov (button);
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

    //Нажали на кнопку
    if ((txMouseY() > 0  && txMouseY() < VISOTA_MENU)
     && (txMouseX () > button->minX && txMouseX () < button->maxX ))
    {
        button->isPushed = true;
    }
    //Фокус потерян
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
        //Фокус на нужной подкнопке
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
    for (int i = 0; i < button->kolvo_knopok; i++)
    {


        /*if (txMouseY() >= 0  &&
            txMouseY() <= 100 &&
            txMouseX () <= 200 &&
            txMouseX () >= 400 &&
            txMouseButtons() & 1) */

        if (txMouseY() > button->knopki[i].minY  &&
            txMouseY() < button->knopki[i].minY + VISOTA_MENU &&
            txMouseX () < button->maxX &&
            txMouseX () > button->minX &&
            txMouseButtons() & 1 && button->isPushed)
        {
            KART[nomer_kartinki].KARTINKA = button->knopki[i].ikonka;
            KART[nomer_kartinki].RISOVAT_KARTINKU = false;

        }
    }
}

int zapolnenie_kartinok(CartincaNaKarte* KART1)
{
    HDC  PrivateHouse = txLoadImage ("Icons\\Houses\\PrivateHouse.bmp");
    HDC  skyscraper = txLoadImage ("Icons\\Houses\\skyscraper.bmp");
    int nomer = 0;
    KART1[0] = {skyscraper,     200, 200, true};
    KART1[1] = {PrivateHouse,   200, 400, true};
    KART1[2] = {skyscraper,     400, 200, true};
    KART1[3] = {PrivateHouse,   300, 200, true};
    KART1[4] = {skyscraper,     200, 300, true};
    KART1[5] = {PrivateHouse,   300, 300, true};
    KART1[6] = {skyscraper,     600, 200, true};
    KART1[7] = {PrivateHouse,   700, 300, true};
    KART1[8] = {skyscraper,     800, 200, true};
    KART1[9] = {PrivateHouse,   400, 500, true};
    KART1[10] = {skyscraper,    500, 600, true};
    KART1[11] = {skyscraper,    600, 700, true};

    txDeleteDC(PrivateHouse);
    txDeleteDC(skyscraper);

    return 12;
}

void map1 (HDC PrivateHouse, HDC skyscraper)
{
    CartincaNaKarte KART1[12];
    KART1[0] = {skyscraper,     200, 200, true};
    KART1[1] = {PrivateHouse,   200, 400, true};
    KART1[2] = {skyscraper,     400, 200, true};
    KART1[3] = {PrivateHouse,   300, 200, true};
    KART1[4] = {skyscraper,     200, 300, true};
    KART1[5] = {PrivateHouse,   300, 300, true};
    KART1[6] = {skyscraper,     600, 200, true};
    KART1[7] = {PrivateHouse,   700, 300, true};
    KART1[8] = {skyscraper,     800, 200, true};
    KART1[9] = {PrivateHouse,   400, 500, true};
    KART1[10] = {skyscraper,    500, 600, true};
    KART1[11] = {skyscraper,    600, 700, true};

    for (int nomer = 0; nomer < 13; nomer++)
    {
        KART1[nomer].X = round((15+KART1[nomer].X)/30)*30;
        KART1[nomer].Y = round((15+KART1[nomer].Y)/30)*30 - 10;
        txBitBlt (txDC(), KART1[nomer].X, KART1[nomer].Y, 30, 30, KART1[nomer].KARTINKA);
    }
}
