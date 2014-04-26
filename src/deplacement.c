#include "../includes/main.h"

int deplacement(char c , plateau_t *p ,plateau_t *tampon)
{
	if(c == 'I'|| c == 'i')
	{
		int i = 0;
		int j = 0;

		while( i < p->hauteur)
		{
			for(j = 0 ; j < p->largeur ; j++)
			{
				if(p->tab[i * p->hauteur + j] == 'P' && p->tab[(i - 1) * p->hauteur + j] != 'M')
				{
					if(p->tab[(i - 1)* p->hauteur + j] == 'C' && p->tab[(i - 2)* p->hauteur + j] != 'M')
					{
						p->tab[i * p->hauteur + j] = '.';
						p->tab[ (i - 1 ) * p->hauteur +j] = 'P';
						p->tab[(i-2) * p->hauteur +j] = 'C';
						return 0;
					}
					if(p->tab[(i - 1)* p->hauteur + j] == 'C' && p->tab[(i - 2)* p->hauteur + j] == 'M')
						return ( 0 );
					p->tab[i * p->hauteur + j] = '.';
					p->tab[ (i - 1 ) * p->hauteur +j] = 'P';
					return ( 0 );
				}
			}
			i++;
		}
		return 0;

	}


	if(c == 'K'|| c == 'k')
	{
		int i = 0;
		int j = 0;

		while( i < p->hauteur)
		{
			for(j = 0 ; j < p->largeur ; j++)
			{
				if(p->tab[i * p->hauteur + j] == 'P' && p->tab[(i + 1)* p->hauteur + j] != 'M')
				{
					if(p->tab[(i + 1)* p->hauteur + j] == 'C' && p->tab[(i + 2)* p->hauteur + j] != 'M')
					{
						p->tab[i * p->hauteur + j] = '.';
						p->tab[ (i + 1 ) * p->hauteur +j] = 'P';
						p->tab[(i+2) * p->hauteur +j] = 'C';
						return 0;
					}
					if(p->tab[(i + 1)* p->hauteur + j] == 'C' && p->tab[(i + 2)* p->hauteur + j] == 'M')
					{
						return 0;
					}
					p->tab[i * p->hauteur + j] = '.';
					p->tab[ (i + 1 ) * p->hauteur +j] = 'P';
					return 0;
				}
			}
			i++;
		}
		return 0;

	}

	if(c == 'J' || c =='j')
	{
		int i = 0;
		int j = 0;

		while( i < p->hauteur)
		{
			for(j = 0 ; j < p->largeur ; j++)
			{
				if(p->tab[i * p->hauteur + j] == 'P' && p->tab[i * p->hauteur + j - 1 ] != 'M')
				{
					if(p->tab[i * p->hauteur + j -1] == 'C' && p->tab[i * p->hauteur + j -2] != 'M')
					{
						p->tab[i * p->hauteur + j] = '.';
						p->tab[i  * p->hauteur + j - 1] = 'P';
						p->tab[i * p->hauteur +j -2 ] = 'C';
						return 0;
					}
					if(p->tab[i * p->hauteur + j -1] == 'C' && p->tab[i * p->hauteur + j -2] == 'M')
					{
						return 0;
					}

					p->tab[i * p->hauteur + j] = '.';					p->tab[i  * p->hauteur + j - 1] = 'P';
					return 0;
				}
			}
			i++;
		}
		return 0;
	}

	if( c == 'L' || c == 'l')
	{
		//droite
		int i = 0;
		int j = 0;

		while( i < p->hauteur)
		{
			for(j = 0 ; j < p->largeur ; j++)
			{
				if(p->tab[i * p->hauteur + j] == 'P' && p->tab[i * p->hauteur + j + 1 ] != 'M')
				{
					if(p->tab[i * p->hauteur + j +1] == 'C' && p->tab[i * p->hauteur + j+2] != 'M')
					{
						p->tab[i * p->hauteur + j] = '.';
						p->tab[i  * p->hauteur + j + 1] = 'P';
						p->tab[i * p->hauteur +j +2 ] = 'C';
						return 0;
					}
					if(p->tab[i * p->hauteur + j +1] == 'C' && p->tab[i * p->hauteur + j +2] == 'M')
					{
						return 0;
					}

					p->tab[i * p->hauteur + j] = '.';
					p->tab[i  * p->hauteur + j + 1] = 'P';
					return 0;
				}
			}
			i++;
		}
	}

	while(c == 'R' || c == 'r')
	{
		tampon_inverse(p,tampon);
	}

	return 0;
}

