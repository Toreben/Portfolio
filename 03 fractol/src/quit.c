/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 18:36:52 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/22 16:23:39 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	quit(t_window *win, int ex)
{
	if (win)
	{
		if (ex != 1)
			mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
		if (ex != 2)
			mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		free(win);
	}
	play_music(K_M);
	exit(0);
}
