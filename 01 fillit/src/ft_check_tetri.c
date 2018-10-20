/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_tetri.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 04:59:04 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 01:58:05 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_tetri_part1(char **t, int x, int y, int max)
{
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= x + 2) && (x + 2 < max)
			&& (0 <= x + 3) && (x + 3 < max))
		if (t[y][x + 1] == '#' && t[y][x + 2] == '#' && t[y][x + 3] == '#')
			return (1);
	if ((0 <= y + 1) && (y + 1 < max) && (0 <= y + 2) && (y + 2 < max)
			&& (0 <= y + 3) && (y + 3 < max))
		if (t[y + 1][x] == '#' && t[y + 2][x] == '#' && t[y + 3][x] == '#')
			return (1);
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= y + 1) && (y + 1 < max))
		if (t[y][x + 1] == '#' && t[y + 1][x] == '#' && t[y + 1][x + 1] == '#')
			return (1);
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= y + 1) && (y + 1 < max)
			&& (0 <= x - 1) && (x - 1 < max))
		if (t[y][x + 1] == '#' && t[y + 1][x] == '#' && t[y + 1][x - 1] == '#')
			return (1);
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= y + 1) && (y + 1 < max)
			&& (0 <= y + 2) && (y + 2 < max))
		if (t[y + 1][x] == '#' && t[y + 1][x + 1] == '#'
				&& t[y + 2][x + 1] == '#')
			return (1);
	return (0);
}

static int	ft_check_tetri_part2(char **t, int x, int y, int max)
{
	if ((0 <= y + 1) && (y + 1 < max) && (0 <= x - 1) && (x - 1 < max)
			&& (0 <= y + 2) && (y + 2 < max))
		if (t[y + 1][x] == '#' && t[y + 1][x - 1] == '#'
				&& t[y + 2][x - 1] == '#')
			return (1);
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= y + 1) && (y + 1 < max)
			&& (0 <= y + 2) && (y + 2 < max))
		if (t[y + 1][x] == '#' && t[y + 2][x] == '#' && t[y + 2][x + 1] == '#')
			return (1);
	if ((0 <= y + 1) && (y + 1 < max) && (0 <= x - 1) && (x - 1 < max)
			&& (0 <= x - 2) && (x - 2 < max))
		if (t[y + 1][x] == '#' && t[y + 1][x - 1] == '#'
				&& t[y + 1][x - 2] == '#')
			return (1);
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= y + 1) && (y + 1 < max)
			&& (0 <= y + 2) && (y + 2 < max))
		if (t[y][x + 1] == '#' && t[y + 1][x + 1] == '#'
				&& t[y + 2][x + 1] == '#')
			return (1);
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= y + 1) && (y + 1 < max)
			&& (0 <= x + 2) && (x + 2 < max))
		if (t[y + 1][x] == '#' && t[y][x + 1] == '#' && t[y][x + 2] == '#')
			return (1);
	return (0);
}

static int	ft_check_tetri_part3(char **t, int x, int y, int max)
{
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= y + 1) && (y + 1 < max)
			&& (0 <= y + 2) && (y + 2 < max))
		if (t[y][x + 1] == '#' && t[y + 1][x] == '#' && t[y + 2][x] == '#')
			return (1);
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= y + 1) && (y + 1 < max)
			&& (0 <= x + 2) && (x + 2 < max))
		if (t[y + 1][x] == '#' && t[y + 1][x + 1] == '#'
				&& t[y + 1][x + 2] == '#')
			return (1);
	if ((0 <= y + 1) && (y + 1 < max) && (0 <= x - 1) && (x - 1 < max)
			&& (0 <= y + 2) && (y + 2 < max))
		if (t[y + 1][x] == '#' && t[y + 2][x] == '#' && t[y + 2][x - 1] == '#')
			return (1);
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= y + 1) && (y + 1 < max)
			&& (0 <= x + 2) && (x + 2 < max))
		if (t[y][x + 1] == '#' && t[y][x + 2] == '#' && t[y + 1][x + 2] == '#')
			return (1);
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= y + 1) && (y + 1 < max)
			&& (0 <= y + 2) && (y + 2 < max))
		if (t[y + 1][x] == '#' && t[y + 2][x] == '#' && t[y + 1][x + 1] == '#')
			return (1);
	return (0);
}

static int	ft_check_tetri_part4(char **t, int x, int y, int max)
{
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= y + 1) && (y + 1 < max)
			&& (0 <= x - 1) && (x - 1 < max))
		if (t[y + 1][x] == '#' && t[y + 1][x + 1] == '#'
				&& t[y + 1][x - 1] == '#')
			return (1);
	if ((0 <= y + 1) && (y + 1 < max) && (0 <= x - 1) && (x - 1 < max)
			&& (0 <= y + 2) && (y + 2 < max))
		if (t[y + 1][x] == '#' && t[y + 1][x - 1] == '#' && t[y + 2][x] == '#')
			return (1);
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= y + 1) && (y + 1 < max)
			&& (0 <= x + 2) && (x + 2 < max))
		if (t[y][x + 1] == '#' && t[y][x + 2] == '#' && t[y + 1][x + 1] == '#')
			return (1);
	if ((0 <= x + 1) && (x + 1 < max) && (0 <= y + 1) && (y + 1 < max)
			&& (0 <= x + 2) && (x + 2 < max))
		if (t[y][x + 1] == '#' && t[y + 1][x + 1] == '#'
				&& t[y + 1][x + 2] == '#')
			return (1);
	return (0);
}

int			ft_check_tetri(char **t, int x, int y)
{
	int max;

	max = 4 + (5 * (y / 5));
	return (ft_check_tetri_part1(t, x, y, max) ||
			ft_check_tetri_part2(t, x, y, max) ||
			ft_check_tetri_part3(t, x, y, max) ||
			ft_check_tetri_part4(t, x, y, max));
}
