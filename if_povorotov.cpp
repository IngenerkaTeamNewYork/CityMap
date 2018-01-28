#pragma once

#include "TXLib.h"

int massiv[100][100];

void if_povorot_na_pravo(int x,int y)
{
    HDC  pic = txLoadImage ("Doroga_New.bmp");

    //Дороги со всех сторон
    /*
    1
   111
    1
    */
    if (x > 0 and y > 0 and
        massiv[x][y] == 1 and
        massiv[x][y + 1] == 1 and
        massiv[x + 1][y] == 1 and
        massiv[x - 1][y] == 1 and
        massiv[x][y - 1] == 1)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 64, 34);
    }
    /*
    1
   011
    1
    */
    else if (x >= 0 and y > 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 1 and
        massiv[x][y + 1] == 1 and
        massiv[x + 1][y] == 1 and
        massiv[x - 1][y] == 0)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 196, 34);
    }
    /*
    1
   011
    0
    */
     else if (x >= 0 and y > 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 1 and
        massiv[x][y + 1] == 0 and
        massiv[x + 1][y] == 1 and
        massiv[x - 1][y] == 0)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 105, 0);
    }
    /*
    0
   011
    1
    */
     else if (x >= 0 and y >= 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 0 and
        massiv[x][y + 1] == 1 and
        massiv[x + 1][y] == 1 and
        massiv[x - 1][y] == 0)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 3, 3);
    }
    /*
    1
   110
    1
    */
     else if (x > 0 and y > 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 1 and
        massiv[x][y + 1] == 1 and
        massiv[x + 1][y] == 0 and
        massiv[x - 1][y] == 1)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 167, 35);
    }
    /*
    1
   111
    0
    */
     else if (x > 0 and y > 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 1 and
        massiv[x][y + 1] == 0 and
        massiv[x + 1][y] == 1 and
        massiv[x - 1][y] == 1)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 133, 35);
    }
    /*
    0
   111
    1
    */
     else if (x > 0 and y >= 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 0 and
        massiv[x][y + 1] == 1 and
        massiv[x + 1][y] == 1 and
        massiv[x - 1][y] == 1)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 99, 35);
    }
    /*
    0
   111
    0
    */
     else if (x > 0 and y >= 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 0 and
        massiv[x][y + 1] == 0 and
        massiv[x + 1][y] == 1 and
        massiv[x - 1][y] == 1)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 31, 35);
    }
    /*
    1
   010
    1
    */
     else if (x >= 0 and y > 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 1 and
        massiv[x][y + 1] == 1 and
        massiv[x + 1][y] == 0 and
        massiv[x - 1][y] == 0)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 0, 35);
    }
    /*
    1
   110
    0
    */
     else if (x > 0 and y > 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 1 and
        massiv[x][y + 1] == 0 and
        massiv[x + 1][y] == 0 and
        massiv[x - 1][y] == 1)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 33, 0);
    }
    /*
    0
   110
    1
    */
     else if (x > 0 and y >= 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 0 and
        massiv[x][y + 1] == 1 and
        massiv[x + 1][y] == 0 and
        massiv[x - 1][y] == 1)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 68, 0);
    }
    /*
    0
   010
    1
    */
     else if (x >= 0 and y > 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 0 and
        massiv[x][y + 1] == 1 and
        massiv[x + 1][y] == 0 and
        massiv[x - 1][y] == 0)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 0, 35);
    }
    /*
    0
   011
    0
    */
     else if (x > 0 and y >= 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 0 and
        massiv[x][y + 1] == 0 and
        massiv[x + 1][y] == 1 and
        massiv[x - 1][y] == 0)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 31, 35);
    }
    /*
    1
   010
    0
    */
     else if (x >= 0 and y > 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 1 and
        massiv[x][y + 1] == 0 and
        massiv[x + 1][y] == 0 and
        massiv[x - 1][y] == 0)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 0, 35);
    }

    /*
    0
   110
    0
    */
     else if (x > 0 and y >= 0 and
        massiv[x][y] == 1 and
        massiv[x][y - 1] == 0 and
        massiv[x][y + 1] == 0 and
        massiv[x + 1][y] == 0 and
        massiv[x - 1][y] == 1)
    {
        txBitBlt (txDC(), 30 * x, 30 * y, 30, 30, pic, 31, 35);
    }


    txDeleteDC (pic);
}

int main()
{
    srand(time(NULL));
    int elementov = 8;
    txCreateWindow(800, 600);

    //zapolnenie
    for (int stroka = 0; stroka < elementov; stroka++)
    {
        for (int stolbec = 0; stolbec < elementov; stolbec++)
        {
            massiv[stroka][stolbec] = rand() % 2;
        }
    }

    //vyvod na ekran
    char stroka_elementov[100];
    for (int stroka = 0; stroka < elementov; stroka++)
    {
        strcpy(stroka_elementov, "");
        for (int stolbec = 0; stolbec < elementov; stolbec++)
        {
            if (massiv[stroka][stolbec] == 0)
            {
                strcat(stroka_elementov, "0");
            }
            else
            {
                strcat(stroka_elementov, "1");
            }
        }

        txTextOut(100, 400 + 20 * stroka, stroka_elementov);
    }


    //kartinki
    for (int stroka = 0; stroka < elementov; stroka++)
    {
        for (int stolbec = 0; stolbec < elementov; stolbec++)
        {
            if_povorot_na_pravo(stroka, stolbec);
        }
    }

    return 0;
}
