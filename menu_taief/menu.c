#include <stdlib.h>
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu.h"
 
void musique (Mix_Music *music)
{
	if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s",Mix_GetError());
	}
	music=Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music,-1);
}

void init_menu(menu *m,SDL_Surface *ecran)
{
	SDL_Color couleurNoire = {0, 0, 0};

	//******Background
	m->back[0] = IMG_Load("back.jpg") ;
	m->back[1] = IMG_Load("back2.png") ;
	m->back[2] = IMG_Load("back3.png") ;
	m->back[3] = IMG_Load("back4.png") ;
	m->back[4] = IMG_Load("back5.png") ;
	m->back[5] = IMG_Load("intro.png") ;
	m->back[6] = IMG_Load("intro2.png") ;
		
	m->posback.x= (ecran->w) - (m->back[0]->w) ; 
	m->posback.y= (ecran->h) - (m->back[0]->h);

	//*****texte : dans credits
	m->txt.couleur=couleurNoire;
	m->txt.police = TTF_OpenFont("Candara.ttf", 20);
	m->txt.texte = TTF_RenderText_Blended(m->txt.police, "ALL RIGHTS RESERVED.", m->txt.couleur);
	m->txt.postxt.x= (ecran->w/2)-(m->txt.texte->w*2.35);
	m->txt.postxt.y=(ecran->h/1.02) - (m->txt.texte->h*0.75);
	  
	//******Bouton Play
	m->boutons[0]= IMG_Load("play.png") ;//petit
	m->posboutons[0].x=(ecran->w/2)-(m->boutons[0]->w*1.75); 
	m->posboutons[0].y=(ecran->h/2)-(m->boutons[0]->h);

	m->boutons[5]=IMG_Load("playbig.png") ;//grand
	m->posboutons[5].x=(ecran->w/2)-(m->boutons[5]->w*1.63); 
	m->posboutons[5].y=(ecran->h/2)-(m->boutons[5]->h/1.1);

	//******Bouton Settings
	m->boutons[1] = IMG_Load("settings.png") ;//petit
	m->posboutons[1].x=(ecran->w/2)-(m->boutons[1]->w*1.75); 
	m->posboutons[1].y=(ecran->h/1.75)-(m->boutons[1]->h/4);
	
	m->boutons[6]=IMG_Load("settingsbig.png") ; //grand
	m->posboutons[6].x=(ecran->w/2)-(m->boutons[6]->w*1.63); 
	m->posboutons[6].y=(ecran->h/1.75)-(m->boutons[6]->h/3.2);

	//*******Bouton Credits
	m->boutons[2] = IMG_Load("credits.png") ;//petit
	m->posboutons[2].x=(ecran->w/2)-(m->boutons[2]->w*1.75); 
	m->posboutons[2].y=(ecran->h/1.27)-(m->boutons[2]->h/1.3); 
	 
	m->boutons[7]=IMG_Load("creditsbig.png") ; //grand
	m->posboutons[7].x=(ecran->w/2)-(m->boutons[7]->w*1.63); 
	m->posboutons[7].y=(ecran->h/1.27)-(m->boutons[7]->h/1.5);

	//******Bouton Exit
	m->boutons[3]=IMG_Load("exit.png") ; //petit
	m->posboutons[3].x=(ecran->w/2)+(m->boutons[3]->w*0.85);
	m->posboutons[3].y=(ecran->h/1.27)-(m->boutons[3]->h/1.3);

	m->boutons[8]=IMG_Load("exitbig.png") ;//grand
	m->posboutons[8].x=(ecran->w/2)+(m->boutons[8]->w*0.72); 
	m->posboutons[8].y=(ecran->h/1.27)-(m->boutons[8]->h/1.5);

	//***** Titre + design
	m->boutons[4]=IMG_Load("title.png") ;// stalwart
	m->posboutons[4].x=(ecran->w/2)-(m->boutons[4]->w/1.65); 
	m->posboutons[4].y=(ecran->h/1.2)-(m->boutons[4]->h/0.5);
 
	m->boutons[9]=IMG_Load("viruss.png") ;//Virus
	m->posboutons[9].x=(ecran->w/3)*2.2;
	m->posboutons[9].y=(ecran->h/2.5)-(m->boutons[9]->h);

	//******Option Fullscreen
	m->options[0]=IMG_Load("fullscreenlittleNEW.png") ; //petit
	m->posoptions[0].x=(ecran->w/2)-(m->options[0]->w*1.75); 
	m->posoptions[0].y=(ecran->h/2)-(m->options[0]->h*2.5);

	m->options[5]=IMG_Load("fullscreenbigNEW.png") ;//grand
	m->posoptions[5].x=(ecran->w/2)-(m->options[5]->w*1.55);  
	m->posoptions[5].y=(ecran->h/2)-(m->options[5]->h*2.25);
	
	//***** Options Son
	m->options[1]=IMG_Load("audiomuteNEW.png") ;//Audio Mute
	m->posoptions[1].x=(ecran->w/2)-(m->options[1]->w*2.4);  
	m->posoptions[1].y=(ecran->h/2)-(m->options[1]->h/1.35);   

	m->options[6]=IMG_Load("audiofullNEW.png") ;//Audio Full
	m->posoptions[6].x=(ecran->w/2)-(m->options[6]->w*2.4); 
	m->posoptions[6].y=(ecran->h/2)-(m->options[6]->h/1.35);
	 
	//***** Options Barres son
	m->options[2]= SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0, 0, 0);//Barre Noire
	SDL_FillRect(m->options[2], NULL, SDL_MapRGB(m->options[2]->format, 0, 0, 0));
	m->posoptions[2].x=(ecran->w/2)-(m->options[2]->w*0.328);
	m->posoptions[2].y=(ecran->h/2)-(m->options[2]->h*0.8);

	m->posoptions[7].x= 410 ; //Barre Rouge //Si je mets les memes coordonnees que barre noire -->bug
	m->posoptions[7].y= 260 ; 

	//****** Option Retour
	m->options[3]=IMG_Load("return.png") ;//petit
	m->posoptions[3].x = (ecran->w/3)*2.4;
	m->posoptions[3].y = (ecran->h/4)-(m->options[3]->h*2);

	m->options[8]=IMG_Load("returnbig.png") ; //grand
	m->posoptions[8].x = (ecran->w/3)*2.365; 
	m->posoptions[8].y = (ecran->h/4)-(m->options[8]->h*1.7); 

	//***** Options GUI 
	m->options[4]=IMG_Load("settingsGUI.png") ;//SettingsGUI
	m->posoptions[4].x=(ecran->w) - (m->options[4]->w) ; 
	m->posoptions[4].y=(ecran->h) - (m->options[4]->h) ;

	m->options[9]=IMG_Load("creditsGUI.png") ;//CreditsGUI
	m->posoptions[9].x=(ecran->w) - (m->options[9]->w) ; 
	m->posoptions[9].y=(ecran->h) - (m->options[9]->h) ;

	m->options[10]=IMG_Load("ExitGUII.png") ;//CreditsGUI
	m->posoptions[10].x=(ecran->w) - (m->options[10]->w) ; 
	m->posoptions[10].y=(ecran->h) - (m->options[10]->h) ;
	
	//****** Option Exit : Yes NO
	m->options[11]=IMG_Load("yes.png");//YES
	m->posoptions[11].x=250;
	m->posoptions[11].y=240;

	m->options[13]=IMG_Load("yesbig.png");//YES big
	m->posoptions[13].x=240;
	m->posoptions[13].y=230;

	m->options[12]=IMG_Load("no.png");//NO
	m->posoptions[12].x=250;
	m->posoptions[12].y=370;

	m->options[14]=IMG_Load("nobig.png");//NO big
	m->posoptions[14].x=240;
	m->posoptions[14].y=360;

	//***** Play
	m->play[0]=IMG_Load("Backplay.png");
	m->posplay[0].x=(ecran->w)-(m->play[0]->w);
	m->posplay[0].y=(ecran->h)-(m->play[0]->h);

	m->play[5]=IMG_Load("playGUII.png");
	m->posplay[5].x=(ecran->w)-(m->play[5]->w);
	m->posplay[5].y=(ecran->h)-(m->play[5]->h);

	m->play[18]=IMG_Load("playGUI.png");//GUI new load
	
	m->play[1]=IMG_Load("solo.png");
	m->posplay[1].x=400;
	m->posplay[1].y=200;

	m->play[6]=IMG_Load("solobig.png");
	m->posplay[6].x=390;
	m->posplay[6].y=190;

	m->play[2]=IMG_Load("multiplayer.png");
	m->posplay[2].x=400;
	m->posplay[2].y=355;

	m->play[7]=IMG_Load("multiplayerbig.png");
	m->posplay[7].x=390;
	m->posplay[7].y=345;

	m->play[3]=IMG_Load("new game.png");
	m->posplay[3].x=240;
	m->posplay[3].y=280;

	m->play[8]=IMG_Load("newgamebig.png");
	m->posplay[8].x=230;
	m->posplay[8].y=270;

	m->play[4]=IMG_Load("load game.png");
	m->posplay[4].x=530;
	m->posplay[4].y=280;

	m->play[9]=IMG_Load("loadgamebig.png");
	m->posplay[9].x=520;
	m->posplay[9].y=270;

	m->play[10]=IMG_Load("icone.png");
	m->posplay[10].x=890;
	m->posplay[10].y=5;
	
	m->play[11]=IMG_Load("iconebig.png");
	m->posplay[11].x=887;
	m->posplay[11].y=3;	

	//*********PAUSE: resume restart settings exit 

	m->play[12]=IMG_Load("pauseGUII.png");
	m->pospause[0].x=0;
	m->pospause[0].y=0;

	m->play[13]=IMG_Load("resume.png");
	m->pospause[1].x=383; 
	m->pospause[1].y=153;

	m->play[15]=IMG_Load("resumebig.png");
	m->pospause[5].x=370; 
	m->pospause[5].y=144;
	
	m->play[14]=IMG_Load("restart.png");
	m->pospause[2].x=383; 
	m->pospause[2].y=253;

	m->play[16]=IMG_Load("restartbig.png");
	m->pospause[6].x=370; 
	m->pospause[6].y=244;
	
	m->pospause[3].x=383; //settings
	m->pospause[3].y=353;
	
	m->pospause[7].x=370; //settings big
	m->pospause[7].y=344;

	m->pospause[4].x=383; //exit
	m->pospause[4].y=453;

	m->pospause[8].x=370; //exit big
	m->pospause[8].y=444;

	m->play[17]=IMG_Load("saveGUI.png");
	m->pospause[9].x=0;
	m->pospause[9].y=0;	

	m->pospause[10].x=240;//yes (save)
	m->pospause[10].y=330;

	m->pospause[12].x=230;// yes big (save)
	m->pospause[12].y=320;
	
	m->pospause[11].x=530;//no (don't save)
	m->pospause[11].y=330;

	m->pospause[13].x=520;//no big (don't save)
	m->pospause[13].y=320;
	

	//*****Autres
	m->intro=1;
	m->choix_boutons=-1;
	m->choix_options=-1;
	m->grand=-1;
	m->mode=-1;

	for (int j=0;j<4;j++)
		m->choix_mode[j]=-1;
	
}

void init_input(input *inp)
{
	//*****clavier
	inp->c.haut=-1;
	inp->c.bas=-1;
	inp->c.droite=-1;
	inp->c.gauche=-1;
	inp->c.echap=-1;
	inp->c.entrer=-1;
	inp->c.espace=-1;
	inp->c.a=-1;
	inp->c.b=-1;
	inp->c.c=-1;
	inp->c.p=-1;
	inp->c.s=-1;
	inp->c.n=-1;
	inp->c.y=-1;
	inp->c.w=-1;
	inp->c.z=-1;

	//****souris
	inp->s.left=-1;
	inp->s.right=-1;
	inp->s.middle=-1;
	inp->s.posclick.x=-1;
	inp->s.posclick.y=-1;
	inp->s.motion.x=-1;
	inp->s.motion.y=-1;
}

menu afficher_intro(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.back[5],NULL,ecran,&m.posback);
	SDL_Flip(ecran);
	SDL_Delay(500);
	SDL_BlitSurface(m.back[6],NULL,ecran,&m.posback);
	SDL_Flip(ecran);
	SDL_Delay(1500);
	m.intro=0;

	return m; 
}

void afficher_menu(menu m,SDL_Surface *ecran)
{
	//*****Animation menu principal	
	/*if (*b<5)	
	{
	SDL_BlitSurface(m.back[*b],NULL,ecran,&m.posback) ;
	if (*b==4)
		*b=0;
	else
		*b++;
	}
	SDL_Flip(ecran);
	SDL_Delay(40) ;*/
	SDL_BlitSurface(m.back[0],NULL,ecran,&m.posback) ;
	SDL_BlitSurface(m.boutons[4],NULL,ecran,&m.posboutons[4]);
	SDL_BlitSurface(m.boutons[9],NULL,ecran,&m.posboutons[9]);
	for (int i=0; i<4;i++)
	{
		SDL_BlitSurface(m.boutons[i],NULL,ecran,&m.posboutons[i]) ;
		if (m.grand==i)
			SDL_BlitSurface(m.boutons[i+5],NULL,ecran,&m.posboutons[i+5]) ;
	} 
}

void afficher_play1(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.back[0],NULL,ecran,&m.posback);
	SDL_BlitSurface(m.play[5],NULL,ecran,&m.posplay[5]);//GUI
	SDL_BlitSurface(m.options[3],NULL,ecran,&m.posoptions[3]);//Return
	
	SDL_BlitSurface(m.play[1],NULL,ecran,&m.posplay[1]);//Solo
	SDL_BlitSurface(m.play[2],NULL,ecran,&m.posplay[2]);//multi
	if (m.grand==8)
		SDL_BlitSurface(m.play[6],NULL,ecran,&m.posplay[6]);//Solo big
	else if (m.grand==9)
		SDL_BlitSurface(m.play[7],NULL,ecran,&m.posplay[7]);//multi big
	else if (m.grand==4)//retour
		SDL_BlitSurface(m.options[8],NULL,ecran,&m.posoptions[8]);	
}

void afficher_play2(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.back[0],NULL,ecran,&m.posback);
	SDL_BlitSurface(m.play[18],NULL,ecran,&m.posplay[5]);//GUI
	SDL_BlitSurface(m.options[3],NULL,ecran,&m.posoptions[3]);//Return

	SDL_BlitSurface(m.play[3],NULL,ecran,&m.posplay[3]);//New Game
	SDL_BlitSurface(m.play[4],NULL,ecran,&m.posplay[4]);//Load Game
	if (m.grand==10)
		SDL_BlitSurface(m.play[8],NULL,ecran,&m.posplay[8]);//new game big
	else if (m.grand==11)
		SDL_BlitSurface(m.play[9],NULL,ecran,&m.posplay[9]);//load game big
	else if (m.grand==4)//retour
		SDL_BlitSurface(m.options[8],NULL,ecran,&m.posoptions[8]);		
}

void afficher_play(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.play[0],NULL,ecran,&m.posplay[0]);//map level 1
	SDL_BlitSurface(m.play[10],NULL,ecran,&m.posplay[10]);//icone
	if (m.grand==14)
		SDL_BlitSurface(m.play[11],NULL,ecran,&m.posplay[11]);//icone big
}

void afficher_pause(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.play[0],NULL,ecran,&m.posplay[0]);//playGUI
	SDL_BlitSurface(m.play[12],NULL,ecran,&m.pospause[0]);//pauseGUI	
	SDL_BlitSurface(m.play[13],NULL,ecran,&m.pospause[1]);//Resume
	SDL_BlitSurface(m.play[14],NULL,ecran,&m.pospause[2]);//Restart
	SDL_BlitSurface(m.boutons[1],NULL,ecran,&m.pospause[3]);//Settings
	SDL_BlitSurface(m.boutons[3],NULL,ecran,&m.pospause[4]);//Exit

	if (m.grand==15)
		SDL_BlitSurface(m.play[15],NULL,ecran,&m.pospause[5]);//Resume ++
	else if (m.grand==16)
		SDL_BlitSurface(m.play[16],NULL,ecran,&m.pospause[6]);//Restart ++
	else if (m.grand==17)
		SDL_BlitSurface(m.boutons[6],NULL,ecran,&m.pospause[7]);//Settings ++
	else if (m.grand==18)
		SDL_BlitSurface(m.boutons[8],NULL,ecran,&m.pospause[8]);//Exit ++
}

void afficher_save(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.play[17],NULL,ecran,&m.pospause[9]);//SaveGUI
	SDL_BlitSurface(m.options[11],NULL,ecran,&m.pospause[10]);//YES
	SDL_BlitSurface(m.options[12],NULL,ecran,&m.pospause[11]);//NO

	if (m.grand==19)//YES
		SDL_BlitSurface(m.options[13],NULL,ecran,&m.pospause[12]);
	else if (m.grand==20)//NO
		SDL_BlitSurface(m.options[14],NULL,ecran,&m.pospause[13]);
}

void afficher_settings(menu m,SDL_Surface *ecran,int *volume,int barrougeX,int *full)
{
	int longbarRouge=0,aux;

	if (m.mode==-1)
	{
		SDL_BlitSurface(m.back[0],NULL,ecran,&m.posback);
		SDL_BlitSurface(m.options[3],NULL,ecran,&m.posoptions[3]);//Retour
		if (m.grand==4)//retour
			SDL_BlitSurface(m.options[8],NULL,ecran,&m.posoptions[8]);
	}

	SDL_BlitSurface(m.options[4],NULL,ecran,&m.posoptions[4]);//SettingsGUI
	SDL_BlitSurface(m.options[0],NULL,ecran,&m.posoptions[0]);//Fullscreen
	SDL_BlitSurface(m.options[2],NULL,ecran,&m.posoptions[2]);//Barre son
	SDL_BlitSurface(m.boutons[3],NULL,ecran,&m.posboutons[3]);//Exit
	
	longbarRouge=((200*(*volume))/128)+410 ;
	m.options[7] = SDL_CreateRGBSurface(SDL_HWSURFACE, longbarRouge-410, 50, 32, 0, 0, 0, 0);
	SDL_FillRect(m.options[7], NULL, SDL_MapRGB(m.options[7]->format, 255, 0, 0));
	SDL_BlitSurface(m.options[7],NULL,ecran,&m.posoptions[7]);
	
	//*****Reglage son
	aux=*volume;
	if (m.choix_options==7) 
	{
		m.options[7]=SDL_CreateRGBSurface(SDL_HWSURFACE, barrougeX-410, 50, 32, 0, 0, 0, 0);
		SDL_FillRect(m.options[7], NULL, SDL_MapRGB(m.options[7]->format, 255, 0, 0));
		SDL_BlitSurface(m.options[7],NULL,ecran,&m.posoptions[7]) ;
	 	*volume=(int)((barrougeX-410)*128)/200 ; 
	 	Mix_VolumeMusic(*volume) ;
		aux=(*volume);
		 	
	}else if (m.choix_options==6)
	{
		if ((*volume) !=0)//mute
		{
			(*volume)=0 ; 
			Mix_VolumeMusic(*volume) ;				
		}else if ((*volume)==0)//play
		{
			(*volume)=aux ; 
			Mix_VolumeMusic(*volume) ; 
		}
	}
	if ((*volume)==0)  
		SDL_BlitSurface(m.options[1],NULL,ecran,&m.posoptions[1]);//Mute
	
	else
		SDL_BlitSurface(m.options[6],NULL,ecran,&m.posoptions[6]);//Full 
	
	//****Affichage: Grand ou petit
	if (m.grand==3)//exit
		SDL_BlitSurface(m.boutons[8],NULL,ecran,&m.posboutons[8]);
	else if (m.grand==5)//fullscreen
		SDL_BlitSurface(m.options[5],NULL,ecran,&m.posoptions[5]);
	
	if (m.choix_options==5)//Gestion mode plein ecran
		fullscreen(ecran,&(*full));
}

void fullscreen(SDL_Surface *ecran,int *full)
{
	if (*full==0)
	{
		ecran = SDL_SetVideoMode(950,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN) ;	
	      	*full=1 ;
	} else 
	{
	 	ecran = SDL_SetVideoMode(950,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF ) ;	
		*full=0 ;
	}
}

void afficher_credits(menu m,SDL_Surface *ecran)
{
	SDL_BlitSurface(m.back[0],NULL,ecran,&m.posback);
	SDL_BlitSurface(m.options[9],NULL,ecran,&m.posoptions[9]);//CreditsGUI
	SDL_BlitSurface(m.options[3],NULL,ecran,&m.posoptions[3]);//Retour
	SDL_BlitSurface(m.boutons[3],NULL,ecran,&m.posboutons[3]);//Exit
	SDL_BlitSurface(m.txt.texte,NULL,ecran,&m.txt.postxt);

	if (m.grand==3)//Exit
		SDL_BlitSurface(m.boutons[8],NULL,ecran,&m.posboutons[8]);
	else if (m.grand==4)//retour
		SDL_BlitSurface(m.options[8],NULL,ecran,&m.posoptions[8]);		
}

void afficher_exit(menu m,SDL_Surface *ecran)
{
	if (m.mode==-1)
		SDL_BlitSurface(m.back[0],NULL,ecran,&m.posback);

	SDL_BlitSurface(m.options[10],NULL,ecran,&m.posoptions[10]);//ExitGUI
	SDL_BlitSurface(m.options[11],NULL,ecran,&m.posoptions[11]);//YES
	SDL_BlitSurface(m.options[12],NULL,ecran,&m.posoptions[12]);//NO

	if (m.grand==12)//YES
		SDL_BlitSurface(m.options[13],NULL,ecran,&m.posoptions[13]);
	else if (m.grand==13)//NO
		SDL_BlitSurface(m.options[14],NULL,ecran,&m.posoptions[14]);
}

void gestion_click_menu(input inp,menu m,Mix_Chunk *sound,int *barrougeX)
{
	//*************CLAVIER
	if ((inp.c.echap==1)&&((m.choix_boutons!=-1)&&(m.choix_boutons!=3)))//echap
		Mix_PlayChannel(-1,sound,0);//click
	if (inp.c.entrer==1)
		Mix_PlayChannel(-1,sound,0);
	if (((inp.c.p==1)||(inp.c.s==1)||(inp.c.c==1))&&(m.choix_boutons==-1))//menu principal
		Mix_PlayChannel(-1,sound,0);
	if (((inp.c.n==1)||(inp.c.y==1))&&((m.choix_boutons==3)||((m.choix_boutons==0)&&(m.mode==5))))//exit et save
		Mix_PlayChannel(-1,sound,0);
	if ((inp.c.espace==1)&&((m.choix_boutons==0)&&(m.mode==3)))//ouvrir menu pause
		Mix_PlayChannel(-1,sound,0);

	//*************SOURIS	
		//========= Gestion bruit du click + eviter d'ouvrir settings a partir de credits (par ex)
	if (inp.s.left==1)
	{
		if ((m.choix_boutons==-1)&&((m.grand>=0)&&(m.grand<=3)))//Menu
			Mix_PlayChannel(-1,sound,0);//click
		else if (m.choix_boutons==0)//Play
		{
			if ((m.mode==1)&&((m.grand==8)||(m.grand==9)||(m.grand==4)))//solo/multi
				Mix_PlayChannel(-1,sound,0);//click
			else if ((m.mode==2)&&((m.grand==10)||(m.grand==11)||(m.grand==4)))//New/Loa
				Mix_PlayChannel(-1,sound,0);//click
			else if ((m.mode==3)&&(m.grand==14))//icone pour afficher menu pause
				Mix_PlayChannel(-1,sound,0);//click
			else if ((m.mode==4)&&((m.grand==15)||(m.grand=16)||(m.grand==17)||(m.grand==18)))//menu pause
				Mix_PlayChannel(-1,sound,0);//click
			else if ((m.mode==5)&&((m.grand==19)||(m.grand==20)))//sauvegarde
				Mix_PlayChannel(-1,sound,0);//click

		}else if ((m.choix_boutons==1)&&(m.grand>=3)&&(m.grand<=7))//Settings
			Mix_PlayChannel(-1,sound,0);//click
		else if ((m.choix_boutons==2)&&((m.grand==4)||(m.grand==3)))//Credits
			Mix_PlayChannel(-1,sound,0);//click
		else if ((m.choix_boutons==3)&&((m.grand==12)||(m.grand==13)))//Exit
			Mix_PlayChannel(-1,sound,0);//click

		//========= Gestion barre son
		if ((m.choix_boutons==1)&&(m.grand==7))
		{
			*barrougeX =inp.s.posclick.x;
			printf ("Niveau son = %d \n",*barrougeX-411) ; 
		}
	}	
}

void get_input_menu(input *inp,Mix_Chunk* sound, int *continuer)
{
	SDL_Event event; 
	if(SDL_PollEvent(&event))
	{  
		switch(event.type)
		{
			case SDL_QUIT:
				*continuer=0;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE://echap
						inp->c.echap=1;
						break;
					case SDLK_DOWN:
						inp->c.bas=1;
						break;
					case SDLK_UP:
						inp->c.haut=1;
						break;
					case SDLK_RIGHT:
						inp->c.droite=1;
						break;
					case SDLK_LEFT:
						inp->c.gauche=1;
						break;
					case SDLK_RETURN://entrer
						inp->c.entrer=1;
						break;
					case SDLK_p://play
						inp->c.p=1;
						break; 
					case SDLK_s://settings
						inp->c.s=1;
						break;
					case SDLK_c://credits
						inp->c.c=1;
						break;
					case SDLK_n://NO
						inp->c.n=1;
						break;
					case SDLK_y://YES
						inp->c.y=1;
						break;
					case SDLK_SPACE://espace
						inp->c.espace=1;
						break;
					case SDLK_z:
						inp->c.z=1;
						break;
					case SDLK_w:
						inp->c.w=1;
						break;
				}
				break;	
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
					{
						case SDLK_ESCAPE:				
							inp->c.echap=-1;
							break;
						case SDLK_DOWN:
							inp->c.bas=-1;
							break;
						case SDLK_UP:
							inp->c.haut=-1;
							break;
						case SDLK_RIGHT:
							inp->c.droite=-1;
							break;
						case SDLK_LEFT:
							inp->c.gauche=-1;
							break;
						case SDLK_RETURN://entrer
							inp->c.entrer=-1;
							break;
						case SDLK_p://play
							inp->c.p=-1;
							break; 
						case SDLK_s://settings
							inp->c.s=-1;
							break;
						case SDLK_c://credits
							inp->c.c=-1;
							break;
						case SDLK_n://NO
							inp->c.n=-1;
							break;
						case SDLK_y://YES
							inp->c.y=-1;
							break;
						case SDLK_SPACE://espace
							inp->c.espace=-1;
							break;
						case SDLK_z:
							inp->c.z=-1;
							break;
						case SDLK_w:
							inp->c.w=-1;
							break;
					}
					break;
			case SDL_MOUSEMOTION:
				inp->s.motion.x=event.motion.x;
				inp->s.motion.y=event.motion.y;
				break;
	
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button==SDL_BUTTON_LEFT)//click
				{	
					inp->s.left=1;
					inp->s.posclick.x=event.button.x;
					inp->s.posclick.y=event.button.y;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button==SDL_BUTTON_LEFT)
				{
					inp->s.left=-1;
					inp->s.posclick.x=-1;
					inp->s.posclick.y=-1;
				}
				break;
			}
	}
}

menu zoom_clavier(menu m, input inp)
{
	//*******Quand le joueur utilise les fleches du clavier :
		//=============MENU PRINCIPAL=============//Boutons play settings credits exit
	if (m.choix_boutons==-1)
	{
		if (((m.grand==-1)||(m.grand>3))&&((inp.c.bas==1)||(inp.c.droite==1)||(inp.c.haut==1)))
			m.grand=0;
		else if ((m.grand!=-1)&&(inp.c.bas==1))
		{
			if ((m.grand==2)||(m.grand==3))
				m.grand=0;
			else
				m.grand++;			
		}
		else if ((m.grand!=-1)&&(inp.c.droite==1))
			m.grand=3;
		else if ((m.grand==3)&&(inp.c.gauche==1))
			m.grand=0;
		else if ((m.grand!=-1)&&(inp.c.haut==1))
		{
			if (m.grand==0)
				m.grand=2;
			else 
				m.grand--;
		}
	}	
		//=============PLAY=============//Boutons Solo Multi NewGame LoadGame
	else if (m.choix_boutons==0)
	{
		if (m.mode==1)//Solo ou multi ou return 
		{
			if (((m.grand!=8)&&(m.grand!=9)&&(m.grand!=4))&&(inp.c.droite==1))
				m.grand=4;
			else if (((m.grand!=8)&&(m.grand!=9)&&(m.grand!=4))&&(inp.c.haut==1))
				m.grand=8;
			else if ((m.grand==8)&&(inp.c.haut==1))
				m.grand=4;
			else if ((m.grand==9)&&(inp.c.haut==1))
				m.grand=8;
			else if ((m.grand==4)&&(inp.c.haut==1))
				m.grand=9;
			else if (((m.grand!=8)&&(m.grand!=9)&&(m.grand!=4))&&(inp.c.bas==1))
				m.grand=9;
			else if ((m.grand==8)&&(inp.c.bas==1))
				m.grand=9;
			else if ((m.grand==9)&&(inp.c.bas==1))
				m.grand=4;
			else if ((m.grand==4)&&(inp.c.bas==1))
				m.grand=8;
		}else if (m.mode==2)//NewGame ou LoadGame ou Return 
		{
			if (((m.grand!=10)&&(m.grand!=11)&&(m.grand!=4))&&(inp.c.haut==1))
				m.grand=4;
			else if (((m.grand!=10)&&(m.grand!=11)&&(m.grand!=4))&&((inp.c.droite==1)||(inp.c.bas==1)))
				m.grand=10;
			else if (((m.grand!=10)&&(m.grand!=11)&&(m.grand!=4))&&(inp.c.gauche==1))
				m.grand=11;
			else if ((m.grand==10)&&(inp.c.droite==1))
				m.grand=11;
			else if ((m.grand==11)&&(inp.c.gauche==1))
				m.grand=10;
			else if ((m.grand==4)&&(inp.c.gauche==1))
				m.grand=11;
			else if ((m.grand==10)&&((inp.c.gauche==1)||(inp.c.haut==1)))
				m.grand=4;
			else if ((m.grand==11)&&((inp.c.droite==1)||(inp.c.haut==1)))
				m.grand=4;
			else if ((m.grand==4)&&((inp.c.droite==1)||(inp.c.bas==1)))
				m.grand=10;
		}else if ((m.mode==3)&&(inp.c.espace==1))//afficher menu pause avec l'icone
			m.grand=14;
		else if (m.mode==4)//menu pause
		{
			if ((m.grand!=15)&&(m.grand!=16)&&(m.grand!=17)&&(m.grand!=18)&&(inp.c.haut==1))
				m.grand=15;
			else if ((m.grand!=15)&&(m.grand!=16)&&(m.grand!=17)&&(m.grand!=18)&&(inp.c.bas==1))
				m.grand=18;
			else if ((m.grand==18)&&(inp.c.bas==1))
				m.grand=15;
			else if ((m.grand==15)&&(inp.c.haut==1))
				m.grand=18;
			else if ((m.grand>=15)&&(m.grand<=18)&&(inp.c.haut==1))
				m.grand--;
			else if ((m.grand>=15)&&(m.grand<=18)&&(inp.c.bas==1))
				m.grand++;
			 
		}else if (m.mode==5)//menu sauvegarde
		{
			if ((m.grand!=19)&&(m.grand!=20)&&(inp.c.droite==1))
				m.grand=19;
			else if ((m.grand!=19)&&(m.grand!=20)&&(inp.c.gauche==1))
				m.grand=20;
			else if ((m.grand==19)&&((inp.c.droite==1)||(inp.c.gauche==1)))
				m.grand=20;
			else if ((m.grand==20)&&((inp.c.gauche==1)||(inp.c.droite==1)))
				m.grand=19;
		}
	}
		//=============SETTINGS & CREDITS=============//Boutons retour et exit
	else if (((m.choix_boutons==1)&&(m.choix_mode[2]==-1))||(m.choix_boutons==2))
	{
		if (((m.grand!=3)&&(m.grand!=4))&&(inp.c.haut==1))
			m.grand=4;
		else if (((m.grand!=3)||(m.grand!=4))&&(inp.c.bas==1))
			m.grand=3;
		else if ((m.grand==4)&&((inp.c.haut==1)||(inp.c.bas==1)))
			m.grand=3;
		else if ((m.grand==3)&&((inp.c.haut==1)||(inp.c.bas==1)))
			m.grand=4;

	}
		//=============Settings menu pause=============//Bouton exit
	else if ((m.choix_boutons==1)&&(m.choix_mode[2]==3))
	{
		if ((m.grand!=3)&&((inp.c.haut==1)||(inp.c.bas==1)||(inp.c.droite==1)||(inp.c.gauche==1)))
			m.grand=3;
	}
		//=============EXIT=============// Boutons YES et NO
	else if (m.choix_boutons==3)
	{
		if (((m.grand!=12)&&(m.grand!=13))&&(inp.c.haut==1))
			m.grand=12;
		else if (((m.grand!=12)||(m.grand!=13))&&(inp.c.bas==1))
			m.grand=13;
		else if ((m.grand==12)&&((inp.c.haut==1)||(inp.c.bas==1)))
			m.grand=13;
		else if ((m.grand==13)&&((inp.c.haut==1)||(inp.c.bas==1)))
			m.grand=12;
	}
	//******* Quand le joueur utilise les lettres p s c (cas Menu principal uniquement) :
	if (inp.c.p==1)
		m.grand=0;
	else if (inp.c.s==1)
		m.grand=1;
	else if (inp.c.c==1)
		m.grand=2;

	return m; 
}

menu zoom_souris(menu m,input inp)
{
	//***** Quand le joueur utilise la souris
	if ((inp.s.motion.x!=-1)&&(inp.s.motion.y!=-1))
	{
			//=============Menu principal=============
		if ((m.choix_boutons==-1)&&(inp.s.motion.x>=m.posboutons[0].x)&&(inp.s.motion.x<=m.posboutons[0].x+180)&&(inp.s.motion.y>=m.posboutons[0].y)&&(inp.s.motion.y<=m.posboutons[0].y+70))
			m.grand=0;//sur play
		else if ((m.choix_boutons==-1)&&(inp.s.motion.x>=m.posboutons[1].x)&&(inp.s.motion.x<=m.posboutons[1].x+180)&&(inp.s.motion.y>=m.posboutons[1].y)&&(inp.s.motion.y<=m.posboutons[1].y+70))					
			m.grand=1;//sur settings
		else if((m.choix_boutons==-1)&&(inp.s.motion.x>=m.posboutons[2].x)&&(inp.s.motion.x<=m.posboutons[2].x+180)&&(inp.s.motion.y>=m.posboutons[2].y)&&(inp.s.motion.y<=m.posboutons[2].y+70))
			m.grand=2;//sur credits
		else if (((m.choix_boutons!=0)&&(m.choix_boutons!=3))&&(inp.s.motion.x>=m.posboutons[3].x)&&(inp.s.motion.x<=m.posboutons[3].x+180)&&(inp.s.motion.y>=m.posboutons[3].y)&&(inp.s.motion.y<=m.posboutons[3].y+70))
			m.grand=3;//sur exit

			//=============Settings & Credits & Play=============
		else if (((m.choix_boutons!=-1)&&(m.choix_boutons!=3)&&(m.mode!=3)&&(m.choix_mode[2]==-1))&&(inp.s.motion.x>=m.posoptions[3].x)&&(inp.s.motion.x<=m.posoptions[3].x+180)&&(inp.s.motion.y>=m.posoptions[3].y)&&(inp.s.motion.y<=m.posoptions[3].y+70))
			m.grand=4;//sur return

			//=============Settings=============
		else if ((m.choix_boutons==1)&&(inp.s.motion.x>=m.posoptions[0].x)&&(inp.s.motion.x<=m.posoptions[0].x+60)&&(inp.s.motion.y>=m.posoptions[0].y)&&(inp.s.motion.y<=m.posoptions[0].y+60))
			m.grand=5;//sur fullscreen
		else if ((m.choix_boutons==1)&&(inp.s.motion.x>=m.posoptions[1].x)&&(inp.s.motion.x<=m.posoptions[1].x+60)&&(inp.s.motion.y>=m.posoptions[1].y)&&(inp.s.motion.y<=m.posoptions[1].y+60))					
			m.grand=6;//sur audiomute
		else if ((m.choix_boutons==1)&&(inp.s.motion.x>=m.posoptions[2].x)&&(inp.s.motion.x<=m.posoptions[2].x+200)&&(inp.s.motion.y>=m.posoptions[2].y)&&(inp.s.motion.y<=m.posoptions[2].y+50))
			m.grand=7;//sur barre son

			//=============Play=============
		else if (((m.choix_boutons==0)&&(m.mode==1))&&((inp.s.motion.x>=m.posplay[1].x)&&(inp.s.motion.x<=m.posplay[1].x+180)&&(inp.s.motion.y>=m.posplay[1].y)&&(inp.s.motion.y<=m.posplay[1].y+70)))
			m.grand=8;//Solo
		else if (((m.choix_boutons==0)&&(m.mode==1))&&((inp.s.motion.x>=m.posplay[2].x)&&(inp.s.motion.x<=m.posplay[2].x+180)&&(inp.s.motion.y>=m.posplay[2].y)&&(inp.s.motion.y<=m.posplay[2].y+70)))
			m.grand=9;//Multi

		else if (((m.choix_boutons==0)&&(m.mode==2))&&((inp.s.motion.x>=m.posplay[3].x)&&(inp.s.motion.x<=m.posplay[3].x+180)&&(inp.s.motion.y>=m.posplay[3].y)&&(inp.s.motion.y<=m.posplay[3].y+70)))
			m.grand=10;//New game
		else if (((m.choix_boutons==0)&&(m.mode==2))&&((inp.s.motion.x>=m.posplay[4].x)&&(inp.s.motion.x<=m.posplay[4].x+180)&&(inp.s.motion.y>=m.posplay[4].y)&&(inp.s.motion.y<=m.posplay[4].y+70)))
			m.grand=11;//Load game

		else if (((m.choix_boutons==0)&&(m.mode==3))&&((inp.s.motion.x>=m.posplay[10].x)&&(inp.s.motion.x<=m.posplay[10].x+180)&&(inp.s.motion.y>=m.posplay[10].y)&&(inp.s.motion.y<=m.posplay[10].y+70)))
			m.grand=14;//icone qui affiche menu pause

			//=============Exit=============
		else if ((m.choix_boutons==3)&&((inp.s.motion.x>=m.posoptions[11].x)&&(inp.s.motion.x<=m.posoptions[11].x+180)&&(inp.s.motion.y>=m.posoptions[11].y)&&(inp.s.motion.y<=m.posoptions[11].y+70)))
			m.grand=12;//YES
		else if ((m.choix_boutons==3)&&((inp.s.motion.x>=m.posoptions[12].x)&&(inp.s.motion.x<=m.posoptions[12].x+180)&&(inp.s.motion.y>=m.posoptions[12].y)&&(inp.s.motion.y<=m.posoptions[12].y+70)))
			m.grand=13;//NO

			//=============Sauvegarde=============
		else if (((m.choix_boutons==0)&&(m.mode==5))&&((inp.s.motion.x>=m.pospause[10].x)&&(inp.s.motion.x<=m.pospause[10].x+180)&&(inp.s.motion.y>=m.pospause[10].y)&&(inp.s.motion.y<=m.pospause[10].y+70)))
			m.grand=19;//YES (save)
		else if (((m.choix_boutons==0)&&(m.mode==5))&&((inp.s.motion.x>=m.pospause[11].x)&&(inp.s.motion.x<=m.pospause[11].x+180)&&(inp.s.motion.y>=m.pospause[11].y)&&(inp.s.motion.y<=m.pospause[11].y+70)))
			m.grand=20;//NO (don't save)

			//=============Menu pause=============
		else if (((m.choix_boutons==0)&&(m.mode==4))&&((inp.s.motion.x>=m.pospause[1].x)&&(inp.s.motion.x<=m.pospause[1].x+180)&&(inp.s.motion.y>=m.pospause[1].y)&&(inp.s.motion.y<=m.pospause[1].y+70)))
			m.grand=15;//resume
		else if (((m.choix_boutons==0)&&(m.mode==4))&&((inp.s.motion.x>=m.pospause[2].x)&&(inp.s.motion.x<=m.pospause[2].x+180)&&(inp.s.motion.y>=m.pospause[2].y)&&(inp.s.motion.y<=m.pospause[2].y+70)))
			m.grand=16;//restart
		else if (((m.choix_boutons==0)&&(m.mode==4))&&((inp.s.motion.x>=m.pospause[3].x)&&(inp.s.motion.x<=m.pospause[3].x+180)&&(inp.s.motion.y>=m.pospause[3].y)&&(inp.s.motion.y<=m.pospause[3].y+70)))
			m.grand=17;//settings 
		else if (((m.choix_boutons==0)&&(m.mode==4))&&((inp.s.motion.x>=m.pospause[4].x)&&(inp.s.motion.x<=m.pospause[4].x+180)&&(inp.s.motion.y>=m.pospause[4].y)&&(inp.s.motion.y<=m.pospause[4].y+70)))
			m.grand=18;//exit
		else 
			m.grand=-1;
	}
	return m;					
}
	
menu choix_menu(menu m,input inp)
{
		//******** Choisir la case avec la souris et les lettres p s c
	if ((inp.c.p==1)||((inp.s.posclick.x>=m.posboutons[0].x)&&(inp.s.posclick.x<=m.posboutons[0].x+180)&&(inp.s.posclick.y>=m.posboutons[0].y)&&(inp.s.posclick.y<=m.posboutons[0].y+70)))
		m.choix_boutons=0;//play
	else if ((inp.c.s==1)||((inp.s.posclick.x>=m.posboutons[1].x)&&(inp.s.posclick.x<=m.posboutons[1].x+180)&&(inp.s.posclick.y>=m.posboutons[1].y)&&(inp.s.posclick.y<=m.posboutons[1].y+70)))
		m.choix_boutons=1;//settings
	else if ((inp.c.c==1)||((inp.s.posclick.x>=m.posboutons[2].x)&&(inp.s.posclick.x<=m.posboutons[2].x+180)&&(inp.s.posclick.y>=m.posboutons[2].y)&&(inp.s.posclick.y<=m.posboutons[2].y+70)))
		m.choix_boutons=2;//credits
	else if ((inp.s.posclick.x>=m.posboutons[3].x)&&(inp.s.posclick.x<=m.posboutons[3].x+180)&&(inp.s.posclick.y>=m.posboutons[3].y)&&(inp.s.posclick.y<=m.posboutons[3].y+70))
		m.choix_boutons=3;//exit

		//****** Choisir la case avec les fleches du clavier
	if (inp.c.entrer==1)
	{
		if (m.grand==0)
			m.choix_boutons=0;//play
		else if(m.grand==1)
			m.choix_boutons=1;//settings
		else if (m.grand==2)
			m.choix_boutons=2;//credits
		else if (m.grand==3)
			m.choix_boutons=3;//exit
	}
	return m;
}

menu choix_settings(menu m,input inp)
{
		//******** Choisir la case avec la souris et echap
	if ((inp.s.posclick.x>=m.posoptions[0].x)&&(inp.s.posclick.x<=m.posoptions[0].x+60)&&(inp.s.posclick.y>=m.posoptions[0].y)&&(inp.s.posclick.y<=m.posoptions[0].y+60))
		m.choix_options=5;//fullscreen
	else if ((inp.s.posclick.x>=m.posoptions[1].x)&&(inp.s.posclick.x<=m.posoptions[1].x+60)&&(inp.s.posclick.y>=m.posoptions[1].y)&&(inp.s.posclick.y<=m.posoptions[1].y+60))
		m.choix_options=6;//audiomute
	else if ((m.choix_mode[2]==-1)&&(((inp.s.posclick.x>=m.posoptions[3].x)&&(inp.s.posclick.x<=m.posoptions[3].x+180)&&(inp.s.posclick.y>=m.posoptions[3].y)&&(inp.s.posclick.y<=m.posoptions[3].y+70))||(inp.c.echap==1)))
		m.choix_options=3;//return
	else if ((inp.s.posclick.x>=m.posoptions[2].x)&&(inp.s.posclick.x<=m.posoptions[2].x+200)&&(inp.s.posclick.y>=m.posoptions[2].y)&&(inp.s.posclick.y<=m.posoptions[2].y+50))
		m.choix_options=7;//barre son
	else if (((inp.s.posclick.x>=m.posboutons[3].x)&&(inp.s.posclick.x<=m.posboutons[3].x+180)&&(inp.s.posclick.y>=m.posboutons[3].y)&&(inp.s.posclick.y<=m.posboutons[3].y+70))||((inp.c.echap==1)&&(m.choix_mode[2]==3)))
		m.choix_boutons=3;//exit

		//******* Choisir la case avec les fleches du clavier 
	if (inp.c.entrer==1)
	{
		if (m.grand==3)
			m.choix_boutons=3;//exit
		else if (m.grand==4)
			m.choix_options=3;//return
	}
		//******* Traitement
	if (m.choix_mode[2]==3)
	{
		if (m.choix_boutons==3)
		{
			m.choix_mode[2]=-1;
			m.choix_boutons=0;
			m.mode=4;
			m.grand=-1;
		}
	}else if ((m.choix_mode[2]==-1)&&(m.choix_options==3))
		m.choix_boutons=-1;//retour au menu principal

	return m;
}

menu choix_credits(menu m,input inp)
{
		//******** Choisir la case avec la souris et echap
	if (((inp.s.posclick.x>=m.posoptions[3].x)&&(inp.s.posclick.x<=m.posoptions[3].x+180)&&(inp.s.posclick.y>=m.posoptions[3].y)&&(inp.s.posclick.y<=m.posoptions[3].y+70))||(inp.c.echap==1))
		m.choix_options=3;//return
	else if ((inp.s.posclick.x>=m.posboutons[3].x)&&(inp.s.posclick.x<=m.posboutons[3].x+180)&&(inp.s.posclick.y>=m.posboutons[3].y)&&(inp.s.posclick.y<=m.posboutons[3].y+70))
		m.choix_boutons=3;//exit
	
		//******** Choisir la case avec les fleches du clavier 
	if (inp.c.entrer==1)
	{
		if (m.grand==3)
			m.choix_boutons=3;//exit
		else if (m.grand==4)
			m.choix_options=3;//return
	}
		//******** Traitement 
	if (m.choix_options==3)
		m.choix_boutons=-1;
	return m;
}

menu choix_exit(menu m,input inp,int *continuer)
{
		//******** Choisir la case avec la souris et les lettres y n
	if ((inp.c.y==1)||((inp.s.posclick.x>=m.posoptions[11].x)&&(inp.s.posclick.x<=m.posoptions[11].x+180)&&(inp.s.posclick.y>=m.posoptions[11].y)&&(inp.s.posclick.y<=m.posoptions[11].y+70)))
		m.choix_options=4;//YES
	else if ((inp.c.n==1)||((inp.s.posclick.x>=m.posoptions[12].x)&&(inp.s.posclick.x<=m.posoptions[12].x+180)&&(inp.s.posclick.y>=m.posoptions[12].y)&&(inp.s.posclick.y<=m.posoptions[12].y+70)))
		m.choix_options=5;//NO

		//******** Choisir la case avec les fleches du clavier
	if (inp.c.entrer==1)
	{
		if (m.grand==12)
			m.choix_options=4;//yes
		else if (m.grand==13)
			m.choix_options=5;//no
	}
		//******* Traitement 
	if (m.choix_options==4)
	{
		if (m.mode==-1)
			*continuer=0;//fermer le jeu
		else
		{
			m.choix_boutons=-1;
			m.mode=-1; 
			for (int i=0;i<4;i++)
				m.choix_mode[i]=-1;
		}
	}else if (m.choix_options==5)
	{
		if (m.mode==-1)
			m.choix_boutons=-1;//revenir au menu principal
		else
		{
			m.choix_boutons=0;
			m.mode=4; 
		}
	}

	return m;
}

menu choix_play1(menu m,input inp)
{	
		//******** Choisir la case avec la souris et echap
	if ((inp.s.posclick.x>=m.posplay[1].x)&&(inp.s.posclick.x<=m.posplay[1].x+180)&&(inp.s.posclick.y>=m.posplay[1].y)&&(inp.s.posclick.y<=m.posplay[1].y+70))
		m.choix_mode[0]=1;//Solo
	else if ((inp.s.posclick.x>=m.posplay[2].x)&&(inp.s.posclick.x<=m.posplay[2].x+180)&&(inp.s.posclick.y>=m.posplay[2].y)&&(inp.s.posclick.y<=m.posplay[2].y+70))
		m.choix_mode[0]=2;//Multi
	else if (((inp.s.posclick.x>=m.posoptions[3].x)&&(inp.s.posclick.x<=m.posoptions[3].x+180)&&(inp.s.posclick.y>=m.posoptions[3].y)&&(inp.s.posclick.y<=m.posoptions[3].y+70))||(inp.c.echap==1))
		m.choix_mode[0]=3;//retour
	
		//******** Choisir la case avec les fleches du clavier
	if (inp.c.entrer==1)
	{
		if (m.grand==4)
			m.choix_mode[0]=3;//retour 
		else if (m.grand==8)
			m.choix_mode[0]=1;//solo
		else if (m.grand=9)
			m.choix_mode[0]=2;//multi
		else if (m.grand==4)
			m.choix_mode[0]=3;//retour 
	}
		//******* Traitement 
	if (m.choix_mode[0]==1)
		m.mode=2;//nouvelle partie ou charger une partie
	else if (m.choix_mode[0]==2)
		m.mode=3;//commencer la partie directement
	else if (m.choix_mode[0]==3)
	{
		for (int i=0;i<4;i++)
			m.choix_mode[i]=-1;
		m.choix_boutons=-1;//revenir au menu principal
	}
	return m;
}

menu choix_play2(menu m,input inp)
{
		//******** Choisir la case avec la souris et echap
	if ((inp.s.posclick.x>=m.posplay[3].x)&&(inp.s.posclick.x<=m.posplay[3].x+180)&&(inp.s.posclick.y>=m.posplay[3].y)&&(inp.s.posclick.y<=m.posplay[3].y+70))
		m.choix_mode[1]=1;//New game
	else if ((inp.s.posclick.x>=m.posplay[4].x)&&(inp.s.posclick.x<=m.posplay[4].x+180)&&(inp.s.posclick.y>=m.posplay[4].y)&&(inp.s.posclick.y<=m.posplay[4].y+70))
		m.choix_mode[1]=2;//Load game
	else if (((inp.s.posclick.x>=m.posoptions[3].x)&&(inp.s.posclick.x<=m.posoptions[3].x+180)&&(inp.s.posclick.y>=m.posoptions[3].y)&&(inp.s.posclick.y<=m.posoptions[3].y+70))||(inp.c.echap==1))
		m.choix_mode[1]=3;//retour

		//********* Choisir la case avec les fleches du clavier
 	if (inp.c.entrer==1)
	{
		if (m.grand==4)
			m.choix_mode[1]=3;//retour
		else if (m.grand==10)
			m.choix_mode[1]=1;//new
		else if (m.grand=11)
			m.choix_mode[1]=2;//load
	}
		//******** Traitement 
	if (m.choix_mode[1]==1)
		m.mode=3;
	else if (m.choix_mode[1]==2)
	{
		//appeler la fonction de recuperation
		m.mode=3;
	}else if (m.choix_mode[1]==3)
	{
		m.mode=1;//revenir en arriere: play1: solo ou multi
		for (int i=0;i<4;i++)
			m.choix_mode[i]=-1;
	}

	return m;
}

menu choix_pause (menu m,input inp)
{
		//******** Choisir la case avec la souris
	if ((inp.s.posclick.x>=m.pospause[1].x)&&(inp.s.posclick.x<=m.pospause[1].x+180)&&(inp.s.posclick.y>=m.pospause[1].y)&&(inp.s.posclick.y<=m.pospause[1].y+70))
		m.choix_mode[2]=1;//Resume
	else if ((inp.s.posclick.x>=m.pospause[2].x)&&(inp.s.posclick.x<=m.pospause[2].x+180)&&(inp.s.posclick.y>=m.pospause[2].y)&&(inp.s.posclick.y<=m.pospause[2].y+70))
		m.choix_mode[2]=2;//Restart
	else if ((inp.s.posclick.x>=m.pospause[3].x)&&(inp.s.posclick.x<=m.pospause[3].x+180)&&(inp.s.posclick.y>=m.pospause[3].y)&&(inp.s.posclick.y<=m.pospause[3].y+70))
		m.choix_mode[2]=3;//settings
	else if ((inp.s.posclick.x>=m.pospause[4].x)&&(inp.s.posclick.x<=m.pospause[4].x+180)&&(inp.s.posclick.y>=m.pospause[4].y)&&(inp.s.posclick.y<=m.pospause[4].y+70))
		m.choix_mode[2]=4;//Exit

		//******** Choisir la case avec les fleches du clavier
	if (inp.c.entrer==1)
	{
		if (m.grand==15)
			m.choix_mode[2]=1;//Resume
		else if (m.grand==16)
			m.choix_mode[2]=2;//Restart
		else if (m.grand==17)
			m.choix_mode[2]=3;//settings
		else if (m.grand==18)
			m.choix_mode[2]=4;//Exit
	}
		//******** Traitement 
	if (m.choix_mode[2]==1)//resume
	{
		//faire appel a la fonction de recuperation ?
		m.mode=3;
		m.choix_mode[2]=-1;
	}else if (m.choix_mode[2]==2)//restart
	{
		//reinitialiser toutes les variables perso ennemi enigme....
		m.mode=3;
		m.choix_mode[2]=-1;
	}else if (m.choix_mode[2]==3)//settings
		m.choix_boutons=1;
	else if (m.choix_mode[2]==4)
	{
		if (m.choix_mode[0]==1)
		{
			m.mode=5;//menu de sauvegarde
			m.choix_mode[2]=-1;
		}else if (m.choix_mode[0]==2)
		{
			m.choix_boutons=3;
			m.choix_mode[2]=-1;
		}
	}

	return m;
}

menu choix_sauvegarde(menu m, input inp)
{
		//******** Choisir la case avec la souris et les lettres y n 
	if ((inp.c.y==1)||((inp.s.posclick.x>=m.pospause[10].x)&&(inp.s.posclick.x<=m.pospause[10].x+180)&&(inp.s.posclick.y>=m.pospause[10].y)&&(inp.s.posclick.y<=m.pospause[10].y+70)))
		m.choix_mode[3]=1;//SAVE (yes)
	else if ((inp.c.y==1)||((inp.s.posclick.x>=m.pospause[11].x)&&(inp.s.posclick.x<=m.pospause[11].x+180)&&(inp.s.posclick.y>=m.pospause[11].y)&&(inp.s.posclick.y<=m.pospause[11].y+70)))
		m.choix_mode[3]=2;//DONT SAVE (no)

		//****** Choisir la case avec les fleches du clavier
	if (inp.c.entrer==1)
	{
		if (m.grand==19)
			m.choix_mode[3]=1;//save
		else if (m.grand==20)
			m.choix_mode[3]=2;//don't save
	}
		//******* Traitement
	if (m.choix_mode[3]==1)
	{
		//faire appel a la fonction de sauvegarde
		m.choix_boutons=-1;//retour au menu principal
		m.mode=-1;
		for (int i=0;i<4;i++)	
			m.choix_mode[i]=-1;
	}else if (m.choix_mode[3]==2)
	{
		m.choix_boutons=-1;//retour au menu principal
		m.mode=-1;
		for (int i=0;i<4;i++)	
			m.choix_mode[i]=-1;
	}

	return m;
}

void update_menu(menu *m,input *inp,int *continuer,Mix_Chunk *sound,int *barrougeX)
{
	*m= zoom_clavier(*m, *inp);
	*m=zoom_souris(*m,*inp);
	gestion_click_menu(*inp,*m,sound,&(*barrougeX));

	m->choix_options=-1;

	if (m->choix_boutons==-1)
		*m=choix_menu(*m,*inp);
	else if (m->choix_boutons==1)
		*m=choix_settings(*m,*inp);
	else if (m->choix_boutons==2)
		*m=choix_credits(*m,*inp);
	else if (m->choix_boutons==3)
		*m=choix_exit(*m,*inp,&(*continuer));
	else if (m->choix_boutons==0)
	{
		if (m->mode==-1)
		{
			for (int i=0;i<4;i++)
				m->choix_mode[i]=-1;
			m->mode=1;
		}else if (m->mode==1)
			*m=choix_play1(*m,*inp);
		else if (m->mode==2)
			*m=choix_play2(*m,*inp);
		else if ((m->mode==3)&&((inp->c.espace==1)||((inp->s.posclick.x>=m->posplay[10].x)&&(inp->s.posclick.x<=m->posplay[10].x+55)&&(inp->s.posclick.y>=m->posplay[10].y)&&(inp->s.posclick.y<=m->posplay[10].y+55))))
			m->mode=4;//menu icone
		else if (m->mode==4)
			*m=choix_pause(*m,*inp);
		else if (m->mode==5)
			*m=choix_sauvegarde(*m,*inp);
	}	

	init_input(&(*inp));
}

void liberer_menu(menu *m)
{	
	for (int k=0;k<15;k++)
		SDL_FreeSurface(m->options[k]);

	for(int i=0;i<7;i++)
		SDL_FreeSurface(m->back[i]);
	
	for (int j=0;j<10;j++)
		SDL_FreeSurface(m->boutons[j]);
	
	for (int h=0;h<19;h++)
		SDL_FreeSurface(m->play[h]);	

	SDL_FreeSurface(m->txt.texte);
	TTF_CloseFont(m->txt.police);
}
