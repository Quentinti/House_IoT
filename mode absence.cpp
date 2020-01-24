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

void fonction_mode_absence (home maison, capt_gene capt_generaux, struct_mode & mode, int & temp_absence)
{

    if (capt_generaux[0] > 0)            // reinitialise le temp absence
    {
        temp_absence = 0;
    }
    else
    {
       temp_absence++;                // compte le temp d'absence
    }
    if (temp_absence > 48)
    {
        mode.mode_securite_vacance_absence = true;                 // si le temp absence depasse un jour passe en mode vacance absence
        mode.mode_absence = true;
    }
    else
    {
       mode.mode_securite_vacance_absence = false;
       mode.mode_absence = false;
    }

}

// ============================ Fin du programme ============================ //
