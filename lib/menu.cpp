#include "TXLib.h"
#include "configs.cpp"

//Листовой уровень
struct BUTTON2
{
    const char* textbutton;
    int minX;
    int minY;
    bool isPushed;
    HDC pic;
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
    if((txMouseButtons() & 1) && (color == RGB(0, 0, 0)) && X_COORD < 3500)
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
    button->knopki[0] =  {"KrasivyiDom",    button->minX, 75, false, txLoadImage("Houses\\KrasivyiDom.bmp")};
    button->knopki[1] =  {"Cottage",        button->minX, 100, false, txLoadImage("Houses\\Cottage.bmp")};
    button->knopki[2] =  {"Domische",       button->minX, 125, false, txLoadImage("Houses\\Domische.bmp")};
    button->knopki[3] =  {"SkyScraper",     button->minX, 150, false, txLoadImage("Houses\\SkyScraper.bmp")};
    button->knopki[4] =  {"House",          button->minX, 175, false, txLoadImage("Houses\\House.bmp")};
    button->knopki[5] =  {"Dacha",          button->minX, 200, false, txLoadImage("Houses\\Dacha.bmp")};
    button->knopki[6] =  {"TipichnyiDom",   button->minX, 225, false, txLoadImage("Houses\\TipichnyiDom.bmp")};

    button->kolvo_knopok = 7;

}
void zapolnenie_mosiva2(BUTTON* button)
{
    button->knopki[0] =  {"Cafe",           button->minX, 75, false, txLoadImage("Houses\\KrasivyiDom.bmp")};
    button->knopki[1] =  {"Hotel",          button->minX, 100, false, txLoadImage("Houses\\Hotel.bmp")};
    button->knopki[2] =  {"Magnit ",        button->minX, 125, false, txLoadImage("Houses\\Domische.bmp")};
    button->knopki[3] =  {"OfficeTelegram", button->minX, 150, false, txLoadImage("Houses\\SkyScraper.bmp")};
    button->knopki[4] =  {"Pyatyorochka	",  button->minX, 175, false, txLoadImage("Houses\\House.bmp")};
    button->knopki[5] =  {"carService",     button->minX, 200, false, txLoadImage("Houses\\Dacha.bmp")};
    button->knopki[6] =  {"	klinika	",      button->minX, 225, false, txLoadImage("Houses\\KrasivyiDom.bmp")};
    button->knopki[7] =  {"leviyMagazin",   button->minX, 250, false, txLoadImage("Houses\\Cottage.bmp")};
    button->knopki[8] =  {"museum",         button->minX, 275, false, txLoadImage("Houses\\Domische.bmp")};
    button->knopki[9] =  {"tyurima",        button->minX, 300, false, txLoadImage("Houses\\SkyScraper.bmp")};

    button->kolvo_knopok = 10;

}

void zapolnenie_mosiva3 (BUTTON* button)
{

    button->knopki[0] =  {"Hotel",          button->minX, 75, false, txLoadImage("Houses\\Hotel.bmp")};
    button->knopki[1] =  {"MGU",            button->minX, 100, false, txLoadImage("Houses\\MGU.bmp")};
    button->knopki[2] =  {"StatuyaSvobody", button->minX, 125, false, txLoadImage("Houses\\StatuyaSvobody.bmp")};
    button->knopki[3] =  {"Eiffel",         button->minX, 150, false, txLoadImage("Houses\\Eiffel.bmp")};

    button->kolvo_knopok = 4;

}

void zapolnenie_mosiva4 (BUTTON* button)
{

    button->knopki[0] =  {"Hotel",          button->minX, 75, false, txLoadImage("Houses\\Hotel.bmp")};
    button->knopki[1] =  {"MGU",            button->minX, 100, false, txLoadImage("Houses\\MGU.bmp")};
    button->knopki[2] =  {"StatuyaSvobody", button->minX, 125, false, txLoadImage("Houses\\StatuyaSvobody.bmp")};
    button->knopki[3] =  {"Eiffel",         button->minX, 150, false, txLoadImage("Houses\\Eiffel.bmp")};

    button->kolvo_knopok = 4;

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
     && (txMouseX () > button->minX && txMouseX () < button->maxX))
    {
        button->isPushed = true;
    }
    //Фокус потерян
    else if ((txMouseX () < button->minX || txMouseX () > button->maxX))
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
    if ( (txMouseButtons() & 1) &&
    (txMouseY() > button->knopki[i].minY  &&
    txMouseY() < button->knopki[i].minY+30)
     && (txMouseX () > button->minX &&
     txMouseX () < button->maxX))
    {
        button->isPushed = true;
    }
    //Фокус потерян
    else if ((txMouseX () < button->minX || txMouseX () > button->maxX))
    {
        button->isPushed = false;

    }
     }


    for (int i = 0; i < button->kolvo_knopok; i++)
    {

      if (txMouseY() > button->knopki[i].minY  &&
          txMouseY() < button->knopki[i].minY + 30 &&
          txMouseX () < button->maxX &&
          txMouseX () > button->minX &&
          txMouseButtons() & 1 && button->isPushed)
          {
            KARTINKA = button->knopki[i].pic;
          }
    }
}
