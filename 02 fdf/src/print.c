/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 22:09:21 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/12 20:02:11 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void	calc_print_map(t_window *win)
{
	size_t	i;
	size_t	j;
	size_t	maxi;
	size_t	maxj;
	int		max_next_j;

	maxi = (size_t)win->map[0][0].x2d;
	i = (size_t)win->map[0][0].y2d;
	while (++i <= maxi)
	{
		if (i + 1 <= maxi)
			max_next_j = win->map[i + 1][0].x2d;
		else
			max_next_j = -1;
		j = 0;
		maxj = (size_t)win->map[i][0].x2d;
		while (++j <= maxj)
		{
			if (j != maxj)
				print_seg(win, win->map[i][j], win->map[i][j + 1], 1);
			if (max_next_j != -1)
				if (i != maxi && j <= (size_t)max_next_j)
					print_seg(win, win->map[i][j], win->map[i + 1][j], 1);
		}
	}
}

void		print_map(t_window *win)
{
	ft_bzero(win->img.img_str, WIN_Y * IMG_X * 4);
	calc_print_map(win);
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		win->img.img_ptr, UID_X + 10, 0);
	ft_uid(win);
}
