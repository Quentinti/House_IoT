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

#include <mutex>
#include <thread>

std::mutex mtx; //utilisation de mutex
using namespace std;		// permet d'utiliser les flux cin et cout

// ============================ Sous programmes ============================= //

void eclairage (home & maison, capt_gene & capt_generaux, struct_mode mode)
{
    int i;
    t_chaine name;
    for(i = 0; i < 5; i++)
    {
        if (maison[i].capt_button > 0)
        {
            maison[i].act_led = 100;
            //sprintf("lumiere", "%d", i);
            //capt_write(name , "max");

        }
        else if (maison[i].capt_ir > 0)
        {
            maison[i].act_led = 100  ;
            //sprintf("lumiere", "%d", i);
            //capt_write(name , "max");
        }
        else if (mode.mode_nuit == 1 && maison[i].act_volet == 0)
        {
            //sprintf("lumiere", "%d", i);
            //capt_write(name , "min");
            maison[i].act_led = 0;
        }
        else
        {
            maison[i].act_led = 100 - capt_generaux[6];
        }
    }
}
// ============================ Fin du programme ============================ //
