

void afficher(enemy *e,SDL_Surface *ecran)
{
SDL_Surface *img=NULL;
if(e->direction==1)
{
//SDL_BlitSurface(fond,NULL,ecran,&posfond);
SDL_BlitSurface(e->imgR[e->frame],NULL,ecran,&(e->position));
//SDL_Flip(ecran);
//SDL_Delay(150);

e->frame++;
if(e->frame==10)
{
e->frame=0;
}

}
else
{
//SDL_BlitSurface(fond,NULL,ecran,&posfond);
SDL_BlitSurface(e->imgL[e->frame],NULL,ecran,&(e->position));
//SDL_Flip(ecran);
//SDL_Delay(150);
e->frame++;
if(e->frame==10)
{
e->frame=0;
}
}
}
