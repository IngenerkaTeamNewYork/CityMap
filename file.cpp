#pragma once
#include "TXLib.h"
#include <iostream>

#include <fstream>
#include <string>
using namespace std;

struct CartincaNaKarte
{
    HDC KARTINKA;
    string adress;
    int X;
    int Y;
    bool RISOVAT_KARTINKU;
};

int main(int argc, char* argv[])
{

    txCreateWindow(1,1);
    CartincaNaKarte KART = {txLoadImage("Icons\\Monuments\\Lenin.bmp"), "Icons\\Monuments\\Lenin.bmp", 200, 200, true};
    for(int i; i< nomer; i++)
    {
    ofstream fout;
    fout.open("gfdg.txt");
    fout << KART[i].adress << "," << KART[i].X << "," << KART[i].Y << endl;
    fout.close();
    }
 }
