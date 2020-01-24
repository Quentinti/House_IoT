// ===================== Liste des fichiers d'en-tete ======================= //
#include <iostream>
#include <clocale>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <locale>

#include <sstream>
#include <string>
#include <iostream>
#include "Types.h"
#include "chauffage.h"
#include "read_write.h"

using namespace std;		// permet d'utiliser les flux cin et cout

// ============================ Sous programmes ============================= //

void chauffage (home & maison, capt_gene capt_generaux, struct_mode mode)
{
    int i, y;
    t_chaine name;
    if (mode.mode_manuel == 1) {
        for(i = 0; i < 5; i++) {
            if (maison[i].capt_buttonplus == 1 && maison[i].act_temp < 30) {
                maison[i].act_temp++;
                //sprintf(name, "chauffage%d", i);
                //capt_write(name , "augmenter");
            }
            else if (maison[i].capt_buttonmoins == 1 && maison[i].act_temp > 0) {
                maison[i].act_temp--;
                //sprintf(name, "chauffage%d", i);
                //capt_write(name , "baisser");
            }
        }
    }
    else {
        for(i = 0; i < 5; i++) {
            if (mode.mode_nuit)
            {
                maison[i].act_temp = 18;
            }
            if (mode.mode_jour)
            {
                maison[i].act_temp = 20;
            }
            if (mode.mode_vacance)
            {
                maison[i].act_temp = 12;
            }
            if (mode.mode_absence)
            {
                maison[i].act_temp = 16;
            }
            if (mode.mode_securite)
            {
                y = 0;
                do
                {
                    maison[i].act_temp++;
                    y++;
                }
                while (y < 5 && maison[i].act_temp < 30);
            }
            switch (i) {
            case 1:
                maison[i].act_temp--;
                break;
            case 2:
                maison[i].act_temp = maison[i].act_temp - 3;
                break;
            case 3:
                maison[i].act_temp = maison[i].act_temp + 2;
                break;
            case 4:
                maison[i].act_temp = maison[i].act_temp - 6;
                break;
            default:
                maison[i].act_temp = capt_generaux[5];
            }
        }
    }
}

// ============================ Fin du programme ============================ //
