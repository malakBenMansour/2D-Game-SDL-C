
#ifndef ENNEMI_H
#define ENNEMI_H

typedef struct ENTITE_SECONDAIRE 
{ 
SDL_Surface* enemi[0];
SDL_Rect position;
int direction; //1 : a droite,  0: a gauche

}ENTITE_SECONDAIRE ;

void intialiser_entite(ENTITE_SECONDAIRE *entite);

void afficherennemi(ENTITE_SECONDAIRE *entite ,SDL_Surface *ecran);
void deplacement_aleatoire(ENTITE_SECONDAIRE *e,int min,int max,SDL_Rect positionecran);

#endif
