#include "../includes/main.h"

char contenu_case(plateau_t *p , int x , int y)
{
	printf("%c", p->tab[x * p->largeur + y]);
	return p->tab[x * p->largeur + y];
}


void tableau_tampon(plateau_t *p, plateau_t *tampon)
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

void tampon_inverse(plateau_t *p, plateau_t *tampon)
{
	int i = 0;
	int j = 0;

	while(i < p->hauteur)
	{
		while(j < p->largeur)
		{
			p->tab[i * p->hauteur + j] = tampon->tab[i * p->hauteur +j];
			j++;
		}
		i++;
	}
}

void menu()
{
    	printf("************************************************************************************************");
	printf("*                                 Bienvenue sur Sokoban                                        *");
	printf("************************************************************************************************");
    	printf("*         -Si vous souhaitez jouer , tapez 1                                                   *");
    	printf("*         -Pour quitter , taper 2                                                              *");
    	printf("************************************************************************************************");
}

void	alloc_memoire_partie(partie_t *partie)
{
	partie = ( struct partie_s * )malloc( sizeof( struct partie_s ) );
}

void	alloc_memoire_plateau(plateau_t *p)
{
	p = ( struct plateau_s * )malloc( sizeof( struct plateau_s ) );
}

void	alloc_memoire_tableau(plateau_t *p)
{
	p->tab = (char*)malloc(sizeof(char) * (p->hauteur) * (p->largeur));
}

void	detruire_tab(char *tab)
{
	free(tab);
}

void	detruire_plateau(plateau_t *p)
{
	free(p);
}

void	detruire_partie(partie_t *partie)
{
	free(partie);
}

void	endgame(partie_t *partie)
{
	detruire_tab(partie->p->tab);
	detruire_tab(partie->tampon->tab);
	detruire_plateau(partie->p);
	detruire_plateau(partie->tampon);
	detruire_partie(partie);
}


