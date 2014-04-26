#include "../includes/ft_sokoban.h"


void afficher_tableau(plateau_t *p) /* Affichage dun tableau selon lignes et colonnes*/
{
        int i = 0;
        int j = 0;

        while( i < p->hauteur)
        {
                for(j = 0 ; j < p->largeur ; j++)
                        printf(" %c", p->tab[i * p->hauteur +j]);
                printf("\n");
                i++;
        }
}
