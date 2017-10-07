#include "TXLib.h"

//Листовой уровень
struct BUTTON2
{
    const char* textbutton;
    int minX;
    int minY;
    bool isPushed;
};

struct BUTTON
{
    const char* textbutton;
    int minX;
    int maxX;
    bool isPushed;
    BUTTON2 knopki[15];
};

void zapolnenie_mosiva1(BUTTON* button)
{
    button->knopki[0] =  {"KrasivyiDom",    button->minX, 100, false};
    button->knopki[1] =  {"Cottage",        button->minX, 125, false};
    button->knopki[2] =  {"Domische",       button->minX, 150, false};
    button->knopki[3] =  {"SkyScraper",     button->minX, 175, false};
    button->knopki[4] =  {"House",          button->minX, 200, false};
    button->knopki[5] =  {"Dacha",          button->minX, 225, false};
    button->knopki[6] =  {"TipichnyiDom",   button->minX, 250, false};
    button->knopki[7] =  {"Hotel",          button->minX, 275, false};
    button->knopki[8] =  {"MGU",            button->minX, 300, false};
    button->knopki[9] =  {"StatuyaSvobody", button->minX, 325, false};
    button->knopki[10] = {"Eiffel",         button->minX, 350, false};

}
void menu_draw(BUTTON* button)
{
    txSetColor (TX_LIGHTBLUE);
    txSetFillColor (RGB(180,250,250));
    txRectangle (button->minX , 50,  button->maxX, 100);
}

void menu_focus(BUTTON* button)
{
    txSetColor (TX_LIGHTBLUE);
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
        for(int i = 0; i < 11; i++)
        {
        txTextOut(button->knopki[i].minX, button->knopki[i].minY, button->knopki[i].textbutton);
        }
        //Фокус на нужной подкнопке
        if (txMouseY() > 250  && txMouseY() < 300)
        {
            txSetFillColor(TX_RED);
            txRectangle (txMouseX(), txMouseY(), txMouseX() + 100, txMouseY() + 100);
        }
    }
}
