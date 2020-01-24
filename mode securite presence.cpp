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

void fonction_mode_securite (capt_gene capt_generaux, struct_mode & mode)
{
    mode.mode_securite = false;
    capt_generaux[8] = false; //buzzer
    //capt_write("buzzer" , "off");
    if (capt_generaux[1] > 0)   // si gaz alors alarme et ventilation
    {
        capt_generaux[9] = 100; //ventillateur
        //capt_write("ventilation" , "max");
        capt_generaux[8] = true;
        //capt_write("buzzer" , "on");
    }
    else if(capt_generaux[3]>0)   //si moississure ventilation et chauffage
    {
        capt_generaux[9] = 75;
        mode.mode_securite = true;
    }
    else if(capt_generaux[4]>50)          // si humidité ventilation et chauffage
    {
        capt_generaux[9] = 100;
        //capt_write("ventilation" , "max");
        mode.mode_securite = true;
    }
     else if(capt_generaux[2] > 0 )       // si poussiere ventilation
    {
        capt_generaux[9] = 50;
    }
    else
    {
        capt_generaux[9] = 25;                    // cas normal ventilation faible
    }

}

// ========================== Programme principal =========================== //

// ============================ Fin du programme ============================ //
