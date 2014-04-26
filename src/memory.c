#include "../includes/ft_sokoban.h"

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
