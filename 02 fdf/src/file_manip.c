/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file_manip.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 19:04:49 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 08:21:04 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		open_map(const char *name)
{
	int		fd_map;

	if ((fd_map = open(name, O_RDONLY)) == -1)
	{
		ft_putendl("Error while oppening the file.");
		exit(0);
	}
	return (fd_map);
}

void	close_map(int fd)
{
	if (close(fd))
	{
		ft_putendl("Error while closing the file.");
		exit(0);
	}
}

size_t	get_map_y(int fd)
{
	int		size;
	char	*line;

	size = 0;
	while (0 <= gnl(fd, &line))
	{
		free(line);
		size++;
	}
	return (size);
}
