#include "../includes/ft_sokoban.h"

char contenu_case(plateau_t *p , int x , int y)
{
	printf("%c", p->tab[x * p->largeur + y]);
	return p->tab[x * p->largeur + y];
}


void tableau_tampon(plateau_t *p, plateau_t *tampon) //Copie un tableau dans un autre
{
	int i = 0;
	int j = 0;

	while(i < p->hauteur)
	{
		while(j < p->largeur)
		{
			tampon->tab[i * p->hauteur + j] = p->tab[i * p->hauteur +j];
			j++;
		}
		i++;
	}
}


