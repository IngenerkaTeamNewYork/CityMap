#pragma once

#include "TXLib.h"
#include <iostream>

#include <fstream>
#include <string>
#include "cartinca.cpp"
#include "configs.cpp"
#include "if_povorotov.cpp"

using namespace std;

int massive(CartincaNaKarte* KART1)
{
    int nomer = 0;

    ifstream fout;
    const char* imya_faila = txInputBox ("Введите название файла(Пример:Lenin)", "System", "");
    ADRESS = imya_faila;
    fout.open(imya_faila);

    if (!fout)
    {
        fout.close();
        char* imya_faila2 = new char[195];
        strcpy(imya_faila2, "Files\\");
        strcat(imya_faila2, imya_faila);
        fout.open(imya_faila2);
        ADRESS = imya_faila2;
    }
    if (!fout)
    {
        fout.close();
        char* imya_faila3 = new char[195];
        strcpy(imya_faila3, "Files\\");
        strcat(imya_faila3, imya_faila);
        strcat(imya_faila3, ".txt");
        fout.open(imya_faila3);
        ADRESS = imya_faila3;
    }

    if (fout)
    {
        string get = "1";
        while (fout.good() && strlen(get.c_str()) > 0) {
            getline (fout, get);

            if (strlen(get.c_str()) > 0)
            {
                int pos1 = get.find(',');
                string adress = get.substr(0, pos1 );
                get = get.substr(pos1 + 1);

                int pos2 = get.find(',');
                string x = get.substr(0, pos2);
                get = get.substr(pos2 + 1);

                int pos3 = get.find(',');
                string y = get.substr(0, pos3);

                KART1[nomer] = {txLoadImage(adress.c_str()), atoi(x.c_str()), atoi(y.c_str()), true, adress.c_str()};
                nomer++;
            }
        }

        fout.close();
    }

    return nomer;
}

void efshliu(CartincaNaKarte* KART1, int nomer)
{
    for (int stroka = 0; stroka < 100; stroka++)
    {
        for (int stolbec = 0; stolbec < 100; stolbec++)
        {
            massiv[stroka][stolbec] = 0;
        }
    }


    for (int n = 0; n < nomer; n++)
    {
        if (KART1[n].RISOVAT_KARTINKU and KART1[n].X >= 0 and KART1[n].Y >= 0 and
            KART1[n].X <= 1000 and KART1[n].Y <= 600)
        {
            Kart2[KART1[n].X/30][KART1[n].Y/30] = KART1[n];
            if (strcmp(KART1[n].adress.c_str(), "Icons\\Roads\\Doroga.bmp") == 0)
            {
                massiv[KART1[n].X/30][KART1[n].Y/30] = 1;
            }
        }
    }


    for (int stroka = 0; stroka < 100; stroka++)
    {
        for (int stolbec = 0; stolbec < 100; stolbec++)
        {
            if_povorot_na_pravo(stolbec, stroka, picDorogi);
        }
    }
}

void saveMassive(CartincaNaKarte* KART1, int nomer_kartinki)
{
    const char* imya_faila_save = txInputBox ("Where to save?", "System", ADRESS);

    ofstream fout_save;
    fout_save.open(imya_faila_save);

    for (int i = 0; i< nomer_kartinki; i++)
    {
        if (KART1[i].RISOVAT_KARTINKU)
        {
            fout_save << KART1[i].adress << "," << KART1[i].X << "," << KART1[i].Y << endl;
        }
    }

    fout_save.close();
}
