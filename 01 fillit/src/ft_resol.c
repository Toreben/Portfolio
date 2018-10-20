/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_resol.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 21:08:02 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 15:33:35 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_next_square(int nb)
{
	int		i;

	i = 2;
	nb *= 4;
	while (i * i < nb)
		i++;
	return (i);
}

static char	**ft_rm(char **grille, char lettre)
{
	int i;
	int j;

	i = 0;
	while (grille[i])
	{
		j = 0;
		while (grille[i][j])
		{
			if (grille[i][j] == lettre)
				grille[i][j] = '.';
			j++;
		}
		i++;
	}
	return (grille);
}

static void	ft_printgrille(char **grille)
{
	int a;

	a = -1;
	while (grille[++a])
		ft_putendl(grille[a]);
}

static int	ft_calcul(char **grille, t_tetri *list, int size)
{
	int		i;
	int		j;

	if (list == NULL)
		return (1);
	i = 0;
	while (grille[i])
	{
		j = 0;
		while (grille[i][j])
		{
			if (ft_check_position(grille, list, i, j))
			{
				if (ft_calcul(grille, list->next, size))
					return (1);
				else
					grille = ft_rm(grille, list->lettre);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		ft_resol(t_tetri *list)
{
	int		i;
	char	**grille;
	int		size_min;

	size_min = ft_next_square(ft_calcul_size_min(list));
	if (!(grille = ft_makegrid(size_min)))
		return ;
	while (!ft_calcul(grille, list, size_min))
	{
		i = -1;
		while (++i <= size_min)
			free(grille[i]);
		free(grille);
		if (!(grille = ft_makegrid(++size_min)))
			return ;
	}
	ft_printgrille(grille);
}
