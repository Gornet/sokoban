#include "../includes/ft_sokoban.h"

t_bool  ft_check_location( char *location )
{
        char    *adress;
        char    *v_location;

        adress = "Plateaux/";
        v_location = location;
        while ( *v_location++ == *adress++ )
        {
                if ( *v_location == '/' )
                        return ( TRUE );
        }
        return ( FALSE );
}
