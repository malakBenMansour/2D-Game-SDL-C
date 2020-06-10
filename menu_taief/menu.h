#ifndef FONCTIONS_H_
#define FONCTIONS_H_
typedef struct clavier
{
	int haut;
	int bas;
	int droite;
	int gauche;
	int echap;
	int entrer;
	int espace;
	int a;
	int b;
	int c;
	int p; 
	int s;
	int y; 
	int n; 
	int w;
	int z;	
}clavier; 

typedef struct souris 
{
	int left; 
	int right; 
	int middle;
	SDL_Rect motion;
	SDL_Rect posclick;
}souris;

/*typedef struct manette 
{

}manette;*/
typedef struct input
{
	clavier c;
	souris s;
	//manette m;
}input;

typedef struct texte
{
	TTF_Font *police;
	SDL_Surface *texte; 
	SDL_Color couleur;
	SDL_Rect postxt;
}texte;

typedef struct menu
{
	SDL_Surface *back[7];
	SDL_Rect posback;
	SDL_Surface* boutons[10];//play settings credits exit design menuprincipal
	SDL_Rect posboutons[10];
	SDL_Surface* options[16];// fullscreen audiomute audiofull retour barresSon yes no background Exit
	SDL_Rect posoptions[16];
	SDL_Surface *play[19];//backgrounds solo multi new load icone resume restart 
	SDL_Rect posplay[13];
	SDL_Rect pospause[14];//Resume Restart Settings Exit yes no backgrounds
	texte txt;
	int intro;
	int choix_boutons;// 0=play ; 1=settings;  2=credits; 3=exit 
	int choix_options;// 0=fullscreen; 1=audio; 2=barreSon; 3=return; 4=yes; 5=no; 6=save; 7=dontSave
	int grand; //Le bouton apparait en plus grand lorsque le joueur est dessus (clavier + souris)
	int mode;//1=Solo ou multi ; 2=New ou load ; 3=le jeu demarre; 4=minimenu ; 5=Sauvegarde ;
	int choix_mode[4];//0=Solo(1)-Multi(2)-return(3); 1=New(1)-Load(2)-return(3); 2=resume(1)-restart(2)-settings(3)-exit(4); 3=save(1)-dontsave(2)
}menu;

void musique(Mix_Music *music);
void init_menu(menu *m,SDL_Surface *ecran);
void init_input(input *inp);

menu afficher_intro(menu m,SDL_Surface *ecran);
void afficher_menu(menu m,SDL_Surface *ecran);
void afficher_play1(menu m,SDL_Surface *ecran);	
void afficher_play2(menu m,SDL_Surface *ecran);
void afficher_play(menu m,SDL_Surface *ecran);
void afficher_pause(menu m,SDL_Surface *ecran);
void afficher_save(menu m,SDL_Surface *ecran);
void afficher_settings(menu m,SDL_Surface *ecran,int *volume,int barrougeX,int *full);
void afficher_credits(menu m,SDL_Surface *ecran);
void afficher_exit(menu m,SDL_Surface *ecran);

void fullscreen(SDL_Surface *ecran,int *full);

void get_input_menu(input *inp,Mix_Chunk* sound,int *continuer);
void gestion_click_menu(input inp,menu m,Mix_Chunk *sound,int *barrougeX);//+gestion son 

menu zoom_clavier(menu m, input inp);
menu zoom_souris(menu m,input inp);

menu choix_menu(menu m,input inp);
menu choix_settings(menu m,input inp);
menu choix_credits(menu m,input inp);
menu choix_exit(menu m,input inp,int *continuer);
menu choix_play1(menu m,input inp);
menu choix_play2(menu m,input inp);
menu choix_pause (menu m,input inp);
menu choix_sauvegarde(menu m, input inp);

void update_menu(menu *m,input *inp,int *continuer,Mix_Chunk *sound, int *barrougeX);

void liberer_menu(menu *m);

#endif
