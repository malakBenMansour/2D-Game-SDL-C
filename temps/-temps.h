#ifndef temps_H_
#define temps_H_




typedef struct temps
{
    int score_courant;
    SDL_Surface *temps_image;
    SDL_Rect temps_position;
    int  tempsinit;
    int tempsactuel;
    int tempsres;
    char tempsrestant[20];
} temps;



void init_temps(temps *t);
void init_temps2(temps *t);
void update_temps(temps *t);
void augmenter_vie(vie *viee);
void afficher_temps(temps t, SDL_Surface *ecran);
void free_temps(temps t);
void generer_temps(temps *t, SDL_Surface *ecran);
