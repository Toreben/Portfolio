/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 05:44:07 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 08:21:08 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static t_point	create_point_3d(t_point point, int x, int y, int z)
{
	point.x3d_or = x;
	point.y3d_or = y;
	point.z3d_or = z;
	return (point);
}

static void		free_quit(int i, char **line_split, t_point **map, char *line)
{
	while (0 <= --i)
		free(map[i]);
	free(map[0]);
	free(map);
	ft_strdel(line_split);
	ft_strdel(&line);
	exit(0);
}

static t_point	*fill_line(t_point *map, char **line_split, size_t i)
{
	size_t j;

	j = -1;
	while (line_split[++j])
	{
		map[j + 1] = create_point_3d(map[j + 1], i - 1, j,
			ft_atoi(line_split[j]));
		free(line_split[j]);
	}
	free(line_split);
	return (map);
}

static int		check_line(char **line_split)
{
	int i;

	i = -1;
	while (line_split[++i])
		if (!(ft_str_is_number(line_split[i])))
		{
			ft_putendl("Invalid data in the map. Please, check it.");
			return (0);
		}
	return (1);
}

t_point			**fill_map(int fd, t_point **map, char *line, size_t map_y)
{
	char	**line_split;
	size_t	i;

	i = 0;
	while (0 <= gnl(fd, &line))
	{
		if (ft_strlen(line) != 0 || !map_y)
		{
			i += map[0][0].y2d;
			line_split = ft_strsplit(line, ' ');
			if (!check_line(line_split))
				free_quit(i, line_split, map, line);
			if (!(map[++i] = (t_point*)malloc(sizeof(t_point)
					* (ft_strstrlen(line_split) + 1))))
				free_quit(i, line_split, map, line);
			map[i][0].x2d = ft_strstrlen(line_split);
			map[i] = fill_line(map[i], line_split, i);
			map_y = 0;
		}
		else
			map[0][0].y2d++;
		ft_strdel(&line);
	}
	return (map);
}
