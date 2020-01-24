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
#include "read_write.h"

using namespace std;		// permet d'utiliser les flux cin et cout

// ============================ Sous programmes ============================= //
void fonction_mode_nuit (home & maison, capt_gene & capt_generaux, struct_mode & mode)
{
    int j;
    t_chaine name;
    for (j = 0 ; j <=4 ; j++)
    {
        if (mode.mode_vacance && maison[j].capt_lum < 10 && capt_generaux[7] <22)
        {
              // si mode vacance, peu de luminosité et apres 22H alors fermer les volets

            mode.mode_nuit = false;
            mode.mode_jour = true;          //chauffage nuit
            maison[j].act_volet = 1;
                    //sprintf("volet", "%d", j);
                    //capt_write(name , "fermer");


        }

        else if (maison[j].capt_lum < 10 )         // si mode normal et peu de luminosité fermer les volets
        {
            mode.mode_nuit = true;
            mode.mode_jour = false;
            maison[j].act_volet = 0;              // chauffage nuit
            //sprintf("volet", "%d", j);
            //capt_write(name , "fermer");
        }
        else
        {
            mode.mode_nuit = false;
            mode.mode_jour = true;              // sinon volets ouverts chauffage normal
            maison[j].act_volet = 1;
            //sprintf("volet", "%d", j);
            //capt_write(name , "ouvrir");
        }
    }
}
// ============================ Fin du programme ============================ //
