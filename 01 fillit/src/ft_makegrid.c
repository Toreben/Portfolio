/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_makegrid.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/03 23:15:29 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 15:21:04 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_makegrid(int size)
{
	char	**map;
	int		i;
	int		j;

	i = -1;
	if (!(map = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	map[size] = NULL;
	while (++i < size)
	{
		map[i] = (char*)malloc(sizeof(char) * (size + 1));
		j = -1;
		while (++j < size)
			map[i][j] = '.';
		map[i][size] = '\0';
	}
	return (map);
}
