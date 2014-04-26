#include "../includes/sokoban.h"

t_bool	ft_check_extension( char *extension )
{
	char    *ext;
	int     j;
	int     i;

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
