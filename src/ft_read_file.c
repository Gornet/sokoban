#include "../includes/ft_sokoban.h"

#include <stdlib.h>
#include <stdio.h>

char	*ft_read_file( char *location )
{
	FILE		*file;
	unsigned int	width;
	unsigned int	height;
	char		*map;
	char		*buff;
	
	file = fopen( location, "r" );
	if ( file )
	{
		fscanf(file, "%d %d", &width, &height);
		printf("largeur : %d\nhauteur : %d\n", width, height);
		if ((map = (char *) malloc(sizeof(char) * sizeof(width))))
		{			
			buff = (char *) malloc(sizeof(char) * sizeof(width));
			while ( fgets( buff, width, file ) )
			{
				printf("%s", buff);
				strcat( map, buff );
			}
			printf("%s\n", map);
			return ( map );
		}
	}
	else
		printf("Impossible to open file");
}
