/**

* @file  fonct.c

*/

#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include"fonct.h"

/**
* @brief To initialize the map b .
* @param b the map
* @param url the url of the image
* @return Nothing
*/

void map_initial()
{


SDL_Surface *screen = NULL;
SDL_Surface *image = NULL;
SDL_Surface *image2=NULL;
SDL_Rect positionecran;
SDL_Rect positionecran2;
SDL_Event event;

int done=1;

//Set up screen
    screen = SDL_SetVideoMode(1600,400,32, SDL_SWSURFACE | SDL_DOUBLEBUF);
     if(screen == NULL)
      {
        printf("Unable to set video mode: %s",SDL_GetError());
        
      }
     
 image = SDL_LoadBMP("background.bmp");
     if(image == NULL)
       {
         printf("Unable to load bitmap: %s\n",SDL_GetError());
        
       }

positionecran.x=0;
positionecran.y=0;
positionecran.w=image->w; 
positionecran.h=image->h;

SDL_Surface *mini_map=NULL;
SDL_Rect positionecran3;



image2=IMG_Load("detective.png"); 
if(image2 == NULL)
{
printf("Unable to load png:%s \n",SDL_GetError()); 

}

SDL_SetColorKey(image2,SDL_RLEACCEL|SDL_SRCCOLORKEY,SDL_MapRGB(image2->format,255,255,255)); 

positionecran2.x=300; 
positionecran2.y=150; 

positionecran2.w=image2->w; 
positionecran2.h=image2->h; 




mini_map = IMG_Load("background2.jpg");
     if(mini_map == NULL)
       {
         printf("Unable to load bitmap: %s\n",SDL_GetError());
        
       }

positionecran3.x=1250;
positionecran3.y=240;
positionecran3.w=mini_map->w; 
positionecran3.h=mini_map->h;


SDL_Surface *mini_pers=NULL; 
SDL_Rect positionecran4;

mini_pers = IMG_Load("detective2.png");
     if(mini_pers == NULL)
       {
         printf("Unable to load : %s\n",SDL_GetError());
        
       }

positionecran4.x=1250;
positionecran4.y=300;
positionecran4.w=mini_map->w; 
positionecran4.h=mini_map->h;



SDL_SetColorKey(mini_pers,SDL_RLEACCEL|SDL_SRCCOLORKEY,SDL_MapRGB(mini_pers->format,255,255,255)); 



while(done)
{

SDL_BlitSurface(image,&positionecran,screen,NULL); 
SDL_BlitSurface(image2,&positionecran,screen,&positionecran2); 

SDL_BlitSurface(mini_map,&positionecran,screen,&positionecran3); 
SDL_BlitSurface(mini_pers,&positionecran,screen,&positionecran4); 

while(SDL_PollEvent(&event))
    {
         switch(event.type)
         {
            //Si on veut quitter, done=1 suffira
            case SDL_QUIT:
               	done=0;
               	break;
case SDL_KEYDOWN:
            {
               if(event.key.keysym.sym == SDLK_ESCAPE)
               done = 0;
                else if (event.key.keysym.sym == SDLK_LEFT){
                   positionecran2.x -=30;
                   positionecran4.x -=3;}
  else if (event.key.keysym.sym == SDLK_RIGHT){
                   positionecran2.x +=30;
                   positionecran4.x +=3;}
 else if (event.key.keysym.sym == SDLK_UP){
                   positionecran2.y -=30;
                   positionecran4.y -=3;}
 else if (event.key.keysym.sym == SDLK_DOWN){
                   positionecran2.y +=30;
                    positionecran4.y +=3;}
               break;
            }
             
        }
    }




SDL_Flip(screen);
}
}

    



