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
    fout.open("file.txt");
    string imya_faila;
    getline (fout, imya_faila);
    fout.close();

    fout.open(imya_faila);
    //txCreateWindow(800, 600);
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
        get = get.substr(pos3 + 2);

        //string bools = get;

        /*HDC pic = txLoadImage(adress.c_str());
        txBitBlt (txDC(), atoi(x.c_str()), atoi(y.c_str()), 30, 30, pic, 0, 0);
        txDeleteDC(pic);*/

        KART1[nomer] = {txLoadImage(adress.c_str()), atoi(x.c_str()), atoi(y.c_str()), true};
        nomer++;
    }
    fout.close();

    return nomer;
}
