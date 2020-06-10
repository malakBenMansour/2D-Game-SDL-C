#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "defs.h"
#include "background.h"
#include "personnage.h"
#include "jouer.h"
#include "scrolling.h"
#include "scorevie.h"
#include "enigme.h"
#include "collision.h"

int initialiser (jeu *game)
{

    Mix_Music *musique;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    musique = Mix_LoadMUS("./menu/bip.mp3");
    Mix_PlayMusic(musique, -1);
    Mix_AllocateChannels(10);
    Mix_Chunk *mouseEffect = Mix_LoadWAV("./menu/button16.wav");
    Mix_VolumeChunk(mouseEffect, 100);
    Mix_VolumeMusic(MIX_MAX_VOLUME);
    Mix_PauseMusic();
    initBackground(&(game->B1));
    initBackground(&(game->B3));
    init_perso(&(game->p1));
    init_perso2(&(game->p2));
    initscore_et_vie2(&(game->s2), &(game->v2));
    initBackground(&(game->B2));

    initscore_et_vie1(&(game->s1), &(game->v1));
    init_temps(&(game->t1));
    init_temps2(&(game->t2));
    init(&(game->e));
    game->game_over = 0;
    game->time_over = 0;
    game->time_over2 = 0;
    game->i = 5;

    //chargerBackgroundCollision(&(game->m1));
    game->col1.backgroundImg=IMG_Load("maps/map1.png");
    



    init_enigmes(game->tabl,game->tableau);
    
}


void test(jeu *game)
{


    
    if(game->t1.tempsres <= 0)
    {
        game->time_over = 1;
        game->B1.backgroundImg = IMG_Load("./maps/gameover.jpg");

    }
    if(game->t2.tempsres <= 0)
    {
        game->time_over = 2;
        game->B2.backgroundImg = IMG_Load("./maps/gameover.jpg");

    }

    if(game->v1.vie_restante == 0)
    {
        game->B1.backgroundImg = IMG_Load("./maps/gameover.jpg");
     game->p1.position.x=7000;
      game->time_over = 1;

    }

    /*if(game->v2.vie_restante==0)
    	{game->B2.backgroundImg=IMG_Load("./maps/gameover.jpg");}*/
    
    
    if(game->v1.vie_restante == 0  && game->v2.vie_restante == 0)
    {
        game->game_over = 1;
    }
     



}



int load_images(jeu *game)
{


    if(load_perso1(&(game->p1)) == -1)
    {
        fprintf(stderr, "Erreur Chargement personnage\n");
        return(-1);
    }

    if(charger_Background(&(game->B1)) == -1)
    {
        fprintf(stderr, "Erreur Chargement Background \n");
        return(-1);
    }
    if(charger_Background2(&(game->B3)) == -1)
    {
        fprintf(stderr, "Erreur Chargement Background \n");
        return(-1);
    }
    if(charger_Background(&(game->B2)) == -1)
    {
        fprintf(stderr, "Erreur Chargement Background \n");
        return(-1);
    }
    if(load_perso2(&(game->p2)) == -1)
    {
        fprintf(stderr, "Erreur Chargement personnage\n");
        return(-1);
    }

}



void input (int keys_on[], jeu *game)
{
    SDL_Event event;

    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
    while (SDL_PollEvent(&event))
    {

        switch (event.type)
        {

        case SDL_QUIT:
            game->game_over = 1;
            break;
        case SDL_KEYDOWN:
            keys_on[event.key.keysym.sym] = 1;
            break;

        case SDL_KEYUP:
            keys_on[event.key.keysym.sym] = 0;

            break;

        case SDL_MOUSEBUTTONDOWN:

            keys_on[event.button.button]=1;
            if(event.button.x < game->p2.position.x)
            {
                game->directionSouris=1;
            }
            if(event.button.x > game->p2.position.x)
            {
                game->directionSouris=2;
            }

            /*printf("souris X %d\n",event.button.x );
            printf("Direction %d\n",game->directionSouris );*/

        break;




        }

    }
}



void update (int keys_on[], jeu *game, SDL_Surface *screen)
{
    test(game);
    int sens;
    int col;

    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
    if(game->time_over == 0)
    {
        update_temps(&game->t1);
        move(&(game->e));
            if(game->e.position.x==600)
            {
                game->e.direction=2;
            }
            if(game->e.position.x==300)
            {
                game->e.direction=1;
            }


           // printf("PersoX=%d,EnemyX%d,EnemyX+W%d\n",game->p1.position.x,game->e.position.x,game->e.position.x+game->e.position.h );
           // printf("%d persoooo %d\n",game->e.position.w+game->e.position.x,game->p1.position.x );





            if(game->e.position.x< game->p1.position.x && game->p1.position.x < game->e.position.x+100  )
                {
                    
                    game->p1.position.x+=250;
                    game->v1.vie_restante--;
                    //printf("COLLISION\n");

                }




 if (keys_on[SDLK_SPACE] )
         {
            if( game->p1.direction==0 && game->p1.on_ground==1  )
            {   if((inventaire(&(game->B1),&(game->p1)))==1)
                {
                update_score3(&game->s1);
                }

             //printf("y= %d\n",(game->p1.position.y ));
                game->p1.on_ground=0;
                game->p1.position.x = game->p1.position.x +80;
                game->p1.position.y = game->p1.position.y-JUMP_HEIGHT;
                Annim_SAUT_RIGHT(&game->p1);
                scrollright(&(game->B1),&(game->p1));
            }
            else if( game->p1.direction==1 && game->p1.on_ground==1)  
            {
                game->p1.on_ground=0;
                game->p1.position.x = game->p1.position.x -80;
                game->p1.position.y = game->p1.position.y-JUMP_HEIGHT;
                Annim_SAUT_LEFT(&game->p1);
                scrollright(&(game->B1),&(game->p1));

            }

        }

        if (!(keys_on[SDLK_SPACE]) )
        {

                game->p1.position.y=70; 
                game->p1.on_ground=1;
            if(game->p1.direction==0)
            {
                game->p1.position_Anim.y=perso_HEIGHT;
    
            }
            else 
            {
                game->p1.position_Anim.y=0;
            }
    
        }
        if(keys_on[SDLK_RIGHT] && game->p1.on_ground==1) 
        {
            
           
           col=check_collision(screen,game->p1.position,3,game->col1.backgroundImg);
            //printf("%d\n",col );
           if(col==0 || game->p1.position.x>150)
           {
                game->i=0;
                game->p1.direction=0;
                scrollright(&(game->B1),&(game->p1));





                //printf("x= %d\n",(game->p1.position.x ));

                //printf("score= %d\n",(game->s1.score_courant ));
            if((inventaire(&(game->B1),&(game->p1)))==1)
                {
                update_score3(&game->s1);
                }

                Move_Right(&(game->p1));
                Annim_Right(&(game->p1));
                update_score(&game->s1);
                }

        }
        if(keys_on[SDLK_LEFT] && game->p1.on_ground==1) 
        {
                game->i=1;
                game->p1.direction=1;
                scrollleft(&(game->B1),&(game->p1));
                Move_Left(&(game->p1));
                Annim_Left(&(game->p1));
            if((inventaire(&(game->B1),&(game->p1)))==1)
            {
                update_score3(&game->s1);
            }
        
    
        }




        if((((keys_on[SDLK_s])&&(keys_on[SDLK_LEFT])) ||((keys_on[SDLK_s])&&(keys_on[SDLK_RIGHT])))  && game->p1.on_ground==1)  
        {   

                game->p1.acceleration+=100;
                Move_Right1(&(game->p1),game->B1,game->i);

            if((inventaire(&(game->B1),&(game->p1)))==1)
            {
                update_score3(&game->s1);
            }
            
            if(game->i==0)
            {
                scrollright(&(game->B1),&(game->p1));
                update_score2(&game->s1);
            }
            else if (game->i==1)
                    
            {   
                scrollleft(&(game->B1),&(game->p1));
            }
        }
       
    }
    if(game->time_over2 == 0)
    {
        update_temps(&game->t2);
        if (keys_on[SDLK_LSHIFT] )
         {
            if( game->p2.direction==0 && game->p2.on_ground==1  )
            {
                game->p2.on_ground=0;
                game->p2.position.x = game->p2.position.x +80;
                game->p2.position.y = game->p2.position.y-105;
                Annim_SAUT_RIGHT(&game->p2);
                scrollright(&(game->B2),&(game->p2));
            }
            else if( game->p2.direction==1 && game->p2.on_ground==1)  
            {
                game->p2.on_ground=0;
                game->p2.position.x = game->p2.position.x -105;
                game->p2.position.y = game->p2.position.y-90;
                Annim_SAUT_LEFT(&game->p2);
                scrollright(&(game->B2),&(game->p2));

            }

        }

        if (!(keys_on[SDLK_LSHIFT]) )
        {

                game->p2.position.y=450; 
                game->p2.on_ground=1;
            if(game->p2.direction==0)
            {
                game->p2.position_Anim.y=perso_HEIGHT;
    
            }
            else 
            {
                game->p2.position_Anim.y=0;
            }
    
        }

        if(keys_on[SDL_BUTTON_LEFT]&& game->p2.on_ground==1) 
        {
                    if(game->directionSouris==2)
                    {
                        game->i=2;
                    game->p2.direction=0;
                    Move_Right(&(game->p2));
            if((inventaire(&(game->B2),&(game->p2)))==1)
            {
                    update_score3(&game->s2);
            }
                    Annim_Right(&(game->p2));
                    scrollright2(&(game->B2),&(game->p2));
                    update_score(&game->s2);
                   
                    }
                    if(game->directionSouris==1)
                    {
                        game->i=3;
                    game->p2.direction=1;
                    Move_Left(&(game->p2));
                    Annim_Left(&(game->p2));
                    scrollleft2(&(game->B2),&(game->p2)); 
                    }
                     keys_on[SDL_BUTTON_LEFT]=0;

        }


            
        if(keys_on[SDLK_d]&& game->p2.on_ground==1) 
        {
                    game->i=2;
                    game->p2.direction=0;
                    Move_Right(&(game->p2));
            if((inventaire(&(game->B2),&(game->p2)))==1)
            {
                    update_score3(&game->s2);
            }
                    Annim_Right(&(game->p2));
                    scrollright2(&(game->B2),&(game->p2));
                    update_score(&game->s2);

        }
        if(keys_on[SDLK_q] &&game->p2.on_ground==1)
        {
                    game->i=3;
                    game->p2.direction=1;
                    Move_Left(&(game->p2));
                    Annim_Left(&(game->p2));
                    scrollleft2(&(game->B2),&(game->p2)); 
        }


        if((((keys_on[SDLK_w])&&(keys_on[SDLK_q])) ||((keys_on[SDLK_w])&&(keys_on[SDLK_d]))) && game->p2.on_ground==1)  
        {
                game->p2.acceleration+=100;
                Move_Right1(&(game->p2),game->B2,game->i);

            if(game->i==2)
            {
                    scrollright(&(game->B2),&(game->p2));
                    update_score2(&game->s2);

                if((inventaire(&(game->B2),&(game->p2)))==1)
                {
                    update_score3(&game->s2);
                }
            }
            else if (game->i==3)
            {
                    scrollleft(&(game->B2),&(game->p2));
            }
        }

/*
keys_on[SDLK_RIGHT]=0;
game->p1.position.x+=3;
j=dossier();
if (j==1) {
 game->i=0;
                game->p1.direction=0;
                scrollright(&(game->B1),&(game->p1));}
else {
game->v1.vie_restante--;}
   */


if(game->p1.position.x>1 &&   game->p1.position.x<4)
        {
           

int l;




keys_on[SDLK_RIGHT]=0;
game->p1.position.x+=3;
l=dossier();

if(l==1)
{
printf("right\n");
  game->i=0;
                game->p1.direction=0;
                scrollright(&(game->B1),&(game->p1));
}
else 
{
printf("wrong\n");
game->v1.vie_restante--;
}

/* input (keys_on, game);*/

        }

if(game->p1.position.x>5 &&   game->p1.position.x<8)
        {
           

int j;
int r=0;



keys_on[SDLK_RIGHT]=0;
game->p1.position.x+=3;
j=generer_enigmes(game->tabl);

r=saisir(screen,game->tableau,j);

if(r==0)
{
printf("right\n");
  game->i=0;
                game->p1.direction=0;
                scrollright(&(game->B1),&(game->p1));
}
else 
{
printf("wrong\n");
game->v1.vie_restante--;
}

input (keys_on, game);

        }
        }

}
void display_game ( jeu *game, SDL_Surface *screen)
{
    SDL_Rect pos1 = {0, 0, 0, 350};
    SDL_Rect pos2 = {0, 375, 0, 350};
    SDL_Rect pos3 = {0, 220, 0, 350};
SDL_BlitSurface(game->col1.backgroundImg,NULL, screen, &pos1);
    blitBackground(&(game->B1), &pos1, screen);
    blitBackground(&(game->B2), &pos2, screen);
    blitBackground(&(game->B3), &pos3, screen);
    //blitBackground(&(game->m1), &pos1, screen);


    /*SDL_Surface *bg;

    bg=IMG_Load("maps/map1.png");*/
    



    blit_perso(&(game->p1),  screen);
    afficher(&(game->e),screen);
    generer_score_vie(&(game->s1), &(game->v1), screen);
    generer_score_vie(&(game->s2), &(game->v2), screen);
    generer_temps(&(game->t1), screen);
    generer_temps(&(game->t2), screen);
    afficher_vie_et_score(game->s1, game->v1, screen);
    afficher_temps(game->t1, screen);
    afficher_temps(game->t2, screen);
    afficher_vie_et_score(game->s2, game->v2, screen);
    blit_perso(&(game->p2),  screen);
    //SDL_Delay(150);
    SDL_Flip(screen);
}

/*************************************************************************************************************************
*********************************************************************************************************/

void free_game(jeu *game)
{

    Mix_CloseAudio();
    free_vie_et_score(game->s2, game->v2);
    free_temps(game->t1);
    free_temps(game->t2);
    freeBackground(&(game->B1));
    free_perso(&(game->p1));
    freeBackground(&(game->B2));
    freeBackground(&(game->B3));
    free_perso(&(game->p2));
    destruct(&(game->e));

}
/*************************************************************************************************************************
*********************************************************************************************************/

int jouer(jeu *game, SDL_Surface *screen)
{
    Uint32 start;
    int keys_on[323] = {0};
    initialiser (game);
    load_images(game);

    while(game->game_over == 0)
    {

        start = SDL_GetTicks();
        input (keys_on, game);

        update (keys_on, game, screen );
        display_game (game, screen)	;
        


    }
    free_game(game);

    return(0);
}































