#pragma once

#include "TXLib.h"
#include "configs.cpp"


struct CartincaNaKarte
{
    HDC KARTINKA;
    int X;
    int Y;
    bool RISOVAT_KARTINKU;
    string adress;
};

CartincaNaKarte* KART = new CartincaNaKarte[KOLICHESTVO_KARTINOK_NA_KARTE];
