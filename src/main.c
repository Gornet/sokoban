#include "../includes/main.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1

typedef enum
{
	FALSE = 0,
	TRUE  = 1
}			t_bool;

void	ft_putchar( char c)
{
	write( 1, &c, 1 );
}

void            ft_putnbr(int n)
{
        if (n <= 9 && n >= 0)
                ft_putchar(n + '0');
        else if (n < 0)
        {
                ft_putchar('-');
                ft_putnbr(-n);
        }
        else
        {
                ft_putnbr(n / 10);
                ft_putnbr(n % 10);
        }
}

void	ft_putstr( char *s )
{
	while ( *s )
	{
		ft_putchar( *s );
		s++;
	}
}

void	ft_putendl( char const *s )
{
        while ( *s )
        {
                ft_putchar( *s );
                s++;
        }
        ft_putchar( '\n' );
}

int	ft_strlen( char *s1 )
{
	int	i;

	i = 0;
	while ( s1[i++] );
	return ( i );
}

t_bool	ft_check_location( char *location )
{
	char	*adress;
	char	*v_location;

	adress = "Plateaux/";
	v_location = location;
	while ( *v_location++ == *adress++ )
	{
		if ( *v_location == '/' )
			return ( TRUE );
	}
	return ( FALSE );
}

t_bool	ft_check_extension( char *extension )
{
	char	*ext;
	int	j;
	int	i;

	i = 0;
	ext = ".map";
	while ( extension[i] )
	{
		if ( extension[i] == '.' )
		{
			j = 0;
			while ( extension[i + j] == ext[j])
				j++;
			return ((j == ft_strlen( ext )) ? TRUE : FALSE);
		}
		i++;
	}
}

void	ft_sokoban( char *location )
{
	int	fd;
	char	*buff[BUFFER_SIZE + 1];
	int	ret;

	if ( fd = open( location, O_RDONLY ) > 0 )
	{
		while (( ret = read( fd, buff, BUFFER_SIZE ) ))
		{
			buff[ret] = '\0';
			printf("%s", buff);
		}
	}
	
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
					ft_putendl("invalid extension");
			}
			else
				ft_putendl("invalid location");
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
