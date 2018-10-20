/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   uid.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 21:52:40 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/11 12:12:12 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*calcul_repere(t_point *point, t_window *win)
{
	t_angle alpha;
	t_angle omega;

	alpha = win->alpha;
	omega = win->omega;
	*point = mult_matrix_point(win->rot, *point, 1);
	point->x2d = (50 * (omega.cos_ang * point->x3d_rot + (omega.sin_ang
					* point->y3d_rot))) + 100;
	point->y2d = (50 * (alpha.sin_ang * ((omega.sin_ang * point->x3d_rot)
					- (omega.cos_ang * point->y3d_rot)) + (-alpha.cos_ang
					* point->z3d_rot / 100))) + (WIN_Y / 1.1);
	return (point);
}

static void		uid_rep(t_window *win)
{
	int		i;
	t_point	rep[4];

	rep[0].x3d_rel = 0;
	rep[0].y3d_rel = 0;
	rep[0].z3d_or = 0;
	rep[1].x3d_rel = 1;
	rep[1].y3d_rel = 0;
	rep[1].z3d_or = 0;
	rep[1].col = 0xB20D0D;
	rep[2].x3d_rel = 0;
	rep[2].y3d_rel = 1;
	rep[2].z3d_or = 0;
	rep[2].col = 0x3198D6;
	rep[3].x3d_rel = 0;
	rep[3].y3d_rel = 0;
	rep[3].z3d_or = 1;
	rep[3].col = 0x229954;
	i = -1;
	while (++i < 4)
	{
		rep[i] = *(calcul_repere(rep + i, win));
		rep[0].col = rep[i].col;
		print_seg(win, rep[0], rep[i], 0);
	}
}

static void		uid_string2(t_window *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 50, WIN_Y / 2.53,
		0xD5D9E0, "Reset map : 0");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 50, WIN_Y / 2.42,
		0xD5D9E0, "Arrows to move");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 50, WIN_Y / 1.86,
		0xD5D9E0, "Bonuses : find");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 45, WIN_Y / 1.8,
		0xD5D9E0, "by yourself");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 102, WIN_Y / 1.16,
		0x3198D6, "x");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 64, WIN_Y / 1.16,
		0xB20D0D, "y");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 47, WIN_Y / 1.16,
		0x229954, "z");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 50, WIN_Y / 1.39,
		0xD5D9E0, "Colorscheme :");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 47, WIN_Y / 1.35,
		0xD5D9E0, win->colorscheme);
	uid_rep(win);
}

static void		uid_string1(t_window *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 50, WIN_Y / 4.65,
		0xD5D9E0, "Rotation on x : W S");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 50, WIN_Y / 4.29,
		0xD5D9E0, "Rotation on y : Q E");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 50, WIN_Y / 3.99,
		0xD5D9E0, "Rotation on z : A D");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 50, WIN_Y / 2.79,
		0xD5D9E0, "Decrease Z : -");
	mlx_string_put(win->mlx_ptr, win->win_ptr, WIN_X / 50, WIN_Y / 2.66,
		0xD5D9E0, "Increase Z : +");
	uid_string2(win);
}

void			ft_uid(t_window *win)
{
	t_point	line[4];
	int		i;

	line[0].x2d = UID_X;
	line[0].y2d = 0;
	line[1].x2d = UID_X;
	line[1].y2d = WIN_Y;
	line[2].x2d = UID_X;
	line[2].y2d = WIN_Y / 1.2;
	line[3].x2d = 0;
	line[3].y2d = line[2].y2d;
	i = 0;
	while (i < 4)
		line[i++].col = 0xD5D9E0;
	i = 0;
	while (i++ < 10)
	{
		print_seg(win, line[0], line[1], 0);
		line[0].x2d++;
		line[1].x2d++;
		print_seg(win, line[2], line[3], 0);
		line[2].y2d++;
		line[3].y2d++;
	}
	uid_string1(win);
}
