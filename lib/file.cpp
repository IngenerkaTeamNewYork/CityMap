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

    fout.open(imya_faila);

    int nomer = 0;
    while (fout.good()) {
        string get;
        getline (fout, get);

        int pos1 = get.find(',');
        string adress = get.substr(0, pos1 );
        get = get.substr(pos1 + 2);

        int pos2 = get.find(',');
        string x = get.substr(0, pos2);
        get = get.substr(pos2 + 2);

        int pos3 = get.find(',');
        string y = get.substr(0, pos3);

        KART1[nomer] = {txLoadImage(adress.c_str()), atoi(x.c_str()), atoi(y.c_str()), true};
        nomer++;
    }

    fout.close();

    return nomer;
}

void saveMassive()
{
    ofstream fout;
    fout.open("gfdg.txt");

    CartincaNaKarte KART[1];
    KART[0] = {txLoadImage("Icons\\Monuments\\Lenin.bmp"), 200, 200, true, "Icons\\Monuments\\Lenin.bmp"};
    for(int i = 0; i< 1; i++)
    {
        fout << KART[i].adress << "," << KART[i].X << "," << KART[i].Y << endl;
    }

    fout.close();
}
