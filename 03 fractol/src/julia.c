/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/06 21:06:14 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/22 14:16:36 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			modif_julia_center(int x, int y, void *param)
{
	t_window *win;

	win = (t_window*)param;
	if (win->fract.current_fract != JULIA)
		return ;
	if (win->fract.julia.is_moving == FALSE)
		return ;
	win->fract.julia.center.rea = (x / win->fract.zoom)
		+ win->fract.julia.x_min;
	win->fract.julia.center.ima = (y / win->fract.zoom)
		+ win->fract.julia.y_min;
	create_julia(win);
}

void			init_julia(t_window *win)
{
	t_julia julia;

	win->fract.current_fract = JULIA;
	julia.x_min = JULIA_XMIN;
	julia.width = JULIA_WIDTH;
	julia.y_min = JULIA_YMIN;
	julia.height = JULIA_HEIGHT;
	julia.center.rea = -0.70176;
	julia.center.ima = -0.3842;
	julia.is_moving = FALSE;
	if ((IMG_G_X / julia.width) < (IMG_G_Y / julia.height))
		win->fract.zoom = (IMG_G_X / julia.width);
	else
		win->fract.zoom = (IMG_G_Y / julia.height);
	win->fract.julia = julia;
	create_julia(win);
}

static t_uint	ft_julia(t_comp zn, t_comp center, t_uint max,
	t_colorscheme color)
{
	double	mod;
	t_uint	itter;

	itter = -1;
	while (++itter <= max)
	{
		zn = bop_comp(bop_comp(zn, zn, MULT), center, ADD);
		mod = (zn.rea * zn.rea) + (zn.ima * zn.ima);
		if (mod >= 4.0)
			return (ft_color(itter, max, color));
	}
	return (0x0);
}

static void		*thread_calc_julia(void *param)
{
	int			x;
	int			y;
	t_comp		point;
	t_thread	*thread;
	t_julia		*julia;

	thread = (t_thread*)param;
	julia = (t_julia*)thread->fract;
	y = (thread->num_thread * IMG_G_Y / NB_THREAD) - 1;
	while (++y < ((thread->num_thread + 1) * IMG_G_Y / NB_THREAD))
	{
		point.ima = (y / thread->zoom) + julia->y_min;
		x = -1;
		while (++x < IMG_G_X)
		{
			point.rea = (x / thread->zoom) + julia->x_min;
			thread->img_str[((t_uint)y * IMG_G_X) + x] = ft_julia(point,
				julia->center, thread->itter_max, thread->colorscheme);
		}
	}
	free(thread);
	pthread_exit(NULL);
}

void			create_julia(t_window *win)
{
	int				itter;
	pthread_t		a_thread[NB_THREAD];
	t_thread		*thread;

	itter = -1;
	while (++itter < NB_THREAD)
	{
		if (!(thread = (t_thread*)malloc(sizeof(t_thread))))
			quit(win, 0);
		thread->num_thread = itter;
		thread->fract = (void*)&(win->fract.julia);
		thread->img_str = win->img.img_str;
		thread->zoom = win->fract.zoom;
		thread->itter_max = win->fract.itter_max;
		thread->colorscheme = win->fract.colorscheme;
		pthread_create(&a_thread[itter], NULL, thread_calc_julia, thread);
	}
	itter = -1;
	while (++itter < NB_THREAD)
		pthread_join(a_thread[itter], NULL);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		win->img.img_ptr, 0, UI_Y + BORDER);
}
