#include "../includes/ft_sokoban.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1

int	ft_strlen( char *s1 )
{
	int	i;

	i = 0;
	while ( s1[i++] );
	return ( i );
}

int	main( int ac, char **av )
{
	char		c;
	partie_t	*partie;
	int		largeur;
	int		hauteur;
	int		score;
	static int	pos;

	if ( ac )
	{
		if ( av[1] )
		{
			if ( ft_check_location( av[1] ) )
			{
				if (ft_check_extension( av[1] ))
					ft_sokoban( av[1] );
				else
					printf("invalid extension\n");
			}
			else
				printf("invalid location\n");
		}
		else if ( av[1] == NULL )
		{
			largeur = 10;
			hauteur = 10;
			score = 1;
			alloc_memoire_partie( partie );
			partie->score = score;
			alloc_memoire_plateau( partie->p );
			alloc_memoire_plateau( partie->tampon );
			partie->p->largeur = largeur;
			partie->p->hauteur = hauteur;
			alloc_memoire_tableau( partie->p );
			partie->tampon->largeur = partie->p->largeur;
			partie->tampon->hauteur = partie->p->hauteur;
			alloc_memoire_tableau( partie->tampon );
			plateau( partie->p );
			tableau_tampon( partie->p, partie->tampon );
			afficher_tableau( partie->p );
			while( partie->p->tab[A] != 'C' )
			{	
				printf("Rentrez i pour aller en haut , k pour aller en bas ,");
				printf(" j pour aller a gauche , l pour aller a droite , ");
				printf("r pour revenir au coup precedent\n");
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
		}
	}
	return ( 0 );
}
