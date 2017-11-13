#include "TXLib.h"
#include "configs.cpp"
#include "cartinca.cpp"

void debug_function(int nomer_kartinki)
{
    if (DEBUG_MODE)
    {
        for (int nomer = 0; nomer < nomer_kartinki; nomer++)
        {
            char str[100];
            sprintf(str, "%d", KART[nomer].X);
            txTextOut(100, 100 + 25*nomer, str);

            sprintf(str, "%d", KART[nomer].Y);
            txTextOut(200, 100 + 25*nomer, str);

            if (KART[nomer].RISOVAT_KARTINKU)
                txTextOut(300, 100 + 25*nomer, "RISOVAT");
            if (KART[nomer].KARTINKA != NULL)
                txTextOut(400, 100 + 25*nomer, "KARTINKA");
        }
    }
}
