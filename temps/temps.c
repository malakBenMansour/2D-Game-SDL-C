#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "-temps.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>





void update_temps(temps *t)
{
    (t->tempsres = 100000000 - (SDL_GetTicks() - t->tempsinit));

}



void afficher_temps(temps t, SDL_Surface *ecran)
{

    SDL_BlitSurface(t.temps_image, NULL, ecran, &(t.temps_position));


}






void free_temps(temps t)
{
    SDL_FreeSurface(t.temps_image);



}




void init_temps(temps *t)
{

    t->tempsinit = SDL_GetTicks();
    t->tempsactuel = SDL_GetTicks();
    t->tempsres = 900000;
    t->temps_position.x = 0;
    t->temps_position.y = 60;
    TTF_Init();
    TTF_Font *police = NULL ;
    SDL_Color noire = {0, 0, 0};
    police = TTF_OpenFont("Ubuntu-Title.ttf", 20);
    sprintf(t->tempsrestant, "temps :%d", (t->tempsres));
    t->temps_image = TTF_RenderText_Blended(police, t->tempsrestant, noire);
    TTF_CloseFont(police);
    TTF_Quit();
}

void init_temps2(temps *t)
{

    t->tempsinit = SDL_GetTicks();
    t->tempsactuel = SDL_GetTicks();
    t->tempsres = 900000;
    t->temps_position.x = 0;
    t->temps_position.y = 460;
    TTF_Init();
    TTF_Font *police = NULL ;
    SDL_Color noire = {0, 0, 0};
    police = TTF_OpenFont("Ubuntu-Title.ttf", 20);
    sprintf(t->tempsrestant, "temps :%d", (t->tempsres));
    t->temps_image = TTF_RenderText_Blended(police, t->tempsrestant, noire);
    TTF_CloseFont(police);
    TTF_Quit();
}



void generer_temps(temps *t, SDL_Surface *ecran)
{

    TTF_Init();
    TTF_Font *police = NULL ;
    SDL_Color noire = {0, 0, 0};
    police = TTF_OpenFont("Ubuntu-Title.ttf", 20);

    sprintf(t->tempsrestant, "temps :%d", (t->tempsres));

    t->temps_image = TTF_RenderText_Blended(police, t->tempsrestant, noire);

    TTF_CloseFont(police);
    TTF_Quit();
}

