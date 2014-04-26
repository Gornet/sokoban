#include "../includes/main.h"

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


void init_tableau(plateau_t *p) // Sert a initialise le tableau , que toutes les cases soient des points*/
{
	int i = 0;
	int j = 0;

	while( i < p->hauteur)
	{
		for(j = 0;j < p->largeur;j++)
			p->tab[i * p->hauteur + j]  = '.' ;
		i++;
	}
}



void placer_robot(plateau_t *p) /*On place le robot*/
{
	p->tab[1013] = 'P';
}

void placer_mur(plateau_t *p) /* on place les murs*/
{
	int i = 0;
	int j = 0;
	int x = p->hauteur -1;
	int a;
	int b;
	int z = 140;

	while (i < p->hauteur)
	{
		for(j = 0;j < p->largeur ;j++) /*Met des murs tout autour de la map*/
		{
			if(j == 0 || j == x || i == 0 || i == x)
			{
				p->tab[i * p->hauteur + j] = 'M';
			}
		}
		i++;
	}

	srand(time(NULL));
	for(i = 0 ; i < z ; i++) /*Place des murs aleatoirement sur la map*/
	{
		a = (rand()%(40));
		b = (rand()%(40));
		p->tab[a * p->hauteur + b] = 'M';
	}
}

void placer_caisse(plateau_t *p) /*Place la caisse*/
{
	p->tab[655] = 'C';
}

void placer_arrive(plateau_t *p) /*Place l'arrive*/
{
	p->tab[A] = 'A';
}

void plateau(plateau_t *p)
{
	init_tableau(p); /*On initialise un tableau ou on place des murs , le perso , la caisse et le point d'arrive*/
	placer_mur(p);
	placer_robot(p);
	placer_caisse(p);
	placer_arrive(p);
}

