#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "gestion.h"
#include "enigmeA.h"
#include "JEU.h"
#include"fonctiony.h"
#include "sauvegarde.h"

void update_save(save *s, acteur p, object e,int temps)
{
	s->posperso.x=p.positionimage.x; 
	s->posperso.y=p.positionimage.y; 
	s->posennemi.x=e.position.x; 
	s->posennemi.y=e.position.y; 
	s->temps=temps; 
	s->score=p.score; 
	s->vies=p.vie;
}

void enregistrer (save s,char nomfichier[])
{
	FILE *fichier=NULL;

	fichier=fopen(nomfichier,"wb");
	if (fichier !=NULL)
	{
		fwrite(&s,sizeof(save),1,fichier);
		printf("Sauvegarde reussie ! \n");	
		fclose (fichier);
	}else 
		printf("Impossible d'ouvrir le fichier !\n");
}

void recuperer (char nomfichier[],save *s)
{
	FILE *fichier=NULL; 
	
	fichier=fopen(nomfichier,"rb");
	if (fichier !=NULL)
	{
		fread(&(*s),sizeof(save),1,fichier);
		printf("Recuperation reussie ! \n");	
		fclose (fichier);
	}else 
		printf("Impossible d'ouvrir le fichier !\n");
}

void remplir_variables(save s, acteur *p, object *e,int *temps)
{
	p->positionimage.x=s.posperso.x; 
	p->positionimage.y=s.posperso.y; 
	p->vie=s.vies; 
	p->score=s.score; 
	
	e->position.x=s.posennemi.x; 
	e->position.y=s.posennemi.y; 
	e->Direction=s.direction_ennemi; 
	
	*temps=s.temps;
}

void verification_recuperer(acteur p, object e,int temps)
{
	printf("----------------- Structures acteur object et variable temps -----------------\n");
	printf("perso.x=%d ; perso.y= %d ; vie = %d score = %d\n",p.positionimage.x,p.positionimage.y,p.vie,p.score);
	printf("ennemi.x= %d ; ennemi.y= %d; direction= %d\n",e.position.x,e.position.y, e.Direction);
	printf("Temps = %d \n \n ",temps);
}

void verification_enregistrer(save s)
{
	printf("----------------- Structure save -----------------\n");
	printf("perso.x=%d ; perso.y= %d ; vie = %d score = %d\n",s.posperso.x,s.posperso.y,s.vies,s.score);
	printf("ennemi.x= %d ; ennemi.y= %d; direction= %d\n",s.posennemi.x,s.posennemi.y, s.direction_ennemi);
	printf("Temps = %d \n \n ",s.temps);

}
