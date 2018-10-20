/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 18:12:47 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/12 01:49:55 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_open_read(char *av)
{
	int		fd;
	char	str[650];

	if ((fd = open(av, O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	if ((read(fd, str, 650)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	if ((close(fd)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	return (ft_strdup(str));
}

int			main(int ac, char **av)
{
	char	*str;

	if (ac != 2)
		ft_putendl("usage: ./fillit fichier.fillit");
	else
	{
		str = ft_open_read(av[1]);
		if (str != NULL)
		{
			if (!ft_check(str))
				ft_putendl("error");
			else
				ft_resol(ft_chartolist(ft_tetrasplit(str)));
		}
	}
	return (0);
}
