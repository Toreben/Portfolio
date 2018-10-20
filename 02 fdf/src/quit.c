/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 03:39:45 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 08:31:55 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	quit(t_window *win, t_point **map)
{
	int i;
	int maxi;

	i = -1;
	if (win)
	{
		maxi = win->map[0][0].x2d;
		while (++i <= maxi)
			free(win->map[i]);
		free(win->map);
		mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		free(win);
	}
	else
	{
		maxi = map[0][0].x2d;
		while (++i <= maxi)
			free(map[i]);
		free(map);
	}
	exit(0);
}
