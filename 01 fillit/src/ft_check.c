/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 19:36:15 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/12 01:50:43 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_find_sharp(char **tetri)
{
	int y;
	int x;

	y = 0;
	while (tetri[y])
	{
		x = 0;
		while (tetri[y][x] != '#' && tetri[y][x])
			x++;
		if (tetri[y][x] == '#' && tetri[y][x])
		{
			if (ft_check_tetri(tetri, x, y))
				if (tetri[y + (5 - (y % 5)) - 1])
					y += (5 - (y % 5));
				else
					y += (5 - (y % 5) - 1);
			else
				return (0);
		}
		else
			y++;
	}
	return (1);
}

static int	ft_check_grid_line(char **strline)
{
	int x;
	int y;
	int nb_sharp;

	y = 0;
	while (strline[y] != NULL)
	{
		x = -1;
		if (!(y % 5))
			nb_sharp = 0;
		if (ft_strlen(strline[y]) != 4 && ft_strlen(strline[y]) != 0)
			return (0);
		while (strline[y][++x])
		{
			if (strline[y][x] != '.' && strline[y][x] != '#')
				return (0);
			if (strline[y][x] == '#')
				nb_sharp++;
		}
		y++;
		if (!((y + 1) % 5) && nb_sharp != 4)
			return (0);
	}
	return (1);
}

static int	ft_check_grid_size(char *str)
{
	int i;
	int nbline;

	i = -1;
	nbline = 0;
	while (str[++i])
	{
		if (str[i] == '\n')
			nbline++;
		if (str[i] == '\n' && str[i - 1] == '\n')
			if ((nbline % 5) != 0)
				return (0);
		if (129 < nbline)
			return (0);
	}
	return (!((nbline + 1) % 5));
}

int			ft_check(char *str)
{
	char **strline;

	if (!ft_check_grid_size(str))
		return (0);
	strline = ft_tetrasplit(str);
	if (!ft_check_grid_line(strline))
		return (0);
	if (!ft_find_sharp(strline))
		return (0);
	return (1);
}
