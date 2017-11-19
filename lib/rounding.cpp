#pragma once

#include "TXLib.h"
#include "cartinca.cpp"
#include "configs.cpp"

void round (CartincaNaKarte* KART, int x, int y)
{
    KART->X = round((ROUNDING/2+x)/ROUNDING)*ROUNDING;
    KART->Y = round((ROUNDING/2+y)/ROUNDING)*ROUNDING - 10;
 }
