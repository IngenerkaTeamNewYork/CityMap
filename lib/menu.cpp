#include "TXLib.h"

//Листовой уровень
struct BUTTON2
{
    const char* textbutton;
    int minX;
    int maxX;
    bool isPushed;
};

struct BUTTON
{
    const char* textbutton;
    int minX;
    int maxX;
    bool isPushed;
    BUTTON2 knopki[10];
};

void menu_draw(BUTTON* button)
{
    txSetColor (TX_LIGHTBLUE);
    txSetFillColor (RGB(180,250,250));
    txRectangle (button->minX , 50,  button->maxX, 100);
}

void menu_focus(BUTTON* button)
{
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

        //Фокус на нужной подкнопке
        if (txMouseY() > 250  && txMouseY() < 300)
        {
            txSetFillColor(TX_RED);
            txRectangle (txMouseX(), txMouseY(), txMouseX() + 100, txMouseY() + 100);
        }
    }
}
