#include <SDL/SDL.h>
#define CAMERA_W 100
#define CAMERA_H 200
/**
* @struct Background
* @brief struct for backround
*/
struct background
{
 SDL_Rect bckg; /*!< RECTANGLE*/
 SDL_Surface *img; /*!< SURFACE*/
};
typedef struct background background;
void initBckg (background * b, char url[]);
void showBckg (SDL_Surface * screen, background b);
void scrollToLeft (background * b);
void scrollToRight (background * b);*/
