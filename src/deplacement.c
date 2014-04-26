#include "../includes/ft_sokoban.h"

int deplacement(char c , plateau_t *p ) /*Fonction de deplacement*/
{


	//Jexpliquerais pour un seul cas le fontionnement de la fontion
	if(c == 'I'|| c == 'i')
	{
		//haut
		int i = 0;
		int j = 0;

		while( i < p->hauteur)
		{
			for(j = 0 ; j < p->largeur ; j++) //On parcoure le tableau
			{
				if(p->tab[i * p->hauteur + j] == 'P' && p->tab[(i - 1) * p->hauteur + j] != 'M') /*On cherche le perso puis on verifie si la case suivante
																								   dans la direction souhaitee n'est pas un mur*/
				{
					if(p->tab[(i - 1)* p->hauteur + j] == 'C' && p->tab[(i - 2)* p->hauteur + j] != 'M') /*Meme chose en cas de caisse a la case suivante et celle encore apres pas un mur*/
					{
						p->tab[i * p->hauteur + j] = '.';
						p->tab[ (i - 1 ) * p->hauteur +j] = 'P';
						p->tab[(i-2) * p->hauteur +j] = 'C';
						return 0;
					}
					if(p->tab[(i - 1)* p->hauteur + j] == 'C' && p->tab[(i - 2)* p->hauteur + j] == 'M') /*Cas ou il ya un mur apres une caisse dans la direction souhaitee*/
					{
						return 0;
					}
					p->tab[i * p->hauteur + j] = '.'; //Si il ny a pas de caisse
					p->tab[ (i - 1 ) * p->hauteur +j] = 'P';
					return 0;
				}
			}
			i++;
		}
		return 0;

	}


	if(c == 'K'|| c == 'k')
	{
		//derriere
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
		//gauche
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
	return 0;
}

