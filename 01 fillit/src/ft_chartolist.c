/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_chartolist.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 21:28:23 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 13:31:35 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static t_sharp	ft_init_sharp(char **strline, t_sharp *sharp)
{
	int		i;
	int		j;
	int		tmp;
	t_sharp sharp_dest;

	tmp = 0;
	i = sharp->y;
	while (i < 4 && !tmp)
	{
		j = -1;
		while (strline[i][++j] && !tmp)
		{
			if (strline[i][j] == '#')
			{
				strline[i][j] = '.';
				sharp_dest.x = j - sharp->x;
				sharp_dest.y = i - sharp->y;
				tmp = 1;
			}
		}
		i++;
	}
	return (sharp_dest);
}

static t_tetri	*ft_sharp(t_tetri *tetri, char **strline)
{
	t_sharp	sharp1;

	sharp1.x = 0;
	sharp1.y = 0;
	sharp1 = ft_init_sharp(strline, &sharp1);
	tetri->sharp2 = ft_init_sharp(strline, &sharp1);
	tetri->sharp3 = ft_init_sharp(strline, &sharp1);
	tetri->sharp4 = ft_init_sharp(strline, &sharp1);
	return (tetri);
}

t_tetri			*ft_chartolist(char **strline)
{
	t_tetri	*tmp;
	t_tetri	*ret;
	int		i;

	i = 0;
	tmp = ft_newtetri();
	ret = tmp;
	while (strline[i])
	{
		tmp->lettre = (i / 5) + 'A';
		tmp = ft_sharp(tmp, strline + i);
		if (strline[i + 4])
		{
			tmp->next = ft_newtetri();
			tmp = tmp->next;
		}
		i += ((strline[i + 4] ? 5 : 4));
	}
	return (ret);
}
