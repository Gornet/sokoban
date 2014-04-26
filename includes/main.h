
#ifndef	MAIN_H
# define	MAIN_H

/*Ajout des bibliotheques */
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>

 /*Les define*/
# define	N	40
# define 	A	1525

typedef struct			plateau_s
{
	char			*tab;
 	unsigned int		largeur;
	unsigned int		hauteur;
}				plateau_t;

typedef struct			partie_s
{
	struct plateau_s	*p;
	struct plateau_s	*tampon;
	int			score;
}				partie_t;



void	init_tableau(plateau_t *p);
void	afficher_tableau(plateau_t *p);
void	placer_robot(plateau_t *p);
void	placer_mur(plateau_t *p);
void	placer_caisse(plateau_t *p);
void	placer_arrive(plateau_t *p);
int	deplacement(char c , plateau_t *p,plateau_t *tampon);
void	detruire_plateau(plateau_t *p);
void	creer_plateau(plateau_t *p);
void	plateau(plateau_t *p);
char	contenu_case(plateau_t *p , int x , int y);
void	tableau_tampon(plateau_t *p, plateau_t *tampon);
void	tampon_inverse(plateau_t *p, plateau_t *tampon);
void	menu();
void	alloc_memoire_partie(partie_t *partie);
void	alloc_memoire_plateau(plateau_t *p); //X
void	alloc_memoire_tableau(plateau_t *p); //X
void	detruire_tab(char *tab);
void	detruire_plateau(plateau_t *p);
void	detruire_partie(partie_t *partie);
void	endgame(partie_t *partie);

#endif








