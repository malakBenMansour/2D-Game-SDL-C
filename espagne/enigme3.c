#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "enigme3.h"

int enigme3(void)
{

SDL_Surface *screen=NULL; SDL_Surface *enigme3=NULL; SDL_Surface *repo1=NULL; SDL_Surface *repo2=NULL; SDL_Surface *repo3=NULL; 
SDL_Rect pos_enigme,pos1,pos2,pos3;

SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(900,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
if(!screen)
{printf("unabe to set 600x400 video: %s\n",SDL_GetError());}
enigme3= IMG_Load("question 3 espagne.png");
if(!enigme3)
{printf("unable to load enigme1: %s\n" ,SDL_GetError());}

repo1= IMG_Load("Q3 vrai.png");
if(!repo1)
{printf("unable to load : %s\n" ,SDL_GetError());}

repo2= IMG_Load("Q3 faux.png");
if(!repo2)
{printf("unable to load: %s\n" ,SDL_GetError());}

repo3= IMG_Load("Q3 faux 2.png");
if(!repo3)
{printf("unable to load: %s\n" ,SDL_GetError());}


pos_enigme.x=0; 
pos_enigme.y=0; 

pos1.x=180,50; pos1.y=220;
pos2.x=180,50; pos2.y=310;
pos3.x=180,50 ; pos3.y=390;
pos1.h=repo1->h; 
pos1.w=repo1->w;

pos2.h=repo2->h; 
pos2.w=repo2->w;
pos3.h=repo3->h; 
pos3.w=repo3->w;

SDL_BlitSurface(enigme3,NULL,screen,&pos_enigme);
SDL_BlitSurface(repo1,NULL,screen,&pos1);
SDL_BlitSurface(repo2,NULL,screen,&pos2);
SDL_BlitSurface(repo3,NULL,screen,&pos3);
SDL_Flip(screen);
SDL_Event event;
int done=1;

while(done)
{ 
SDL_BlitSurface(enigme3,NULL,screen,&pos_enigme);
SDL_BlitSurface(repo1,NULL,screen,&pos1);
SDL_BlitSurface(repo2,NULL,screen,&pos2);
SDL_BlitSurface(repo3,NULL,screen,&pos3);


  SDL_WaitEvent(&event);
  switch(event.type)
{
  case SDL_KEYDOWN :
  switch(event.key.keysym.sym)
   {
     case SDLK_ESCAPE :
     done=0;
     break;
      case SDLK_a : 
     return 1;
default:
    return 0; 

      }
   break;
   case SDL_MOUSEBUTTONUP :
   switch(event.button.button)
  {
   case SDL_BUTTON_LEFT :
    if (event.button.x>pos1.x && event.button.x<(pos1.x+pos1.w) &&event.button.y>pos1.y &&event.button.y<(pos1.y+pos1.h))
{
 return 1;
}

else 
{
 return 0;
}
break;
}
break;
}
}

SDL_FreeSurface(enigme3);
SDL_FreeSurface(repo1);
SDL_FreeSurface(repo2);
SDL_FreeSurface(repo3);
return 0;
}
