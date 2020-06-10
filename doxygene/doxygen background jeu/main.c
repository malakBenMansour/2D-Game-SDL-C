/*
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date June 05, 2020
*
* Testing program for background 
*
*/

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "options.h"
#include "animation.h"
#include "defs.h"
#include "jouer.h"


int main ()
{
    jeu game;

	

    SDL_Surface *screen;
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        fprintf( stderr, "Unable to init SDL" );
        return 1;
    }
    atexit(SDL_Quit);
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_SRCALPHA);
    if ( !screen )
    {
        fprintf(stderr, "Unable to set /n");
        return 1;
    }

    SDL_WM_SetCaption(" esm el jeu", NULL);
    SDL_WM_SetIcon(IMG_Load("./options/map0.jpg"), NULL);
   //animation(screen);
   //load(screen);
   //menu(screen);

    jouer(&game, screen);



    return 0;
}
