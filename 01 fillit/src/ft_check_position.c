/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_position.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 19:47:53 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 13:11:24 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_position(char **map, t_tetri *tetri, int a, int b)
{
	int size;
	int i;

	i = 0;
	size = ft_strlen(map[i]);
	if ((a + (tetri->sharp2).y >= 0 && a + (tetri->sharp2).y < size) &&
		(a + (tetri->sharp3).y >= 0 && a + (tetri->sharp3).y < size) &&
		(a + (tetri->sharp4).y >= 0 && a + (tetri->sharp4).y < size) &&
		(b + (tetri->sharp2).x >= 0 && b + (tetri->sharp2).x < size) &&
		(b + (tetri->sharp3).x >= 0 && b + (tetri->sharp3).x < size) &&
		(b + (tetri->sharp4).x >= 0 && b + (tetri->sharp4).x < size))
	{
		if (map[a][b] == '.'
				&& map[a + (tetri->sharp2).y][b + (tetri->sharp2).x] == '.'
				&& map[a + (tetri->sharp3).y][b + (tetri->sharp3).x] == '.'
				&& map[a + (tetri->sharp4).y][b + (tetri->sharp4).x] == '.')
		{
			map[a][b] = tetri->lettre;
			map[a + (tetri->sharp2).y][b + (tetri->sharp2).x] = tetri->lettre;
			map[a + (tetri->sharp3).y][b + (tetri->sharp3).x] = tetri->lettre;
			map[a + (tetri->sharp4).y][b + (tetri->sharp4).x] = tetri->lettre;
			return (1);
		}
	}
	return (0);
}
