#include "../includes/ft_sokoban.h"

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
