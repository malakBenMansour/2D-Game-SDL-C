

void Annim_Right(perso *p)
{
        p->position_Anim.x += perso_WIDTH;
    p->position_Anim.x = p->position_Anim.x % (perso_WIDTH *15);    
        p->position_Anim.y = perso_HEIGHT;
        
}
void Annim_Left(perso *p)
{    
        p->position_Anim.x += perso_WIDTH;

    p->position_Anim.x = p->position_Anim.x % (perso_WIDTH *15);
    p->position_Anim.y =0;

}
