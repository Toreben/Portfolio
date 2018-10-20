/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pre_print.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 22:39:13 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/12 19:59:30 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_point			calcul_point_2d(t_point point, t_window *win)
{
	t_angle alpha;
	t_angle omega;

	alpha = win->alpha;
	omega = win->omega;
	point = mult_matrix_point(win->rot, point, win->fac_z);
	point.x2d = (win->fac * (omega.cos_ang * point.x3d_rot + (omega.sin_ang
		* point.y3d_rot))) + win->repere.x0 - UID_X;
	point.y2d = (win->fac * (alpha.sin_ang * ((omega.sin_ang * point.x3d_rot)
		- (omega.cos_ang * point.y3d_rot)) + (alpha.cos_ang
		* point.z3d_rot / 100))) + win->repere.y0;
	return (point);
}

static t_point	**add_p0_map(t_window *win, t_point **map, t_origin p0)
{
	int		i;
	size_t	j;

	win->repere.y0 = WIN_Y / 2;
	win->repere.x0 = (IMG_X / 2) + UID_X;
	i = map[0][0].y2d;
	while (++i <= map[0][0].x2d)
	{
		j = 0;
		while (++j <= (size_t)map[i][0].x2d)
		{
			map[i][j].x3d_rel = map[i][j].x3d_or - p0.y0;
			map[i][j].y3d_rel = map[i][j].y3d_or - p0.x0;
			map[i][j] = calcul_point_2d(map[i][j], win);
			if (IMG_X <= map[i][j].x2d || WIN_Y <= map[i][j].y2d)
			{
				j = (size_t)map[i][0].x2d + 3;
				win->fac = (win->fac > 1) ? win->fac - 1 : win->fac / 2;
			}
			else
				map[i][j].col = set_point_color(win->color, map[i][j]);
		}
		(j == (size_t)map[i][0].x2d + 4) ? i = 0 : 0;
	}
	return (map);
}

static void		loop(t_window *win)
{
	print_map(win);
	mlx_hook(win->win_ptr, 2, 1L, deal_key, win);
	mlx_hook(win->win_ptr, 17, (1L << 17), (void*)red_cross, (void*)win);
	mlx_mouse_hook(win->win_ptr, deal_mouse, win);
	mlx_loop(win->mlx_ptr);
}

void			init_print(t_point ***map, char *title, char *colorscheme)
{
	t_window	*win;
	t_origin	p0;
	int			inc;

	p0.y0 = (*map)[0][0].y2d + ((*map)[0][0].x2d - (*map)[0][0].y2d) / 2;
	inc = 0;
	if (!(*map)[p0.y0])
		while ((*map)[p0.y0][0].x2d == 0)
		{
			if ((*map)[p0.y0 + (inc++)][0].x2d != 0)
				p0.y0 += inc;
			else if ((*map)[p0.y0 + inc][0].x2d != 0)
				p0.y0 -= inc;
		}
	p0.x0 = (*map)[p0.y0][0].x2d / 2;
	if (!(win = (t_window*)malloc(sizeof(t_window))))
		quit(NULL, *map);
	win = create_win(win, title, colorscheme);
	win->colorscheme = colorscheme;
	win->map = add_p0_map(win, *map, p0);
	win->fac_aj = win->fac;
	loop(win);
}
