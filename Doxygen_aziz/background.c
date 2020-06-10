/**
* @file background.c
*/



#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"


/**
* @brief To initialize the background b .
* @param b the background
* @param url the url of the image 
* @return Nothing
*/

void initBckg (background * b, char url[]){
b->img = IMG_Load (url);
b->bckg.x = 0;
b->bckg.y = 0;
b->bckg.w = b->img->w;
b->bckg.h = b->img->h;
}
void showBckg (SDL_Surface * screen, background b){
SDL_BlitSurface (b.img, &(b.bckg), screen, NULL);
}
void scrollToLeft (background * b){
if (b->bckg.x != 0)
b->bckg.x--;
}
void scrollToRight (background * b){
if (b->bckg.w - b->bckg.x != CAMERA_W)
b->bckg.x++;
}
