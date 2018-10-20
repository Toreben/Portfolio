/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 23:22:10 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/22 15:30:44 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_itter(t_window *win)
{
	char	*to_print1;
	char	*to_print2;
	char	*itter;

	itter = ft_itoa(win->fract.itter_max);
	to_print1 = ft_strdup("Increase/decrease iterations : +/- [");
	to_print2 = ft_strjoin(to_print1, itter);
	free(to_print1);
	free(itter);
	to_print1 = ft_strjoin(to_print2, "]");
	free(to_print2);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 26 * UI_X / 70, 3 * UI_Y / 5,
		0xD5D9E0, to_print1);
	free(to_print1);
}

static void	ft_ui_string(t_window *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 6 * UI_X / 70, UI_Y / 5,
		0xD5D9E0, "Arrows to move");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 6 * UI_X / 70, 2 * UI_Y / 5,
		0xD5D9E0, "Mouse Wheel Up/Left Click : zoom in");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 6 * UI_X / 70, 3 * UI_Y / 5,
		0xD5D9E0, "Mouse Wheel Down/Right Click : zoom out");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 26 * UI_X / 70, 2 * UI_Y / 5,
		0xD5D9E0, "Reset map : R");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 26 * UI_X / 70, UI_Y / 5,
		0xD5D9E0, "Change colors : [0-9]");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 48 * UI_X / 70, UI_Y / 5,
		0xD5D9E0, "Lock/Unlock Julia : Space");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 48 * UI_X / 70, 2 * UI_Y / 5,
		0xD5D9E0, "Bonuses : find by yourself");
	mlx_string_put(win->mlx_ptr, win->win_ptr, UI_X + ((IMG_D_X) / 2.5),
		(IMG_D_Y) * 1 / 2, 0xD5D9E0, "Mandelbrot");
	mlx_string_put(win->mlx_ptr, win->win_ptr, UI_X + ((IMG_D_X) / 2.5),
		(IMG_D_Y) * 3 / 2, 0xD5D9E0, "Burning Ship");
	mlx_string_put(win->mlx_ptr, win->win_ptr, UI_X + ((IMG_D_X) / 2.25),
		(IMG_D_Y) * 5 / 2, 0xD5D9E0, "Julia");
	ft_itter(win);
}

static void	ft_menu(t_window *win)
{
	t_comp	p1;
	t_comp	p2;
	int		line;
	int		width;

	line = NB_FRACT;
	while (--line)
	{
		p1.rea = UI_X - 1;
		p1.ima = IMG_D_Y * (NB_FRACT - line) + BORDER * (NB_FRACT - 1 - line);
		p2.rea = WIN_X - 1;
		p2.ima = IMG_D_Y * (NB_FRACT - line) + BORDER * (NB_FRACT - 1 - line);
		width = BORDER;
		while (width--)
		{
			print_seg(win, p1, p2);
			p1.ima++;
			p2.ima++;
		}
	}
}

static void	ft_fractal_lines(t_window *win)
{
	t_comp	p1;
	t_comp	p2;
	t_comp	p3;
	t_comp	p4;
	int		i;

	p1.rea = 0 - 1;
	p1.ima = UI_Y;
	p2.rea = UI_X - 1;
	p2.ima = UI_Y;
	p3.rea = UI_X;
	p3.ima = 0 - 1;
	p4.rea = UI_X;
	p4.ima = WIN_Y - 1;
	i = BORDER;
	while (i--)
	{
		print_seg(win, p1, p2);
		p1.ima++;
		p2.ima++;
		print_seg(win, p3, p4);
		p3.rea++;
		p4.rea++;
	}
}

void		ft_ui(t_window *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	ft_menu(win);
	ft_fractal_lines(win);
	ft_ui_string(win);
}
