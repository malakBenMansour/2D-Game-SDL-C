#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <math.h>
#include"ennemi.h"



void intialiser_entite(ENTITE_SECONDAIRE *entite)
{ 
entite->enemi[0]=IMG_Load("2.png");

if(entite->enemi[0]==NULL);
exit(EXIT_FAILURE);
entite->position.x=500;
entite->position.y=600;
entite->direction = 1;
}

 void deplacement_aleatoire(ENTITE_SECONDAIRE *e,int min,int max,SDL_Rect positionecran)
{       
	     
        if ((e->position).x + positionecran.x >= max )
		e->direction = 0;
	if  ((e->position).x+ positionecran.x <= min )
		e->direction = 1;
	if ( e->direction == 1)
		(e->position).x += 5;
	if (e->direction == 0)
		(e->position).x -= 5;
            

} 

void afficherennemi(ENTITE_SECONDAIRE *entite ,SDL_Surface *ecran)
{  
entite->position.h=50;
entite->position.w=50;

SDL_Delay(20);
SDL_BlitSurface( &entite->enemi[entite->direction],NULL, ecran,&entite->position);


}

