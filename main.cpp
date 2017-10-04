#include "TXLib.h"
#include "lib\\menu.cpp"

int main()
{
    txCreateWindow (900, 900);
    BUTTON buttons[4];
    buttons[0] = {"sdfsdf", 10, 225};
    buttons[1] = {"uhuhli", 225, 440};
    buttons[2] = {"dtudud", 440, 665};
    buttons[3] = {"aseyer", 665, 900};

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
         txSetFillColor(TX_BLACK);
    txClear();
   txSetColor (TX_LIGHTBLUE);

        function1(&buttons[0]);
        function1(&buttons[1]);
        function1(&buttons[2]);
        function1(&buttons[3]);
        focus(&buttons[0]);
        focus(&buttons[1]);
        focus(&buttons[2]);
        focus(&buttons[3]);

     /*if ((txMouseY() > 50  && txMouseY() < 100)
          &&(txMouseX () > 10 && txMouseX () < 225))
        {

           txRectangle (10, 100, 225, 500);

        }

        else if ((txMouseY() > 50  && txMouseY() < 100)
                  &&(txMouseX () > 225 && txMouseX () < 440))
        {

           txRectangle (225, 100, 440, 500);

        }
         else if ((txMouseY() > 50  && txMouseY() < 100)
                  &&(txMouseX () > 440 && txMouseX () < 665))
        {
           txRectangle (440, 100, 655, 500);

        }
         else if ((txMouseY() > 50  && txMouseY() < 100)
                  &&(txMouseX () > 665 && txMouseX () < 900))
        {

           txRectangle (665, 100, 870, 500);


        }  */

        txSleep(5);
    }

    return 0;
}


