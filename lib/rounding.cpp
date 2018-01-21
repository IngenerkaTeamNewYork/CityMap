#pragma once

#include "TXLib.h"
#include "cartinca.cpp"
#include "configs.cpp"

int roundY (int y)
{
    return round ( y / ROUNDING ) * ROUNDING - 10;
}

int roundX (int x)
{
    return round ( x / ROUNDING ) * ROUNDING;
}

void round (CartincaNaKarte* KART, int x, int y)
{
    KART->X = roundX(x);
    KART->Y = roundY(y);
}
