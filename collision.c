 if(game->e.position.x< game->p1.position.x && game->p1.position.x < game->e.position.x+100  )
                {
                    
                    game->p1.position.x+=250;
                    game->v1.vie_restante--;
                    //printf("COLLISION\n");

                }
