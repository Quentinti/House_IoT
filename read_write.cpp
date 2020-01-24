// ===================== Liste des fichiers d'en-tete ======================= //
#include <iostream>
#include <clocale>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <constream>
#include <locale>
#include <sstream>
#include <string>
#include <iostream>

#include "Types.h"
#include "iotxx.h"

using namespace iot;

using namespace conio;      //permet d'utiliser conio
using namespace std;		// permet d'utiliser les flux cin et cout

// ============================ Sous programmes ============================= //

void capt_read(capt_gene & capt_generaux, home & maison)
{
    int retour;

    retour = lire_capteur("accelerometre", capt_generaux[0]);
    retour = lire_capteur("capteur_gaz", capt_generaux[1]);
    retour = lire_capteur("detecteur_poussiere", capt_generaux[2]);
    retour = lire_capteur("detecteur_moisissure", capt_generaux[3]);
    retour = lire_capteur("detecteur_humidite", capt_generaux[4]);
    capt_generaux[5] = 20; //temperature par defaut de toute la maison
    retour = lire_capteur("luminosite_ext", capt_generaux[6]); //lumunosite exterieure
    retour = lire_capteur("temps", capt_generaux[7]);
    retour = lire_capteur("tempsvacance", capt_generaux[10]); //temp vacance voulue par l'utilisateur

    retour = lire_capteur("thermometre_1", maison[0].capt_temp);
    retour = lire_capteur("thermometre_2", maison[1].capt_temp);
    retour = lire_capteur("thermometre_3", maison[2].capt_temp);
    retour = lire_capteur("thermometre_4", maison[3].capt_temp);
    retour = lire_capteur("thermometre_5", maison[4].capt_temp);

    retour = lire_capteur("luminosite1", maison[0].capt_lum);
    retour = lire_capteur("luminosite2", maison[1].capt_lum);
    retour = lire_capteur("luminosite3", maison[2].capt_lum);
    retour = lire_capteur("luminosite4", maison[3].capt_lum);
    retour = lire_capteur("luminosite5", maison[4].capt_lum);

    retour = lire_capteur("detecteur_presence1", maison[0].capt_ir);
    retour = lire_capteur("detecteur_presence2", maison[1].capt_ir);
    retour = lire_capteur("detecteur_presence3", maison[2].capt_ir);
    retour = lire_capteur("detecteur_presence4", maison[3].capt_ir);
    retour = lire_capteur("detecteur_presence5", maison[4].capt_ir);

    retour = lire_capteur("bouton1", maison[0].capt_button);
    retour = lire_capteur("bouton2", maison[1].capt_button);
    retour = lire_capteur("bouton3", maison[2].capt_button);
    retour = lire_capteur("bouton4", maison[3].capt_button);
    retour = lire_capteur("bouton5", maison[4].capt_button);

    retour = lire_capteur("boutonplus1", maison[0].capt_buttonplus);
    retour = lire_capteur("boutonplus2", maison[1].capt_buttonplus);
    retour = lire_capteur("boutonplus3", maison[2].capt_buttonplus);
    retour = lire_capteur("boutonplus4", maison[3].capt_buttonplus);
    retour = lire_capteur("boutonplus5", maison[4].capt_buttonplus);

    retour = lire_capteur("boutonmoins1", maison[0].capt_buttonmoins);
    retour = lire_capteur("boutonmoins2", maison[1].capt_buttonmoins);
    retour = lire_capteur("boutonmoins3", maison[2].capt_buttonmoins);
    retour = lire_capteur("boutonmoins4", maison[3].capt_buttonmoins);
    retour = lire_capteur("boutonmoins5", maison[4].capt_buttonmoins);
}

void capt_write(t_chaine actionneur, t_chaine action)
{
    int retour;
    retour = commander_actionneur(actionneur , action);
}
