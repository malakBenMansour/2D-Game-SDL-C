#pragma once
#include "JEU.h"
#include"fonctiony.h"
typedef struct save 
{
	SDL_Rect posperso; 
	SDL_Rect posennemi; 
	int temps; 
	int score; 
	int vies; 
	int direction_ennemi;
}save; 

void update_save(save *s, acteur p, object e,int temps);
void enregistrer (save s,char nomfichier[]);

void recuperer (char nomfichier[],save *s);
void remplir_variables(save s, acteur *p, object *e,int *temps);

void verification_recuperer(acteur p, object e,int temps);//a ne pas mettre dans le programme principal du jeu
void verification_enregistrer(save s);//a ne pas mettre dans le programme principal du jeu
