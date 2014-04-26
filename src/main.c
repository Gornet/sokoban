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
		else if ( !av[1] )
			printf("unknown location\n");
	}
	return ( 0 );
}
