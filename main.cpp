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

#include "Types.h" //utilisation de fichiers h pour avoir les fonctions/procédures dans d'autres fichiers distincs
#include "chauffage.h"
#include "read_write.h"
#include "modeabsenceh.h"
#include "gestionvoletsh.h"
#include "lumiere.h"
#include "modesecuritepresenceh.h"
#include "modesecuritevacanceabsenceh.h"
#include "modevacanceh.h"
#include "modesecuritepresenceh.h"

using namespace conio;      //permet d'utiliser conio
using namespace std;		// permet d'utiliser les flux cin et cout

// ============================ Sous programmes ============================= //

temps calcul_temp(capt_gene capt_generaux) //cette fonction tranforme le temps de heure vers un type jour et heure
{
    temps tempjh;
    tempjh.jour = capt_generaux[7] / 24;
    tempjh.heure = capt_generaux[7] - (24 * tempjh.jour);

    return tempjh;
}
void menu() //procédure affiche le menu principal du programme
// l'instruction setclr(COLOR) permet le changement de couleur
// l'instruction setxy(coordx, coordy) permet de positionner le texte dans la console
// l'instruction clreol() permet de clear la ligne précedemment évoquée dans le setxy
{
    clrscr();
    cout << setxy(45,1) << setclr(LIGHTGRAY) << "Menu principal - Maison Connectee" << endl;
    clreol();
    cout << setxy(2,3) << setclr(GREEN) << "[M]onitoring" << endl;
    clreol();
    cout << setxy(2,5) << setclr(YELLOW) << "[P]arametres" << endl;
    clreol();
    cout << setxy(2,7) << setclr(RED) << "[Q]uitter" << endl;
    clreol();
    cout << setxy(2,10) << setclr(WHITE) << "Votre Choix ?" << endl;
    clreol();
}

void monitoring_act(int page, capt_gene capt_generaux, struct_mode mode, home maison, temps tempjh) //Cette procédure permet
//l'actualisation du menu monitoring
{
    int i;
    clreol();
    cout << setxy(60,29) << setclr(YELLOW) << "Temps : " << tempjh.jour << " jour(s) et " << tempjh.heure << " heures" ;
    if (page == 1) //en fonction de la page active
    {
        cout << setxy(2,7) << setclr(LIGHTGRAY) << "Sonde accelerometre : " << capt_generaux[0] << endl; //correspondance des capteurs
        //dans le fichier read_write.cpp
        cout << setxy(30,7) << setclr(LIGHTGRAY) << "Capteur de gaz : " << capt_generaux[1] <<endl;
        clreol();
        cout << setxy(30,8) << setclr(LIGHTGRAY) << "Capteur de poussiere : " << capt_generaux[2] << endl;
        clreol();
        cout << setxy(30,9) << setclr(LIGHTGRAY) << "Capteur de moisissure : " << capt_generaux[3] << endl;
        clreol();
        cout << setxy(30,10) << setclr(LIGHTGRAY) << "Capteur d'humidite : " << capt_generaux[4] << endl;
        clreol();
        cout << setxy(30,11) << setclr(LIGHTGRAY) << "Capteur de lumunositee exterieure : " << capt_generaux[6] << endl;
        clreol();
        cout << setxy(30,12) << setclr(LIGHTGRAY) << "Buzzer : " << capt_generaux[8] << endl;
        clreol();
        cout << setxy(30,13) << setclr(LIGHTGRAY) << "Ventillateur: " << capt_generaux[9] << endl;
        clreol();
        for (i = 1; i < 60; i++)   //horizontal
        {
            cout << setxy(i,4) << setclr(LIGHTGRAY) << "-" << endl;
            cout << setxy(i,23) << setclr(LIGHTGRAY) << "-" << endl;
        }
        for (i = 4; i < 23; i++)   //vertical
        {
            cout << setxy(29,i) << setclr(LIGHTGRAY) << "|" << endl;
        }

    }
    else if (page == 2)
    {
        clreol();
        cout << setxy(2,5) << setclr(LIGHTGRAY) << "Capteur lumunositee : " << maison[0].capt_lum << endl;
        clreol();
        cout << setxy(2,7) << setclr(LIGHTGRAY) << "Capteur infrarouge : " << maison[0].capt_ir << endl;
        clreol();
        cout << setxy(2,8) << setclr(LIGHTGRAY) << "Capteur bouton : " << maison[0].capt_button << endl;
        clreol();
        cout << setxy(2,9) << setclr(LIGHTGRAY) << "Actionneur temperature chauffage : " << maison[0].act_temp << endl;
        clreol();
        cout << setxy(2,10) << setclr(LIGHTGRAY) << "Actionneur volet : " << maison[0].act_volet << endl;
        clreol();
        cout << setxy(2,11) << setclr(LIGHTGRAY) << "Actionneur led : " << maison[0].act_led << endl;
        clreol();
        for (i = 1; i < 60; i++)   //horizontal
        {
            cout << setxy(i,4) << setclr(LIGHTGRAY) << "-" << endl;
            cout << setxy(i,23) << setclr(LIGHTGRAY) << "-" << endl;
        }
        for (i = 5; i < 23; i++)   //vertical
        {
            cout << setxy(59,i) << setclr(LIGHTGRAY) << "|" << endl;
        }
    }
    else if (page == 3)
    {
        clreol();
        cout << setxy(2,5) << setclr(LIGHTGRAY) << "Capteur lumunositee : " << maison[1].capt_lum << endl;
        clreol();
        cout << setxy(2,7) << setclr(LIGHTGRAY) << "Capteur infrarouge : " << maison[1].capt_ir << endl;
        clreol();
        cout << setxy(2,8) << setclr(LIGHTGRAY) << "Capteur bouton : " << maison[1].capt_button << endl;
        clreol();
        cout << setxy(2,9) << setclr(LIGHTGRAY) << "Actionneur temperature chauffage : " << maison[1].act_temp << endl;
        clreol();
        cout << setxy(2,10) << setclr(LIGHTGRAY) << "Actionneur volet : " << maison[1].act_volet << endl;
        clreol();
        cout << setxy(2,11) << setclr(LIGHTGRAY) << "Actionneur led : " << maison[1].act_led << endl;
        clreol();
        for (i = 1; i < 60; i++)   //horizontal
        {
            cout << setxy(i,4) << setclr(LIGHTGRAY) << "-" << endl;
            cout << setxy(i,23) << setclr(LIGHTGRAY) << "-" << endl;
        }
        for (i = 5; i < 23; i++)   //vertical
        {
            cout << setxy(59,i) << setclr(LIGHTGRAY) << "|" << endl;
        }
    }
    else if (page == 4)
    {
        clreol();
        cout << setxy(2,5) << setclr(LIGHTGRAY) << "Capteur lumunositee : " << maison[2].capt_lum << endl;
        clreol();
        cout << setxy(2,7) << setclr(LIGHTGRAY) << "Capteur infrarouge : " << maison[2].capt_ir << endl;
        clreol();
        cout << setxy(2,8) << setclr(LIGHTGRAY) << "Capteur bouton : " << maison[2].capt_button << endl;
        clreol();
        cout << setxy(2,9) << setclr(LIGHTGRAY) << "Actionneur temperature chauffage : " << maison[2].act_temp << endl;
        clreol();
        cout << setxy(2,10) << setclr(LIGHTGRAY) << "Actionneur volet : " << maison[2].act_volet << endl;
        clreol();
        cout << setxy(2,11) << setclr(LIGHTGRAY) << "Actionneur led : " << maison[2].act_led << endl;
        clreol();
        for (i = 1; i < 60; i++)   //horizontal
        {
            cout << setxy(i,4) << setclr(LIGHTGRAY) << "-" << endl;
            cout << setxy(i,23) << setclr(LIGHTGRAY) << "-" << endl;
        }
        for (i = 5; i < 23; i++)   //vertical
        {
            cout << setxy(59,i) << setclr(LIGHTGRAY) << "|" << endl;
        }
    }
    else if (page == 5)
    {
        clreol();
        cout << setxy(2,5) << setclr(LIGHTGRAY) << "Capteur lumunositee : " << maison[3].capt_lum << endl;
        clreol();
        cout << setxy(2,7) << setclr(LIGHTGRAY) << "Capteur infrarouge : " << maison[3].capt_ir << endl;
        clreol();
        cout << setxy(2,8) << setclr(LIGHTGRAY) << "Capteur bouton : " << maison[3].capt_button << endl;
        clreol();
        cout << setxy(2,9) << setclr(LIGHTGRAY) << "Actionneur temperature chauffage : " << maison[3].act_temp << endl;
        clreol();
        cout << setxy(2,10) << setclr(LIGHTGRAY) << "Actionneur volet : " << maison[3].act_volet << endl;
        clreol();
        cout << setxy(2,11) << setclr(LIGHTGRAY) << "Actionneur led : " << maison[3].act_led << endl;
        clreol();
        for (i = 1; i < 60; i++)   //horizontal
        {
            cout << setxy(i,4) << setclr(LIGHTGRAY) << "-" << endl;
            cout << setxy(i,23) << setclr(LIGHTGRAY) << "-" << endl;
        }
        for (i = 5; i < 23; i++)   //vertical
        {
            cout << setxy(59,i) << setclr(LIGHTGRAY) << "|" << endl;
        }
    }
    else if (page == 6)
    {
        clreol();
        cout << setxy(2,5) << setclr(LIGHTGRAY) << "Capteur lumunositee : " << maison[4].capt_lum << endl;
        clreol();
        cout << setxy(2,7) << setclr(LIGHTGRAY) << "Capteur infrarouge : " << maison[4].capt_ir << endl;
        clreol();
        cout << setxy(2,8) << setclr(LIGHTGRAY) << "Capteur bouton : " << maison[4].capt_button << endl;
        clreol();
        cout << setxy(2,9) << setclr(LIGHTGRAY) << "Actionneur temperature chauffage : " << maison[4].act_temp << endl;
        clreol();
        cout << setxy(2,10) << setclr(LIGHTGRAY) << "Actionneur volet : " << maison[4].act_volet << endl;
        clreol();
        cout << setxy(2,11) << setclr(LIGHTGRAY) << "Actionneur led : " << maison[4].act_led << endl;
        clreol();
        for (i = 1; i < 60; i++)   //horizontal
        {
            cout << setxy(i,4) << setclr(LIGHTGRAY) << "-" << endl;
            cout << setxy(i,23) << setclr(LIGHTGRAY) << "-" << endl;
        }
        for (i = 5; i < 23; i++)   //vertical
        {
            cout << setxy(59,i) << setclr(LIGHTGRAY) << "|" << endl;
        }
    }
    else if (page == 7) //affichage des modes
    {
        clreol();
        cout << setxy(2,5) << setclr(LIGHTGRAY) << "Mode manuel = " << mode.mode_manuel << endl;
        clreol();
        cout << setxy(2,8) << setclr(LIGHTGRAY) << "Mode vacance = " << mode.mode_vacance << endl;
        clreol();
        cout << setxy(2,9) << setclr(LIGHTGRAY) << "Mode absence  = " << mode.mode_absence << endl;
        clreol();
        cout << setxy(2,10) << setclr(LIGHTGRAY) << "Mode securite  = " << mode.mode_securite << endl;
        clreol();
        for (i = 1; i < 60; i++)   //horizontal
        {
            cout << setxy(i,4) << setclr(LIGHTGRAY) << "-" << endl;
            cout << setxy(i,23) << setclr(LIGHTGRAY) << "-" << endl;
        }
        for (i = 5; i < 23; i++)   //vertical
        {
            cout << setxy(59,i) << setclr(LIGHTGRAY) << "|" << endl;
        }
    }
}

void monitoring(int page, capt_gene capt_generaux, struct_mode mode, home maison) //cette procédure affiche le texte qui n'a pas besoin
//d'être actualiser dans l'interface monitoring
{
    int i;
    clrscr();
    if (page == 1)
    {
        clreol();
        cout << setxy(40,1) << setclr(LIGHTGRAY) << "Monitoring - Maison Connectee - Page n 1" << endl;
        clreol();
        cout << setxy(40,3) << setclr(LIGHTGRAY) << "Capteur de securite generaux" << endl;
        clreol();
        cout << setxy(2,6) << setclr(LIGHTGRAY) << "Detecteurs de presence" << endl;
        cout << setxy(30,5) << setclr(LIGHTGRAY) << "Detecteurs securite" << endl;
        cout << setxy(2,24) << setclr(BLUE) << "Vers la page [2]" << endl;
        cout << setxy(2,25) << setclr(BLUE) << "Ou tappez la page que vous voulez au pave numerique... (1 a 8)" << endl;
        cout << setxy(2,26) << setclr(RED) << "/! Actualisation par changement de page /!" << endl;
        cout << setxy(2,27) << setclr(YELLOW) << "[P]aramtres" << endl;
        cout << setxy(2,28) << setclr(GREEN) << "[R]etour menu" << endl;
        cout << setxy(2,29) << setclr(RED) << "[Q]uitter le programme" << endl;
    }
    else if (page == 2)
    {
        clreol();
        cout << setxy(40,1) << setclr(LIGHTGRAY) << "Monitoring - Maison Connectee - Page n 2" << endl;
        clreol();
        cout << setxy(40,3) << setclr(LIGHTGRAY) << "Salle a manger" << endl;
        clreol();

        cout << setxy(2,24) << setclr(BLUE) << "Vers la page [1]" << endl;
        cout << setxy(2,25) << setclr(BLUE) << "Vers la page [3]" << endl;
        cout << setxy(2,26) << setclr(BLUE) << "Ou tappez la page que vous voulez au pave numerique... (1 a 8)" << endl;
        cout << setxy(2,27) << setclr(RED) << "/! Actualisation par changement de page /!" << endl;
        cout << setxy(2,28) << setclr(YELLOW) << "[P]aramtres" << endl;
        cout << setxy(2,29) << setclr(GREEN) << "[R]etour menu" << endl;
        cout << setxy(2,30) << setclr(RED) << "[Q]uitter le programme" << endl;
    }
    else if (page == 3)
    {
        clreol();
        cout << setxy(40,1)<< setclr(LIGHTGRAY) << "Monitoring - Maison Connectee - Page n 3" << endl;
        clreol();
        cout << setxy(40,3) << setclr(LIGHTGRAY) << "Cuisine" << endl;
        clreol();
        cout << setxy(2,24) << setclr(BLUE) << "Vers la page [2]" << endl;
        cout << setxy(2,25) << setclr(BLUE) << "Vers la page [4]" << endl;
        cout << setxy(2,26) << setclr(BLUE) << "Ou tappez la page que vous voulez au pave numerique... (1 a 8)" << endl;
        cout << setxy(2,27) << setclr(RED) << "/! Actualisation par changement de page /!" << endl;
        cout << setxy(2,28) << setclr(YELLOW) << "[P]aramtres" << endl;
        cout << setxy(2,29) << setclr(GREEN) << "[R]etour menu" << endl;
        cout << setxy(2,30) << setclr(RED) << "[Q]uitter le programme" << endl;
    }
    else if (page == 4)
    {
        clreol();
        cout << setxy(40,1) << setclr(LIGHTGRAY) << "Monitoring - Maison Connectee - Page n 4" << endl;
        clreol();
        cout << setxy(40,3) << setclr(LIGHTGRAY) << "Chambre" << endl;
        clreol();
        cout << setxy(2,24) << setclr(BLUE) << "Vers la page [3]" << endl;
        cout << setxy(2,25) << setclr(BLUE) << "Vers la page [5]" << endl;
        cout << setxy(2,26) << setclr(BLUE) << "Ou tappez la page que vous voulez au pave numerique... (1 a 8)" << endl;
        cout << setxy(2,27) << setclr(RED) << "/! Actualisation par changement de page /!" << endl;
        cout << setxy(2,28) << setclr(YELLOW) << "[P]aramtres" << endl;
        cout << setxy(2,29) << setclr(GREEN) << "[R]etour menu" << endl;
        cout << setxy(2,30) << setclr(RED) << "[Q]uitter le programme" << endl;
    }
    else if (page == 5)
    {
        clreol();
        cout << setxy(40,1) << setclr(LIGHTGRAY) << "Monitoring - Maison Connectee - Page n 5" << endl;
        clreol();
        cout << setxy(40,3) << setclr(LIGHTGRAY) << "Salle de bain" << endl;
        clreol();
        cout << setxy(2,24) << setclr(BLUE) << "Vers la page [4]" << endl;
        cout << setxy(2,25) << setclr(BLUE) << "Vers la page [6]" << endl;
        cout << setxy(2,26) << setclr(BLUE) << "Ou tappez la page que vous voulez au pave numerique... (1 a 8)" << endl;
        cout << setxy(2,27) << setclr(RED) << "/! Actualisation par changement de page /!" << endl;
        cout << setxy(2,28) << setclr(YELLOW) << "[P]aramtres" << endl;
        cout << setxy(2,29) << setclr(GREEN) << "[R]etour menu" << endl;
        cout << setxy(2,30) << setclr(RED) << "[Q]uitter le programme" << endl;
    }
    else if (page == 6)
    {
        clreol();
        cout << setxy(40,1) << setclr(LIGHTGRAY) << "Monitoring - Maison Connectee - Page n 6" << endl;
        clreol();
        cout << setxy(40,3) << setclr(LIGHTGRAY) << "Garage" << endl;
        clreol();
        cout << setxy(2,24) << setclr(BLUE) << "Vers la page [5]" << endl;
        cout << setxy(2,25) << setclr(BLUE) << "Vers la page [7]" << endl;
        cout << setxy(2,26) << setclr(BLUE) << "Ou tappez la page que vous voulez au pave numerique... (1 a 8)" << endl;
        cout << setxy(2,27) << setclr(RED) << "/! Actualisation par changement de page /!" << endl;
        cout << setxy(2,28) << setclr(YELLOW) << "[P]aramtres" << endl;
        cout << setxy(2,29) << setclr(GREEN) << "[R]etour menu" << endl;
        cout << setxy(2,30) << setclr(RED) << "[Q]uitter le programme" << endl;
    }
    else if (page == 7)
    {
        clreol();
        cout << setxy(40,1) << setclr(LIGHTGRAY) << "Monitoring - Maison Connectee - Page n 7" << endl;
        clreol();
        cout << setxy(40,3) << setclr(LIGHTGRAY) << "Etat des modes" << endl;
        cout << setxy(2,24) << setclr(BLUE) << "Vers la page [6]" << endl;
        cout << setxy(2,25) << setclr(BLUE) << "Vers la page [8]" << endl;
        cout << setxy(2,26) << setclr(BLUE) << "Ou tappez la page que vous voulez au pave numerique... (1 a 8)" << endl;
        cout << setxy(2,27) << setclr(RED) << "/! Actualisation par changement de page /!" << endl;
        cout << setxy(2,28) << setclr(YELLOW) << "[P]aramtres" << endl;
        cout << setxy(2,29) << setclr(GREEN) << "[R]etour menu" << endl;
        cout << setxy(2,30) << setclr(RED) << "[Q]uitter le programme" << endl;
    }
}

void parametre(struct_mode mode) //cette procédure affiche les parametres
{
    cout << setxy(40,1) << setclr(LIGHTGRAY) << "Parametres - Maison Connectee" << endl;
    clreol();
    cout << setxy(40,3) << setclr(LIGHTGRAY) << "Modes" << endl;
    cout << setxy(2,5) << setclr(LIGHTGRAY) << "Mode manuel : " << mode.mode_manuel << endl;
    cout << setxy(2,6) << setclr(LIGHTGRAY) << "Mode nuit : " << mode.mode_nuit << endl;
    cout << setxy(2,7) << setclr(LIGHTGRAY) << "Mode jour : " << mode.mode_jour << endl;
    cout << setxy(2,8) << setclr(LIGHTGRAY) << "Mode absence : " << mode.mode_absence << endl;
    cout << setxy(2,9) << setclr(LIGHTGRAY) << "Mode securite : " << mode.mode_securite << endl;
    cout << setxy(2,10) << setclr(LIGHTGRAY) << "Mode vacance : " << mode.mode_vacance << endl;
    cout << setxy(30,5) << setclr(LIGHTGRAY) << "[A] pour changer l'etat" << endl;
    cout << setxy(30,6) << setclr(LIGHTGRAY) << "[B] pour changer l'etat" << endl;
    cout << setxy(30,7) << setclr(LIGHTGRAY) << "[C] pour changer l'etat" << endl;
    cout << setxy(30,8) << setclr(LIGHTGRAY) << "[D] pour changer l'etat" << endl;
    cout << setxy(30,9) << setclr(LIGHTGRAY) << "[E] pour changer l'etat" << endl;
    cout << setxy(30,10) << setclr(LIGHTGRAY) << "[F] pour changer l'etat" << endl;
    cout << setxy(2,11) << setclr(RED) << "/! Vous devez changer l'etat d'un autre mode" << endl;
    cout << setxy(2,12) << setclr(RED) << "    avant de changer de nouveau l'etat d'un meme mode /! " << endl;

    cout << setxy(2,26) << setclr(YELLOW) << "[M]Monitoring" << endl;
    cout << setxy(2,27) << setclr(GREEN) << "[R]etour menu" << endl;
    cout << setxy(2,28) << setclr(RED) << "[Q]uitter le programme" << endl;
    clreol();
}

// ========================== Programme principal =========================== //
int main(void)
{
    setlocale(LC_ALL, "french");
    // Declarations locale

    int temp, page, i, temp_absence;
    bool menuv, monitoringv, retourmenuv, parametrev, page1v, page2v, page3v;
    bool page4v, page5v, page6v, page7v, avar, bvar, cvar, dvar, evar, fvar;
    char choix;
    home maison;
    struct_mode mode;
    capt_gene capt_generaux;
    temps tempjh;

    // Actions

    //on définie la valeur les variables pour éviter les problèmes
    menuv = true;
    monitoringv = false;
    page1v = true;
    page2v = false;
    page3v = false;
    page4v = false;
    page5v = false;
    page6v = false;
    page7v = false;
    page = 1;
    retourmenuv = false;
    parametrev = false;
    avar = false;
    bvar = false;
    cvar = false;
    dvar = false;
    evar = false;
    fvar = false;

    mode.mode_manuel = 0;
    mode.mode_nuit = 0;
    mode.mode_jour = 0;
    mode.mode_vacance = 0;
    mode.mode_absence = 0;
    mode.mode_securite = 0;
    mode.mode_securite_vacance_absence;
    capt_generaux[7] = 0;
    tempjh.heure = 0;
    tempjh.jour = 0;
    temp_absence = 0;

    for (i = 0; i < 5; i++)
    {
        maison[i].act_temp = 20;
    }

    menu(); //appel de menu
    do //boucle qui tourne pour l'actualisation et l'obtention des données
    {
        // Base de temps
        Sleep(800);
        // Détection appui touche
        if (_kbhit())
        {
            // Lecture d'un caractère au clavier
            choix = toupper(_getch());
            clearkeybuf();
        }
        switch(choix)
        {
        case 'M':
            if (menuv == true || parametrev == true)   // Permet d'eviter le scintillement du monitoring
            {
                clrscr();
                menuv = false;
            }
            if (monitoringv == false)
            {
                monitoringv = true;
                page1v = true;
                page2v = false;
                page3v = false;
                page4v = false;
                page5v = false;
                page6v = false;
                page7v = false;
                retourmenuv = false;
                parametrev = false;
                page = 1;

                monitoring(page, capt_generaux, mode, maison);
            }
            break;
        case 'R':
            if (retourmenuv == false)
            {cout << "test";
                menuv = true;
                monitoringv = false;
                page1v = false;
                page2v = false;
                page3v = false;
                page4v = false;
                page5v = false;
                page6v = false;
                page7v = false;
                retourmenuv = true;
                parametrev = false;
                page = 1;

                clrscr();
                menu();
            }
            break;
        case '1':
            if (page1v == false && menuv == false && parametrev == false)
            {
                menuv = false;
                monitoringv = true;
                page1v = true;
                page2v = false;
                page3v = false;
                page4v = false;
                page5v = false;
                page6v = false;
                page7v = false;
                retourmenuv = false;
                parametrev = false;
                page = 1;

                clrscr();
                monitoring(page, capt_generaux, mode, maison);
            }
            break;
        case '2':
            if (page2v == false && menuv == false && parametrev == false)
            {
                menuv = false;
                monitoringv = true;
                page1v = false;
                page2v = true;
                page3v = false;
                page4v = false;
                page5v = false;
                page6v = false;
                page7v = false;
                retourmenuv = false;
                parametrev = false;
                page = 2;

				clrscr();
                monitoring(page, capt_generaux, mode, maison);
            }
            break;
        case '3':
            if (page3v == false && menuv == false && parametrev == false)
            {
                menuv = false;
                monitoringv = true;
                page1v = false;
                page2v = false;
                page3v = true;
                page4v = false;
                page5v = false;
                page6v = false;
                page7v = false;;
                retourmenuv = false;
                parametrev = false;
                page = 3;

				clrscr();
                monitoring(page, capt_generaux, mode, maison);
            }
            break;
        case '4':
            if (page4v == false && menuv == false && parametrev == false)
            {
                menuv = false;
                monitoringv = true;
                page1v = false;
                page2v = false;
                page3v = false;
                page4v = true;
                page5v = false;
                page6v = false;
                page7v = false;
                retourmenuv = false;
                parametrev = false;
                page = 4;

				clrscr();
                monitoring(page, capt_generaux, mode, maison);
            }
            break;
        case '5':
            if (page5v == false && menuv == false && parametrev == false)
            {
                menuv = false;
                monitoringv = true;
                page1v = false;
                page2v = false;
                page3v = false;
                page4v = false;
                page5v = true;
                page6v = false;
                page7v = false;
                retourmenuv = false;
                parametrev = false;
                page = 5;

				clrscr();
                monitoring(page, capt_generaux, mode, maison);
            }
            break;
        case '6':
            if (page6v == false && menuv == false && parametrev == false)
            {
                menuv = false;
                monitoringv = true;
                page1v = false;
                page2v = false;
                page3v = false;
                page4v = false;
                page5v = false;
                page6v = true;
                page7v = false;
                retourmenuv = false;
                parametrev = false;
                page = 6;

				clrscr();
                monitoring(page, capt_generaux, mode, maison);
            }
            break;
        case '7':
            if (page7v == false && menuv == false && parametrev == false)
            {
                menuv = false;
                monitoringv = true;
                page1v = false;
                page2v = false;
                page3v = false;
                page4v = false;
                page5v = false;
                page6v = false;
                page7v = true;
                retourmenuv = false;
                parametrev = false;
                page = 7;

				clrscr();
                monitoring(page, capt_generaux, mode, maison);
            }
            break;
        case 'P':
            if (parametrev == false)   // Permet d'eviter le scintillement du monitoring
            {
                clrscr();
                menuv = false;
                monitoringv = false;
                page1v = false;
                page2v = false;
                page3v = false;
                page4v = false;
                page5v = false;
                page6v = false;
                page7v = false;
                retourmenuv = false;
                parametrev = true;;

				clrscr();
                parametre(mode);
            }

            break;
        case 'A':
            if (parametrev == true && avar == false)
            {
                mode.mode_manuel = !mode.mode_manuel;
                parametre(mode);
                avar = true;
                bvar = false;
                cvar = false;
                dvar = false;
                evar = false;
                fvar = false;
            }
            break;
        case 'B':
            if (parametrev == true && bvar == false && mode.mode_jour == 0)
            {
                mode.mode_nuit = !mode.mode_nuit;
                parametre(mode);
                avar = false;
                bvar = true;
                cvar = false;
                dvar = false;
                evar = false;
                fvar = false;
            }
            break;
        case 'C':
            if (parametrev == true && cvar == false && mode.mode_nuit == 0)
            {
                mode.mode_jour = !mode.mode_jour;
                parametre(mode);
                avar = false;
                bvar = false;
                cvar = true;
                dvar = false;
                evar = false;
                fvar = false;
            }
            break;
        case 'D':
            if (parametrev == true && dvar == false)
            {
                mode.mode_absence = !mode.mode_absence;
                parametre(mode);
                avar = false;
                bvar = false;
                cvar = false;
                dvar = true;
                evar = false;
                fvar = false;
            }
            break;
        case 'E':
            if (parametrev == true && evar == false)
            {
                mode.mode_securite = !mode.mode_securite;
                clrscr();
                parametre(mode);
                avar = false;
                bvar = false;
                cvar = false;
                dvar = false;
                evar = true;
                fvar = false;
            }
            break;
        case 'F':
            if (parametrev == true && fvar == false)
            {
                mode.mode_vacance = !mode.mode_vacance;
                clrscr();
                parametre(mode);
                avar = false;
                bvar = false;
                cvar = false;
                dvar = false;
                evar = false;
                fvar = true;
            }
            break;
        case 'Q':
            clrscr();
            cout << setclr(RED) << "Fermeture du programme..." << endl;
            cout << setxy(2,5);
            cout << setbk(RED);
            for (i = 0; i < 10; i++)
            {
                Sleep(500);
                cout << '█';
            }
            cout << setbk(BLACK);
            break;
        default:
            cout << setbk(BLACK);
        }

        //appel des procédure / fonctions des différents modes
        capt_read(capt_generaux, maison);
        chauffage(maison, capt_generaux, mode);
        eclairage(maison, capt_generaux, mode);
        fonction_mode_securite(capt_generaux, mode);
        fonction_mode_vacance(mode);
        fonction_mode_securite_vacance_absence(maison, capt_generaux, mode);
        fonction_mode_nuit(maison, capt_generaux, mode);
        fonction_mode_absence(maison, capt_generaux, mode, temp_absence);
        tempjh = calcul_temp(capt_generaux);

        if (monitoringv)
        {
            monitoring_act(page, capt_generaux, mode, maison, tempjh);
        }
    }
    while (choix != 'Q');

// retour au systeme d'exploitattion
    return 0;
}
// ============================ Fin du programme ============================ //
