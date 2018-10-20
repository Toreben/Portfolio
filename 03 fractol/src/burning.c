/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   burning.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/27 01:39:18 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/22 15:49:43 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				init_burning(t_window *win)
{
	t_burning burning;

	win->fract.current_fract = BURNING;
	burning.x_min = BURNING_XMIN;
	burning.width = BURNING_WIDTH;
	burning.y_min = BURNING_YMIN;
	burning.height = BURNING_HEIGHT;
	if ((IMG_G_X / burning.width) < (IMG_G_Y / burning.height))
		win->fract.zoom = (IMG_G_X / burning.width);
	else
		win->fract.zoom = (IMG_G_Y / burning.height);
	win->fract.burning = burning;
	create_burning(win);
}

static t_uint		ft_burning(t_comp num, t_uint max, t_colorscheme color)
{
	double			mod;
	t_uint			itter;
	t_comp			zn;

	itter = -1;
	zn.rea = 0;
	zn.ima = 0;
	while (++itter <= max)
	{
		zn.rea = fabs(zn.rea);
		zn.ima = fabs(zn.ima);
		zn = bop_comp(bop_comp(zn, zn, MULT), num, ADD);
		mod = (zn.rea * zn.rea) + (zn.ima * zn.ima);
		if (mod >= 4.0)
			return (ft_color(itter, max, color));
	}
	return (0x0);
}

static void			*thread_calc_burning(void *param)
{
	int				x;
	int				y;
	t_comp			point;
	t_thread		*thread;
	t_burning		*burning;

	thread = (t_thread*)param;
	burning = (t_burning*)thread->fract;
	y = (thread->num_thread * IMG_G_Y / NB_THREAD) - 1;
	while (++y < ((thread->num_thread + 1) * IMG_G_Y / NB_THREAD))
	{
		point.ima = (y / thread->zoom) + burning->y_min;
		x = -1;
		while (++x < IMG_G_X)
		{
			point.rea = (x / thread->zoom) + burning->x_min;
			thread->img_str[((t_uint)y * IMG_G_X) + x] = ft_burning(point,
				thread->itter_max, thread->colorscheme);
		}
	}
	free(thread);
	pthread_exit(NULL);
}

void				create_burning(t_window *win)
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
		thread->fract = (void*)&(win->fract.burning);
		thread->img_str = win->img.img_str;
		thread->zoom = win->fract.zoom;
		thread->itter_max = win->fract.itter_max;
		thread->colorscheme = win->fract.colorscheme;
		pthread_create(&a_thread[itter], NULL, thread_calc_burning, thread);
	}
	itter = -1;
	while (++itter < NB_THREAD)
		pthread_join(a_thread[itter], NULL);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		win->img.img_ptr, 0, UI_Y + BORDER);
}
