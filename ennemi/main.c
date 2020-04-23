#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <math.h>
#include"ennemi.h"

int main()
{

int min=600, max = 800,done=0;
SDL_Event event;
ENTITE_SECONDAIRE entite;

SDL_Surface *ecran=NULL;
SDL_Surface *image=NULL;
SDL_Rect positionecran;

if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL:%s\n",SDL_GetError()); 
return EXIT_FAILURE ;
return EXIT_SUCCESS ;
} 

ecran=SDL_SetVideoMode(1920,680,32,SDL_SWSURFACE|SDL_DOUBLEBUF); 

if(ecran==NULL)
{
printf("Unable to set video mode:%s",SDL_GetError()); 
return 1 ; 
}

image=IMG_Load("1.png"); 
if(image == NULL)
{
printf("Unable to load png:%s \n",SDL_GetError()); 
return 1; 
}

positionecran.x=0;
positionecran.y=0;
positionecran.w=image->w; 
positionecran.h=image->h;


intialiser_entite(&entite);

while(done)
{
SDL_BlitSurface(image,&positionecran,ecran,NULL); 
SDL_PollEvent(&event);

deplacement_aleatoire(&entite,min,max,positionecran);

afficherennemi(&entite,ecran);


SDL_Flip(ecran);
}

SDL_FreeSurface(ecran);

    
    SDL_FreeSurface(image);


  SDL_Quit();

    
    return 0;
}
