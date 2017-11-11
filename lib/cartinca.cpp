#pragma once

#include "TXLib.h"
#include "configs.cpp"


/*struct MAP
{
    int X;
    int Y;
    int RX;
    int RY;
    HDC ISKARTINKA;
};
*/
struct CartincaNaKarte
{
    HDC KARTINKA;
    int X;
    int Y;
    bool RISOVAT_KARTINKU;
};

CartincaNaKarte KART[KOLICHESTVO_KARTINOK_NA_KARTE];
