#pragma once

#include "TXLib.h"
#include <iostream>

#include <fstream>
#include <string>
#include "cartinca.cpp"

using namespace std;

int massive(CartincaNaKarte* KART1)
{
    ifstream fout;
    fout.open("Files\\Openfile.txt");
    string imya_faila;
    getline (fout, imya_faila);
    fout.close();

    //const char* imya_faila = txInputBox ("Откуда брать?", "System", "");
    fout.open(imya_faila);

    int nomer = 0;
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

			bool lenin_zhiv = false;
            for (int i = 0; i < nomer; i++)
            {
                if (KART1[i].adress == adress)
                {
                    KART1[nomer] = {KART1[i].KARTINKA, atoi(x.c_str()), atoi(y.c_str()), true, adress.c_str()};
                    lenin_zhiv = true;
					break;
                }
            }

            if (!lenin_zhiv)
            {
                KART1[nomer] = {txLoadImage(adress.c_str()), atoi(x.c_str()), atoi(y.c_str()), true, adress.c_str()};
            }

            nomer++;
        }
    }

    fout.close();

    return nomer;
}

void saveMassive(CartincaNaKarte* KART1, int nomer_kartinki)
{
    ifstream fout;
    fout.open("Files\\savefile.txt");
    string imya_faila_save;
    getline (fout, imya_faila_save);
    fout.close();
    //const char* imya_faila_save = txInputBox ("Куда сохранять?", "System", "");

    ofstream fout_save;
    fout_save.open(imya_faila_save);

    for(int i = 0; i< nomer_kartinki; i++)
    {
        if (KART1[i].RISOVAT_KARTINKU)
        {
            fout_save << KART1[i].adress << "," << KART1[i].X << "," << KART1[i].Y << endl;
        }
    }

    fout.close();
}
