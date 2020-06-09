/**

* @file  main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 15, 2019
*
* Testing program for background scrollilng
*
*/

#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include"fonct.h"

int main( int argc, char* args[] ){
SDL_Surface *screen = NULL;

int done=1;

//Start SDL
   
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL:%s\n",SDL_GetError()); 
return EXIT_FAILURE ;
return EXIT_SUCCESS ;
} 


 //Set up screen
    screen = SDL_SetVideoMode(1700,400,32, SDL_SWSURFACE | SDL_DOUBLEBUF);
     if(screen == NULL)
      {
        printf("Unable to set video mode: %s",SDL_GetError());
        return 1;
      }






while(done)
{
map_initial();


}

    SDL_FreeSurface(screen);
   

SDL_Quit();
return 0; 
}
