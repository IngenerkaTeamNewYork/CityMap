#include "TXLib.h"
#include <iostream>

#include <fstream>
#include <string>
#include <cstring>


struct Button2
{
    const char* textbutton;
    int minX;
    int minY;
    bool isPushed;
    HDC pic;
    HDC ikonka;
};

struct Button
{
    const char* textbutton;
    int minX;
    int maxX;
    bool isPushed;
    Button2 knopki[15];
    int kolvo_knopok;
};

using namespace std;

int main ()
{
    txCreateWindow (1000, 800);
    Button buttons[6];
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
                {textbutton, 50, 250, false, txLoadImage(picAdress), txLoadImage(ikonAdress)};
            nomer_knopki2++;
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
            buttons[nomer_knopki] = {textbutton,  50, 250, false, {}};
            nomer_knopki2 = 0;
        }
    }

    //Last button of first level
    if (nomer_knopki > 0)
    {
        buttons[nomer_knopki].kolvo_knopok = nomer_knopki2;
    }

    fout.close();
}
