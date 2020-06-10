#ifndef SCOREVIE_H_
#define SCOREVIE_H_


typedef struct vie
{
    int vie_restante;
    SDL_Surface *vie_image;
    SDL_Rect vie_position;
    char vi[20];
} vie;
typedef struct score
{
    int score_courant;
    SDL_Surface *score_image;
    SDL_Rect score_position;
    char sco[20];
} score;
typedef struct temps
{
    int score_courant;
    SDL_Surface *temps_image;
    SDL_Rect temps_position;
    int  tempsinit;
    int tempsactuel;
    int tempsres;
    char tempsrestant[20];
} temps;



typedef struct coeur//une entite secondaire amentant la vie
{
    SDL_Rect pos_coeur;
    SDL_Surface *image;
    int changer;
} coeur;

void initscore_et_vie2(score *s, vie *v);
void initscore_et_vie1(score *s, vie *v);
void init_temps(temps *t);
void init_temps2(temps *t);
//initialisation
void vie_rest(vie *viee, int reponse_alaquestion); // verification d'un reponse vrai ou faux
void update_score3(score *scoree);
void update_score(score *scoree);
void update_score2(score *scoree);
void update_temps(temps *t);
void augmenter_vie(vie *viee);
//cette fonction sera utiliser si le joueur recupere une vie
void afficher_vie_et_score(score s, vie v, SDL_Surface *ecran);
void afficher_temps(temps t, SDL_Surface *ecran);
void free_vie_et_score(score scoree, vie viee);
void free_temps(temps t);
void generer_score_vie(score *scoree, vie *viee, SDL_Surface *ecran); // remplir le ttf par les nombrs actuel
void generer_temps(temps *t, SDL_Surface *ecran);
void intialiser_coeur(coeur *c);
void afficher_coeur(coeur c, SDL_Surface *screen);









#endif
