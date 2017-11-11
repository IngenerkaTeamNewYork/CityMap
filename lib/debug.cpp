#include "TXLib.h"
#include "configs.cpp"
#include "cartinca.cpp"


void debug_function(int nomer_kartinki)
{
    if (DEBUG_MODE)
    {
        if (KART[nomer_kartinki].RISOVAT_KARTINKU)
        {
            txTextOut(450, 500, "RISOVAT");
        }
        if (KART[nomer_kartinki].KARTINKA != nullptr)
        {
            txTextOut(450, 600, "KARTINKA");
        }

        char str[100];
        sprintf(str, "%d", nomer_kartinki);  //Writing car_x_coord value to str
        txTextOut(450, 550, str);
    }
}
