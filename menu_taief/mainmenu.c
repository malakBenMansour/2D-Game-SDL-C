#include <stdlib.h>
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"

int main(void) 
{
	SDL_Surface *ecran,*icon ; 	
	menu m;
	input inp;
	int continuer=1,volume=128, barrougeX=0,full=0;
	Mix_Music* music=NULL;
	Mix_Chunk *sound=NULL;
	Mix_Music *intro=NULL; 

	SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(950,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF) ;
	//SDL_WM_SetIcon(IMG_Load("img.png"), NULL);//NE MARCHE PAS
	SDL_WM_SetCaption("stalwart",NULL);
	
	intro =Mix_LoadMUS("intro.wav");
	Mix_PlayMusic(intro,1);

	TTF_Init();

	init_input(&inp);
	init_menu(&m,ecran);

	while (continuer) 
   	{
		get_input_menu(&inp,sound,&continuer);
		update_menu(&m,&inp,&continuer,sound,&barrougeX);
		
		if (m.intro==1)//logo 
		{
			m=afficher_intro(m,ecran);
			musique(music);//son continu
			sound = Mix_LoadWAV("pop.wav");//son bref
		}else if (m.choix_boutons==-1)
			afficher_menu(m,ecran);
		else if (m.choix_boutons==0)//play
		{
			if (m.mode==1)//play1: solo ou multi 
				afficher_play1(m,ecran);
			else if (m.mode==2)//play2: new ou load
				afficher_play2(m,ecran);
			else if (m.mode==3)//jeu
			{
				//integrer le jeu
				afficher_play(m,ecran);
			}else if (m.mode==4)//menu pause
				afficher_pause(m,ecran);
			else if (m.mode==5)//menu sauvegarde
				afficher_save(m,ecran);	
		}else if (m.choix_boutons==1)//settings
			afficher_settings(m,ecran,&volume,barrougeX,&full);
		else if (m.choix_boutons==2)//credits
			afficher_credits(m,ecran);
		else if (m.choix_boutons==3)//exit
			afficher_exit(m,ecran);

		SDL_Flip(ecran);	
	}

	Mix_FreeMusic(music);
	Mix_FreeChunk(sound);
	Mix_CloseAudio();
	liberer_menu(&m);
	SDL_FreeSurface(ecran);
	TTF_Quit();	
	SDL_Quit() ;
	return (0);
}
