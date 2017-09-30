#include "TXLib.h" 

struct BUTTON
{
    const char* textbutton;
    int minX;
    int maxX;
};


void function1 (BUTTON* button)
{
   txSetColor (TX_LIGHTBLUE);
    txSetFillColor (RGB(180,250,250));
     txRectangle (button->minX , 50,  button->maxX, 100);

}

void focus(BUTTON* button)
{
    if ((txMouseY() > 50  && txMouseY() < 100)
     && (txMouseX () > button->minX && txMouseX () < button->maxX))
    {

       txRectangle (button->minX, 100, button->maxX, 500);

    }
}