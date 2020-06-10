
#include "background.h"
#include <SDL/SDL_image.h>
int charger_Background(Background *B)
{

    B->backgroundImg = IMG_Load("maps/italie1.png");
    if (B->backgroundImg == NULL)
    {
        printf("erreur: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
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

void freeBackground(Background *B)
{
    SDL_FreeSurface(B->backgroundImg);
}
