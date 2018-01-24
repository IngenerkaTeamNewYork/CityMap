#pragma once

#include "TXLib.h"

int massiv[100][100];

void if_povorot_na_pravo(int x,int y)
{
    HDC  pic = txLoadImage ("Doroga_New.bmp");

    if (massiv[x][y] == massiv[x + 1][y])
    {
        if (massiv[x][y] == massiv[x][y + 1])
        {
            txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 0, 0);
        }
        else
        {
            if(massiv[x][y] == massiv[x][y - 1])
            {
                txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 0, 0);
            }
            else
            {
                txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 0, 0);
            }
        }
    }
    else
    {
        if(massiv[x][y] == massiv[x - 1][y])
        {
            if(massiv[x][y] == massiv[x][y + 1])
            {
                txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 0, 0);
            }
            else
            {
                if(massiv[x][y] == massiv[x][y + 1])
            }
        }
    }

    txDeleteDC (pic);
}

int main()
{
    txCreateWindow(800, 600);

    massiv[0][0] = 1;
    massiv[0][1] = 1;
    massiv[1][0] = 1;
    massiv[1][1] = 0;

    if_povorot_na_pravo(0, 0);
    if_povorot_na_pravo(1, 0);
    if_povorot_na_pravo(0, 1);
    if_povorot_na_pravo(1, 1);


    return 0;
}
