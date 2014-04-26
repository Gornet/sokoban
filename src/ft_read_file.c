#include "../includes/ft_sokoban.h"

#include <stdlib.h>
#include <stdio.h>

char	**ft_read_file( char *location )
{
	FILE		*file;
	unsigned int	width;
	unsigned int	height;
	unsigned int	index_i;
	char		**map;
	char		*buff;
	
	file = fopen( location, "r" );
	if ( file )
	{
		fscanf(file, "%d %d", &width, &height);
		printf("largeur : %d\nhauteur : %d\n", width, height);
		if ((map = (char **) malloc(sizeof(char*) * sizeof(height + 1))))
		{		
			index_i = 0;	
			buff = (char *) malloc(sizeof(char) * sizeof(width));
			while ( fgets( buff, width, file ) )
			{
				map[index_i] = strdup(buff);
				printf("%s", map[index_i]);
				index_i++;
			}
			return ( map );
		}
	}
	else
		printf("Impossible to open file");
}
