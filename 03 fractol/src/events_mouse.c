/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events_mouse.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/23 19:46:09 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/22 16:32:03 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_is_in_img(int x, int *y)
{
	if ((UI_Y + BORDER < *y) && (x < IMG_G_X))
	{
		*y -= (UI_Y + BORDER);
		return (1);
	}
	else
		return (0);
}

static void	ft_swap_fract(int x, int y, int button, t_window *win)
{
	if (IMG_G_X + BORDER < x && button == M_LCLICK)
	{
		if ((y <= IMG_D_Y) && (win->fract.current_fract != MANDEL))
			init_mandel(win);
		else if (((IMG_D_Y + BORDER < y) && (y < 2 * IMG_D_Y + BORDER))
			&& (win->fract.current_fract != BURNING))
			init_burning(win);
		else if ((2 * (IMG_D_Y + BORDER) < y) && (y < 3 * IMG_D_Y + 2 * BORDER)
			&& (win->fract.current_fract != JULIA))
			init_julia(win);
	}
}

int			deal_mouse(int button, int x, int y, void *param)
{
	t_window *win;

	win = (t_window*)param;
	if (ft_is_in_img(x, &y))
	{
		if (win->fract.current_fract == MANDEL)
		{
			mouse_mandel(button, x, y, &(win->fract));
			create_mandel(win);
		}
		else if (win->fract.current_fract == BURNING)
		{
			mouse_burning(button, x, y, &(win->fract));
			create_burning(win);
		}
		else if (win->fract.current_fract == JULIA)
		{
			mouse_julia(button, x, y, &(win->fract));
			create_julia(win);
		}
	}
	else
		ft_swap_fract(x, y, button, win);
	return (0);
}

void		red_cross(void *param)
{
	deal_key(K_ESC, param);
}
