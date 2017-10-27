#include "TXLib.h"
#include "configs.cpp"

const int RASSTOYANIE_MEZHDU_KNOPKAMI = 40;

//Листовой уровень
struct BUTTON2
{
    const char* textbutton;
    int minX;
    int minY;
    bool isPushed;
    HDC pic;
    HDC ikonka;
};

struct BUTTON
{
    const char* textbutton;
    int minX;
    int maxX;
    bool isPushed;
    BUTTON2 knopki[15];
    int kolvo_knopok;
};

void Arrows (HDC arrows)
{
    txBitBlt (txDC(), 0, 0, 908, 49, arrows, 0, 0);
}

 void shift ()
 {
    COLORREF color = txGetPixel(txMouseX(), txMouseY());

    //Стрелка вправо
    if((txMouseButtons() & 1) && (color == RGB(0, 0, 1)) && X_COORD < 3500)
    {
        X_COORD += 900;
        txSleep(1000);
    }

    //Стрелка влево
    if((txMouseButtons() & 1) && (color == RGB(1, 0, 0)) && X_COORD > 0)
    {
        X_COORD -= 900;
        txSleep(1000);
    }
}

void zapolnenie_mosiva1(BUTTON* button)
{
    int y = 25;
    int nomer_elementa = 0;

    button->knopki[nomer_elementa++] =  {"    PrivateHouse",     button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false,
        txLoadImage("Pictures\\Houses\\PrivateHouse.bmp"),     txLoadImage("Icons\\Houses\\PrivateHouse.bmp")};
    button->knopki[nomer_elementa++] =  {"    Five-building",     button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false,
        txLoadImage("Pictures\\Houses\\Five-building.bmp"),    txLoadImage("Icons\\Houses\\Five-building.bmp")};
    button->knopki[nomer_elementa++] =  {"    SkyScraper",     button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false,
        txLoadImage("Pictures\\Houses\\SkyScraper.bmp"),       txLoadImage("Icons\\Houses\\SkyScraper.bmp")};

    button->kolvo_knopok = 3;

}
void zapolnenie_mosiva2(BUTTON* button)
{
    int y = 25;
    button->knopki[0] =  {"    hotel",          button->minX, y = y+RASSTOYANIE_MEZHDU_KNOPKAMI, false, txLoadImage("Pictures\\PublicHouses\\hotel.bmp"), txLoadImage("Icons\\PublicHouses\\hotel.bmp")};
    button->knopki[1] =  {"    pochta",         button->minX, y = y+25, false, txLoadImage("Pictures\\PublicHouses\\pochta.bmp"), txLoadImage("Icons\\PublicHouses\\pochta.bmp")};
    button->knopki[2] =  {"    Pyatyorochka	",  button->minX, y = y+25, false, txLoadImage("Pictures\\PublicHouses\\Pyatyorochka.bmp"), txLoadImage("Icons\\PublicHouses\\Pyatyorochka.bmp")};
    button->knopki[3] =  {"    klinika	",      button->minX, y = y+25, false, txLoadImage("Pictures\\PublicHouses\\klinika.bmp"), txLoadImage("Icons\\PublicHouses\\klinika.bmp")};
    button->knopki[4] =  {"    museum",         button->minX, y = y+25, false, txLoadImage("Pictures\\PublicHouses\\museum.bmp"), txLoadImage("Icons\\PublicHouses\\museum.bmp")};
    button->knopki[5] =  {"    tyurima",        button->minX, y = y+25, false, txLoadImage("Pictures\\PublicHouses\\tyurima.bmp"), txLoadImage("Icons\\PublicHouses\\tyurima.bmp")};

    button->kolvo_knopok = 6;

}

void zapolnenie_mosiva3 (BUTTON* button)
{
    int y = 25;

    button->knopki[0] =  {"    Lenin",          button->minX, y = y+25, false, txLoadImage("Pictures\\Monuments\\Lenin.bmp"), txLoadImage("Icons\\Monuments\\Lenin.bmp")};
    button->knopki[1] =  {"    EiffelTower",    button->minX, y = y+25, false, txLoadImage("Pictures\\Monuments\\EiffelTower.bmp"), txLoadImage("Icons\\Monuments\\EiffelTower.bmp")};
    button->knopki[2] =  {"    StatuyaSvobodi", button->minX, y = y+25, false, txLoadImage("Pictures\\Monuments\\StatuyaSvobodi.bmp"), txLoadImage("Icons\\Monuments\\StatuyaSvobodi.bmp")};

    button->kolvo_knopok = 3;

}

void zapolnenie_mosiva4 (BUTTON* button)
{
    int y = 25;
    button->knopki[0] =  {"    Reka",          button->minX, y = y+25, false, txLoadImage("Pictures\\Roads\\Reka.bmp"), txLoadImage("Icons\\Roads\\Reka.bmp")};
    button->knopki[1] =  {"    Pole",          button->minX, y = y+25, false, txLoadImage("Pictures\\Roads\\Pole.bmp"), txLoadImage("Icons\\Roads\\Pole.bmp")};
    button->knopki[2] =  {"    SosnoviyLes",   button->minX, y = y+25, false, txLoadImage("Pictures\\Roads\\SosnoviyLes.bmp"), txLoadImage("Icons\\Roads\\SosnoviyLes.bmp")};
    button->knopki[3] =  {"    Gora",          button->minX, y = y+25, false, txLoadImage("Pictures\\Roads\\Gora.bmp"), txLoadImage("Icons\\Roads\\Gora.bmp")};
    button->knopki[4] =  {"    Kamni",         button->minX, y = y+25, false, txLoadImage("Pictures\\Roads\\Kamni.bmp"), txLoadImage("Icons\\Roads\\Kamni.bmp")};
    button->knopki[5] =  {"    Railway",       button->minX, y = y+25, false, txLoadImage("Pictures\\Roads\\Railway.bmp"), txLoadImage("Icons\\Roads\\Railway.bmp")};
    button->knopki[6] =  {"    Doroga",        button->minX, y = y+25, false, txLoadImage("Pictures\\Roads\\Doroga.bmp"), txLoadImage("Icons\\Roads\\Doroga.bmp")};



    button->kolvo_knopok = 7;

}


void menu_draw(BUTTON* button)
{
    txSetColor (TX_LIGHTBLUE);
    txSetFillColor (RGB(180,250,250));
    txRectangle (button->minX, 0,  button->maxX, 50);
    txTextOut(button->minX + 50, 25, button->textbutton);
}

void menu_focus(BUTTON* button)
{
    txSetColor (TX_BLUE);
    txSetFillColor (RGB(180,250,250));

    //Нажали на кнопку
    if ((txMouseY() > 0  && txMouseY() < 50)
     && (txMouseX () > button->minX && txMouseX () < button->maxX ))
    {
        button->isPushed = true;
    }
    //Фокус потерян
    else if ((txMouseX () < button->minX || txMouseX () > button->maxX || txMouseY() < 0  || txMouseY() > 400))
    {
        button->isPushed = false;
    }

    if (button->isPushed)
    {

        txRectangle (button->minX, 50, button->maxX, 400);
        for (int i = 0; i < button->kolvo_knopok; i++)
        {
            txTextOut(button->knopki[i].minX, button->knopki[i].minY, button->knopki[i].textbutton);
        }
        //Фокус на нужной подкнопке
        for (int i = 0; i < button->kolvo_knopok; i++)
        {
            if (
                txMouseY() > button->knopki[i].minY  &&
                txMouseY() < button->knopki[i].minY + 30 &&
                txMouseX () < button->maxX &&
                txMouseX () > button->minX)
            {
                txBitBlt (txDC(), txMouseX(), txMouseY(), txMouseX() + 150, txMouseY() + 200, button->knopki[i].pic, 0, 0);
            }
        }
    }
}


void appearance (BUTTON* button)
{
    for (int i = 0; i < button->kolvo_knopok; i++)
    {

        if (txMouseY() > button->knopki[i].minY  &&
            txMouseY() < button->knopki[i].minY + 30 &&
            txMouseX () < button->maxX &&
            txMouseX () > button->minX &&
            txMouseButtons() & 1 && button->isPushed)
        {
            KARTINKA = button->knopki[i].ikonka;
            RISOVAT_KARTINKU = false;
        }
    }
}

void map1 (HDC PrivateHouse, HDC skyscraper)
{
   txBitBlt (txDC(), 200, 200, 30, 30, skyscraper);
   txBitBlt (txDC(), 200, 400, 30, 30, PrivateHouse);
   txBitBlt (txDC(), 400, 200, 30, 30, skyscraper);
   txBitBlt (txDC(), 300, 200, 30, 30, PrivateHouse);
   txBitBlt (txDC(), 200, 300, 30, 30, skyscraper);
   txBitBlt (txDC(), 300, 300, 30, 30, PrivateHouse);
   txBitBlt (txDC(), 600, 200, 30, 30, skyscraper);
   txBitBlt (txDC(), 700, 300, 30, 30, PrivateHouse);
   txBitBlt (txDC(), 800, 200, 30, 30, skyscraper);
   txBitBlt (txDC(), 400, 500, 30, 30, PrivateHouse);
   txBitBlt (txDC(), 500, 600, 30, 30, skyscraper);
   txBitBlt (txDC(), 600, 700, 30, 30, PrivateHouse);
}
