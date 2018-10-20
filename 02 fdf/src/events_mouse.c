/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events_mouse.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 18:42:39 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/20 04:55:48 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		deal_mouse(int button, int x, int y, void *param)
{
	t_window *win;

	(void)x;
	(void)y;
	win = (t_window*)param;
	if (button == M_WHEELUP || button == M_WHEELDOWN)
	{
		if (button == M_WHEELUP)
			win->fac *= 1.25;
		if (button == M_WHEELDOWN && win->fac)
		{
			if (win->fac > 0.25)
				win->fac *= 0.75;
			else
				win->fac = 0.1;
		}
		update_point(win, 0x201);
	}
	return (0);
}

void	red_cross(void *param)
{
	deal_key(53, param);
}
