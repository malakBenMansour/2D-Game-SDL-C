#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "scorevie.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


void update_score2(score *scoree)
{
    (scoree->score_courant = scoree->score_courant + 2);
}

void update_score(score *scoree)
{
    (scoree->score_courant = scoree->score_courant + 1);
}

void update_score3(score *scoree)
{
    (scoree->score_courant = scoree->score_courant + 100);

}

void update_temps(temps *t)
{
    (t->tempsres = 100000000 - (SDL_GetTicks() - t->tempsinit));

}


void augmenter_vie(vie *viee)
{
    viee->vie_restante = viee->vie_restante + 1;
}



void afficher_vie_et_score(score s, vie v, SDL_Surface *ecran)
{

    SDL_BlitSurface(v.vie_image, NULL, ecran, &(v.vie_position));
    SDL_BlitSurface(s.score_image, NULL, ecran, &(s.score_position));

}

void afficher_temps(temps t, SDL_Surface *ecran)
{

    SDL_BlitSurface(t.temps_image, NULL, ecran, &(t.temps_position));


}
void free_vie_et_score(score scoree, vie viee)
{
    SDL_FreeSurface(viee.vie_image);
    SDL_FreeSurface(scoree.score_image);


}
void free_temps(temps t)
{
    SDL_FreeSurface(t.temps_image);



}

void initscore_et_vie1(score *s, vie *v)
{




    v->vie_restante = 6;
    v->vie_position.x = 0;
    v->vie_position.y = 30;
    s->score_courant = 0;
    s->score_position.x = 0;
    s->score_position.y = 0;

    TTF_Init();
    TTF_Font *police = NULL ;
    SDL_Color noire = {0, 0, 0};
    police = TTF_OpenFont("Ubuntu-Title.ttf", 20);

    sprintf(v->vi, "vie :%d", v->vie_restante);
    v->vie_image = TTF_RenderText_Blended(police, v->vi, noire);


    sprintf(s->sco, "score  : %d", s->score_courant);
    s->score_image = TTF_RenderText_Blended(police, s->sco, noire);
    TTF_CloseFont(police);
    TTF_Quit();
}


/*************************************************************************************************************************
*********************************************************************************************************/

void initscore_et_vie2(score *s, vie *v)
{

    v->vie_restante = 3;
    v->vie_position.x = 0;
    v->vie_position.y = 420;
    s->score_courant = 0;
    s->score_position.x = 0;
    s->score_position.y = 390;

    TTF_Init();
    TTF_Font *police = NULL ;
    SDL_Color noire = {0, 0, 0};
    police = TTF_OpenFont("Ubuntu-Title.ttf", 20);
    sprintf(v->vi, "vie :%d", v->vie_restante);
    v->vie_image = TTF_RenderText_Blended(police, v->vi, noire);


    sprintf(s->sco, "score  : %d", s->score_courant);
    s->score_image = TTF_RenderText_Blended(police, s->sco, noire);
    TTF_CloseFont(police);
    TTF_Quit();
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


void generer_score_vie(score *scoree, vie *viee, SDL_Surface *ecran)
{

    TTF_Init();
    TTF_Font *police = NULL ;
    SDL_Color noire = {0, 0, 0};
    police = TTF_OpenFont("Ubuntu-Title.ttf", 20);

    sprintf(viee->vi, "vie :%d", viee->vie_restante);

    viee->vie_image = TTF_RenderText_Blended(police, viee->vi, noire);

    sprintf(scoree->sco, "score  : %d", scoree->score_courant);
    scoree->score_image = TTF_RenderText_Blended(police, scoree->sco, noire);
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


