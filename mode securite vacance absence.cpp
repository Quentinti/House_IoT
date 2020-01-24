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

using namespace std;		// permet d'utiliser les flux cin et cout

// ============================ Sous programmes ============================= //


void fonction_mode_securite_vacance_absence (home & maison, capt_gene & capt_generaux, struct_mode & mode )
{

    int i,j;

    if (mode.mode_securite_vacance_absence)
    {
        mode.mode_securite = true;
        capt_generaux[8] = 0; //buzzer
        i=19;
        for (j = 0 ; j <=4 ; j++)
        {
            maison[j].act_led = 0;
        }
        do
        {
            i++;
            if(capt_generaux[7] == i)      //allumer la lumiere 2h par jours
            {
                    for (j = 0 ; j <=4 ; j++)
                    {
                       maison[j].act_led = 100;
                    }

            }
        }
        while (i<= 22);
        if  (capt_generaux[0]> 0)    //alarme si presence
        {
            capt_generaux[8] = 1; //buzzer
            for (j = 0 ; j <=4 ; j++)
            {
                maison[j].act_led = 100;
            }
        }
    }
}

// ============================ Fin du programme ============================ //
