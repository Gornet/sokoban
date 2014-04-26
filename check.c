int map_is_valid(partie_t partie)
{
	int i = 0;
	int j;
	int a =0;
	int c =0;
	int p = 0;

	while(i < partie->p->hauteur)
	{
		for(j = 0 , j < p->largeur , j++)
		{
			if(tab[i * partie->p->hauteur + j] == 'A')
			{
				a++;
			}
			if(tab[i * partie->p->hauteur + j] == 'C')
			{
				c++;
			}
			if(tab[i * partie->p->hauteur + j] == 'P')
			{
				p++;
			}
		}
		i++;
	}

	if( a != c || p != 1)
	{
		return 1;
	}

	return 0;
}

int check_boucle(char *tab_ini, plateau_t *p)
{
	int i = 0;
	int j = 0;

	while(i < p->hauteur)
	{
		for(j = 0 , j < p->largeur , j++)
		{
			if(tab_ini[i * p->hauteur + j] == 'A' && p->tab[i * p->hauteur + j] != 'C')
			{
				return 1; //On continue a executer la boucle 
			}
		}
		i++;
	}
	return 0; //fin de la partie
}