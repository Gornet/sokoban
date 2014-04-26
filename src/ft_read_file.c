#include "../includes/ft_sokoban.h"

#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int	len;

	len = strlen(s1) + strlen(s2);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	strcpy(str, s1);
	strcat(str, s2);
	return (str);
}

char	*ft_read_file( char *location )
{
	FILE		*file;
	unsigned int	width;
	unsigned int	height;
	char		*map;
	char		*buff;
	char		*tmp;
	
	file = fopen( location, "r" );
	if ( file )
	{
		fscanf(file, "%d %d", &width, &height);
		printf("largeur : %d\nhauteur : %d\n", width, height);
		if ((map = (char *) malloc(sizeof(char) * sizeof(height * width + 1))))
		{		
			buff = (char *) malloc(sizeof(char) * sizeof(width));
			while ( fgets( buff, width, file ) )
			{
				tmp = buff;
 				tmp = strchr(buff ,'\n');
				if ( tmp ) *tmp = 0;		
				map = ft_strjoin( map, buff );
			}
			return ( map );
		}
	}
	else
		printf("Impossible to open file");
}
