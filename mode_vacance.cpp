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
//#include "modevacance.h"

using namespace std;		// permet d'utiliser les flux cin et cout

// ============================ Sous programmes ============================= //

void fonction_mode_vacance(struct_mode & mode)      // activer quand utilisateur en vacance
{
    mode.mode_securite_vacance_absence = false;
    if (mode.mode_vacance== true)
    {
        mode.mode_securite_vacance_absence = true;

    }

}
// ============================ Fin du programme ============================ //
