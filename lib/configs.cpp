int X_COORD = 0;
HDC KARTINKA = nullptr;
int X;
int Y;
bool RISOVAT_KARTINKU = false;
const int VISOTA_MENU = 50;
const int X_ICRANA = 100;
const int Y_ICRANA = 1000;
const int RASSTOYANIE_MEZHDU_KNOPKAMI = 40;
const int NIZHINIY_Y = 400;
const int M_X_PLUS_COORDINATA = 150;
const int M_Y_PLUS_COORDINATA = 200;



struct cartinca
{
    HDC KARTINKA;
    int X;
    int Y;
    bool RISOVAT_KARTINKU;
};

const int w = 4;
cartinca KART[w];
