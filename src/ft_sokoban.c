
#include "../includes/ft_sokoban.h"

void	ft_sokoban( char *location )
{
	char	*map;

	map = ft_read_file(location);
	if (map)
	{
		printf("map :\n%s\n", map );
/*
		alloc_memoire_partie( partie );
		partie->score = score;
		alloc_memoire_plateau( partie->p );
		alloc_memoire_plateau( partie->tampon );
		partie->p->largeur = ft_get_width( location );
		partie->p->hauteur = ft_get_height( location );
		alloc_memoire_tableau( partie->p );
		partie->tampon->largeur = partie->p->largeur;
		partie->tampon->hauteur = partie->p->hauteur;
		alloc_memoire_tableau( partie->tampon );
		plateau( partie->p );
		tableau_tampon( partie->p, partie->tampon );
		afficher_tableau( partie->p );
		while( partie->p->tab[A] != 'C' )
		{
			printf("i = haut , k = bas\n");
			printf("j = gauche , l = droite\n ");
			printf("r = coup precedent\n");
			scanf(" %c",&c);
			printf("\n\n");
			deplacement( c, partie->p, partie->tampon );
			tableau_tampon( partie->p, partie->tampon );
			system( "clear" );
			printf( "COUP N'%d\n\n\n\n",partie->score );
			afficher_tableau( partie->p );
			partie->score++;
		}
		printf( "Vous avez reussi\n" );
		endgame( partie );
*/
	}
	else
		printf("error");
}
