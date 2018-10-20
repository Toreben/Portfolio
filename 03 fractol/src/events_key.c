/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events_key.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 22:31:28 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/22 15:10:50 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			key_color(int key, t_colorscheme *color)
{
	if (key == K_1 || key == K_2 || key == K_3 || key == K_4 || key == K_5 ||
		key == K_6 || key == K_7 || key == K_8 || key == K_9 || key == K_0 ||
		key == K_PAD_0 || key == K_PAD_1 || key == K_PAD_2 || key == K_PAD_3 ||
		key == K_PAD_4 || key == K_PAD_5 || key == K_PAD_6 || key == K_PAD_7 ||
		key == K_PAD_8 || key == K_PAD_9 || key == K_C)
	{
		(key == K_1 || key == K_PAD_1) ? *color = 1 : 0;
		(key == K_2 || key == K_PAD_2) ? *color = 2 : 0;
		(key == K_3 || key == K_PAD_3) ? *color = 3 : 0;
		(key == K_4 || key == K_PAD_4) ? *color = 4 : 0;
		(key == K_5 || key == K_PAD_5) ? *color = 5 : 0;
		(key == K_6 || key == K_PAD_6) ? *color = 6 : 0;
		(key == K_7 || key == K_PAD_7) ? *color = 7 : 0;
		(key == K_8 || key == K_PAD_8) ? *color = 8 : 0;
		(key == K_9 || key == K_PAD_9) ? *color = 9 : 0;
		(key == K_0 || key == K_PAD_0) ? *color = 0 : 0;
		(key == K_C) ? *color = (*color + 1) % 10 : 0;
		return (1);
	}
	else
		return (0);
}

void		key_mandel(int key, t_window *win)
{
	double		dec;

	if (key == K_UP || key == K_DOWN)
	{
		dec = win->fract.mandel.height / 12;
		dec = (key == K_DOWN) ? dec : -dec;
		win->fract.mandel.y_min += dec;
	}
	if (key == K_LEFT || key == K_RIGHT)
	{
		dec = win->fract.mandel.width / 12;
		dec = (key == K_RIGHT) ? dec : -dec;
		win->fract.mandel.x_min += dec;
	}
	if (key == K_R)
	{
		init_mandel(win);
		win->fract.itter_max = ITTER_MAX;
		ft_ui(win);
	}
	create_mandel(win);
}

void		key_burning(int key, t_window *win)
{
	double		dec;

	if (key == K_UP || key == K_DOWN)
	{
		dec = win->fract.burning.height / 12;
		dec = (key == K_DOWN) ? dec : -dec;
		win->fract.burning.y_min += dec;
	}
	if (key == K_LEFT || key == K_RIGHT)
	{
		dec = win->fract.burning.width / 12;
		dec = (key == K_RIGHT) ? dec : -dec;
		win->fract.burning.x_min += dec;
	}
	if (key == K_R)
	{
		init_burning(win);
		win->fract.itter_max = ITTER_MAX;
		ft_ui(win);
	}
	create_burning(win);
}

void		key_julia(int key, t_window *win)
{
	double		dec;

	if (key == K_UP || key == K_DOWN)
	{
		dec = win->fract.julia.height / 12;
		dec = (key == K_DOWN) ? dec : -dec;
		win->fract.julia.y_min += dec;
	}
	if (key == K_LEFT || key == K_RIGHT)
	{
		dec = win->fract.julia.width / 12;
		dec = (key == K_RIGHT) ? dec : -dec;
		win->fract.julia.x_min += dec;
	}
	if (key == K_R)
	{
		init_julia(win);
		win->fract.itter_max = ITTER_MAX;
		ft_ui(win);
	}
	if (key == K_SPACE && win->fract.julia.is_moving)
		win->fract.julia.is_moving = FALSE;
	else if (key == K_SPACE && !win->fract.julia.is_moving)
		win->fract.julia.is_moving = TRUE;
	create_julia(win);
}

int			deal_key(int key, void *param)
{
	t_window	*win;
	int			aj;

	if (play_music(key))
		return (0);
	if (!key_color(key, &((win = (t_window*)param)->fract.colorscheme)))
	{
		if (key == K_ESC)
			quit(win, 0);
		else if (key == K_PAD_PLUS)
			win->fract.itter_max += (win->fract.itter_max < 20) ? 1 : 10;
		else if (key == K_PAD_MINUS)
		{
			aj = (win->fract.itter_max <= 20) ? 1 : 10;
			win->fract.itter_max -= (win->fract.itter_max == 0) ? 0 : aj;
		}
		ft_ui(win);
	}
	if (win->fract.current_fract == MANDEL)
		key_mandel(key, win);
	else if (win->fract.current_fract == BURNING)
		key_burning(key, win);
	else if (win->fract.current_fract == JULIA)
		key_julia(key, win);
	return (0);
}
