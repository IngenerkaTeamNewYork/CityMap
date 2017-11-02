#include "TXLib.h"
#include "configs.cpp"

struct CartincaNaKarte
{
    HDC KARTINKA;
    int X;
    int Y;
    bool RISOVAT_KARTINKU;
};

CartincaNaKarte KART[KOLICHESTVO_KARTINOK_NA_KARTE];
