

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>
#include "defs.h"
/**
* @struct Background
* @brief struct for backround
*/
struct Background
{
    SDL_Surface *backgroundImg;
    SDL_Rect back_Pos;
    int i;
};
typedef struct Background Background;

int charger_Background(Background *B);
int charger_Background2(Background *B);
int chargerBackgroundCollision(Background *B);
void initBackground(Background *B);
void freeBackground(Background *B);
void blitBackground(Background *B, SDL_Rect *pos, SDL_Surface *screen);

#endif
