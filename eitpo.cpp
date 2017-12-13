#include "TXLib.h"
#include <iostream>

#include <fstream>
#include <string>
#include <cstring>
#include "lib\\configs.cpp"
#include "lib\\menu.cpp"


using namespace std;
int KORD_KNOPKI = 50;
int KORD_KNOPKI_Y = 50;



int read (Button* buttons)
{
    int nomer_knopki = -1;
    int nomer_knopki2 = 0;

    ifstream fout;
    fout.open("menu.txt");

    while (fout.good()) {
        string first_level = "";
        getline (fout, first_level);

        //2 level
        if (strcmp(first_level.substr(0,1).c_str(), "%") == 0)
        {
            first_level = first_level.substr(1);

            char* picAdress = new char[195];
            strcpy(picAdress, "Pictures\\");
            strcat(picAdress, buttons[nomer_knopki].textbutton);
            strcat(picAdress, "\\");
            strcat(picAdress, first_level.c_str());
            strcat(picAdress, ".bmp");

            char* ikonAdress = new char[195];
            strcpy(ikonAdress, "Icons\\");
            strcat(ikonAdress, buttons[nomer_knopki].textbutton);
            strcat(ikonAdress, "\\");
            strcat(ikonAdress, first_level.c_str());
            strcat(ikonAdress, ".bmp");

            char* textbutton = new char[100];
            strcpy(textbutton, first_level.c_str());

            buttons[nomer_knopki].knopki[nomer_knopki2] =
                {textbutton, KORD_KNOPKI - SHIR_KNOPKI, KORD_KNOPKI_Y, false, txLoadImage(picAdress), txLoadImage(ikonAdress), ikonAdress};
            nomer_knopki2++;

            KORD_KNOPKI_Y = KORD_KNOPKI_Y + RASSTOYANIE_MEZHDU_KNOPKAMI;


        }
        //1 level
        else
        {
            nomer_knopki++;
            if (nomer_knopki > 0)
            {
                buttons[nomer_knopki - 1].kolvo_knopok = nomer_knopki2;
            }
            char* textbutton = new char[100];
            strcpy(textbutton, first_level.c_str());
            buttons[nomer_knopki] = {textbutton,  KORD_KNOPKI, KORD_KNOPKI + SHIR_KNOPKI, false, {}};
            nomer_knopki2 = 0;
            KORD_KNOPKI = KORD_KNOPKI + SHIR_KNOPKI;
            KORD_KNOPKI_Y = 50;
        }
    }

    //Last button of first level
    if (nomer_knopki > 0)
    {
        buttons[nomer_knopki].kolvo_knopok = nomer_knopki2;
    }

    KOLICHESTVO_KNOPOK_MENU = nomer_knopki + 1;
    SHIR_KNOPKI = (X_ICRANA - 100) / KOLICHESTVO_KNOPOK_MENU;

    for (int i = 0; i < KOLICHESTVO_KNOPOK_MENU; i++)
    {
        buttons[i].minX = 50 + SHIR_KNOPKI * i;
        buttons[i].maxX = 50 + SHIR_KNOPKI * (i + 1);


        for (int nom_but = 0; nom_but < buttons[i].kolvo_knopok; nom_but++)
        {
            buttons[i].knopki[nom_but].minX = buttons[i].minX = 50 + SHIR_KNOPKI * i;
        }
    }

    fout.close();
}
