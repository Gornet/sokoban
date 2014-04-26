
#include "../includes/ft_sokoban.h"

void	ft_sokoban( char *location )
{
	char	**map;

	map = ft_read_file(location);
	if (map)
		printf("Bon\n");
	else
		printf("error");
}
