/**
* @file background.h
* @author wael
* @date Mai 14, 2020
*/
#include <SDL/SDL.h>
#define CAMERA_W 100
#define CAMERA_H 200
struct background
{
SDL_Rect bckg;
SDL_Surface *img;
};
typedef struct background background;
void initBckg (background * b, char url[]);
void showBckg (SDL_Surface * screen, background b);
void scrollToLeft (background * b);
void scrollToRight (background * b);
