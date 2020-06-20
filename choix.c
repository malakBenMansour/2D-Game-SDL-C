
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void choix(SDL_Surface *ecran)
{
    SDL_Surface  *image = NULL ;
    SDL_Rect rect;


 

    rect.x = 0 ;
    rect.y = 0 ;
    image = IMG_Load("menu/choix.png");
    printf("AAAAAAAAAAAAAAAAAAAAAAAAAaa0\n");
 
    SDL_BlitSurface(image , NULL, ecran, &rect);
    SDL_Event event;
    int continuer=1;
    SDL_Flip(ecran);
    FILE *fich;
    fich=fopen("choixperso","w");

    while (continuer==1)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {

        case SDL_QUIT:
            continuer=0;










        case SDL_MOUSEBUTTONDOWN:


            if(event.button.x < 500)
            {
                printf("YMIN\n");
                fprintf(fich,"1\n");
                continuer=0;

            }
            if(event.button.x > 500)
            {
                printf("YSAR\n");
                fprintf(fich,"2\n");
                continuer=0;
            }

        break;




        }

    }
    
    //SDL_Delay(3000);
    SDL_FreeSurface(image);
    fclose(fich);
  
 
}
















