// Puissance 4:
// -Un clic sur une case grise pour choisir ou l'on mets son pion pour le joueur humain (ROUGE)
// IA de base (== random) pour le joueur jaune
// touche F1 pour reinitialiser le tableau de jeu
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#pragma comment (lib, "sdl.lib")
#pragma comment (lib, "sdlmain.lib")
 
#define LARGEURG    50
#define HAUTEURG    50
#define LARGEURP    50
#define HAUTEURP    50
#define BORD 5
 
#define  VIDE ' '
#define ROUGE 'x'
#define JAUNE 'o'
 
#define NB_COLONNES 7
#define NB_LIGNES 6
 
#define TRUE 1
#define FALSE 0
 
typedef struct
{
    int dg;
    int vert;
    int dd;
    int horz;
}Case ;
 
SDL_Surface *ecran = NULL,
        *Sgrille = NULL,
        *prouge = NULL,
        *pjaune = NULL,
        *bouton[7] = {NULL};
 
typedef struct
{
    char grille[NB_COLONNES][NB_LIGNES];  // la grille de jeu
    int player; // TRUE: au joueur ROUGE(humain) de jouer, FALSE: joueur JAUNE(ordinateur)
    int gameover; // TRUE quand la partie est terminée (par VICTOIRE, DEFAITE ou MATCH NUL)
    int nbcoups; // nombre de pions insérer depuis le debut de partie
    int humainOK; // indique que l'humain a joué, remis à faux une fois que l'ordi a joué
}Jeu;
 
void InitSDL()
{
    int i;
    // SDL
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(LARGEURG*NB_COLONNES+BORD*(NB_COLONNES-1), 480, 32 ,SDL_HWSURFACE | SDL_DOUBLEBUF);
 
    Sgrille = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEURG, HAUTEURG, 32, 0, 0, 0, 0);
    SDL_FillRect(Sgrille, NULL, SDL_MapRGB(Sgrille->format, 0, 0, 255));
 
    prouge = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCALPHA, LARGEURP, HAUTEURP, 32, 0, 0, 0, 0);
    SDL_FillRect(prouge, NULL, SDL_MapRGB(prouge->format, 255, 0, 0));
 
    pjaune = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCALPHA, LARGEURP, HAUTEURP, 32, 0, 0, 0, 0);
    SDL_FillRect(pjaune, NULL, SDL_MapRGB(pjaune->format, 255, 255, 0));
 
    for (i = 0; i < 7; i++)
    {
        bouton[i] = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCALPHA, LARGEURG, HAUTEURG, 32, 0, 0, 0, 0);
        SDL_FillRect(bouton[i], NULL, SDL_MapRGB(bouton[i]->format, 128-i, 128-i, 128-i));
    }
}
 
void InitJEU(Jeu * j)
// Reinitialise la grille de jeu et les variables
{
    int w, h;
 
    //JEU
    for(w = 0; w < NB_COLONNES; w++)
    {
        for(h = 0; h < NB_LIGNES; h++)
        {
            j->grille[w][h]=VIDE; // on initialise la tableau pour qu'il soit vide au debut
        }
    }
    j->player = TRUE; // TRUE: au joueur ROUGE(humain) de jouer, FALSE: joueur JAUNE(ordinateur)
    j->gameover = FALSE; // TRUE quand la partie est terminée (par VICTOIRE, DEFAITE ou MATCH NUL)
    j->nbcoups = 0;
    j->humainOK = FALSE;
    printf("Initialisation du jeu.\n");
}
 
int coupvalide(char grille[NB_COLONNES][NB_LIGNES], int colonne) // numero entre 0 et 6 indiquant la colonne jouée
{
    int y;
    int lignefree=-1; // contient le numero de ligne de la case qui est libre pour cette colonne, -1 si la colonne est pleine
 
    colonne -=1; // pour passer de 1..NB_COLONNES à 0..NB_COLONNES-1
 
    if (colonne < 0 || colonne >= NB_COLONNES)
    {
        return FALSE; // si le numero de colonne est en dehors des bornes, le coup n'est pas valide
    }
 
    for ( y = NB_LIGNES-1; y >=0 ; y--) //on part du haut ...
    {
        if (grille[colonne][y] == VIDE) //... et si on trouve une case vide...
            lignefree = y; // ... on note la position de la dernière case vde trouvée
    }
 
    if (lignefree== -1) // aucune case vide n'a été trouvée
    {
        return FALSE; // si la colonne est pleine, le coup n'est pas valide
    }
    return TRUE;
}
 
int check(char grille[NB_COLONNES][NB_LIGNES])
//  Principe:
//  Additioner le contenu de la case adjacente correcte (->meme couleur)
//  au contenu de la case courante.
{
    Case game[NB_COLONNES][NB_LIGNES];
    int ligne, colonne;
    for ( ligne = 0; ligne < NB_LIGNES ; ligne++)
    {
        for ( colonne = 0; colonne < NB_COLONNES; colonne++)
        {
            //  Par defaut il y a 1 pion sur 4 d'aligner correctement
            game[colonne][ligne].horz=1;
            game[colonne][ligne].vert=1;
            game[colonne][ligne].dg=1;
            game[colonne][ligne].dd=1;
        }
    }
 
    // pour le horizontal
    for ( ligne = 0; ligne < NB_LIGNES ; ligne++)
    {
        for ( colonne = 1; colonne < NB_COLONNES; colonne++)
        {
            if ((grille[colonne][ligne]==grille[colonne-1][ligne])&&(grille[colonne][ligne]!=VIDE))
                // meme couleur
            {
                game[colonne][ligne].horz=game[colonne-1][ligne].horz+1;
                if (game[colonne][ligne].horz==4)
                    return TRUE;
            }
        }
    }
    // pour le vertical
    for ( ligne = 1; ligne < NB_LIGNES ; ligne++)
    {
        for ( colonne = 0; colonne < NB_COLONNES; colonne++)
        {
            if ((grille[colonne][ligne]==grille[colonne][ligne-1])&&(grille[colonne][ligne]!=VIDE))
                // meme couleur
            {
                game[colonne][ligne].vert=game[colonne][ligne-1].vert+1;
                if (game[colonne][ligne].vert==4)
                    return TRUE;
            }
        }
    }
    // pour le diagonal gauche:de bas à gauche vers haut à droite
    for ( ligne = 1; ligne < NB_LIGNES ; ligne++)
    {
        for ( colonne = 0; colonne < NB_COLONNES-1; colonne++)
        {
            if ((grille[colonne][ligne]==grille[colonne+1][ligne-1])&&(grille[colonne][ligne]!=VIDE))
                // meme couleur
            {
                game[colonne][ligne].dg=game[colonne+1][ligne-1].dg+1;
                if (game[colonne][ligne].dg==4)
                    return TRUE;
            }
        }
    }
    // pour le diagonal droite:de haut à gauche vers bas à droite
    for ( ligne = 1; ligne < NB_LIGNES ; ligne++)
    {
        for ( colonne = 1; colonne < NB_COLONNES; colonne++)
        {
            if ((grille[colonne][ligne]==grille[colonne-1][ligne-1])&&(grille[colonne][ligne]!=VIDE))
                // meme couleur
            {
                game[colonne][ligne].dd=game[colonne-1][ligne-1].dd+1;
                if (game[colonne][ligne].dd==4)
                    return TRUE;
            }
        }
    }
    return FALSE;
}
 
void joue(Jeu *j, int colonne )
//  colonne entre 1 et NB_COLONNES inclus
{
    int lignefree=-1; // contient le numero de ligne de la case qui est libre pour cette colonne, -1 si la colonne est pleine
    int y;
 
    //même code que coupvalide(), mais nécessaire pour avoir lignefree positionné à la plus basse case libre de la colonne
    colonne -=1; // pour que colonne puisse indicer un tableau partant de 0 à NB_COLONNES exclus
    if (colonne < 0 || colonne >= NB_COLONNES)  // ne devrait pas arriver à ce stade si coupvalide() a été appelé avant cette fonction
    {
        return ; // si le numero de colonne est en dehors des bornes, le coup n'est pas valide
    }
    for ( y = NB_LIGNES-1; y >=0 ; y--)
    {
        if (j->grille[colonne][y] == VIDE)
            lignefree = y;
    }
    if (lignefree== -1) // ne devrait pas arriver a ce stade si coupvalide() a été appelé avant cette fonction
    {
        return;
    }
 
    j->grille[colonne][lignefree]= (j->player == FALSE) ? JAUNE:ROUGE; // on remplit la grille par le coup joué
    printf("%s a joue grille[%d][%d]\n", (j->player == FALSE) ? "JAUNE":"ROUGE", colonne+1, lignefree+1);
}
 
int joueur2IA(int quisuisje, const char grille[NB_COLONNES][NB_LIGNES])
{
    int col;
    static int once = FALSE;
    if (once == FALSE)
    {
        srand(time(NULL));
        once = TRUE;
    }
    col = (rand() % NB_COLONNES) + 1; // donne un nombre entre 1 et NB_COLONNES:
    return col;
}
 
void affichegrille(char grille[NB_COLONNES][NB_LIGNES])
{
    int i = 0, x, y;
    SDL_Rect position;
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    for (i = 0; i < NB_COLONNES; i++)
    {
        position.x = (LARGEURG+BORD)*i;
        position.y = 0;
        SDL_BlitSurface(bouton[i], NULL, ecran, &position);
    }
 
    for (x = 0; x < NB_COLONNES; x++)
    {
        for (y = 0; y < NB_LIGNES; y++)
        {
            position.x = (LARGEURG+BORD)*x;
            position.y = 480+(HAUTEURG + BORD + (HAUTEURG+BORD)*y)*-1; // *-1 car le repère SDL est inversé en y: il va vers le bas donc il faut le redresser pour afficher le tableau vers le haut
             
            if (grille[x][y]!=VIDE)
            {
                if (grille[x][y]==ROUGE)
                    SDL_BlitSurface(prouge, NULL, ecran, &position);
                else
                    SDL_BlitSurface(pjaune, NULL, ecran, &position);
            }
            else
                SDL_BlitSurface(Sgrille, NULL, ecran, &position);
        }
    }
    SDL_Flip(ecran);
}
 
void libere()
{
    int i;
    printf("Cleaning...");
    SDL_FreeSurface(Sgrille);
    SDL_FreeSurface(prouge);
    SDL_FreeSurface(pjaune);
    for (i = 0; i < 7; i++)
        SDL_FreeSurface(bouton[i]);
 
    SDL_Quit();
    printf("Done\n");
}
 
Uint32 getpixel(SDL_Surface *surface, int x, int y)
// trouvé sur le wiki je crois
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
 
    switch(bpp) {
    case 1:
        return *p;
        break;
 
    case 2:
        return *(Uint16 *)p;
        break;
 
    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;
 
    case 4:
        return *(Uint32 *)p;
        break;
 
    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}
 
int main (int argc, char *argv[])
{
    // variables liées a l'affichage SDL
    SDL_Event event;
    int continuer = TRUE; // TRUE tant que pas d'evenement 'quitter'
    Uint8 r, g, b, a;
 
    //variables liées a la logique du puissance4
    Jeu puissance4;
    int colonne;
    InitSDL();
    InitJEU(&puissance4);
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = FALSE;
                break;
 
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_F1: // la touche F1: nouveau jeu
                        InitJEU(&puissance4);
                        break;
                }
                break;
 
            case SDL_MOUSEBUTTONUP:
                r=g=b=a=0;
                SDL_GetRGB(getpixel(ecran, event.button.x, event.button.y), ecran->format,  &r,  &g,  &b);
                if (r==g && g==b && b!=0)
                {
                    //printf("RGBA: (%d, %d, %d) - bouton = %d\n", r, g, b, 128-r);
                    if (coupvalide(puissance4.grille, 128-r +1))
                    {
                        colonne = 128-r +1;
                        puissance4.humainOK = TRUE;
                    }
                    else
                        printf("Coup NON Valide: %d\n", 128-r+1);
                }
                break;
        }
        if (puissance4.humainOK && puissance4.gameover != TRUE)
        {
            if (puissance4.player != TRUE) // au tour de l'ordi
            {
                do
                {
                    colonne = joueur2IA(puissance4.player, puissance4.grille);
                }while(coupvalide(puissance4.grille, colonne)==FALSE); // tant qu'il n'est pas possible de jouer là, on redemande
                puissance4.humainOK = FALSE;    // quand l'ordi a joué, il ne faut plus rejouer tant que l'humain n'a pas jouer!
            }
            joue(&puissance4, colonne);
            puissance4.nbcoups++;
            if (check(puissance4.grille)==TRUE)
            {
                puissance4.gameover = TRUE;
                printf("Victoire de %s au %dieme coups!\n", puissance4.player == FALSE ? "JAUNE" : "ROUGE", puissance4.nbcoups);
            }
            else if (puissance4.nbcoups == NB_COLONNES*NB_LIGNES)
            {
                puissance4.gameover = TRUE;
                printf("Match NUL (%d coups)\n", puissance4.nbcoups);
            }
            puissance4.player = !puissance4.player; // au joueur suivant de jouer
        }
        affichegrille(puissance4.grille);
    }
    libere();
    return 0;
}
