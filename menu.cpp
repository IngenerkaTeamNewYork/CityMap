#include "TXLib.h"

//Листовой уровень
/*struct BUTTON2
{
    const char* textbutton;
    int minX;
    int maxX;
    bool isPushed;
};
    */
struct BUTTON
{
    const char* textbutton;
    int minX;
    int maxX;
    bool isPushed;
    BUTTON* knopki[10];
    HDC pic;
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
        if ((txMouseY() > 250  && txMouseY() < 300)&&(txMouseX() < 250  && txMouseX() > 10))
        {
                txBitBlt (txDC(), txMouseX(), txMouseY(), txMouseX() + 100, txMouseY() + 100, button->pic, 0, 0);
            //txRectangle (txMouseX(), txMouseY(), txMouseX() + 100, txMouseY() + 100);


        }

    }


}
