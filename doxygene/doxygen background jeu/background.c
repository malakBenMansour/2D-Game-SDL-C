/**
* @file background.c
*/


#include "background.h"
#include <SDL/SDL_image.h>
/**
* @brief To charge the background b .
* @param b the background
* @param url the url of the image 
* @return Nothing
*/
int charger_Background(Background *B)
{

    B->backgroundImg = IMG_Load("maps/italie1.png");
    if (B->backgroundImg == NULL)
    {
        printf("erreur: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
/**
* @brief To charge the background b avec masque pour collision.
* @param b the background
* @param url the url of the image 
* @return Nothing
*/
}
int chargerBackgroundCollision(Background *B)
{

    B->backgroundImg = IMG_Load("maps/map1.png");
    if (B->backgroundImg == NULL)
    {
        printf("erreur: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}
int charger_Background2(Background *B)
{

    B->backgroundImg = IMG_Load("maps/fond.jpg");
    if (B->backgroundImg == NULL)
    {
        printf("erreur: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}
/**
* @brief To initialize the background b .
* @param b the background
* @param url the url of the image 
* @return Nothing
*/
void initBackground(Background *B)
{
    B->i = 0;
    B->back_Pos.x = 0;
    B->back_Pos.y = 0;
    B->back_Pos.w = SCREEN_W;
    B->back_Pos.h = SCREEN_H;
}

void blitBackground(Background *B, SDL_Rect *pos, SDL_Surface *screen)
{
    /*if(B->back_Pos.x>B->backgroundImg->w-SCREEN_W)
    	B->back_Pos.x=0;
    if(B->back_Pos.x<0)
    	B->back_Pos.x=B->backgroundImg->w-SCREEN_W;*/
    SDL_BlitSurface(B->backgroundImg, &(B->back_Pos), screen, pos);

}
/**
* @brief To free the background b .
* @param b the background
* @param url the url of the image 
* @return Nothing
*/
void freeBackground(Background *B)
{
    SDL_FreeSurface(B->backgroundImg);
}
