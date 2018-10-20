/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/23 19:16:29 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 23:06:42 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		loop_fract(t_window *win)
{
	mlx_hook(win->win_ptr, 2, 1L, deal_key, win);
	mlx_hook(win->win_ptr, 17, (1L << 17), (void*)red_cross, (void*)win);
	mlx_hook(win->win_ptr, 6, (1L << 6), (void*)modif_julia_center, (void*)win);
	mlx_mouse_hook(win->win_ptr, deal_mouse, win);
	mlx_loop(win->mlx_ptr);
}

static void	input_quit(t_window *win)
{
	ft_putendl("Invalid input : ./fractol [fractal name]");
	ft_putendl("Available fractals :\n1 : Mandelbrot\n2 : Burning Ship");
	ft_putendl("3 : Julia");
	quit(win, 0);
}

int			main(int argc, char **argv)
{
	t_window	*win;

	if (argc != 2)
		input_quit(NULL);
	ft_lower(argv[1]);
	if (!ft_strcmp(argv[1], "mandelbrot") || !ft_strcmp(argv[1], "1"))
	{
		win = create_win();
		init_mandel(win);
	}
	else if (!ft_strcmp(argv[1], "burning ship") || !ft_strcmp(argv[1], "2"))
	{
		win = create_win();
		init_burning(win);
	}
	else if (!ft_strcmp(argv[1], "julia") || !ft_strcmp(argv[1], "3"))
	{
		win = create_win();
		init_julia(win);
	}
	else
		input_quit((win = NULL));
	loop_fract(win);
	return (0);
}
