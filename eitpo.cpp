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
        string first_level = "", second_level = "";
        getline (fout, first_level);

        //2 level
        if (strcmp(first_level.substr(0,1).c_str(), "$") == 0)
        {
            char* picAdress = new char[195];
            strcpy(picAdress, "");
            //cout << nomer_knopki << " " << buttons[nomer_knopki].textbutton << endl;
            second_level = first_level.substr(1);
            first_level = "";

            strcpy(picAdress, "Pictures\\");
            strcat(picAdress, buttons[nomer_knopki].textbutton);
            strcat(picAdress, "\\");
            strcat(picAdress, second_level.c_str());
            strcat(picAdress, ".bmp");
            cout << picAdress << endl;

            /*char* ikonAdress = new char[95];
             strcpy (ikonAdress, "Icons\\Houses\\");
             strcat(ikonAdress, second_level.c_str());
            strcat(ikonAdress, ".bmp");     */

            //txBitBlt(txDC(), 50, 100, 200, 300, txLoadImage(picAdress), 0, 0);
          //cout << string(ikonAdress, strlen(ikonAdress)).substr(0) << endl;

            buttons[nomer_knopki].knopki[nomer_knopki2] =
                {picAdress,  50, 250, false };//txLoadImage(picAdress),     txLoadImage(ikonAdress)};
            nomer_knopki2++;
        }
        //1 level
        else
        {
            cout << "1sdfgsdgfsg" << endl;
            nomer_knopki++;
            //first_level = first_level.substr(0);
            second_level = "";
            if (nomer_knopki > 0)
            {
                buttons[nomer_knopki - 1].kolvo_knopok = nomer_knopki2;
            }
            buttons[nomer_knopki] = {first_level.c_str(),  50, 250, false, {}};
            buttons[nomer_knopki].textbutton = first_level.c_str();
            nomer_knopki2 = 0;
            txSleep(1000);
        }

        //cout << "first_level " << first_level <<
        //    " second_level " << second_level << endl;


    }

    //txClear();
    cout << nomer_knopki << endl;
    for (int i = 0; i <= nomer_knopki + 1; i++)
    {
        for (int j = 0; j < buttons[i].kolvo_knopok; j++)
        {
            cout << i << " " << j << " " << buttons[i].knopki[j].textbutton << endl;
            //txBitBlt(txDC(), 50, 100, 200, 300, buttons[i].knopki[j].pic, 0, 0);

        }
    }

    fout.close();


    //return nomer;

}
