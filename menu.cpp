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

void Arrows ()
{
  txSetFillColor (RGB (0,255,0));

  txRectangle (750, 400, 825, 450);
  POINT tre[3] = {{900, 425}, {825, 475}, {825, 375}};
  txPolygon (tre, 3);

  txSetFillColor (RGB (43,255,43));
  txRectangle (75, 400, 150, 450);
  POINT stre[3] = {{0, 425}, {75, 475}, {75, 375}};

    txPolygon (stre, 3);

}

 void shift ()
 {
 COLORREF color = txGetPixel(txMouseX(), txMouseY());


  if((txMouseButtons() & 1) && (color == RGB(0, 255, 0)) && X_COORD < 3500)
  {
    X_COORD += 900;
    txSleep(1000);
  }

    if((txMouseButtons() & 1) && (color == RGB(43, 255, 43)) && X_COORD > 0)
  {
    X_COORD -= 900;
    txSleep(1000);
  }

}

void zapolnenie_mosiva1(BUTTON* button)
{
    button->knopki[0] =  {"KrasivyiDom",    button->minX, 100, false, txLoadImage("Houses\\KrasivyiDom.bmp")};
    button->knopki[1] =  {"Cottage",        button->minX, 125, false, txLoadImage("Houses\\Cottage.bmp")};
    button->knopki[2] =  {"Domische",       button->minX, 150, false, txLoadImage("Houses\\Domische.bmp")};
    button->knopki[3] =  {"SkyScraper",     button->minX, 175, false, txLoadImage("Houses\\SkyScraper.bmp")};
    button->knopki[4] =  {"House",          button->minX, 200, false, txLoadImage("Houses\\House.bmp")};
    button->knopki[5] =  {"Dacha",          button->minX, 225, false, txLoadImage("Houses\\Dacha.bmp")};
    button->knopki[6] =  {"TipichnyiDom",   button->minX, 250, false, txLoadImage("Houses\\TipichnyiDom.bmp")};

    button->kolvo_knopok = 7;

}
void zapolnenie_mosiva2(BUTTON* button)
{
    button->knopki[0] =  {"Cafe",           button->minX, 100, false, txLoadImage("Houses\\KrasivyiDom.bmp")};
    button->knopki[1] =  {"Hotel",          button->minX, 125, false, txLoadImage("Houses\\Hotel.bmp")};
    button->knopki[2] =  {"Magnit ",        button->minX, 150, false, txLoadImage("Houses\\Domische.bmp")};
    button->knopki[3] =  {"OfficeTelegram", button->minX, 175, false, txLoadImage("Houses\\SkyScraper.bmp")};
    button->knopki[4] =  {"Pyatyorochka	",  button->minX, 200, false, txLoadImage("Houses\\House.bmp")};
    button->knopki[5] =  {"carService",     button->minX, 225, false, txLoadImage("Houses\\Dacha.bmp")};
    button->knopki[6] =  {"	klinika	",      button->minX, 250, false, txLoadImage("Houses\\KrasivyiDom.bmp")};
    button->knopki[7] =  {"leviyMagazin",   button->minX, 275, false, txLoadImage("Houses\\Cottage.bmp")};
    button->knopki[8] =  {"museum",         button->minX, 300, false, txLoadImage("Houses\\Domische.bmp")};
    button->knopki[9] =  {"tyurima",        button->minX, 325, false, txLoadImage("Houses\\SkyScraper.bmp")};

    button->kolvo_knopok = 10;

}

void zapolnenie_mosiva3 (BUTTON* button)
{

    button->knopki[0] =  {"Hotel",          button->minX, 100, false, txLoadImage("Houses\\Hotel.bmp")};
    button->knopki[1] =  {"MGU",            button->minX, 125, false, txLoadImage("Houses\\MGU.bmp")};
    button->knopki[2] =  {"StatuyaSvobody", button->minX, 150, false, txLoadImage("Houses\\StatuyaSvobody.bmp")};
    button->knopki[3] =  {"Eiffel",         button->minX, 175, false, txLoadImage("Houses\\Eiffel.bmp")};

    button->kolvo_knopok = 4;

}

void zapolnenie_mosiva4 (BUTTON* button)
{

    button->knopki[0] =  {"Hotel",          button->minX, 100, false, txLoadImage("Houses\\Hotel.bmp")};
    button->knopki[1] =  {"MGU",            button->minX, 125, false, txLoadImage("Houses\\MGU.bmp")};
    button->knopki[2] =  {"StatuyaSvobody", button->minX, 150, false, txLoadImage("Houses\\StatuyaSvobody.bmp")};
    button->knopki[3] =  {"Eiffel",         button->minX, 175, false, txLoadImage("Houses\\Eiffel.bmp")};

    button->kolvo_knopok = 4;

}


void menu_draw(BUTTON* button)
{
    txSetColor (TX_LIGHTBLUE);
    txSetFillColor (RGB(180,250,250));
    txRectangle (button->minX , 50,  button->maxX, 100);
    txTextOut(button->minX, 50, button->textbutton);
}

void menu_focus(BUTTON* button)
{
    txSetColor (TX_BLUE);
    txSetFillColor (RGB(180,250,250));


    //Нажали на кнопку
    if ((txMouseY() > 50  && txMouseY() < 100)
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

        txRectangle (button->minX, 100, button->maxX, 500);
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
