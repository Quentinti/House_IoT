#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

struct temps
{
    int jour;
    int heure;
};

struct rooms
{
    float capt_lum;
    float capt_temp;
    float capt_ir;
    float capt_button;
    float capt_buttonplus;
    float capt_buttonmoins;
    float act_temp;
    float act_volet;
    float act_led;
};

struct struct_mode
{
    bool mode_manuel;
    bool mode_nuit;
    bool mode_jour;
    bool mode_vacance;
    bool mode_absence;
    bool mode_securite;
    bool mode_securite_vacance_absence;
};

typedef rooms home[5];

typedef float capt_gene[11];

typedef char t_chaine[30];

#endif // TYPES_H_INCLUDED
